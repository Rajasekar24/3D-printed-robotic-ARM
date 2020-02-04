#include <Servo.h>

Servo servos[6];

void setup() {
 
  Serial.begin(9600);
  servos[2].attach(2);
  servos[3].attach(3);
  servos[4].attach(4);
  servos[5].attach(5);
 
}

void loop() {
  
   //start position,end position,angles adding  per loop,delay time, which Servo.
   
  //Home position  
   MotorMove(0,0,10,1000,2);
   Serial.println("Home position  2");
   Serial.println("Wait for  2 Sec");
    delay(2000);
   MotorMove(100,100,1,1000,3);
   Serial.println("Home position  3");
   Serial.println("Wait for  2 Sec");
    delay(2000);
   MotorMove(95,95,10,1000,4);
   Serial.println("Home position  4");
   Serial.println("Wait for  2 Sec");
    delay(2000);
   MotorMove(90,90,10,1000,5);
   Serial.println("Home position  5");
   Serial.println("Home Position Over");
     Serial.println("Wait for  5 Sec");
      delay(5000);
       
    //pick
 
    MotorMove(0,0,10,5,2);
    Serial.println("pick  2");
    MotorMove(100,30,1,10,3);
    Serial.println("coming  3");
    MotorMove(95,140,10,5,4);
    Serial.println("pick  5");
    MotorMove(90,30,10,5,5);
    Serial.println("Pick Over");
    Serial.println("Wait for  5 Sec");
    delay(5000);
    
  //Move
   MotorMove(0,90,5,500,2);
   Serial.println("Move Over");
   Serial.println("Wait for  5 Sec");
    delay(5000);
   
  //Drop
   MotorMove(30,90,10,5,5);
   delay(1000);
   MotorMove(140,95,10,5,4);
    delay(1000);
   MotorMove(30,100,10,20,3);
    delay(1000);
   MotorMove(90,0,1,5,2);
   Serial.println("Drop Over");
   Serial.println("Wait for  5 Sec");
    delay(5000);
    
}

void MotorMove(int start,int end,int jump,int sleep,int servo)
{
  if(start <= end){
    for (int i = start; i <= end; i+=jump) {
      servos[servo].write(i);
      delayMicroseconds(sleep);
      Serial.println("s<e");
      Serial.print("Servo number:");
      Serial.println(servo);
      Serial.print("Servo Position:");
      Serial.println(i);
    }
  }else{
      for (int i = start; i >= end;i-=jump) {
       servos[servo].write(i);
       delayMicroseconds(sleep);
       Serial.println("s>e");
       Serial.print("Servo number:");
       Serial.println(servo);
       Serial.print("Servo Position:");
       Serial.println(i);
    }
  }
}
