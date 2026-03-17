//NOTA: Core0 solo lectura (Encoder), Core1 solo escritura (OLED)
#include "parametros.h"


void setup() {
  //Serial
  Serial.begin(115200);

  //SPI RFID
  SPI.setRX(16);   // MISO      //*
  SPI.setTX(19);   // MOSI
  SPI.setSCK(18);  // SCK

  //Entrada pines
  pinMode(PIN_ENCODER_A, INPUT_PULLUP);
  pinMode(PIN_ENCODER_B, INPUT_PULLUP);
  pinMode(PIN_BOTON_ENCODER, INPUT_PULLUP);
  pinMode(PIN_BOTON_CAPACITIVO, INPUT_PULLUP);
  pinMode(PIN_LLUVIA, INPUT);
  pinMode(PIN_FOTORRESISTOR, INPUT);
  pinMode(PIN_FLAMA, INPUT);
  pinMode(PIN_PIR, INPUT);
  pinMode(PIN_BUZZER, OUTPUT);  //Buzzer
  IrReceiver.begin(PIN_IR, ENABLE_LED_FEEDBACK);
  FLAG_SENSORES = true;
}

void loop() {
  leerEncoder();
  LECTURA_B_ENC = digitalRead(PIN_BOTON_ENCODER);
  processIR();
  switch (int(cuenta / 4)) {
    case 0:
      if (SEL_MENU == 1) {
        //Se hace la lectura de temperatura y humedad en el menu
        if (RFIDmode == 0) {
          SPI.begin();         // Inicia el SPI con los pines definidos
          mfrc522.PCD_Init();  //*
          RFIDmode = 3;
        }
        IRmode = 1;
        EDO_LLUVIA = digitalRead(PIN_LLUVIA);
        EDO_FOTORRESISTOR = analogRead(PIN_FOTORRESISTOR);
        EDO_FLAMA = digitalRead(PIN_FLAMA);
        //Boton
        LECTURA_B = digitalRead(PIN_BOTON_CAPACITIVO);
        if (LECTURA_B != EDO_ANT_B) {
          LDT = millis();
        }
        if ((millis() - LDT) > DD) {
          if (LECTURA_B != EDO_ACT_B) {
            EDO_ACT_B = LECTURA_B;
          }
        }
        EDO_ANT_B = LECTURA_B;

        valPIR = digitalRead(PIN_PIR);
      }
      break;
    case 1:
      if (SEL_MENU == 1) {
        //Se hace la lectura de temperatura y humedad en el menu
        if (RFIDmode == 0) {
          SPI.begin();         // Inicia el SPI con los pines definidos
          mfrc522.PCD_Init();  //*
          RFIDmode = 2;
        }
        IRmode = 1;
        EDO_LLUVIA = digitalRead(PIN_LLUVIA);
        EDO_FOTORRESISTOR = analogRead(PIN_FOTORRESISTOR);
        EDO_FLAMA = digitalRead(PIN_FLAMA);
        //Boton
        LECTURA_B = digitalRead(PIN_BOTON_CAPACITIVO);
        if (LECTURA_B != EDO_ANT_B) {
          LDT = millis();
        }
        if ((millis() - LDT) > DD) {
          if (LECTURA_B != EDO_ACT_B) {
            EDO_ACT_B = LECTURA_B;
          }
        }
        EDO_ANT_B = LECTURA_B;

        valPIR = digitalRead(PIN_PIR);
      }
      break;
    case 2:
      if (SEL_MENU == 1)  //Se hace la lectura en el menu
        break;
    case 3:
      if (SEL_MENU == 1) {
        if (RFIDmode == 0) {
          SPI.begin();         // Inicia el SPI con los pines definidos
          mfrc522.PCD_Init();  //*
          RFIDmode = 1;
        }
      }
      break;
    case 4:
      if (SEL_MENU == 1) IRmode = 1;
      break;
    case 5:
      if (SEL_MENU == 1) EDO_LLUVIA = digitalRead(PIN_LLUVIA);
      break;
    case 6:
      if (SEL_MENU == 1) EDO_FOTORRESISTOR = analogRead(PIN_FOTORRESISTOR);
      break;
    case 7:
      if (SEL_MENU == 1) EDO_FLAMA = digitalRead(PIN_FLAMA);
      break;
    case 8:
      if (SEL_MENU == 1) {
        //BotonCapacitivo
        LECTURA_B = digitalRead(PIN_BOTON_CAPACITIVO);
        if (LECTURA_B != EDO_ANT_B) {
          LDT = millis();
        }
        if ((millis() - LDT) > DD) {
          if (LECTURA_B != EDO_ACT_B) {
            EDO_ACT_B = LECTURA_B;
          }
        }
        EDO_ANT_B = LECTURA_B;
      }
      break;
    case 9:
      if (SEL_MENU == 1) {
        valPIR = digitalRead(PIN_PIR);
      }
      break;
  }
}

