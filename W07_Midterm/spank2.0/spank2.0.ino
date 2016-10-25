#include <Servo.h>

Servo myServo;
#define servoPin 9

//int pos = 75;
#define trigPin 5
#define echoPin 4


void setup() {
  // put your setup code here, to run once:

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  pinMode(servoPin, OUTPUT);

}

void loop() {

  long duration, distance;

  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance < 30) {  // This is where the LED On/Off happens
    digitalWrite(servoPin, HIGH); // When the Red condition is met, the Green LED should turn off
    myServo.write(110);
  }
  else {
    digitalWrite(servoPin, LOW);
    myServo.write(75);
  }

  delay(500);

}
