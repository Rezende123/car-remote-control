void initSerial() {
  Serial.begin(9600);
  while (!Serial);
  
  servoDirection.attach(SERVO_PORT);

  pinMode(MOTOR_FORWARD_PORT, OUTPUT);
  pinMode(MOTOR_BACKWARD_PORT, OUTPUT);
}
