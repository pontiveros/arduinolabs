
/**********************************/
/* 05/06/2021                     */
/* Pedro Ontiveros                */
/* ontiveros.pedro@gmail.com      */
/*                                */
/**********************************/

#define ZERO  0x00111111
#define ONE   0x00000110
#define TWO   0x01011011
#define THREE 0x01001111
#define FOUR  0x01100110
#define FIVE  0x01101101
#define SIX   0x01111101
#define SEVEN 0x00000111
#define EIGHT 0x01111111
#define NINE  0x01101111

const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;
const int pot = A0;
unsigned long counter = 0;

void setup() {
  
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(pot, INPUT);
}

int getPause() {
  int sensor = analogRead(pot);
  return map(sensor, 0, 1023, 50, 1000);
}

void printNumber(unsigned long digit) {
  digitalWrite(a, (digit & 0x00000001) ? HIGH : LOW);
  digitalWrite(b, (digit & 0x00000010) ? HIGH : LOW);
  digitalWrite(c, (digit & 0x00000100) ? HIGH : LOW);
  digitalWrite(d, (digit & 0x00001000) ? HIGH : LOW);
  digitalWrite(e, (digit & 0x00010000) ? HIGH : LOW);
  digitalWrite(f, (digit & 0x00100000) ? HIGH : LOW);
  digitalWrite(g, (digit & 0x01000000) ? HIGH : LOW);
}

void printDigit(unsigned long digit) {
  switch (digit) {
    case 0: printNumber(ZERO);  break;
    case 1: printNumber(ONE);   break;
    case 2: printNumber(TWO);   break;
    case 3: printNumber(THREE); break;
    case 4: printNumber(FOUR);  break;
    case 5: printNumber(FIVE);  break;
    case 6: printNumber(SIX);   break;
    case 7: printNumber(SEVEN); break;
    case 8: printNumber(EIGHT); break;
    case 9: printNumber(NINE);  break;
  }
}

void loop() {
  printDigit(counter++);
  delay(getPause());
  if (counter > 9) {
    counter = 0;
  }
}
