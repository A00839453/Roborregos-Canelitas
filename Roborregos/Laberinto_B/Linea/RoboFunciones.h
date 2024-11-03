#ifndef ROBOFUNCION_H
#define ROBOFUNCION_H

#include "RoboVariables.h"

// Funciones para los motores
void DetenerMotores() {
    motor3.drive(0);
    motor4.drive(0);
}

void MoverAdelante(int speed) {
    motor3.drive(speed);
    motor4.drive(speed);
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

// Función para leer sensores infrarrojos en la barra seguidora de línea
void Leer_Sensores_ir() {
    for (int i = 0; i <= 15; i++) {
        digitalWrite(SL0, i & 0x01);
        digitalWrite(SL1, i & 0x02);
        digitalWrite(SL2, i & 0x04);
        digitalWrite(SL3, i & 0x08);
        int sensorValor = analogRead(OM);
        Serial.print("SensorIR:");
        Serial.print(sensorValor);
        Serial.print("  ");
    }
    Serial.println();
}

// Lee la posición de la línea usando un cálculo ponderado de los sensores
int LeerPosicionLinea() {
    int valorPosicion = 0;
    int sumaValores = 0;
    int sumaPonderada = 0;

    for (int i = 0; i <= 15; i++) {
        digitalWrite(SL0, i & 0x01);
        digitalWrite(SL1, i & 0x02);
        digitalWrite(SL2, i & 0x04);
        digitalWrite(SL3, i & 0x08);

        int valorSensor = analogRead(OM);
        if (valorSensor < Muestras[i]) {
            sumaPonderada += i * 100;
            sumaValores++;
        }
    }
    return (sumaValores == 0) ? -1 : sumaPonderada / sumaValores;
}

// Control PID para seguir la línea con compensación de velocidad y memoria de última posición
void ControlPID() {
    static int errorPrevio = 0;
    static int integral = 0;
    static int velocidadIzquierdaPrev = 0;
    static int velocidadDerechaPrev = 0;
    static int ultimaPosicionValida = Target; // Memoria de última posición válida

    int posicionLinea = LeerPosicionLinea();

    // Si no detecta la línea, usa la última posición válida para guiarlo
    if (posicionLinea == -1) {
        posicionLinea = ultimaPosicionValida;
    } else {
        ultimaPosicionValida = posicionLinea;
    }

    // Cálculo del error y ajuste PID
    int error = posicionLinea - Target;
    integral = constrain(integral + error, -1000, 1000);
    int derivada = error - errorPrevio;
    int ajuste = kp * error + ki * integral + kd * derivada;

    // Zona muerta para reducir el zigzag
    if (abs(error) < 7) ajuste = 0;

    errorPrevio = error;

    // Suavizado de velocidad para motores con compensación del lado derecho
    int velocidadIzquierda = constrain((velocidadIzquierdaPrev * 0.8) + ((VelocidadBase + ajuste) * 0.2), -255, 255);
    int velocidadDerecha = constrain((velocidadDerechaPrev * 0.8) + ((VelocidadBase - ajuste - 3) * 0.2), -255, 255); // Compensación de -3 en el lado derecho (haciendo pruebas se movia un poco mas rapido)

    // Guardar velocidades para la próxima iteración
    velocidadIzquierdaPrev = velocidadIzquierda;
    velocidadDerechaPrev = velocidadDerecha;

    // Asignar velocidades a los motores
    motor3.drive(velocidadIzquierda);
    motor4.drive(velocidadDerecha);
}

#endif