void setup1() {
  Serial1.setRX(RX_PIN);  //  Se configura e inicia la comunicacion con ESP32
  Serial1.setTX(TX_PIN);
  Serial1.begin(115200);
  //Serial1.println("Serial 1");  //*
  //while(Serial1.available()) Serial1.read();
  //Pantalla OLED
  Wire.setSDA(PIN_SDA_PANTALLA);
  Wire.setSCL(PIN_SCL_PANTALLA);
  Wire.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  delay(100);

  //Servomotor/PuenteH
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  pwm.writeMicroseconds(0, 1500);
  delay(500);
  pwm.setPWM(1, 0, 0);
  pwm.setPWM(2, 0, 0);
  //Neopixel
  NeoPixel.begin();
  //------
  display.clearDisplay();
  display.drawBitmap(0, 0, logo, 128, 64, 1);
  display.display();

  delay(2000);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(42, 10);
  display.println("UNIT");
  display.setTextSize(1);
  display.setCursor(35, 25);
  display.println("Electronics");
  display.setTextSize(2);
  display.setCursor(10, 45);
  display.println("SmartHome");
  display.display();

  delay(2000);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(42, 10);
  display.println("UNIT");
  display.setTextSize(1);
  display.setCursor(35, 25);
  display.println("Electronics");
  display.setTextSize(2);
  display.setCursor(0, 35);
  display.println("Conectando");
  display.setCursor(15, 50);
  display.println("sensores");
  display.display();
  delay(2000);
}


void loop1() {
  if (FLAG_SENSORES == true) menu();
  if (connection == 1){

    static String serialBuffer;
    static unsigned long lastReceiveTime = 0;

    while (Serial1.available()) {
      char c = Serial1.read();
      serialBuffer += c;
      lastReceiveTime = millis();
      if (c == '\n') {
      processSerialMessage(serialBuffer);
      serialBuffer = "";
      }
    }
    if (serialBuffer.length() > 0 && (millis() - lastReceiveTime > 500)) {
      Serial.print("Timeout, datos incompletos: ");
      Serial.println(serialBuffer);
      serialBuffer = "";
    }
  }
}

void processSerialMessage(String message) {
  message.trim();
  if (message.length() == 0) return;

  Serial.print("Recibido: ");
  Serial.println(message);
  
  if (connection == 1) {
    if (processData(message)) {
      executeCommand();
    }
  } else if (processFlag(message)) {
    Serial.print("Estado conexión: ");
    Serial.println(connection);
  }
}

void executeCommand() {
  Serial.println(sensor);
  if (String(sensor) == "motor") {
    Serial.println(val);
    if (val == 1){
      pwm.setPWM(1, 0, 3000);
      pwm.setPWM(2, 0, 0); 
    }else {
      pwm.setPWM(1, 0, 0);
      pwm.setPWM(2, 0, 0); 
    }
  } else if (String(sensor) == "servo") {
    pwm.writeMicroseconds(0, val == 1 ? 800 : 1500);
  }else if (String(sensor) == "buzzer") {
    if (num == 1) playJingleBells();
    else playOther();
  }
}

