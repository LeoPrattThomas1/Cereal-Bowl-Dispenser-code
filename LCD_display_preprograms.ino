void fillUpCereal(){
  int wtOffset;
  int i = 1;
  int wt;

  lcdFillingSet(setWt);//set up the program
  wtOffset = analogRead(potPin);

  //add a delay between the start so button can be unpressed for the exit

  //open servo
  myServo.write(servoOpen); 

  while(setWt > wt) {


    //get wt of pin (THIS WILL BE CHANGED)
    wt = analogRead(potPin);
    wt = wt - wtOffset;

    //add wt to LCD display
    lcdFilling(wt);

    //add load bar
    if ((setWt*i/(16-offsetLoad)) < wt) {
      setLCD(i+offsetLoad);
      i++;
    }
    //add a exit, delay so no overlap on loops
    if (digitalRead(buttonPin) == LOW){ delay(500); break; }
  }
  //open servo
  myServo.write(servoClose); 

  //reset the screen when were done
  lcdStartCode();
}
/*=============================
           LCD SHIT
==============================*/


//START DISPLAY 

//start start LCD display code
void lcdStartCode(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press To Start");
  lcd.setCursor(0, 1);
  lcd.print("Fill To: ");
}

//update wt set 
int lcdStartLines(){
  int setWeight;
  lcd.setCursor(9, 1);
  setWeight = analogRead(potPin);
  lcd.print(setWeight);
  lcd.print("g");
  
  //add some delay so it doenst look like a stroke
  delay(50);

  return setWeight;
}


//FILL DISPLAY

//set up load display
void lcdFillingSet(int setWT){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Weight <- ");
  lcd.print(setWT);
}

//fill wt set
void lcdFilling(int WT){
  //clear board
  lcd.setCursor(0, 1);
  lcd.print("        ");
  
  //set wt and g
  lcd.setCursor(0, 1);
  lcd.print(WT);
  lcd.print("g");

  //add some delay so it doenst look like a stroke
  delay(50);
}


//Fill bar in filling screen
void setLCD(int loadCell){
  
  Serial.println(loadCell);
  lcd.createChar(0, load);

  lcd.setCursor(loadCell, 1);
  lcd.write(byte(0));
  //lcd.print("F");
}

