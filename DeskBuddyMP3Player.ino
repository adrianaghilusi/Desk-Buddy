#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX 
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
int sensorval=0;
int led;
int b4 = 6;
DFRobotDFPlayerMini player;
int buttonStateNew;
int buttonStateOld=1;
int ledState=0;

void setup() {

  Serial.begin(9600);
  softwareSerial.begin(9600);
  if (player.begin(softwareSerial)) {
   Serial.println("OK");

    player.volume(0);
    player.play(1);
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
  pinMode(A2,OUTPUT);
pinMode(A3,OUTPUT);
pinMode(A4,OUTPUT);
pinMode(A0,INPUT);
pinMode(b4, INPUT);
}
int pressCount = 0;
int song =1;
void loop() {
delay(10);
buttonStateNew= digitalRead(b4);

  if(buttonStateOld == 0 && buttonStateNew == 1)
{
  
if (pressCount%2==0){ 
player.volume(10);
 Serial.print(led)  ; 
 player.play(song);

  }

else
{ 
  player.volume(0); 
  ledState=0;
 
}
 pressCount++;
 song++;
 if(song >4)
  song =1;
}
if(pressCount%2!=0){
   sensorval = analogRead(A0);
led = map(sensorval, 300,1024,0,255);
analogWrite(A2,led);
analogWrite(A3,led);
analogWrite(A4,led);
}
buttonStateOld=buttonStateNew;     

Serial.println(pressCount);
  }
