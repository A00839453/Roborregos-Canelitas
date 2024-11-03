#ifndef ROBOVARIABLES_H
#define ROBOVARIABLES_H

// Pines del Puente H1
#define AIN1 25
#define AIN2 24
#define BIN1 22
#define BIN2 23
#define PWMA 12
#define PWMB 13
#define STBY 255  // No se usa en esta configuración, ya que STBY está conectado a VCC

// Pines del Puente H2
#define AIN1_H2 7
#define AIN2_H2 8
#define BIN1_H2 10
#define BIN2_H2 11
#define PWMA_H2 6
#define PWMB_H2 9

const int offsetA = 1;
const int offsetB = 1;

// Configuración de los motores
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);
Motor motor3 = Motor(AIN1_H2, AIN2_H2, PWMA_H2, offsetA, STBY);
Motor motor4 = Motor(BIN1_H2, BIN2_H2, PWMB_H2, offsetB, STBY);

int speed = 0;
float duration, distance;

// Configuración para los sensores ultrasónicos
// Ultrasonico 1 - izquierda
#define Trig1 30
#define Echo1 31

// Ultrasonico 2 - adelante
#define Trig2 32
#define Echo2 33

// Ultrasonico 3 - derecha
#define Trig3 34
#define Echo3 35

// Ultrasonico 4 - para la pelota
#define Trig4 36
#define Echo4 37

// Configuración sensor infrarrojo
const int S0 = A0;
const int S1 = A1;
const int S2 = A2;
const int S3 = A3;
const int ANALOG_IN = A4;

int sensorValores[16];
int Valor_Digital[16];

#define Pinza 44

#endif

