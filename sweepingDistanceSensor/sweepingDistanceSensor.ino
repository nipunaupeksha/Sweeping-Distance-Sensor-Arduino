#include <Servo.h>
const int SERVO = 9; //Servo on pin 9
const int IR = 0; //IR Distance Sensor on Analog Pin 0
const int LED1 = 3; //LED Output 1
const int LED2 = 5; //LED Output 2
const int LED3 = 6; //LED Output 3
const int LED4 = 11; //LED Output 4

Servo myServo; //Servo Object
int dist1 = 0;//Quadrant 1 distance
int dist2 = 0;//Quadrant 2 distance
int dist3 = 0;//Quadrant 3 distance
int dist4 = 0;//Quadrant 4 distance
void setup() {
  myServo.attach(SERVO);//Attach the servo
  pinMode(LED1,OUTPUT);//Set LED to Output
  pinMode(LED2,OUTPUT);//Set LED to Output
  pinMode(LED3,OUTPUT);//Set LED to Output
  pinMode(LED4,OUTPUT);//Set LED to Output
}

void loop() {
  //Sweep the servo into four regions and change the LEDs
  dist1 = readDistance(15); //Measure IR distance at 15 degrees
  analogWrite(LED1,dist1); //Adjust LED brightness
  delay(300);

  dist2 = readDistance(65); //Measure IR distance at 65 degrees
  analogWrite(LED1,dist2); //Adjust LED brightness
  delay(300);

  dist3 = readDistance(115); //Measure IR distance at 115 degrees
  analogWrite(LED1,dist3); //Adjust LED brightness
  delay(300);

  dist4 = readDistance(165); //Measure IR distance at 165 degrees
  analogWrite(LED1,dist4); //Adjust LED brightness
  delay(300);
}

int readDistance(int pos){
  myServo.write(pos); //move to given position
  delay(600); //wait for servo to move
  int dist = analogRead(IR); //read IR sensor
  dist = map(dist,50,500,0,255); //scale it to LED range
  dist = constrain(dist,0,255);//constrain it
  return dist; //return scaled distance
  }
