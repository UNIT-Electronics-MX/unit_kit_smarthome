//https://randomnerdtutorials.com/arduino-ide-2-install-esp32-littlefs/
#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include "LittleFS.h"
#include <ArduinoJson.h>

#include <mutex>
// Pines Serial
#define TX_PIN 17
#define RX_PIN 16


volatile bool wifiConnected = false;
volatile bool newSerialData = false;
volatile int sendRP = 0;
std::mutex mtx;

// Variables WiFi
String ssid;
String pass;
const char* ssidPath = "/ssid.txt";
const char* passPath = "/pass.txt";
volatile int connection = 0;
volatile int lastconnection = 0;

// Variables de sensores
float Temperature = 0;
float Humidity = 0;
int SoilHumidity = 0;
int Light = 0;
int Flame = 0;
int Rainwater = 0;
const char* doorState = "";
int PIRState = 0;
const char* IRval = "";
int BTNstate = 0;

float lastTemperature = 0;
float lastHumidity = 0;
int lastSoilHumidity = 0;
int lastLight = 0;
int lastFlame = 0;
int lastRainwater = 0;
const char* lastdoorState = "";
int lastPIRState = 0;
const char* lastIRval = "";
int lastBTNstate = 0;

JsonDocument docSens;
JsonDocument docLed;
JsonDocument docRP;
JsonDocument docFlag;
JsonDocument docFlag2;
JsonDocument doc;

int OnlineState = 0;

 const char* sensor = "";
 int num = 0;
 int val = 0;
int r = 0;
int g = 0;
int b = 0;

const char* lastsensor = "";
int lastnum =0;
int lastval = 0;
int lastr = 0;
int lastg = 0;
int lastb = 0;


// Configuración WiFi
AsyncWebServer server(80);
WiFiServer tcpServer(80);
std::vector<String> availableNetworks;