void leerEncoder() {
  //BotonEncoder
  if (LECTURA_B_ENC != EDO_ANT_B_ENC) {
    LDT = millis();
  }
  if ((millis() - LDT) > DD) {
    if (LECTURA_B_ENC != EDO_ACT_B_ENC) {
      EDO_ACT_B_ENC = LECTURA_B_ENC;
      if (EDO_ACT_B_ENC == false) {
        SEL_MENU++;
      }
    }
  }
  EDO_ANT_B_ENC = LECTURA_B_ENC;

  //Encoder
  if (SEL_MENU == 0) {

    ENC_A = digitalRead(PIN_ENCODER_A);
    ENC_B = digitalRead(PIN_ENCODER_B);

    ESTADO_ENC = ENC_A + (ENC_B * 2);

    if (ESTADO_ENC != ESTADO_ENC_ANTERIOR) {
      if ((ESTADO_ENC == 3) && (ESTADO_ENC_ANTERIOR == 2) && (cuenta < 36)) cuenta++;
      if ((ESTADO_ENC == 1) && (ESTADO_ENC_ANTERIOR == 3) && (cuenta < 36)) cuenta++;
      if ((ESTADO_ENC == 0) && (ESTADO_ENC_ANTERIOR == 1) && (cuenta < 36)) cuenta++;
      if ((ESTADO_ENC == 2) && (ESTADO_ENC_ANTERIOR == 0) && (cuenta < 36)) cuenta++;

      if ((ESTADO_ENC == 0) && (ESTADO_ENC_ANTERIOR == 2) && (cuenta > 0)) cuenta--;
      if ((ESTADO_ENC == 1) && (ESTADO_ENC_ANTERIOR == 0) && (cuenta > 0)) cuenta--;
      if ((ESTADO_ENC == 3) && (ESTADO_ENC_ANTERIOR == 1) && (cuenta > 0)) cuenta--;
      if ((ESTADO_ENC == 2) && (ESTADO_ENC_ANTERIOR == 3) && (cuenta > 0)) cuenta--;
    }
    ESTADO_ENC_ANTERIOR = ESTADO_ENC;
  }
}

void menu() {
  switch (int(cuenta / 4)) {
    case 0:
      programaAPP();
      break;
    case 1:
      programaOffline();
      break;
    case 2:
      testTemperaturaHumedad();
      break;
    case 3:
      testRFID();
      break;
    case 4:
      testIR();
      break;
    case 5:
      testLluvia();
      break;
    case 6:
      testFotorresistor();
      break;
    case 7:
      testFlama();
      break;
    case 8:
      testBoton();
      break;
    case 9:
      testPIR();
      break;
  }
  delay(50);
}

void programaAPP() {
  switch (SEL_MENU) {
    case 0:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(42, 10);
      display.println("UNIT");
      display.setTextSize(1);
      display.setCursor(35, 25);
      display.println("Electronics");
      display.setTextSize(2);
      display.setCursor(18, 35);
      display.println("Programa");
      display.setCursor(48, 50);
      display.println("APP");
      display.display();
      break;
    case 1:
    /*-------------------------------------------------------------*/
      if (connection == 0) {
        if (Serial1.availableForWrite()) {
          JsonDocument flag;
          flag["online"] = 1;
          serializeJson(flag, Serial1);
          Serial1.println();
        }
      }
      while (!connection) {
        //Aqui
        if (Serial1.available()) {
          String Recibido = Serial1.readStringUntil('\n');
          Serial.println(Recibido);
          processFlag(Recibido);
          delay(100);
        }
      }
      /*-------------------------------------------------------------*/
      processPIR();
      readRFID();
      //Lectura de temp y humedad
      if (ATH10_mode == 0) {
        aht.begin();
        ATH10_mode = 1;
      }

      aht.getEvent(&humidity, &temp);
      dato_temperatura = float(temp.temperature);
      dato_humedad = float(humidity.relative_humidity);
      //delay(500);
      /*-------------------------------------------------------------*/
      doc["temp"] = dato_temperatura;
      doc["humidity"] = dato_humedad;
      doc["flame"] = int(EDO_FLAMA);
      doc["light"] = int(EDO_FOTORRESISTOR);
      doc["rain"] = int(EDO_LLUVIA);
      doc["door"] = uidString;
      doc["pir"] = EDO_PIR;
      doc["ir"] = IR_value;
      doc["button"] = int(EDO_ACT_B);

      if (Serial1.availableForWrite()) {
        serializeJson(doc, Serial1);
        Serial1.println(""); 
      }

      /*-------------------------------------------------------------*/
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0, 10);
      display.setTextSize(1);
      display.println("Ingrese la siguiente IP en la aplicacion: ");
      display.setTextSize(2);
      display.println(IP);
      display.display();
      break;
    case 2:
      if (connection == 1) {
        if (Serial1.availableForWrite()) {
          JsonDocument flag;
          flag["online"] = 0;
          serializeJson(flag, Serial1);
          Serial1.println();
          connection = 0;
        }
      }
      NeoPixel.setPixelColor(0, NeoPixel.Color(0, 0, 0));
      NeoPixel.setPixelColor(1, NeoPixel.Color(0, 0, 0));
      NeoPixel.setPixelColor(2, NeoPixel.Color(0, 0, 0));
      NeoPixel.show();
      pwm.setPWM(1, 0, 0);
      pwm.setPWM(2, 0, 0);
      SEL_MENU = 0;
      menu();
      break;
  }
}

