
/********************************************/
/* 04/08/2021                               */
/* Pedro Ontiveros                          */
/* ontiveros.pedro@gmail.com                */
/*                                          */
/* This is a free software with NO WARRANTY */
/********************************************/

const int analogPin = A0;
const int   ledSize = 9;
const int ledPins[] = {2,3,4,5,6,7,8,9,10};
int f1 = 1;

void setup() {
  for (int index = 0; index < ledSize; index++) {
    pinMode(ledPins[index], OUTPUT);     
  }
}

void loop() {
  int   sensor = analogRead(analogPin);
  int ledLevel = map(sensor, 0, 1023, 0, ledSize);

  if (f1 == 1) {
    goForward(1, (ledLevel*10));
    goForward(0, (ledLevel*10));
  } else {
    goBackward(1, (ledLevel*10));
    goBackward(0, (ledLevel*10));
  }

  f1 = (f1 == 1) ? 0 : 1;
  
  delay(ledLevel);
}

void goForward(int flag, int pause) {
  for (int index = 0; index < ledSize; index++) {
      digitalWrite(ledPins[index], (flag == 1) ? HIGH : LOW);
      delay(pause);
    }
}

void goBackward(int flag, int pause) {
  for (int index = (ledSize - 1); index >= 0; index--) {
      digitalWrite(ledPins[index], (flag == 1) ? HIGH : LOW);
      delay(pause);
    }  
}
