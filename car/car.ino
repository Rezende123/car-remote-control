#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* SSID = "eu"; // rede wifi
const char* PASSWORD = "eueueueu"; // senha da rede wifi

String BASE_URL = "http://192.168.43.235:8080/command";

void initSerial();
void initWiFi();
String getCommand();

WiFiClient client;
HTTPClient http;

void setup() {
  initSerial();
  initWiFi();
}

void loop() {

  String response = getCommand();

  Serial.println("##[RESULT]## ==> " + response);
  
}
