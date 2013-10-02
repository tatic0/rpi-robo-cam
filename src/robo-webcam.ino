#include <Servo.h> 

int posS1 = 90;         // variable to store the servo position
int posS2 = 90;         // variable to store the servo position
int posS1i = 90;        // servo 1 initial position
int posS2i = 90;        // servo 2 initial position
int incomingByte = 0;  // for incoming serial data
int currentPosS1;      //current position servo 1
int currentPosS2;      //current position servo 2

Servo servo1;  // create servo object to control a servo. A maximum of eight servo objects can be created 
Servo servo2;  // create servo object to control a servo. A maximum of eight servo objects can be created 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Arduino code starting");

  servo1.attach(9);  // attaches the servo on pin 9 to the servo object 
  servo1.write(posS1i); //set the servo position to 0 degrees

  servo2.attach(10);  // attaches the servo on pin 9 to the servo object 
  servo2.write(posS2i); //set the servo position to 0 degrees

  /* ascii codes for the keys to de used:
  == servos ==
   a = 97
   d = 100
   s = 115
   w = 119
   x = 120
  */
}

void loop() {
  // put your loop code here, to be repeated over and over and over
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);

  switch(incomingByte){
/*
  S E R V O S
*/

    case 97: 
      if(posS1 > 180){
        posS1=170;
      }
      posS1 += 10; 
      servo1.write(posS1);
      currentPosS1 = servo1.read();
      Serial.print("S1 Current position: ");
      Serial.println(currentPosS1);
      break;
    case 100:
      if(posS1 < 0){
        posS1=10;
      }
      posS1 -= 10; 
      servo1.write(posS1);
      currentPosS1 = servo1.read();
      Serial.print("S1 Current position: ");
      Serial.println(currentPosS1);
      break;
    case 115: 
      if(posS2 > 180){
        posS2=170;
      }
      posS2 += 10; 
      servo2.write(posS2);
      currentPosS2 = servo2.read();
      Serial.print("S2 Current position: ");
      Serial.println(currentPosS2);
      break;
    case 119:
      if(posS2 < 0){
        posS2=10;
      }
      posS2 -= 10; 
      servo2.write(posS2);
      currentPosS2 = servo2.read();
      Serial.print("S2 Current position: ");
      Serial.println(currentPosS2);
      break;
    case 120: // x 
      Serial.println("Reset servo to default position");
      servo1.write(posS1i);
      servo2.write(posS2i);
      posS1 = 90;
      posS2 = 90;
      break;
    default:
      incomingByte = 0;
    }
  Serial.print("S1 Current position requested: ");
  Serial.println(posS1);
  Serial.print("S2 Current position requested: ");
  Serial.println(posS2);
  incomingByte = 0;
  }  
}
