#ifndef ROBOVARIABLES_H
#define ROBOVARIABLES_H

bool flag = false;

//Variables Laberinto A
#define NormalSpeed 100
#define DisFront 7
#define DisSides 7
#define DisPelota 4

#define Wait 1400  //Tiempo de espera para que avance
#define WaitG 1000 //Tiempo de espera para el giro

// Librerías necesarias para el proyecto
#include <SparkFun_TB6612.h>   // Control de los motores
#include <Servo.h>             // Control del servomotor

// Pines del Puente H2
#define AIN1_H2 7
#define AIN2_H2 8
#define BIN1_H2 10
#define BIN2_H2 11
#define PWMA_H2 6
#define PWMB_H2 9

// Definición de motores con sus offsets
const int offset1 = -1;  // Ajusta el sentido del motor 1 (inferior izquierda)
const int offset2 = 1;   // Ajusta el sentido del motor 2 (inferior derecha)
const int offset3 = 1;   // Ajusta el sentido del motor 3 (superior izquierda)
const int offset4 = 1;   // Ajusta el sentido del motor 4 (superior derecha)

// Definición de motores TB6612 con los pines correspondientes y offsets
Motor motor3(AIN1_H2, AIN2_H2, PWMA_H2, offset3, 255); // Motor superior izquierda
Motor motor4(BIN1_H2, BIN2_H2, PWMB_H2, offset4, 255); // Motor superior derecha

// Pines del servomotor de la pinza
#define servoPin 44
Servo gripperServo; // Instancia del servomotor

// Pines de los sensores ultrasónicos

// Ultrasonico izquierda
#define Trig1 30
#define Echo1 31
// Ultrasonico frontal
#define Trig2 32
#define Echo2 33
// Ultrasonico derecha
#define Trig3 34
#define Echo3 35
// Ultrasonico pinza
#define Trig4 36
#define Echo4 37

#endif
