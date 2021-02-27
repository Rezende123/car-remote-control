#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>

#define SERVO_PORT 11

const char* SSID = "eu"; // rede wifi
const char* PASSWORD = "eueueueu"; // senha da rede wifi
String BASE_URL = "http://192.168.43.235:8080/command";

void initWiFi();

WiFiClient client;
HTTPClient http;

void setup() {
  Serial.begin(9600);
  initWiFi();
}

void loop() {

  String response = getCommand();
  Serial.println(response);
  delay(100);

}
