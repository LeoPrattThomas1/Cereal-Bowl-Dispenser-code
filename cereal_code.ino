/*
MIT License

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
SOFTWARE.
*/

// include the library code:
#include <LiquidCrystal.h>
#include <Servo.h>


//              LCD VARS
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


//              Servo/potentiometer Vars
Servo myServo;  // create servo object to control a servo

int potPin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
    //fill bowl vars
    const int constantFill = 10;//max wight of the seral depended in LBS
    int 
        weight,//active weght of bowl (in LBS)
        servo_rotation,//angle of servo in DEG
        bowlWeight; // wight of bowl pre dispense in LBS

    //servo,potentiometer setup
    myServo.attach(9);  // attaches the servo on pin 9 to the servo object

    //LCD display setup
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Weight LBS");

    //scale inputs and vars

    //table code and vars

}

//get the weight of the bowl and convert it into a number

int getWeight(){
    lcd.print(0.1);
    
    //read scale
    //calibrate amount to 
    return; //weight in lbs
}

void loop() {
    //   set LCD
    //get weight of item

    //   open bowl
    //→ if Bowl 
    //weight a second to get real wight of bowl
    //→ servo open (6) 
    //→ Wait till [constant_fill]  (while weight != constant_fill)
    //→ servo close (6)
}