#ifndef ROBOVARIABLES_H
#define ROBOVARIABLES_H

#include <SparkFun_TB6612.h>   // Control de los motores

// Pines del Puente H1
#define AIN1 25
#define AIN2 24
#define BIN1 22
#define BIN2 23
#define PWMA 12
#define PWMB 13

// Pines del Puente H2
#define AIN1_H2 7
#define AIN2_H2 8
#define BIN1_H2 10
#define BIN2_H2 11
#define PWMA_H2 6
#define PWMB_H2 9

// Definición de motores con sus offsets
const int offset1 = -1;
const int offset2 = 1;
const int offset3 = 1;
const int offset4 = 1;

// Definición de motores TB6612 con los pines correspondientes y offsets
Motor motor1(AIN1, AIN2, PWMA, offset1, 255);
Motor motor2(BIN1, BIN2, PWMB, offset2, 255);
Motor motor3(AIN1_H2, AIN2_H2, PWMA_H2, offset3, 255); //IZQUIERDO 
Motor motor4(BIN1_H2, BIN2_H2, PWMB_H2, offset4, 255); //DERECHI

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