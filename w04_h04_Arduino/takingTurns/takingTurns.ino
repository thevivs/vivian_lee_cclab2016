int led = 13;
int ledOne = 12;
int ledTwo = 8;
int ledThree = 4;



int buttonPin = 2;
int buttonState = 0;

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(led, OUTPUT);
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledThree, OUTPUT);
  pinMode(buttonPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {

    digitalWrite(led, HIGH);
    digitalWrite(ledTwo, HIGH);

  } else {

    digitalWrite(ledOne, HIGH);
    digitalWrite(ledThree, HIGH);
  }

  if(buttonState ==LOW){
       digitalWrite(led, LOW);
       digitalWrite(ledOne, LOW);
       digitalWrite(ledTwo, LOW);
       digitalWrite(ledThree, LOW);

  }

}

