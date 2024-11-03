#ifndef ROBOFUNCION_H
#define ROBOFUNCION_H

#include "RoboVariables.h"

// Funciones para los motores
void DetenerMotores(){
    motor3.drive(0);
    motor4.drive(0);
}

void MoverAdelante(int speed) {
    motor3.drive(speed); //Izquierdo
    motor4.drive(speed); //Derecho
}

void MoverAtras(int speed) {
    motor3.drive(-speed);
    motor4.drive(-speed);
}

void GirarIzquierda(int speed) {
    motor3.drive(-speed);
    motor4.drive(speed);
}

void GirarDerecha(int speed) {
    motor3.drive(speed);
    motor4.drive(-speed);
}
// Control de la pinza del servomotor
void AbrirPinza() {
    gripperServo.write(120);  // Ángulo de apertura de la pinza
    Serial.println("Pinza abierta");
}

void CerrarPinza() {
    gripperServo.write(0);   // Ángulo de cierre de la pinza
    Serial.println("Pinza cerrada");
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
   // delay(250);
    return distance;
}
#endif
