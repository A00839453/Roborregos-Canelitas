#define DirIzq 9
#define VelIzq 5
#define DirDer 6
#define VelDer 3
#define GO 8
#define RDY 12
void setup()
{
  pinMode(DirIzq, OUTPUT);
  pinMode(VelIzq, OUTPUT);
  pinMode(DirDer, OUTPUT);
  pinMode(VelDer, OUTPUT);
  pinMode(GO, INPUT);
  pinMode(RDY, INPUT);
  Serial.begin(9600);
}

void loop()
{

 if (digitalRead(GO) == HIGH)
  {
    adelante(100);//0-255
   
  }
  if (digitalRead(GO) == LOW)
  {
    paro();
  }

}
void adelante(int velocidad)
{
  digitalWrite(DirIzq, LOW); //controlar la direccion del motor izquierdo
  analogWrite(VelIzq, velocidad); //controlar la velocidad de motor izquierdo
  digitalWrite(DirDer, HIGH); //controlar la direccion del motor derecho
  analogWrite(VelDer, velocidad); //controlar la velocidad de motor derecho
}
void atras(int velocidad)
{
  digitalWrite(DirIzq, HIGH); //controlar la direccion del motor izquierdo
  analogWrite(VelIzq, velocidad); //controlar la velocidad de motor izquierdo
  digitalWrite(DirDer, LOW); //controlar la direccion del motor derecho
  analogWrite(VelDer, velocidad); //controlar la velocidad de motor derecho
}
void paro()
{
  digitalWrite(DirIzq, HIGH); //controlar la direccion del motor izquierdo
  analogWrite(VelIzq, 0); //controlar la velocidad de motor izquierdo
  digitalWrite(DirDer, LOW); //controlar la direccion del motor derecho
  analogWrite(VelDer, 0); //controlar la velocidad de motor derecho
}
