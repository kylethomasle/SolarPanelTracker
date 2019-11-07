//Author: Kyle Thomas Le
//Date: 11-06-2019
//Class: ECE 3301 with Dr. Omar
//Description: Servo motor control for tilting solar panel based on input voltages

#include <Servo.h>

int servoPin = 9;    //Port 9 to control servo
int analogPin1 = A2; //Analog input A2
int analogPin2 = A4; //Analog input A4

double vin1, vin2, vin1_unadjusted, vin2_unadjusted; 

Servo myservo;  //Create servo object

int pos = 0;    //Store initial servo position as zero. 
int sens = 10;  //Create sensitivity parameter to account for error
int delaytime = 30; //Universal delay time between motor movement

void setup() {
  myservo.attach(servoPin);  //Connects servo object to servoPin por
  myservo.write(0);          //Reset servo position to 0
  Serial.begin(9600);        //Launch serial port to print values
}

void loop() {
  vin1_unadjusted = analogRead(analogPin1);   //Read analog inputs
  vin2_unadjusted = analogRead(analogPin2);
  vin1 = map(vin1_unadjusted, 0, 1023, 0, 100); //Convert analog input from 0-1023 scale to 0-100 scale. 
  vin2 = map(vin2_unadjusted, 0, 1023, 0, 100);
  
  Serial.println(vin1);   //View vin1 vs vin2 using serial plotter 
  Serial.println(vin2);


  if(vin1<=vin2+sens & vin1 >= vin2-sens) //Stop if inputs are exactly the same or within sensitivity
  {
    //Serial.println("Equal, not moving!");  //Notify stopped using serial monitor for debugging
  }
  else if(vin1 > vin2 + sens)   //Tilt forward if vin1 is greater than vin2 with sensitivity
  {
    //Serial.println("Forward!" + (String)pos);   //Notify forward direction using serial monitor for debugging
    if(pos < 180)
      pos += 1; 
    myservo.write(pos);
    delay(delaytime);
  }
  else if(vin1 < vin2 - sens)   //Tilt backward if vin1 is less than vin2 with sensitivity
  {
    //Serial.println("Backward!" + (String)pos); //Notify backward direction using serial monitor for debugging
    if(pos > 0)
      pos -= 1; 
    myservo.write(pos-1);
    delay(delaytime);
  }
  else
  {
    //Serial.println("Error state!"); //Notify if error if no other state is found 
  }
}
