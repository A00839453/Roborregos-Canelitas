#include "RoboVariables.h"
#include "RoboFunciones.h"

void setup() {
    Serial.begin(9600);
    // Configuración de pines de los sensores ultrasónicos como salida y entrada
    pinMode(Trig1, OUTPUT); // Izquierda
    pinMode(Echo1, INPUT);
    pinMode(Trig2, OUTPUT); //Frontal
    pinMode(Echo2, INPUT);
    pinMode(Trig3, OUTPUT); //Derecha
    pinMode(Echo3, INPUT);
    pinMode(Trig4, OUTPUT); //Pelota
    pinMode(Echo4, INPUT);
    gripperServo.attach(servoPin);  // Conectar el servomotor al pin asignado
    MoverAdelante(NormalSpeed);
    delay(1500);
}

void loop() {  
  /*
  flag es una bandera que nos va a ayudar a saber si anteriormente ya se había tomado la pelota o no.
  Si la distancia del sensor 'Pelota' es menor o igual a la permitida
  y no se ha prendido la bandera, haremos el proceso para agarrar la pelota.
  En el caso que no se lea la distancia para la pelota, continuaremos resolviendo el laberinto con la función maze().
  */
  if(CalcularDistancia(Trig4, Echo4)<=DisPelota && flag == false){
    DetenerMotores();
    AbrirPinza();
    MoverAdelante(NormalSpeed);
    delay(200);
    DetenerMotores();
    CerrarPinza();
    delay(200);
    flag = true;
  } else {
    Maze();
  }
}

void Maze(){
   //Si la distancia de los sensores (izquierdo, frontal y derecha) es mayor a la permitida significa que no tiene ningun obstaculo, por lo que se movera hacia adelante.
  if (CalcularDistancia(Trig2, Echo2)>DisFront && CalcularDistancia(Trig3, Echo3)>DisSides && CalcularDistancia(Trig1, Echo1)>DisSides) 
    {MoverAdelante(NormalSpeed);}
     //Si la distancia de los sensores (izquierdo, frontal y derecha) es menor a la permitida significa que tiene obstaculos en todos los lados, 
    //lo que significa que esta en un dead end, tendrá que salir de reversa y elegir entre izquierda o derecha, dependiendo de cual tiene el obstaculo más lejos. 
    else if (CalcularDistancia(Trig2, Echo2)<DisFront && CalcularDistancia(Trig3, Echo3)<DisSides && CalcularDistancia(Trig1, Echo1)<DisSides)
    {
      MoverAtras(NormalSpeed);
      delay(Wait+200);
      if((CalcularDistancia(Trig1, Echo1))>(CalcularDistancia(Trig3, Echo3)) ){ GirarIzquierda(NormalSpeed);delay(WaitG);}
      else {GirarDerecha(NormalSpeed);delay(WaitG);}
    }
    //Si detecta obstaculos del lado derecho y frontal, hará un giro a la izquierda.
    else if (CalcularDistancia(Trig2, Echo2)<DisFront && CalcularDistancia(Trig3, Echo3)<DisSides && CalcularDistancia(Trig1, Echo1)>DisSides)
    {GirarIzquierda(NormalSpeed);delay(WaitG);}
    //Si detecta obstaculos del lado izquierdo y frontal, hará un giro a la derecha.
    else if (CalcularDistancia(Trig2, Echo2)<DisFront && CalcularDistancia(Trig3, Echo3)>DisSides && CalcularDistancia(Trig1, Echo1)<DisSides)
    {GirarDerecha(NormalSpeed);delay(WaitG);}
    //Si detecta obstaculos del lado derecho, hará un giro a la izquierda y se movera hacia adelante.
    else if (CalcularDistancia(Trig2, Echo2)<DisFront && CalcularDistancia(Trig3, Echo3)>DisSides && CalcularDistancia(Trig1, Echo1)>DisSides)
    {
      GirarIzquierda(NormalSpeed);
      delay(WaitG);
      MoverAdelante(NormalSpeed);
    }
    //Si detecta obstaculos del lado izquierdo, hará un giro a la derecha y se movera hacia adelante.
    else if (CalcularDistancia(Trig2, Echo2)>DisFront && CalcularDistancia(Trig3, Echo3)>DisSides && CalcularDistancia(Trig1, Echo1)<DisSides)
    {
      GirarDerecha(NormalSpeed);
      delay(WaitG);
      MoverAdelante(NormalSpeed);
    }
    //Si detecta un obstaculo enfrente, sin obstaculos a los lados, hara un giro a la izquierda y se movera hacia adelante.
    else if (CalcularDistancia(Trig2, Echo2)>DisFront && CalcularDistancia(Trig3, Echo3)<DisSides && CalcularDistancia(Trig1, Echo1)>DisSides)
    {
      GirarIzquierda(NormalSpeed);
      delay(WaitG);
      MoverAdelante(NormalSpeed);
    } else {
      //Si hay alguna condición no descrita en las otras en este código, el robot seguira avanzando. 
      MoverAdelante(NormalSpeed);
    }
}