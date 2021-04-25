#include <Servo.h>

#define SERVO_PORT 11
#define MOTOR_FORWARD_PORT 10
#define MOTOR_BACKWARD_PORT 9

void initSerial();
void setDirection(int direction);
void setVelocity(int velocity);

Servo servoDirection;

void setup() {
  initSerial();
}

void loop() {

  String response = readStringSerial();

  //Serial.println("##[RESULT]## ==> " + response);

  if (response != "") {
    String delimiter = "|";

    int pos = response.indexOf(delimiter);
    int velocity = response.substring(0, pos).toInt();
    int direction = response.substring(pos+1, response.length()).toInt();
    
    Serial.print("{ velocity: ");
    Serial.print(velocity);
    Serial.print(", direction: ");
    Serial.print(direction);
    Serial.println(" }");

    setDirection( direction );
    //setVelocity( velocity );

  }
}