void programaOffline() {
  switch (SEL_MENU) {
    case 0:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(42, 10);
      display.println("UNIT");
      display.setTextSize(1);
      display.setCursor(35, 25);
      display.println("Electronics");
      display.setTextSize(2);
      display.setCursor(18, 35);
      display.println("Programa ");
      display.setCursor(20, 50);
      display.println("Offline");
      display.display();
      break;
    case 1:
      RFIDstate = 1;
      /*-------------------------------------------------------------*/
      processPIR();
      readRFID();
      //Lectura de temp y humedad
      if (ATH10_mode == 0) {
        aht.begin();
        ATH10_mode = 1;
      }

      aht.getEvent(&humidity, &temp);
      dato_temperatura = float(temp.temperature);
      dato_humedad = float(humidity.relative_humidity);
      delay(500);
      /*-------------------------------------------------------------*/

      /*-------------------------------------------------------------*/
      //Rutina 
      Serial.print("Temperatura: ");Serial.println(dato_temperatura);
      Serial.print("Fotorresistor: ");Serial.println(String(EDO_FOTORRESISTOR, DEC));
      Serial.print("PIR: ");Serial.println(EDO_PIR);
      Serial.print("RFID: ");Serial.print(mensajeOffline);Serial.print(" | ");Serial.println(uidString);
      
      //LOGICA TEMPERATURA Y FLAMA 
      if (dato_temperatura > 35 || EDO_FLAMA == 1){
        pwm.setPWM(1, 0, 3000);
        pwm.setPWM(2, 0, 0); 
      } else{
        pwm.setPWM(1, 0, 0);
        pwm.setPWM(2, 0, 0); 
      }
      //LOGICA RFID && LLUVIA 
      if ((uidString == acceptedRFID_2 && EDO_PUERTA == 1)||(EDO_LLUVIA == 0 && EDO_PUERTA == 1)){
          pwm.writeMicroseconds(0, 1500);
          mensajeOffline = uidString; 
          EDO_PUERTA = 0;
          delay(200);
          uidHandled = true;
      }
      //LOGICA IR IRMODE=2
      //IRMODE = 2;
      //LOGICA FOTORRESISTOR
      if ((String(EDO_FOTORRESISTOR, DEC)).toInt() >= 850){
        NeoPixel.setPixelColor(0, NeoPixel.Color(255, 255, 255));
        NeoPixel.setPixelColor(1, NeoPixel.Color(255, 255, 255));
        NeoPixel.show();
      } else {
        NeoPixel.setPixelColor(0, NeoPixel.Color(0, 0, 0));
        NeoPixel.setPixelColor(1, NeoPixel.Color(0, 0, 0));
        NeoPixel.show();
      }

      //LOGICA BOTON
      if (EDO_ACT_B == 1){
        playDingDong();
        delay(50);
      }
      
      //LOGICA PIR
      if (EDO_PIR == 1) {
        NeoPixel.setPixelColor(2, NeoPixel.Color(255, 255, 255));
        NeoPixel.show();
      } else {
        NeoPixel.setPixelColor(2, NeoPixel.Color(0, 0, 0));
        NeoPixel.show();
      }
  
      /*-------------------------------------------------------------*/
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);
      display.println("OFFLINE");
      display.setCursor(5, 15);
      display.setTextSize(1);
      display.print("Temp :");display.print(dato_temperatura); display.println(" °C");
      display.setCursor(5, 25);
      display.print("Hum :"); display.print(dato_humedad); display.println(" % rH");
      display.setCursor(5, 35);
      display.print("BTN :"); display.print(EDO_ACT_B);
      display.setCursor(50, 35);
      display.print("| LDR :"); display.println(EDO_FOTORRESISTOR, DEC);
      display.setCursor(5, 45);
      display.print("RFID :"); display.print(mensajeOffline);
      display.display();
      
      break;
    case 2:
      RFIDstate = 0;
      RFIDmode = 0;
      NeoPixel.clear();
      NeoPixel.show();
      SEL_MENU = 0;
      menu();
      break;
  }
}

