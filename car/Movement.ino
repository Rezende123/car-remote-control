void setDirection(int direction) {
    servoDirection.write(direction);
}

void setVelocity(int velocity) {
    bool isBackward = (velocity < 0);
    
    if (isBackward) {
      velocity *= -1;
    }
  
    int motorPotence = map(velocity, 0, 50, 0, 255);

    if (isBackward) {
      analogWrite(MOTOR_BACKWARD_PORT, motorPotence);
    } else {
      analogWrite(MOTOR_FORWARD_PORT, motorPotence);
    }
}
