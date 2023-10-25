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
const uint8_t rs = 6, en = 7, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int 
  wt,
  servoOpen  = 90,
  servoClose = 0;

HX711 scale;
//              Servo/potentiometer Vars
Servo myServo;  // create servo object to control a servo

const int servoPin = 12;
int start = 400;
int end = 800;

uint8_t potPin = A0;  // analog pin used to connect the potentiometer
uint8_t buttonPin = 3;
uint32_t val;    // variable to read the value from the analog pin
int setWt;


//declare scale vars
const uint8_t dataLC = 5;
const uint8_t clockLC = 4;
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


void setup() {
    //fill bowl vars
    const int constantFill = 10;//max wight of the seral depended in LBS
    int 
        weight,//active weight of bowl (in LBS)
        servo_rotation,//angle of servo in DEG
        bowlWeight; // wight of bowl pre dispense in LBS

    //servo,potentiometer setup
    myServo.attach(servoPin);  // attaches the servo on pin 9 to the servo object

    myServo.write(servoOpen); 
    delay(500);
    myServo.write(servoClose); 
    pinMode(buttonPin, INPUT);

    //LCD display setup
    lcd.begin(16, 2);
    lcdStartCode();

    //scale inputs
    scale.begin(dataLC, clockLC);
    scale.set_offset(31190);
    scale.set_scale(441.780517);
    scale.tare();

    //table code and vars

    //setup serial
    Serial.begin(9600);
    

}

void loop() {
    //get weight of item
    //wt = getWt();/*

    //set WT
    setWt = lcdStartLines();
    //if the button is pressed run the program
    if (digitalRead(buttonPin) == LOW){
      delay(500);
      fillUpCereal();
    }//*/
}






//get the weight of the bowl and convert it into a number
int getWt(){
  
  Wt = scale.get_units(5);
  
  delay(250); // add a bit of delay so it cna process the numbers
    

  //print to servo
  lcd.setCursor(0, 1);
  lcd.print("                    ");
  lcd.setCursor(0, 1);
  lcd.print(Wt);
  //Serial.println(Wt);*/
  //weight in lbs
}




//  -- END OF FILE --

