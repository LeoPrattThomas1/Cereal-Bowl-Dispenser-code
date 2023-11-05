/*MIT License

Copyright (c) 2023 Leo Pratt-Thomas
 
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

// include the library code:
#include <LiquidCrystal.h>
#include "HX711.h"
#include <Servo.h>


//              LCD VARS
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const uint8_t rs = 6, en = 7, d4 = 8, d5 = 9, d6 = 10, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
uint16_t 
  wt,
  //servo stuff
  servoOpen  = 45,
  servoClose = 0,
  //calibrate load stuff
  calibrationAccuracy = 20,
  calibrateDivideBy = 2;

Servo myServo1; 
Servo myServo2;
HX711 scale;
//              Servo/potentiometer Vars
 // create servo object to control a servo

const uint8_t servo1Pin = 3;
const uint8_t servo2Pin = 11;
const uint8_t potPin = A5;  // analog pin used to connect the potentiometer
const uint8_t buttonPin = 2;
const uint8_t 
  dataPin = 4,
  clockPin = 5;


uint32_t val;    // variable to read the value from the analog pin
int setWt;


//declare scale vars

volatile float Wt;


void lcdStartCode();
int lcdStartLines();
void lcdFillingSet(int setWT);
void lcdFilling(int WT);
void setLCD(int loadCell);

const uint8_t offsetLoad = 8; 

uint8_t load[8] = {
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111,
	0b11111
};


void setup() 
{
    //fill bowl vars
    const int constantFill = 10;//max wight of the seral depended in LBS
    int 
        weight,//active weight of bowl (in LBS)
        servo_rotation,//angle of servo in DEG
        bowlWeight; // wight of bowl pre dispense in LBS

    //servo,potentiometer setup
    myServo1.attach(servo1Pin); 
    myServo2.attach(servo2Pin);  // attaches the servo on pin 9 to the servo object

    //Set up Servo
    openServo();
    delay(500);
    openServo();//*/

    //Set up button
    pinMode(buttonPin, INPUT);

    //LCD display setup
    lcd.begin(16, 2);
    lcd.clear();
    lcdStartCode();

    //set up scale data
    scale.begin(dataPin, clockPin);
    scale.tare(); //Set Scale to 0 
    scale.set_scale(243.061996); //Calibration amount for scale
    //*/

    //serial display
    // Serial.begin(9600); //commented out Serial to icresse performance
}

void loop() 
{
    //set WT
    setWt = lcdStartLines();

    //If the button is pressed run the program
    if (digitalRead(buttonPin) == LOW){
      //delay so not button infiniate loop
      delay(500);
      fillUpCereal();//Fill up serial Algritam
    }
}



//despenceing cerial
void openServo(){
  myServo1.write(0);  //left
  myServo2.write(0); //right
}

//#not despencing cerial
void closeServo(){
  myServo1.write(25); //left
  myServo2.write(-25); //right
}

/*
{
  
  Wt = scale.read();
  Serial.println(Wt);
  delay(250);
  return Wt;
}*/



//  -- END OF FILE --

