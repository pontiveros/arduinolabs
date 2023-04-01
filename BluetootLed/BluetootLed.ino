
const int LED = 5;
char switchstate;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  while(Serial.available()>0) {
    //code to be  executed only when Serial.available()>0
    /*Serial.available>0 is to check if  there is any reading from the 
    HC-05 Bluetooth module.*/ 
    switchstate = Serial.read();
    
    /*The  character we had declared earlier is now being assigned a value-
    the value of  whatever Serial.read() is.*/
    //Serial.read() is to read the value coming from  app.
    Serial.print(switchstate);
    
    //This will print the value onto the Serial  monitor.
    Serial.print("\n");
    
    //This moves to the next line after every new line printed.
    delay(15);
    
    /*Gives a break of 15 milliseconds. Delay is  for human eye, and for
    speed of some computers, as some will crash at high speeds.*/
    if(switchstate  == '1'){//Checking if the value from app is '1'
      digitalWrite(5, HIGH);
      //If  it is, write the component on pin 5(LED) high. 
    } else if(switchstate == '0') { //Else,  if the vaue from app is '0',
      digitalWrite(5, LOW);//Write the component on pin  5(LED) low.
    }
  }
}
