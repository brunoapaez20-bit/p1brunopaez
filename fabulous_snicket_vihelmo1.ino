#define R 11
#define A 10
#define V 6
#define PR A0
#define PA A1
#define PV A2
#define Boton 2
int ValorRojo; 
int ValorVerde;
int ValorAzul;
bool ValorBoton;

void setup()
{
  pinMode(Boton,INPUT);
  pinMode(R,OUTPUT);
  pinMode(A,OUTPUT);
  pinMode(V,OUTPUT);
  Serial.begin(9800);
}

void loop()
{
  ValorBoton = digitalRead(Boton);
  delay(100);
  if(ValorBoton == LOW){
    Serial.println("tenes 10 segundos para configurar el color del LED");
    delay(10000);
    ValorRojo = analogRead(PR);
    ValorVerde = analogRead(PV);
    ValorAzul = analogRead(PA);
    ValorRojo = map(ValorRojo,0,1023,0,255);
    ValorVerde = map(ValorVerde,0,1023,0,255);
    ValorAzul =  map(ValorAzul,0,1023,0,255);
    Serial.print("El led esta usando esta config: ");
    Serial.println(ValorRojo);
    Serial.println(ValorVerde);
    Serial.println(ValorAzul);
    
    PrendeApaga();
  }
}


void PrendeApaga(){
    analogWrite(R,ValorRojo);
    analogWrite(V,ValorVerde);
    analogWrite(A,ValorAzul);
    delay(1000);
    analogWrite(R,0);
    analogWrite(V,0);
    analogWrite(A,0);
}