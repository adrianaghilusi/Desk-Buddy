#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <dht.h>
#define temp A3

int randNumber = 0;
LiquidCrystal_I2C lcd(0x27,20,4);
int b1 = 7;
int b2 = 4;
int b3 = 5;
dht DHT;
uint8_t backslash [8]= { 0x00, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00 };
int humComm = 0; //1 for dry //2 for ok //3 for too humid
int tempComm = 0; //1 for cold // 2 for ok // 3 for too hot
byte umbrella[] = {
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B10100,
  B11100,
  B00000
};
byte sun[] = {
  B00000,
  B10101,
  B01110,
  B11011,
  B01110,
  B10101,
  B00000,
  B00000
};
byte flower[] = {
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B11111,
  B01110,
  B00100
};
 

void setup()
{
  Serial.begin(9600);
  lcd.init();                      
  lcd.backlight();
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
//  pinMode(b4, INPUT_PULLUP);
  randomSeed(777);
  lcd.createChar(0, backslash);
  lcd.createChar(1, umbrella);
  lcd.createChar(2,sun);
  lcd.createChar(3,flower);

   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("   ");
   lcd.print(char(0));
   lcd.print("        ");
   lcd.print("/");
   lcd.setCursor(4,1);
   lcd.print(char(0));
   lcd.print("______");
   lcd.print("/");
   delay(2000);
}


void loop()
{
  int p1 = digitalRead(b1); 
  if (p1 == LOW) {
    lcd.clear();
    DHT.read11(temp);  
    lcd.setCursor(1,0);
    lcd.print("Humidity ");
    lcd.setCursor(1,1);
    lcd.print(DHT.humidity);
    lcd.print("%  ");
    if(DHT.humidity >= 70){
      lcd.print(char(1)); 
      humComm = 3;
    }
    else
      lcd.print(char(2));
      if(DHT.humidity >= 30 && DHT.humidity <70)
        humComm = 2;
       if(DHT.humidity < 30)
        humComm = 1;
    delay(2000);
  }
  int p2 = digitalRead(b2);
  if(p2 == LOW){
  lcd.clear();
  DHT.read11(temp);  
  lcd.setCursor(1,0);
  lcd.print("Temperature");
  lcd.setCursor(1,1);
    lcd.print(DHT.temperature); 
    lcd.print("C  ");
    lcd.print(char(3));
  if(DHT.temperature >=30)
    tempComm = 3;
  else if(DHT.temperature >=20)
    tempComm = 2;
  else
    tempComm = 1;
    delay(2000);
  }
  int p3 = digitalRead(b3);
  if(p3 == LOW){
   // long randNumber = random(0,17);
    switch(randNumber){
      case 0:
            if(humComm !=0)
            {
              if(humComm == 1)
                {
                  lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("Hope it rains..");
                }
                if(humComm == 2)
                {
                  lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("Pretty cool out");
                }
                if(humComm ==3)
                {
                  lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("Umbrella, please!");
                }
                break;
            }
     case 1:
            if(tempComm !=0){
              if(tempComm == 1){
                lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("Brr!");
              }
              if(tempComm == 2){
                lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("Go out lol");
              }
              if(tempComm == 3){
                lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("Turn on the AC");
                  lcd.setCursor(1,1);
                  lcd.print("jesus");
              }
              break;
            }
     case 2:
          lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("I like Shakira");
                  lcd.setCursor(1,1);
                  lcd.print("unironically");
          break;

    case 3:
        lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("What if I push");
                  lcd.setCursor(1,1);
                  lcd.print("ur buttons too");
          break;
    
    case 4:
        lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("Let's play");
                  lcd.setCursor(1,1);
                  lcd.print("some music");
          break;
    
    case 5:
        lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("Drink water!");
          break;
    
    case 6:
        lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("Can I get");
                  lcd.setCursor(1,1);
                  lcd.print("a hug?");
          break;
    
    case 7:
        lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("What if this");
                  lcd.setCursor(1,1);
                  lcd.print("is a simulation");
          break;
    
    case 8:
        lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("Let's go");
                  lcd.setCursor(1,1);
                  lcd.print("drinking!");
          break;
    
    case 9:
        lcd.clear();
                  lcd.setCursor(1,0);
                  lcd.print("Don't look");
                  lcd.setCursor(1,1);
                  lcd.print("behind u");
          break;
    case 10:
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Kinda bored hbu");
      break;
     case 11:
     lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("What do computers");
      lcd.setCursor(1,1);
      lcd.print("eat for lunch?");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Microchips");
          break;
     case 12:
     lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("What do you call");
      lcd.setCursor(1,1);
      lcd.print("an old snowman?");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Water");
          break;
    
    case 13:
    lcd.clear();
     lcd.setCursor(0, 0);
      lcd.print("I love puns");
      break;

    case 14:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("How do trees get");
      lcd.setCursor(1,1);
      lcd.print("online?");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("They just log on!");
          break;

          case 15:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("What did 0");
      lcd.setCursor(1,1);
      lcd.print("say to 8?");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nice belt!");
          break;

          case 16:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("What kind of doc");
      lcd.setCursor(1,1);
      lcd.print("fixes brokenwebs?");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("A URLologist.");
          break;
   
  }
  randNumber++;
  if(randNumber > 16)
    randNumber = 0;
  }
}
