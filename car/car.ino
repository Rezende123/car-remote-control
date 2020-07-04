#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>
#include <Servo.h>

const char* SSID = "eu"; // rede wifi
const char* PASSWORD = "eueueueu"; // senha da rede wifi
String BASE_URL = "http://192.168.43.235:8080/command";

const int SERVO_PORT = 11;
const int MOTOR_FORWARD_PORT = 10;
const int MOTOR_BACKWARD_PORT = 9; 

void initSerial();
void initWiFi();
String getCommand();
void setDirection(int direction);
void setVelocity(int velocity);

WiFiClient client;
HTTPClient http;

JSONVar command; // Fields: ['velocity', 'direction']
Servo servoDirection; 

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

     setDirection( command["direction"] );
     setVelocity( command["velocity"] );
  }
}
