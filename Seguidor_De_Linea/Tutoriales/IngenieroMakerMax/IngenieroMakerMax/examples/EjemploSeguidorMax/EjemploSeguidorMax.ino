/*Codigo de ejemplo para un seguidor de linea basado en:
   Arduino Nano
   Motores pololu 12V HPCb
   MAX14 de pololu
   Barra de 16 sensores marca Ingeniero Maker
   Chasis para seguidor de linea en PCB marca Ingeniero Maker
   Modulo de arranque

   Procedimiento de Calibración
   1.-la barra de sensores se debe poner primero en el color blanco de la pista procurando
   que todos los sensores esten sobre el color blanco.

   2.- Presionar el boton en el PCB del robot, despues de esto ya estara calibrado el color blanco.

   3.-la barra de sensores se debe poner despues en el color negro de la pista procurando
   que todos los sensores esten sobre el color negro.

   4.- Presionar el boton en el PCB del robot, despues de esto ya estara calibrado el color negro.

   5.- Presionar de nuevo el boton para hacer el calculo de muestras.
   el robot se encuentra listo para el arranque.
*/
#include<Servo.h>
#include <IngenieroMakerSeguidor16s.h>
#include <IngenieroMakerMax.h>

//Creo control de turbina
Servo turbina;
//CREO EL OBJETO Control
motores Control;
//CREO EL OBJETO Robot
barra16 Robot;
//Mapeo de pines

#define LED     13
#define GO  8 //10
#define BOTON 4 //12
int p;
// Constantes para PID
float KP = 0.01; //0.01; /valor maximo teorico de 65535
float KD = 1; // 1.0;
float Ki = 0.035;//.006

// Regulación de la velocidad Máxima
int Velmax = 90  ;//40 //Maximo 255 nieveles
int VelTurbina = 1400;
// Data para intrgal
int error1 = 0;
int error2 = 0;
int error3 = 0;
int error4 = 0;
int error5 = 0;
int error6 = 0;
unsigned int position = 0;
//declara variables para utilizar PID
int proporcional = 0;         // Proporcional
int integral = 0;           //Intrgral
int derivativo = 0;          // Derivativo
int diferencial = 0;   // Diferencia aplicada a los motores
int last_prop;         // Última valor del proporcional (utilizado para calcular la derivada del error)
int Target = 750; // Setpoint (Como utilizamos 16 sensores, la línea debe estar entre 0 y 1500, por lo que el ideal es que esté en 750)

void setup()
{
  turbina.attach(10);   // ESC conectada al puerto 10
  Serial.begin(9600);
  // Declaramos como salida los pines utilizados
  pinMode(LED   , OUTPUT);
  pinMode(GO, INPUT);
  pinMode(BOTON, INPUT);

  turbina.write(10);
  delay(2000);
   
  //CALIBRACION
  while (digitalRead(BOTON) == HIGH);
  while (digitalRead(BOTON) == LOW);
  for (int i = 0; i < 25; i++)
  {
    Robot.leer_blanco(); //PONER SENSORES EN BLANCO
    digitalWrite(LED, HIGH);
    delay(2);
    digitalWrite(LED, LOW);
    delay(2);
  }


  while (digitalRead(BOTON) == HIGH);
  while (digitalRead(BOTON) == LOW);
  for (int i = 0; i < 25; i++)
  {
    Robot.leer_negro();   //PONER SENSORES EN NEGRO
    digitalWrite(LED, HIGH);
    delay(1);
    digitalWrite(LED, LOW);
    delay(1);
  }

 // while (digitalRead(BOTON) == HIGH);
  //while (digitalRead(BOTON) == LOW);
  Robot.Calcula_muestras(); //CALCULA TABLA DE MUESTRAS
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
    digitalWrite(LED, HIGH);
    delay(100);

  GO_Boton();            // CONTROL DE ARRANQUE

}

void loop()
{
  turbina.write(50);;
  Robot.Leer_Sensores_ir(0);  //1 es para linea negra con fondo blanco
                              //0 es para linea blanca con fondo negro 
  p = Robot.proporcional();
  pid();
}

// BOTON DE ESPERA
void WaitBoton() {
  while (digitalRead(BOTON));
}
// BOTON DE INICIO
void GO_Boton() {
  while (!digitalRead(GO));
}
void pid()
{

  proporcional = p - 750;
  Serial.println(proporcional);
  if ( proporcional <= -Target )
  {
    digitalWrite(DA, HIGH);
    analogWrite (PWMA, 180);
  }
  else if ( proporcional >= Target )
  {
    digitalWrite(DB, HIGH);
    analogWrite (PWMB, 180);
  }

  derivativo = proporcional - last_prop;
  integral = error1 + error2 + error3 + error4 + error5 + error6;
  last_prop = proporcional;

  error6 = error5;
  error5 = error4;
  error4 = error3;
  error3 = error2;
  error2 = error1;
  error1 = proporcional;

  int diferencial = ( proporcional * KP ) + ( derivativo * KD ) + (integral * Ki) ;

  if ( diferencial > Velmax ) diferencial = Velmax;
  else if ( diferencial < -Velmax ) diferencial = -Velmax;

  ( diferencial < 0 ) ?
  Control.Motor(Velmax + diferencial, Velmax) : Control.Motor(Velmax, Velmax - diferencial);

}
