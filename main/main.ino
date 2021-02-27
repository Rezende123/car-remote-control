#include <Arduino_JSON.h>
#include <Servo.h>

#define SERVO_PORT 11
#define MOTOR_FORWARD_PORT 10
#define MOTOR_BACKWARD_PORT 9

void initSerial();
void setDirection(int direction);
void setVelocity(int velocity);

JSONVar command; // Fields: ['velocity', 'direction']
Servo servoDirection;

void setup() {
  initSerial();
}

void loop() {

  String response = readStringSerial();

  // Serial.println("##[RESULT]## ==> " + response);

  if (response != "") {
     command = JSON.parse(response);

//     Serial.print("{ velocity: " + ((int) command["velocity"]) + ", direction" + ((int) command["direction"]) );
     Serial.print("{ velocity: ");
     Serial.print((int) command["velocity"]);
     Serial.print(", direction: ");
     Serial.print((int) command["direction"]);
     Serial.println(" }");

    //  setDirection( command["direction"] );
    //  setVelocity( command["velocity"] );
  }
}
