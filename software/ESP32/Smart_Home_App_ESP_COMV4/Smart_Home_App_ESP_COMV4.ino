#include <parameters.h>

// ===== Núcleo 0 (Principal) - Manejo WiFi =====
void TaskWiFi(void *pvParameters) {
  // Inicializar LittleFS
  if (!LittleFS.begin(true)) {
    Serial.println("Error al montar LittleFS");
    vTaskDelete(NULL);
  }

  // Leer credenciales WiFi
  ssid = readFile(LittleFS, ssidPath);
  pass = readFile(LittleFS, passPath);

  // Intentar conectar a WiFi
  if (ssid != "" && initWiFi()) {

    if(connection==1){
      wifiConnected = true;
      tcpServer.begin();
      Serial.print("Servidor TCP iniciado en: ");
      Serial.println(WiFi.localIP());
    }
    else{
      if (tcpServer.available()){
        tcpServer.stop();
      }
    }
    
  } else {

    WiFi.softAP("UNIT-WIFI-MANAGER", NULL);
    Serial.print("AP iniciado. IP: ");
    Serial.println(WiFi.softAPIP());

    // Configurar servidor web para configuración
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(LittleFS, "/wifimanager.html", "text/html");
    });
    
    server.serveStatic("/", LittleFS, "/");
    
    server.on("/", HTTP_POST, [](AsyncWebServerRequest *request) {
      int params = request->params();
      for(int i=0; i<params; i++){
        const AsyncWebParameter* p = request->getParam(i);
        if(p->isPost()){
          if (p->name() == "ssid") {
            ssid = p->value().c_str();
            writeFile(LittleFS, ssidPath, ssid.c_str());
          }
          if (p->name() == "pass") {
            pass = p->value().c_str();
            writeFile(LittleFS, passPath, pass.c_str());
          }
        }
      }
      request->send(200, "text/plain", "Configuración guardada. Reiniciando...");
      delay(3000);
      ESP.restart();
    });

    server.on("/scan", HTTP_GET, [](AsyncWebServerRequest *request) {
        scanWiFiNetworks();
        
        String json = "[";
        for (size_t i = 0; i < availableNetworks.size(); i++) {
            if (i != 0) json += ",";
            
            // Separar SSID y RSSI
            int separatorPos = availableNetworks[i].indexOf('|');
            String ssid = availableNetworks[i].substring(0, separatorPos);
            String rssi = availableNetworks[i].substring(separatorPos + 1);
            
            // Nota: Aquí el JSON solo incluye el SSID limpio en el campo "ssid"
            json += "{\"ssid\":\"" + ssid + "\",\"rssi\":" + rssi + "}";
        }
        json += "]";
        
        request->send(200, "application/json", json);
    });

    server.begin();
  }

  while (1) {
    if (wifiConnected) {
      if(connection != 1 ){
        wifiConnected = false;
        Serial.println("Connection STOP");
        tcpServer.stop();

      }
      else{
        handleTCPClients();
      }
    }
    else{
      if(connection == 1){
        Serial.println("Connection START");
        tcpServer.begin();
        wifiConnected = true;
      }
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

// ===== Núcleo 1 - Comunicación Serial =====
void TaskSerial(void *pvParameters) {

  Serial1.setPins(RX_PIN, TX_PIN);
  Serial1.begin(115200);
  Serial1.setTimeout(500);

  String serialBuffer;
  unsigned long lastReceiveTime = 0;

  while (1) {
    while (Serial1.available()) {
      char c = Serial1.read();
      serialBuffer += c;
      lastReceiveTime = millis();
      
      if (c == '\n') {
        processRP2040Message(serialBuffer);
        serialBuffer = "";
      }
    }
    if (serialBuffer.length() > 0 && (millis() - lastReceiveTime > 100)) {
      Serial.print("Datos incompletos descartados: ");
      Serial.println(serialBuffer);
      serialBuffer = "";
    }
    if(sendRP ==1){
      sendWifiInfo();
      sendRP =0;
    }
      vTaskDelay(10 / portTICK_PERIOD_MS);

  }
}

void scanWiFiNetworks() {
  availableNetworks.clear();
  
  Serial.println("Escaneando redes WiFi...");
  int numNetworks = WiFi.scanNetworks();
  
  for (int i = 0; i < numNetworks; ++i) {
    availableNetworks.push_back(WiFi.SSID(i) + "|" + String(WiFi.RSSI(i)));
    delay(10);
  }
}

void processRP2040Message(String message) {
  message.trim();
  if (message.length() == 0) return;

  Serial.print("Datos RP2040: ");
  Serial.println(message);
  
  mtx.lock();
  
  if (processSerialData(message)) {
    // Datos de sensores procesados
  } 
  else if (processSerialFlag(message)) {
    if (connection == 1 && Serial1.availableForWrite()) {
      sendConnectionInfo();
    }
  }
  else if(processSerialDelete(message)){

  }
  
  
  mtx.unlock();
}

void sendConnectionInfo() {
  JsonDocument docIP;

  if(WiFi.localIP().toString() != "0.0.0.0"){
    docIP["IP"] = WiFi.localIP().toString();
  }
  else{
    docIP["IP"] = WiFi.softAPIP().toString();
  }
  //docIP["IP"] = WiFi.localIP().toString();
  docIP["val"] = connection;
  
  if (Serial1.availableForWrite()) {
    serializeJson(docIP, Serial1);
    Serial1.println();
    
    Serial.print("Enviado: ");
    serializeJson(docIP, Serial);
    Serial.println();
  }
}

void sendWifiInfo() {

  String data = "";
  
  if(Serial1.availableForWrite()){
    serializeJson(docLed, data);

    for (int i = 0; i < data.length(); i++) {
      Serial1.write(data.charAt(i)); 
      delay(10); 
    }
    Serial1.println();
    
    Serial.print("Enviado: ");
    Serial.print(data);
    Serial.println();

  }
  
}

// ===== Funciones auxiliares =====
String readFile(fs::FS &fs, const char *path) {
  File file = fs.open(path);
  if(!file || file.isDirectory()) return String();
  String content = file.readStringUntil('\n');
  file.close();
  return content;
}

void writeFile(fs::FS &fs, const char *path, const char *message) {
  File file = fs.open(path, FILE_WRITE);
  if(file) file.print(message);
  file.close();
}

void deleteFile(fs::FS &fs, const char *path){
    if(fs.remove(path)){
        Serial.println("- file deleted");
    } else {
        Serial.println("- delete failed");
    }
}

void handleTCPClients() {
  WiFiClient client = tcpServer.available();
  if (client) {
    Serial.println("Cliente conectado");
    while (client.connected()) {
      if (client.available()) {
        String request = client.readStringUntil('\n');
        request.trim();

        Serial.print("Mensaje TCP: ");
        Serial.println(request);

        mtx.lock();
        if(processData(request)){

          Serial.println("Procesando otra cosa");
          sendRP = 1;
        }
        mtx.unlock();
        
      }
      mtx.lock();
      sendSensorData(client);
      mtx.unlock();

      vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
    Serial.println("Cliente desconectado");
  }
}

void sendSensorData(WiFiClient &client) {
  JsonDocument doc;
  doc["temp"] = Temperature;
  doc["humidity"] = Humidity;
  doc["flame"] = Flame;
  doc["light"] = Light;
  doc["rain"] = Rainwater;
  doc["door"] = doorState;
  doc["pir"] = PIRState;
  doc["ir"] = IRval;
  doc["button"] = BTNstate;
  
  serializeJson(doc, client);
  client.println();
  Serial.print("Send Wifi: ");
  serializeJson(doc, Serial);
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  //NeoPixel.begin();

  xTaskCreatePinnedToCore(
    TaskWiFi,    // Función de la tarea
    "TaskWiFi",  // Nombre
    10000,       // Tamaño del stack
    NULL,        // Parámetros
    1,           // Prioridad
    NULL,        // Handle de la tarea
    0            // Núcleo 0
  );

  xTaskCreatePinnedToCore(
    TaskSerial,  // Función de la tarea
    "TaskSerial",// Nombre
    10000,       // Tamaño del stack
    NULL,        // Parámetros
    1,           // Prioridad
    NULL,        // Handle de la tarea
    1            // Núcleo 1
  );
}

bool processData(String data){
  const char* json = data.c_str();

  DeserializationError error = deserializeJson(docLed, json);

  if(error){
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return false;
  }
  const char* test = docLed["sensor"];
  if(test == ""){
    return false;
  }
    if(test == NULL){
    return false;
  }

  sensor = docLed["sensor"];
  num = docLed["numero"];
  val = docLed["valor"];
  r = docLed["data"][0];
  g = docLed["data"][1];
  b = docLed["data"][2];
  return true;

}

bool initWiFi() {
  if (ssid == "") {
    Serial.println("Undefined SSID.");
    return false;
  }
    
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), pass.c_str());
  
  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startTime < 10000) {
    delay(500);
    Serial.print(".");
  }
  
  return WiFi.status() == WL_CONNECTED;
}

