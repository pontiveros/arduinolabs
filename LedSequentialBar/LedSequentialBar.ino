
/**********************************/
/* 04/08/2021                     */
/* Pedro Ontiveros                */
/* pontiveros.developer@gmail.com */
/*                                */
/**********************************/

const int analogPin = A0;
const int   ledSize = 9;
const int ledPins[] = {2,3,4,5,6,7,8,9,10};
int flag = 0;

void setup() {
  for (int index = 0; index < ledSize; index++) {
    pinMode(ledPins[index], OUTPUT);     
  }
}

void loop() {
  int   sensor = analogRead(analogPin);
  int ledLevel = map(sensor, 0, 1023, 0, ledSize);

  for (int index = 0; index < ledSize; index++) {
    digitalWrite(ledPins[index], (flag == 0) ? LOW : HIGH);
    delay(ledLevel*10);
  }

  flag = !flag;
  
  delay(ledLevel);
}
