#include <Servo.h>

Servo servo;
int boton1 = 8;
int boton2 = 9;
int boton3 = 10;

int pos = 0;    // variable to store the servo position
int mode = 0;   // mode

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  servo.attach(3);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
}

void loop() {

  // put your main code here, to run repeatedly:
  //  if (digitalRead(boton1) == HIGH) {
  //    Serial.println("0");
  //    servo.write(0);
  //  }  else if (digitalRead(boton2) == HIGH) {
  //    Serial.println("90");
  //    servo.write(45);
  //  }
  //  else if (digitalRead(boton3) == HIGH) {
  //    Serial.println("180");
  //    servo.write(90);
  //  }
  //  delay(100);

  if (mode == 0) {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
      checkMode();
      if (mode == 1) {
        break;
      }
    }
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
      checkMode();
      if (mode == 1) {
        break;
      }
    }
  } else if (mode == 1) {
    if (digitalRead(boton2) == HIGH) {
      Serial.println("up");
      if (pos < 180) {
        pos++;
      }
      servo.write(pos);
    }
    else if (digitalRead(boton3) == HIGH) {
      Serial.println("down");
      if (pos > 0) {
        pos--;
      }
      servo.write(pos);
    }
  }
}

void checkMode() {
  if (digitalRead(boton1) == HIGH) {
    Serial.println("change mode");
    mode = mode == 0 ? 1 : 0;
  }
}
