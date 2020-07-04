void initSerial() {
  Serial.begin(115200);
  while (!Serial);
  
  servoDirection.attach(SERVO_PORT);

  pinMode(MOTOR_FORWARD_PORT, OUTPUT);
  pinMode(MOTOR_BACKWARD_PORT, OUTPUT);
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
