/********************************************/
/* 10/12/2025                               */
/* Pedro Ontiveros                          */
/* ontiveros.pedro@gmail.com                */
/*                                          */
/* This is a free software with NO WARRANTY */
/********************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVO_0   0
#define SERVO_1   1
#define SERVO_2   2
#define SERVO_3   3
#define SERVO_4   4
#define SERVO_5   5
#define SERVO_15  15

#define SERVO_MIN 150
#define SERVO_MAX 600
#define DELAY     500
#define STEP      80

#define ANGLE_0   0
#define ANGLE_90  90
#define ANGLE_180 180
#define PULSE_0   20
#define PULSE_180 470

Adafruit_PWMServoDriver servo = Adafruit_PWMServoDriver(0x40);

void setup() {
  Serial.begin(9600);
  Serial.println("Start servo tests...");
  servo.begin();
  servo.setOscillatorFrequency(27000000);
  servo.setPWMFreq(60);

  yield();

  setInitialPosition(SERVO_0);
  setInitialPosition(SERVO_1);
  setInitialPosition(SERVO_2);
  setInitialPosition(SERVO_15);

  delay(5000);
}

void loop() {

  Serial.println("start move");
  
  testInitServo(SERVO_0, 0, 180);
  testInitServo(SERVO_1, 40, 140);
  testInitServo(SERVO_2, 40, 140);
  testInitServo(SERVO_15, 65, 135);

  Serial.println("end mode");
}

void testServo(uint8_t nServo, int direction) {
  switch (nServo) {
    case SERVO_0: 
    break;
    case SERVO_1:
    break;
    case SERVO_3: 
    break;
    case SERVO_4:
    break;
    case SERVO_5: 
    break;
    default: 
      Serial.println("######## ERROR SERVO NUMBER #########");
  }
}

void setInitialPosition(int nServo) {
  // Initial position, logic pos 0, servo pos 90
  setServo(nServo, ANGLE_90);
  delay(DELAY);
}

void testInitServo(int nServo, int startPos, int endPos) {

  setInitialPosition(nServo);

  for (int i = ANGLE_90; i < endPos; i++) {
    setServo(nServo, i);
    delay(STEP); 
  }

  setInitialPosition(nServo);

  for (int i = ANGLE_90; i > startPos; i--) {
    setServo(nServo, i);
    delay(STEP);
  }

  setInitialPosition(nServo);
}

void test_servo_0(int nServo) {
  
  setServo(nServo, ANGLE_90); // initial position
  delay(DELAY);

  for (int i = ANGLE_90; i < ANGLE_180; i++) {  // Move from center to left
    setServo(nServo, i);
    delay(STEP);
  }

  delay(DELAY);
  setServo(nServo, ANGLE_90);

  for (int i = ANGLE_90; i >= ANGLE_0; i--) {
    setServo(nServo, i);
    delay(STEP);
  }

  delay(DELAY);
  setServo(nServo, ANGLE_90);
}

void setServo(uint8_t nServo, int angle ) {
  int duty;

  duty = map(angle, ANGLE_0, ANGLE_180, PULSE_0, PULSE_180);

  servo.setPWM(nServo, 0, duty);
}
