#ifndef ROBOVARIABLES_H
#define ROBOVARIABLES_H

#include <SparkFun_TB6612.h> // Librería para el control de los motores

// Pines del Puente H
#define AIN1 7
#define AIN2 8
#define BIN1 10
#define BIN2 11
#define PWMA 6
#define PWMB 9

// Offsets de los motores (ajústalos si es necesario)
const int offsetIzquierdo = 1;
const int offsetDerecho = 1;

// Definición de los motores
Motor motorIzquierdo(AIN1, AIN2, PWMA, offsetIzquierdo, 255); // Motor izquierdo
Motor motorDerecho(BIN1, BIN2, PWMB, offsetDerecho, 255);      // Motor derecho

// Pines del sensor infrarrojo seguidor de línea (con multiplexor HP4067)
#define SL0 A0
#define SL1 A1
#define SL2 A2
#define SL3 A3
#define OM A4

// Array de muestras para calibración
int Muestras[16] = {923, 888, 855, 860, 836, 819, 826, 810, 824, 794, 810, 807, 817, 808, 838, 888};

// Variables PID
float kp = 0.1;
float kd = 1.5;
float ki = 0.01;
int Target = 750;
int VelocidadBase = 80;

#endif