void testTemperaturaHumedad() {
  switch (SEL_MENU) {
    case 0:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(42, 10);
      display.println("UNIT");
      display.setTextSize(1);
      display.setCursor(35, 25);
      display.println("Electronics");
      display.setTextSize(2);
      display.setCursor(5, 35);
      display.println("Test AHT10");
      display.display();
      break;
    case 1:
      if (ATH10_mode == 0) {
        aht.begin();
        ATH10_mode = 1;
      }
      aht.getEvent(&humidity, &temp);
      dato_temperatura = float(temp.temperature);
      dato_humedad = float(humidity.relative_humidity);
      delay(500);
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(5, 5);
      display.println("Temp:");
      display.setCursor(5, 20);
      display.print(dato_temperatura);
      display.print(" °C");
      display.setCursor(5, 35);
      display.println("Hum:");
      display.setCursor(5, 50);
      display.print(dato_humedad);
      display.print(" % rH");
      display.display();
      if (temp.temperature >= 30) {
        pwm.writeMicroseconds(1, 2400);
        pwm.writeMicroseconds(2, 600);
      }  //Encender motor
      else {
        pwm.writeMicroseconds(1, 600);
        pwm.writeMicroseconds(2, 600);
      }  //Apagar motor
      break;
    case 2:
      ATH10_mode = 0;
      pwm.writeMicroseconds(1, 600);
      pwm.writeMicroseconds(2, 600);
      SEL_MENU = 0;
      menu();
      break;
  }
}

void testRFID() {
  switch (SEL_MENU) {
    case 0:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(42, 10);
      display.println("UNIT");
      display.setTextSize(1);
      display.setCursor(35, 25);
      display.println("Electronics");
      display.setTextSize(2);
      display.setCursor(10, 35);
      display.println("Test RFID");
      display.display();
      break;
    case 1:
      RFIDstate = 1;
      readRFID();
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(10, 10);
      display.println("RFID");
      display.setCursor(10, 50);
      display.println(uidString);
      display.display();
      break;
    case 2:
      RFIDstate = 0;
      SEL_MENU = 0;
      SPI.end();
      RFIDmode = 0;
      menu();
      break;
  }
}

void testIR() {
  switch (SEL_MENU) {
    case 0:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(42, 10);
      display.println("UNIT");
      display.setTextSize(1);
      display.setCursor(35, 25);
      display.println("Electronics");
      display.setTextSize(2);
      display.setCursor(20, 35);
      display.println("Test IR");
      display.display();
      break;
    case 1:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(10, 10);
      display.println("IR");
      display.setCursor(10, 40);
      display.println(IR_value);
      display.display();
      break;
    case 2:
      SEL_MENU = 0;
      IRmode = 0;
      IR_value = "";
      menu();
      break;
  }
}

void testLluvia() {
  switch (SEL_MENU) {
    case 0:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(42, 10);
      display.println("UNIT");
      display.setTextSize(1);
      display.setCursor(35, 25);
      display.println("Electronics");
      display.setTextSize(2);
      display.setCursor(42, 35);
      display.println("Test");
      display.setCursor(30, 50);
      display.println("Lluvia");
      display.display();
      break;
    case 1:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(10, 10);
      display.println("Llueve?");
      display.setCursor(10, 30);
      if (EDO_LLUVIA == LOW) {
        display.println("Si, esta lloviendo");  //Lluvia
      } else {
        display.println("No, aun no");
      }
      display.display();
      break;
    case 2:
      SEL_MENU = 0;
      menu();
      break;
  }
}

