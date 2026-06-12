#include <Servo.h>
#define boton 2
#define sensort A3
#define sensorm A2
Servo servo1;
Servo servo2;
int rotacion = 90;
int temperatura;
int sensortemp;
float nivelt;
bool valorboton;
bool movimiento;

void setup()
{
  pinMode(sensorm, INPUT);
  pinMode(boton, INPUT);
  pinMode(sensort, INPUT);
  servo1.attach(A0);
  servo2.attach(A1);
  servo1.write(90);
  servo2.write(90);
  Serial.begin(9800);
}

void loop()
{
  temperatura = analogRead(sensort);
  nivelt = temperatura * (5.0 / 1023.0);
  sensortemp = (nivelt - 0.5) * 100.0;
  Serial.println(sensortemp);
  valorboton = digitalRead(boton);
  movimiento = digitalRead(sensorm);
  moverservo();
  movimiento1();
}

void moverservo()
{
  if(valorboton == LOW)
  {
    delay(3000);
    rotacion = rotacion + 10;
    servo1.write(rotacion);
    servo2.write(rotacion);
  }
  if(valorboton == HIGH)
  {
    servo1.write(45);
    servo2.write(45);
  }
  if(sensortemp >= 35)
  {
    servo1.write(rotacion);
    servo2.write(rotacion);
  }
}

void movimiento1()
{
  if(movimiento == HIGH)
  {
    servo1.write(0);
    servo2.write(0);
    delay(6000);
    servo1.write(90);
    servo2.write(90);
    moverservo();
  }
}