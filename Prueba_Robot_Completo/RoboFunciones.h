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

void GirarIzquierda(int speed) {
    motor1.drive(speed);
    motor2.drive(-speed);
    motor3.drive(-speed);
    motor4.drive(speed);
}

void GirarDerecha(int speed) {
    motor1.drive(-speed);
    motor2.drive(speed);
    motor3.drive(speed);
    motor4.drive(-speed);
}

void DesplazarIzquierda(int speed) {
    motor1.drive(-speed);
    motor2.drive(speed);
    motor3.drive(-speed);
    motor4.drive(speed);
}

void DesplazarDerecha(int speed) {
    motor1.drive(speed);
    motor2.drive(-speed);
    motor3.drive(speed);
    motor4.drive(-speed);
}

void DetenerMotores() {
    motor1.drive(0);
    motor2.drive(0);
    motor3.drive(0);
    motor4.drive(0);
}

// Control de la pinza del servomotor
void AbrirPinza() {
    gripperServo.write(150);  // Ángulo de apertura de la pinza
    Serial.println("Pinza abierta");
}

void CerrarPinza() {
    gripperServo.write(30);   // Ángulo de cierre de la pinza
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
    return distance;
}

// Función para probar los cuatro sensores ultrasónicos
void ProbarUltrasonicos() {
    Serial.print("Distancia Ultrasonico Izquierda: ");
    Serial.print(CalcularDistancia(Trig1, Echo1));
    Serial.println(" cm");

    Serial.print("Distancia Ultrasonico Frontal: ");
    Serial.print(CalcularDistancia(Trig2, Echo2));
    Serial.println(" cm");

    Serial.print("Distancia Ultrasonico Derecha: ");
    Serial.print(CalcularDistancia(Trig3, Echo3));
    Serial.println(" cm");

    Serial.print("Distancia Ultrasonico Pinza: ");
    Serial.print(CalcularDistancia(Trig4, Echo4));
    Serial.println(" cm");

    Serial.println("-----------------------------");
    delay(1000); // Pausa para lectura en el monitor serial
}

// Función para probar la apertura y cierre de la pinza en un ciclo
void ProbarPinza() {
    AbrirPinza();
    delay(2000);  // Mantén la pinza abierta por 2 segundos
    CerrarPinza();
    delay(2000);  // Mantén la pinza cerrada por 2 segundos
}


// Función para inicializar la barra LED RGB
void ConfigurarBarraRGB() {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

// Función para recorrer el espectro de colores en la barra RGB
void MostrarEspectroRGB() {
    for (int hue = 0; hue < 255; hue++) {
        for (int i = 0; i < NUM_LEDS; i++) {
            leds[i] = CHSV(hue, 255, 255);  // Cambia el color a través del espectro
        }
        FastLED.show();
        delay(20);  // Ajusta la velocidad del cambio de color
    }
}

// Función para leer sensores infrarrojos en la barra seguidora de línea
void Leer_Sensores_ir(void) {
    for (int i = 0; i <= 15; i++) {
        digitalWrite(SL0, i & 0x01);
        digitalWrite(SL1, i & 0x02);
        digitalWrite(SL2, i & 0x04);
        digitalWrite(SL3, i & 0x08);
        int sensorValor = analogRead(OM); // Usa OM en lugar de ANALOG_IN
        Serial.print(sensorValor);
        Serial.print("  ");
    }
    Serial.println();
}


// Control de la barra LED RGB para efectos de color
void MostrarEfectoRGB() {
    for (int hue = 0; hue < 255; hue++) {
        for (int i = 0; i < NUM_LEDS; i++) {
            leds[i] = CHSV(hue, 255, 255);  // Recorre el espectro de colores
        }
        FastLED.show();
        delay(20);  // Ajusta la velocidad del cambio de color
    }
}

#endif