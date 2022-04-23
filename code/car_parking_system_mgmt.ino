
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 10, d4 = 6, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  


#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
// twelve servo objects can be created on most boards

//int pos = 0;    // variable to store the servo position

int ct=0,tot=5;

void setup() {
  myservo1.attach(9);// attaches the servo on pin 9 to the servo object
  myservo2.attach(11);
  pinMode(8,INPUT);
  pinMode(7,INPUT);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);

   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("avail space:");
  lcd.print(tot-ct);
  lcd.setCursor(0,1);
  lcd.print("total space:");
  lcd.print(tot);
}

void loop() {

  
  if((digitalRead(7)==HIGH) && (ct<5)){
    myservo2.write(90);             
    delay(3000);
    myservo2.write(0);
    ct++;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("avail space:");
    lcd.print(tot-ct);
    lcd.setCursor(0,1);
    lcd.print("total space:");
    lcd.print(tot);
    
  }

  if((digitalRead(7)==HIGH) && (ct>=5)){
    myservo2.write(0);
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("sorry!!");
    lcd.setCursor(0,1);
    lcd.print("parking full");
  }

  if(digitalRead(7)==LOW){
    myservo2.write(0);
  }
    


  if((digitalRead(8)==HIGH) && (ct>0)){
    
      myservo1.write(90);             
      delay(2000);
      myservo1.write(0);
      ct--;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("avail space:");
      lcd.print(tot-ct);
      lcd.setCursor(0,1);
      lcd.print("total space:");
      lcd.print(tot);
    
  }

   if((digitalRead(8)==LOW) && (ct<0)){
      myservo1.write(0);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("sorry!!");
      lcd.setCursor(0,1);
      lcd.print("CAN'T EXIT");
   }

   if(digitalRead(8)==LOW){
      myservo1.write(0);
   }      

  
}
