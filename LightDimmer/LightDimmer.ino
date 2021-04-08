
/**********************************/
/* Pedro Ontiveros                */
/* pontiveros.developer@gmail.com */
/**********************************/

/* Variables */

int potPin = A0;  // Analog imput pint connected to potentiometer
int potValue = 0; // Value to be read from potentiometer
int led = 9;      // Led output

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);
  analogWrite(led, potValue/4);
  delay(10);
}
