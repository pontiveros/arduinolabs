/********************************************/
/* 02/28/2025                               */
/* Pedro Ontiveros                          */
/* ontiveros.pedro@gmail.com                */
/*                                          */
/* This is a free software with NO WARRANTY */
/********************************************/
#include <Servo.h>

Servo myServo;
int pos = 0;

void setup() {
  myServo.attach(9); // Ataches servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }

  for (pos = 90; pos >= 0; pos--) { // goes from 180 degrees to 0 degrees
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
}