void testFotorresistor() {
  switch (SEL_MENU) {
    case 0:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(42, 10);
      display.println("UNIT");
      display.setTextSize(1);
      display.setCursor(35, 25);
      display.println("Electronics");
      display.setTextSize(2);
      display.setCursor(15, 35);
      display.print("Test LDR");
      display.display();
      break;
    case 1:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(5, 5);
      display.println("VALOR LDR:");
      display.setCursor(5, 40);
      display.println(EDO_FOTORRESISTOR, DEC);
      display.display();
      break;
    case 2:
      SEL_MENU = 0;
      menu();
      break;
  }
}

void testFlama() {
  switch (SEL_MENU) {
    case 0:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(42, 10);
      display.println("UNIT");
      display.setTextSize(1);
      display.setCursor(35, 25);
      display.println("Electronics");
      display.setTextSize(2);
      display.setCursor(2, 35);
      display.println("Test Flama");
      display.display();
      break;
    case 1:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(10, 10);
      display.print("FLAMA: ");
      display.println(EDO_FLAMA);
      display.setCursor(0, 28);
      if (EDO_FLAMA == 0) display.println("Sin fuego");
      else {
        display.println("Cuidado, ");
        display.println("fuego");
      }
      display.display();
      break;
    case 2:
      SEL_MENU = 0;
      menu();
      break;
  }
}

void testBoton() {
  switch (SEL_MENU) {
    case 0:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(42, 10);
      display.println("UNIT");
      display.setTextSize(1);
      display.setCursor(35, 25);
      display.println("Electronics");
      display.setTextSize(2);
      display.setCursor(2, 35);
      display.println("Test Boton");
      display.display();
      break;
    case 1:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(5, 10);
      display.print("Boton: ");
      display.println(EDO_ACT_B);
      display.display();
      break;
    case 2:
      SEL_MENU = 0;
      menu();
      break;
  }
}
void testPIR() {
  switch (SEL_MENU) {
    case 0:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(42, 10);
      display.println("UNIT");
      display.setTextSize(1);
      display.setCursor(35, 25);
      display.println("Electronics");
      display.setTextSize(2);
      display.setCursor(2, 35);
      display.println("Test PIR");
      display.display();
      break;
    case 1:
      processPIR();
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(5, 10);
      display.print("PIR: ");
      display.println(EDO_PIR);
      display.setCursor(5, 18);
      display.display();
      break;
    case 2:
      SEL_MENU = 0;
      menu();
      break;
  }
}

void processPIR() {
  // Verificar si se detectó movimiento
  if (valPIR == HIGH) {
    if (pirState == LOW) {
      // Se acaba de detectar movimiento
      pirState = HIGH;
      EDO_PIR = 1;
    }
  } else {
    if (pirState == HIGH) {
      // El movimiento ha cesado
      pirState = LOW;
      EDO_PIR = 0;
    }

    // Mensaje periódico de "Listo" cada 5 segundos
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
    }
  }

  // Pequeña pausa para evitar fluctuaciones
  delay(100);
}


void readRFID() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    uidString = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      uidString += String(mfrc522.uid.uidByte[i], HEX);
    }

    uidString.toUpperCase();
    if (RFIDstate == 1 ){
      if (uidString != lastUID) {
        uidHandled = false;
        lastUID = uidString;
      }
      if (!uidHandled) {
        if (uidString == acceptedRFID_1 && EDO_PUERTA != 1) {
          pwm.writeMicroseconds(0, 800);
          mensajeOffline = uidString;
          EDO_PUERTA = 1;
          delay(200);
        } else if (uidString != acceptedRFID_1 && uidString != acceptedRFID_2 && uidString != "") {
            int indice = random(0,5);
            mensajeOffline = RFmessage[indice];
        }

        uidHandled = true; // Evita repetir hasta que entre una nueva tarjeta
      }
    }
    

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }
}


