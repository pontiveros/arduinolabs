/********************************************/
/* 03/01/2025                               */
/* Pedro Ontiveros                          */
/* ontiveros.pedro@gmail.com                */
/*                                          */
/* This is a free software with NO WARRANTY */
/********************************************/

int pirPin = 2;
int ledPin = 8;

void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int pirState = digitalRead(pirPin);
  
  if (pirState == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion Detected!");
    delay(1000); 
  } else {
    digitalWrite(ledPin, LOW);
  }
}
