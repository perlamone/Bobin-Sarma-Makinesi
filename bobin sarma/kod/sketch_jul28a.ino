
#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const byte ROWS = 4;
const byte COLS = 3;
char key;


char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {10, 9, 8, 7};
byte colPins[COLS] = {6, 1, 0};

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  
 pinMode(A0,OUTPUT);  // gen dir pin y motor
 pinMode(A1,OUTPUT);  // gen step pin y motor
 pinMode(A2,OUTPUT);  // tur dir pin  x motor
 pinMode(A3,OUTPUT);  //tur step pin  x motor
 analogWrite(A0,LOW);
 analogWrite(A1,LOW);
 analogWrite(A2,LOW);
 analogWrite(A3,LOW);
 
 lcd.begin(16, 2);

}

void loop() {
  int gen=0;
  int tur=0;
  int kesit=0;
  int curs=1;
  String str;
  String  str2;
  String strks;
  String strgen;
  String strks1;
  String strgen1;
  
lcd.setCursor(0, 0);
lcd.print("tur sayisi:");

while(true)
{
  
if (char key = kpd.getKey())
{
lcd.setCursor(curs, 1);
lcd.print(key);
curs++;
 
    if (key=='#')
  { 
  lcd.clear();
  delay(300);
  char key;

  break;
  }
  
   str=key;
   str2=str2+str;
   tur=str2.toInt();
 

}

}



lcd.setCursor(0, 0);
lcd.print("tel kesiti:");
curs=0;


 while(true)
 {
  if (char key = kpd.getKey())
{
  if (key=='#')
 {
  
  delay(300);
  lcd.clear();
  char key;
 
  break;
  }
lcd.setCursor(curs, 1);
lcd.print(key);
curs++;

 
  strks=key;
   strks1=strks1+strks;
   kesit=strks1.toInt();
  
}
  
 }
 curs=0;
 lcd.setCursor(0, 0);
lcd.print("uzunluk:");
 while(true)
 {
    if (char key = kpd.getKey())
{
  
lcd.setCursor(curs, 1);
lcd.print(key);
curs++;
if (key=='#')
{
  char key;

  lcd.clear();
  lcd.setCursor(0, 0);
  delay(100);
  lcd.print(tur);
  lcd.setCursor(6, 0);
  lcd.print(kesit);
  lcd.setCursor(10, 0);
  lcd.print(gen);
  delay (200);
 ///////////////////---------------------------------------*********************************//////////////////////////////////
 int i=0;
 int say=0;
 int say2=0;
 int yanakayma=0;
 int tamami=0;
 tamami=gen*200;
 yanakayma=(kesit*20)/2;
 i=tur*200;
 while(true)// tur atmak için döngü
 {
  lcd.setCursor(0, 1);
  lcd.print("sarma");
 if(say==i)
 {
  break;
 }
 
 digitalWrite(A3,HIGH);
 delay(2);
 digitalWrite(A3,LOW);
 delay(1);
 say=say+1;

 if(say%200==0)
 {
  say2=0;
  while(true) // kesit kadar yana kaymak için 
   {
    lcd.setCursor(0, 1);
    lcd.print("kayma");
    digitalWrite(A1,HIGH);
    delay(5);
    digitalWrite(A1,LOW);
    delay(2);
    say2=say2+1;
    if(say2==yanakayma)
    {
      break;
     }
   }
   
 }

 if(tamami==yanakayma)
 {
   if(A0==HIGH)
    {
      digitalWrite(A0,LOW);
     }
    else
    {
      digitalWrite(A0,HIGH);
    }
 }
 
 
 
 } 
 
  break;
  }

   strgen=key;
   strgen1=strgen1+strgen;
   gen=strgen1.toInt();
}
 }

 
 while(true)
  {
    int tur=0;
    if (tur>0)
  {
    digitalWrite(A0, HIGH);
    delay(5);
    digitalWrite(A0, LOW);
    delay(2);
  }
  
  else{
  break;
  }
  tur= tur-1;
  }




  

  }
