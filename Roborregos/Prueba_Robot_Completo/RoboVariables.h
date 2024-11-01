#ifndef ROBOVARIABLES_H
#define ROBOVARIABLES_H

// Librerías necesarias para el proyecto
#include <SparkFun_TB6612.h>   // Control de los motores
#include <Servo.h>             // Control del servomotor
#include <Wire.h>              // Comunicación I2C (para el giroscopio)
#include <Adafruit_MPU6050.h>  // Sensor IMU (adaptar si usas otro)
#include <FastLED.h>           // Control de la barra LED RGB
#include <IngenieroMakerSeguidor16sFC.h>

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
const int offset1 = -1;  // Ajusta el sentido del motor 1 (inferior izquierda)
const int offset2 = 1;   // Ajusta el sentido del motor 2 (inferior derecha)
const int offset3 = 1;   // Ajusta el sentido del motor 3 (superior izquierda)
const int offset4 = 1;   // Ajusta el sentido del motor 4 (superior derecha)

// Definición de motores TB6612 con los pines correspondientes y offsets
Motor motor1(AIN1, AIN2, PWMA, offset1, 255);          // Motor inferior izquierda
Motor motor2(BIN1, BIN2, PWMB, offset2, 255);          // Motor inferior derecha
Motor motor3(AIN1_H2, AIN2_H2, PWMA_H2, offset3, 255); // Motor superior izquierda
Motor motor4(BIN1_H2, BIN2_H2, PWMB_H2, offset4, 255); // Motor superior derecha

// Pines del sensor de color
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define OUT A5

// Pines del servomotor de la pinza
#define servoPin 44
Servo gripperServo; // Instancia del servomotor

// Pines del sensor infrarrojo seguidor de línea (con multiplexor HP4067)
#define SL0 A1
#define SL1 A2
#define SL2 A3
#define SL3 A4
#define OM A0 // Pin de salida del multiplexor para lectura

// Pines de la barra LED RGB
#define DATA_PIN 6
#define NUM_LEDS 8    // Número de LEDs en la barra RGB, ajustar según sea necesario
CRGB leds[NUM_LEDS];   // Array de LEDs para FastLED

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

// Pines de conexión para el giroscopio
#define SCL_PIN 21
#define SDA_PIN 20

// Variables para los encoders (para medir rotaciones de los motores)
// Encoder motor superior izquierda
#define encoder1Pin 40
// Encoder motor superior derecha
#define encoder2Pin 41
// Encoder motor inferior izquierda
#define encoder3Pin 42
// Encoder motor inferior derecha
#define encoder4Pin 43

#endif
