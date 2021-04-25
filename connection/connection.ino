#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>

#define SERVO_PORT 11

const char* SSID = "eu"; // rede wifi
const char* PASSWORD = "eueueueu"; // senha da rede wifi

String HOST = "https://remote-control-car-server.herokuapp.com";
String URL = "https://remote-control-car-server.herokuapp.com/command";
const int httpPort = 443;

void initWiFi();

WiFiClientSecure client;
HTTPClient http;
JSONVar command;

void setup() {
  Serial.begin(9600);
  initWiFi();
}

void loop() {

  String response = getCommand();
  if (response == "") {
    Serial.println("0|0");
  } else {
    command = JSON.parse(response);
    Serial.print(command["velocity"]);
    Serial.print("|");
    Serial.println(command["direction"]);    
  }
  delay(100);

}
