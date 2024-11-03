#ifndef ROBOVARIABLES_H
#define ROBOVARIABLES_H

#include <Wire.h>
#include <MPU6050.h>
#include <SparkFun_TB6612.h>

// Pines de conexión para el giroscopio
#define SCL_PIN 21
#define SDA_PIN 20

// Pines y configuración del puente H para los motores
#define AIN1_H2 7
#define AIN2_H2 8
#define BIN1_H2 10
#define BIN2_H2 11
#define PWMA_H2 6
#define PWMB_H2 9
const int offset3 = 1;
const int offset4 = 1;
const int NormalSpeed = 255; // Velocidad de movimiento hacia atrás

// Definición de los motores conectados al segundo puente H
Motor motor3(AIN1_H2, AIN2_H2, PWMA_H2, offset3, 255);
Motor motor4(BIN1_H2, BIN2_H2, PWMB_H2, offset4, 255);

// Inicialización del giroscopio
MPU6050 gyroscope;

#endif
