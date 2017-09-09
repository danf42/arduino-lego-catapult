#include <Servo.h>

// Pin assignments
const int buttonFire = 2;
const int buttonReset = 4;
const int servoPin = 9;
const int redLed = 7;
const int greenLed = 8;

// Button States
int fireButtonState = LOW;
int resetButtonState = LOW; 

// Servo Positions
const int positionFire = 179;
const int positionReset = 1;

// Servo 
Servo servoA;

void setup() {
  Serial.begin(9600);
  
  servoA.attach(servoPin);
  pinMode(buttonFire, INPUT);
  pinMode(buttonReset, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  servoA.write(positionReset);
  digitalWrite(greenLed, HIGH);
  digitalWrite(redLed, LOW);

  Serial.println("Ready");
}

void loop() {
  // put your main code here, to run repeatedly:

  fireButtonState = digitalRead(buttonFire);
  resetButtonState = digitalRead(buttonReset);

  if (fireButtonState == HIGH && resetButtonState == LOW){
    servoA.write(positionFire);
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
    Serial.println("Fire");
  } 

  if (fireButtonState == LOW && resetButtonState == HIGH){
    servoA.write(positionReset);
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    Serial.println("Reset");
  }
}