bool processSerialData(String data) {
  const char* json = data.c_str();

  DeserializationError error = deserializeJson(docSens, json);

  if(error){
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return false;
  }

  float test = docSens["temp"];
  if(test == 0){
    return false;
  }

  Temperature = docSens["temp"];
  Humidity = docSens["humidity"];
  Flame = docSens["flame"]; 
  Light = docSens["light"];
  Rainwater = docSens["rain"];
  doorState = docSens["door"];
  PIRState = docSens["pir"];
  IRval = docSens["ir"];
  BTNstate = docSens["button"];
  
  return true;

}


bool processSerialFlag(String data){
  const char* json = data.c_str();

  DeserializationError error = deserializeJson(docFlag, json);

  if(error){
    Serial.print(F("deserializeJson() docFlag failed: "));
    Serial.println(error.f_str());
    return false;
  }
  int conn1 = docFlag["online"] | 2;
  if(conn1 == 2){
    return false;
  }
  connection = docFlag["online"];
  Serial.println(connection);
  return true;

}

bool processSerialDelete(String data){
  const char* json = data.c_str();

  DeserializationError error = deserializeJson(docFlag2, json);

  if(error){
    Serial.print(F("deserializeJson() docFlag failed: "));
    Serial.println(error.f_str());
    return false;
  }
  int del = docFlag["delete"] | 2;
  if(del == 2){
    return false;
  }
  deleteFile(LittleFS, ssidPath);
  deleteFile(LittleFS, passPath);

  return true;

}

void loop() {
}
