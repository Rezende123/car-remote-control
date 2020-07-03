 // ############# LIBRARIES ############### //

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// ############# VARIABLES ############### //

const char* SSID = "eu"; // rede wifi
const char* PASSWORD = "eueueueu"; // senha da rede wifi

String BASE_URL = "http://192.168.43.235:8080/command";

// ############# PROTOTYPES ############### //

void initSerial();
void initWiFi();
void httpRequest(String path);

// ############### OBJECTS ################# //

WiFiClient client;
HTTPClient http;

// ############## SETUP ################# //

void setup() {
  initSerial();
  initWiFi();
}

void loop() {

  String response = getCommand();

  Serial.println("##[RESULT]## ==> " + response);
  
}

// ############# HTTP REQUEST ################ //

String getCommand()
{
  http.begin(BASE_URL);
  http.addHeader("content-type", "application/x-www-form-urlencoded");
  
  String response = "";
  int httpCode = http.GET();                                                               //Send the request
   
  if (httpCode > 0) { //Check the returning code
   
    response = http.getString();   //Get the request response payload
    
  }          
          
  http.end();
  return response;
}

// implementacao dos prototypes

void initSerial() {
  Serial.begin(115200);
  while (!Serial);
}

void initWiFi() {
  delay(10);
  Serial.println("Conectando-se em: " + String(SSID));

  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Conectado na Rede " + String(SSID) + " | IP => ");
  Serial.println(WiFi.localIP());
}