void processIR() {
  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.protocol == UNKNOWN && IrReceiver.decodedIRData.decodedRawData == 0xFFFFFFFF) {
      Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));

    } else {
      if (IrReceiver.decodedIRData.command == 0x45) {  //Numero 1    IRMode 1:Test   2:offline   3:online
        if (IRmode == 1) IR_value = "1";               //LCD PRINT 1
        else if (IRmode == 2) {                        //Abrir puerta
        }
      } else if (IrReceiver.decodedIRData.command == 0x46) {  //Numero 2
        if (IRmode == 1) IR_value = "2";                      //LCD PRINT 2
        else if (IRmode == 2) {                               //Cerrar puerta

        }
      } else if (IrReceiver.decodedIRData.command == 0x47) {  //Numero 3
        if (IRmode == 1) IR_value = "3";                      //LCD PRINT 3
        else if (IRmode == 2) {                               //Encender ventilador

        }
      } else if (IrReceiver.decodedIRData.command == 0x44) {  //Numero 4
        if (IRmode == 1) IR_value = "4";                      //LCD PRINT 4
        else if (IRmode == 2) {                               //Apagar ventilador

        }
      } else if (IrReceiver.decodedIRData.command == 0x40) {  //Numero 5
        if (IRmode == 1) IR_value = "5";                      //LCD PRINT 5
        else if (IRmode == 2) {                               //Cancion 1
        }
      } else if (IrReceiver.decodedIRData.command == 0x43) {  //Numero 6
        if (IRmode == 1) IR_value = "6";                      //LCD PRINT 6
        else if (IRmode == 2) {                               //Cancion 2
        }
      } else if (IrReceiver.decodedIRData.command == 0x7) {  //Numero 7
        if (IRmode == 1) IR_value = "7";                     //LCD PRINT 7
        else if (IRmode == 2) {                              //OFF/ON LED1
        }
      } else if (IrReceiver.decodedIRData.command == 0x15) {  //Numero 8
        if (IRmode == 1) IR_value = "8";                      //LCD PRINT 8
        else if (IRmode == 2) {                               //OFF/ON LED 2
        }
      } else if (IrReceiver.decodedIRData.command == 0x9) {  //Numero 9
        if (IRmode == 1) IR_value = "9";                     //LCD PRINT 9
        else if (IRmode == 2) {                              //OFF/ON LED3
        }
      } else if (IrReceiver.decodedIRData.command == 0x19) {  //Numero 0
        if (IRmode == 1) IR_value = "0";                      //LCD PRINT 0
        else if (IRmode == 2) {
        }
      } else if (IrReceiver.decodedIRData.command == 0x16) {  //Boton *
        if (IRmode == 1) {                                    //LCD PRINT *
        } else if (IRmode == 2) {
        }
      } else if (IrReceiver.decodedIRData.command == 0xD) {  //Boton #
        if (IRmode == 1) {                                   //LCD PRINT #
        } else if (IRmode == 2) {
        }
      } else if (IrReceiver.decodedIRData.command == 0x18) {  //Flecha Arriba
        if (IRmode == 1) {                                    //LCD PRINT 1
        } else if (IRmode == 0) {
          cuenta = cuenta + 4;
        } else if (IRmode == 2) {
        }
      } else if (IrReceiver.decodedIRData.command == 0x52) {  //Flecha Abajo
        if (IRmode == 1) {                                    //LCD PRINT 1
        } else if (IRmode == 0) {
          cuenta = cuenta - 4;
        } else if (IRmode == 2) {
        }
      } else if (IrReceiver.decodedIRData.command == 0x1C) {  //Boton Ok
        if (IRmode == 1) {                                    //LCD PRINT OK
          if (SEL_MENU == 2) SEL_MENU = 0;
          else{ SEL_MENU++; }
        } else if (IRmode == 2) {
        }
      } else if (IrReceiver.decodedIRData.command == 0x8) {  //Flecha izquierda
        if (IRmode == 1) {                                   //LCD PRINT IZQUEIRDA
        } else if (IRmode == 2) {
        }
      } else if (IrReceiver.decodedIRData.command == 0x5A) {  //Flecha derecha
        if (IRmode == 1) {                                    //LCD PRINT DERECHA
        } else if (IRmode == 2) {
        }
      }
      IrReceiver.resume();  // Early enable receiving of the next IR frame
      //IrReceiver.printIRResultShort(&Serial);
      delay(50);
    }
  }
}
 

