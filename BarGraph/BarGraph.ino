
/********************************************/
/* 04/07/2021                               */
/* Pedro Ontiveros                          */
/* ontiveros.pedro@gmail.com                */
/*                                          */
/* This is a free software with NO WARRANTY */
/********************************************/

const int analogPin = A0;
const int   ledSize = 9;
const int ledPins[] = {2,3,4,5,6,7,8,9,10};

void setup() {
  for (int index = 0; index < ledSize; index++) {
    pinMode(ledPins[index], OUTPUT);     
  }
}

void loop() {
  int   sensor = analogRead(analogPin);
  int ledLevel = map(sensor, 0, 1023, 0, ledSize);

  for (int index = 0; index < ledSize; index++) {
    (index < ledLevel) ? digitalWrite(ledPins[index],HIGH) : digitalWrite(ledPins[index],LOW);
  }
}
