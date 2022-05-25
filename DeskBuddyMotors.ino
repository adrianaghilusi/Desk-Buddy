
#include <AFMotor.h>  
#include <NewPing.h>
#include <Servo.h> 

#define TRIG_PIN A0 
#define ECHO_PIN A1 
#define MAX_DISTANCE 200 
#define MAX_SPEED 190 
#define MAX_SPEED_OFFSET 20
#define tableSensor A2

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 
AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);
Servo servo;   

boolean goesForward=false;
int distance = 100;
int speedSet = 0;

void setup() {
  Serial.begin(115200);
  M1.setSpeed(250);
  M2.setSpeed(250);
  M3.setSpeed(250);
  M4.setSpeed(250);
  servo.attach(10);
  servo.write(115);
  delay(2000);
  distance = sonar.ping_cm();
}

void loop(){

int falling = digitalRead(tableSensor);


int distanceR = 0;
 int distanceL =  0;
 delay(400);
 
 if(distance<=5 || falling==1)
 {
  moveStop();
  delay(100);
  moveBackward();
  delay(300);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  {
    turnRight();
    moveStop();
  }else
  {
    turnLeft();
    moveStop();
  }
 }else
 {
  moveForward();
  delay(300);
 }
 distance = sonar.ping_cm();

}


int lookRight()
{
    servo.write(50); 
    delay(500);
    int distance = sonar.ping_cm();
    delay(100);
    servo.write(115);
    delay(100);
    return distance;
    
}
int lookLeft()
{
    servo.write(170); 
    delay(500);
    int distance = sonar.ping_cm();
    delay(100);
    servo.write(115); 
    delay(100);
    return distance;
    
}
void moveStop(){
  M1.run(RELEASE); 
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
  } 
 void moveForward() {

 if(!goesForward)
  {
    goesForward=true;
    M1.run(BACKWARD);      
    M2.run(FORWARD);
    M3.run(BACKWARD); 
    M4.run(FORWARD);     
   for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=4) 
   {
    M1.setSpeed(speedSet);
    M2.setSpeed(speedSet);
    M3.setSpeed(speedSet);
    M4.setSpeed(speedSet);
    delay(5);
   }
  }
}

void moveBackward() {
    goesForward=false;
    M1.run(FORWARD);      
    M2.run(BACKWARD);
    M3.run(FORWARD);
    M4.run(BACKWARD);  
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=4) 
  {
    M1.setSpeed(speedSet);
    M2.setSpeed(speedSet);
    M3.setSpeed(speedSet);
    M4.setSpeed(speedSet);
    delay(5);
  }
}  

void turnRight() {
  M1.run(BACKWARD);
  M2.run(FORWARD);
  M3.run(FORWARD);
  M4.run(BACKWARD);     
  delay(500);
    M1.run(BACKWARD);      
    M2.run(FORWARD);
    M3.run(BACKWARD); 
    M4.run(FORWARD);      
} 
 
void turnLeft() {
  M1.run(FORWARD);     
  M2.run(BACKWARD);  
  M3.run(BACKWARD);
  M4.run(FORWARD);   
  delay(500);
    M1.run(BACKWARD);      
    M2.run(FORWARD);
    M3.run(BACKWARD); 
    M4.run(FORWARD);
} 
