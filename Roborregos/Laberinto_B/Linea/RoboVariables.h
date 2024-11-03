#include <SparkFun_TB6612.h>

#ifndef ROBOVARIABLES_H
#define ROBOVARIABLES_H

// Pines del Puente H2
#define AIN1_H2 7
#define AIN2_H2 8
#define BIN1_H2 10
#define BIN2_H2 11
#define PWMA_H2 6
#define PWMB_H2 9

// Definición de motores con sus offsets
const int offset3 = 1;   // Ajuste para los motores izquierdos
const int offset4 = 1;   // Ajuste para los motores derechos

// Definición de motores TB6612 con los pines correspondientes y offsets
Motor motor3(AIN1_H2, AIN2_H2, PWMA_H2, offset3, 255); // Motores izquierdos
Motor motor4(BIN1_H2, BIN2_H2, PWMB_H2, offset4, 255); // Motores derechos

// Pines del sensor infrarrojo seguidor de línea (con multiplexor HP4067)
#define SL0 A0
#define SL1 A1
#define SL2 A2
#define SL3 A3
#define OM A4 // Pin de salida del multiplexor para lectura

// Array de muestras para calibración
//Esto se calculo probando el sensor Infrarojo en una superficie blanca y obteniendo valores, despues en una superficie negra y tomando valores
//Despues se promedio todos los valores que nos dio cada uno de los 16 sensores infrarojos
//Se sumaron los promedios del blanco y el negro y se dividieron entre 2, ese es el valor de nuestra muestra
//Afuera de esta carpeta esta el Excel con los valores obtenidos para blanco y negro
int Muestras[16] = {923, 888, 855, 860, 836, 819, 826, 810, 824, 794, 810, 807, 817, 808, 838, 888};

// Variables PID
float kp = 0.05;       // Ajuste para reducir el zigzag
float kd = 1.0;        // Reducción para suavizar la reacción
float ki = 0.005;      // Reducción para evitar pulsos
int Target = 750;      // Valor objetivo
int VelocidadBase = 100; // Incremento para mejorar estabilidad en rectas

#endif
