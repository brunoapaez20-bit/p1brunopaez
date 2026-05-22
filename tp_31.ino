#define rojo 11
#define verde 6
#define azul 9
#define sensorluz A0
#define sensortemp A1

int sensort; 
int sensorl;

void setup()
{
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(sensorluz, INPUT);
  pinMode(sensortemp, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int lecturaTMP = analogRead(sensortemp);
  float voltaje = lecturaTMP * (5.0 / 1023.0);
  sensort = (voltaje - 0.5) * 100.0;
  
  int nivelluz = analogRead(sensorluz);
  sensorl = map(nivelluz, 0, 1023, 100, 0);

  Serial.print("El nivel de luz actual es: ");
  Serial.print(sensorl);
  Serial.print("% y la temperatura actual: ");
  Serial.print(sensort);
  Serial.println(" grados");

  prenderleds();
  
  delay(1000);
}

void prenderleds(){
  if(sensorl >= 15 && sensorl <= 23){
    
    if(sensort > 90)
    {
      analogWrite(rojo, 255);
      analogWrite(verde, 0);
      analogWrite(azul, 0);
    } 
    else if(sensort < 18)
    {
      analogWrite(rojo, 0);
      analogWrite(verde, 0);
      analogWrite(azul, 255);
    }
    else
    {
      analogWrite(rojo, 0);
      analogWrite(verde, 255);
      analogWrite(azul, 0);
    }
    
  } else {
    apagartodo();
  }
}

void apagartodo(){
  analogWrite(rojo, 0);
  analogWrite(verde, 0);
  analogWrite(azul, 0);
}