bool processData(String data) {
  const char* json = data.c_str();
  DeserializationError error = deserializeJson(docData, json);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return false;
  } else {
    sensor = docData["sensor"];
    num = docData["numero"];
    val = docData["valor"];
    r = docData["data"][0];
    g = docData["data"][1];
    b = docData["data"][2];
    if(String(sensor) == "motor"){
      if(val==1){
          pwm.writeMicroseconds(1, 2400);
          pwm.writeMicroseconds(2, 600);
        }
        else{
          pwm.writeMicroseconds(1, 600);
          pwm.writeMicroseconds(2, 600);
        }
    } else if (String(sensor) == "servo") {
      if(val==1){
          pwm.writeMicroseconds(0, 800);
        }
        else{
          pwm.writeMicroseconds(0, 1500);
        }
    } else if(String(sensor) == "buzzer"){
      if(num==1){
          playJingleBells();
        }
        else{
          playOther();
        }
    } else if (String(sensor) == "led"){

      processNeoPixel(num,val,r,g,b);
    }

    return true;
  }
}

void playJingleBells() {
 int tempo = 120; // Ajusta este valor para cambiar la velocidad (mayor = más lento)
  
  int size = sizeof(melody1) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {
    // Calcular la duración de la nota
    // 4 = negra, 8 = corchea, etc.
    int noteDuration = (60000 * 4) / (tempo * noteDurations1[thisNote]);
    
    if (melody1[thisNote] != REST) {
      tone(PIN_BUZZER, melody1[thisNote], noteDuration * 0.9);
    }
    
    // Pausa entre notas (incluyendo silencios)
    delay(noteDuration);
    
    // Pequeña pausa adicional para separar las notas
    noTone(PIN_BUZZER);
    delay(noteDuration * 0.1);
  }
}

void playOther() {
  int tempo = 160; // Ajusta este valor para cambiar la velocidad (mayor = más lento)
  
  int size = sizeof(melody5) / sizeof(int);
  //for (int thisNote = 0; thisNote < size; thisNote++) {
  for (int thisNote = 0; thisNote < sizeof(melody5); thisNote++) {
    // Calcular la duración de la nota
    // 4 = negra, 8 = corchea, etc.
    int noteDuration = (60000 * 4) / (tempo * noteDurations5[thisNote]);
    
    if (melody5[thisNote] != REST) {
      tone(PIN_BUZZER, melody5[thisNote], noteDuration * 0.9);
    }
    
    // Pausa entre notas (incluyendo silencios)
    delay(noteDuration);
    
    // Pequeña pausa adicional para separar las notas
    noTone(PIN_BUZZER);
    delay(noteDuration * 0.1);
  }
}

void playDingDong() {
  // Iterar sobre las notas de la melodía:
  int size = sizeof(melody4) / sizeof(int);
  for (int thisNote = 0; thisNote < size; thisNote++) {
    // Calcular la duración de la nota
    int noteDuration = 1000 / noteDurations4[thisNote];
    tone(PIN_BUZZER, melody4[thisNote], noteDuration);

    // Para distinguir las notas, establecer un tiempo mínimo entre ellas
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    // Detener el tono
    noTone(PIN_BUZZER);
  }
}

bool processFlag(String data) {
  const char* json = data.c_str();
  DeserializationError error = deserializeJson(docIP, json);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return false;
  } else {
    IP = docIP["IP"];
    connection = int(docIP["val"]);
    return true;
  }
}

uint16_t calcularCRC(const String& data) {
  uint16_t crc = 0xFFFF;
  for (char c : data) {
    crc ^= (uint8_t)c;
    for (int i = 0; i < 8; i++) {
      if (crc & 1)
        crc = (crc >> 1) ^ 0xA001;
      else
        crc >>= 1;
    }
  }
  return crc;
}

void processNeoPixel(int ledNum, int state, int r, int g, int b){
  if(state == 1){
    NeoPixel.setPixelColor(ledNum -1 , NeoPixel.Color(r, g, b));
  }
  else if (state != 1 ){
    NeoPixel.setPixelColor(ledNum -1 , NeoPixel.Color(0, 0, 0));
  }
  NeoPixel.show();

}