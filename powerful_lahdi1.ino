#include <Servo.h>
#define boton1 2
#define boton2 7

Servo servo1;
Servo servo2;
int rotacion = 0;
bool valorboton;
bool valorboton2;

void setup()
{
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  servo1.attach(A1);
  servo2.attach(A2);
  servo1.write(0);
  servo2.write(0);
  Serial.begin(9800);
}

void loop()
{
  valorboton = digitalRead(boton1);
  valorboton2 = digitalRead(boton2);
  avanzar();
  retroceder();
  if(rotacion < 0){
    rotacion = 0;
  }
  Serial.println(rotacion);
  Serial.println(valorboton);
}

void avanzar(){
  if(valorboton == LOW){
    rotacion = rotacion + 10;
    servo1.write(rotacion);
    servo2.write(rotacion);
    delay(100);
  }
}


void retroceder(){
  if (valorboton2 == LOW){
    rotacion = rotacion - 10;;
    servo1.write(rotacion);
    servo2.write(rotacion);
    delay(100);
  }
}