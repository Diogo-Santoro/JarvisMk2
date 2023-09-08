#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(10, 11);

int pump1Pin = 2;
int pump2Pin = 3;
int pump3Pin = 4;
int pump4Pin = 5;

void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(9600);
  pinMode(pump1Pin, OUTPUT);
  pinMode(pump2Pin, OUTPUT);
  pinMode(pump3Pin, OUTPUT);
  pinMode(pump4Pin, OUTPUT);
  digitalWrite(pump1Pin, LOW);
  digitalWrite(pump2Pin, LOW);
  digitalWrite(pump3Pin, LOW);
  digitalWrite(pump4Pin, LOW);
}

void testPump1() {
  digitalWrite(pump1Pin, HIGH);
}

void testPump2() {
  digitalWrite(pump2Pin, HIGH);
}

void testPump3() {
  digitalWrite(pump3Pin, HIGH);
}

void testPump4() {
  digitalWrite(pump4Pin, HIGH);
}

void loop() {
  if (bluetoothSerial.available() > 0) {
    char command = bluetoothSerial.read();
    switch (command) {
      case '1':
        testPump1();
        break;
      case '2':
        testPump2();
        break;
      case '3':
        testPump3();
        break;
      case '4':
        testPump4();
        break;
      case '0':
        digitalWrite(pump1Pin, LOW);
        digitalWrite(pump2Pin, LOW);
        digitalWrite(pump3Pin, LOW);
        digitalWrite(pump4Pin, LOW);
        break;
      default:
        break;
    }
  }
}
