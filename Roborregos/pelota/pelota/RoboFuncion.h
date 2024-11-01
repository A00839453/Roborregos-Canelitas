#ifndef ROBOFUNCION_H
#define ROBOFUNCION_H

#include "RoboVariables.h"

// Funciones para los motores
void MoverAdelante(int speed) {
    motor1.drive(speed);
    motor2.drive(speed);
    motor3.drive(speed);
    motor4.drive(speed);
}

void MoverAtras(int speed) {
    motor1.drive(-speed);
    motor2.drive(-speed);
    motor3.drive(-speed);
    motor4.drive(-speed);
}

void MoverIzquierda(int speed) {
    motor1.drive(speed);
    motor2.drive(-speed);
    motor3.drive(-speed);
    motor4.drive(speed);
}

void MoverDerecha(int speed) {
    motor1.drive(-speed);
    motor2.drive(speed);
    motor3.drive(speed);
    motor4.drive(-speed);
}

// Funciones para movimientos laterales
void MoverLateralIzquierda(int speed) {
    motor1.drive(-speed);
    motor2.drive(speed);
    motor3.drive(-speed);
    motor4.drive(speed);
}

void MoverLateralDerecha(int speed) {
    motor1.drive(speed);
    motor2.drive(-speed);
    motor3.drive(speed);
    motor4.drive(-speed);
}

// Funciones para los sensores ultrasónicos
int CalcularDistancia(int Trig, int Echo) {
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);
    long duration = pulseIn(Echo, HIGH);
    int distance = duration * 0.034 / 2;
    return distance;
}

// Función para leer sensores infrarrojos
void Leer_Sensores_ir(void) {
    for (int i = 0; i <= 15; i++) {
        digitalWrite(S0, i & 0x01);
        digitalWrite(S1, i & 0x02);
        digitalWrite(S2, i & 0x04);
        digitalWrite(S3, i & 0x08);
        int sensorValor = analogRead(ANALOG_IN);
        Serial.print(sensorValor);
        Serial.print("  ");
    }
    Serial.println();
}

#endif
