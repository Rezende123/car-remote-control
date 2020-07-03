#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>

const char* SSID = "eu"; // rede wifi
const char* PASSWORD = "eueueueu"; // senha da rede wifi

String BASE_URL = "http://192.168.43.235:8080/command";

JSONVar command; // Fields: ['velocity', 'direction']

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

//  Serial.println("##[RESULT]## ==> " + response);

  if (response != "") {
     command = JSON.parse(response);

//     Serial.print("{ velocity: " + ((int) command["velocity"]) + ", direction" + ((int) command["direction"]) );
     Serial.print("{ velocity: ");
     Serial.print((int) command["velocity"]);
     Serial.print(", direction: ");
     Serial.print((int) command["direction"]);
     Serial.println(" }");
  }
}
