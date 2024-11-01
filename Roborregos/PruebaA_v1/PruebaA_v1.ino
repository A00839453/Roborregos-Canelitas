//#include <IngenieroMakerSeguidor16sFC.h>
#include <SparkFun_TB6612.h>

#include "RoboVariables.h"
#include "RoboFuncion.h"

void setup() {
    
    Serial.begin(9600);  // Inicializar el monitor serial para depuración
    motor1.drive(0); // Motor 1 a máxima velocidad
    motor2.drive(0); // Motor 2 a máxima velocidad
    motor3.drive(0); // Motor 3 a máxima velocidad
    motor4.drive(0); // Motor 4 a máxima velocidad
    
    
    pinMode(Trig1, OUTPUT);
    pinMode(Echo1, INPUT);
    pinMode(Trig2, OUTPUT);
    pinMode(Echo2, INPUT);
    pinMode(Trig3, OUTPUT);
    pinMode(Echo3, INPUT);
    pinMode(Trig4, OUTPUT);
    pinMode(Echo4, INPUT);

    /*
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(ANALOG_IN, INPUT);
    */
    
}

void loop() {
  Serial.println("movin");
  MoverAdelante(255);
  //digitalWrite(PWMA,HIGH);
  //digitalWrite(PWMB,HIGH);
  //digitalWrite(PWMA_H2,HIGH);
  //digitalWrite(PWMB_H2,HIGH);
  //delay(2000);
  //MoverAtras(255);
  //delay(2000);
  //MoverIzquierda(100);
  //delay(2000);
  //MoverDerecha(100);
  //delay(2000);

  //Serial.println("Distancia:");
  //delay(2000);
  /*
  Serial.println(CalcularDistancia(Trig1, Echo1));
  delay(2000);
  Serial.println(CalcularDistancia(Trig2, Echo2));
  delay(2000);
  Serial.println(CalcularDistancia(Trig3, Echo3));
  delay(2000);
  Serial.println(CalcularDistancia(Trig4, Echo4));
  delay(2000);
  */

  //Leer_Sensores_ir();
}