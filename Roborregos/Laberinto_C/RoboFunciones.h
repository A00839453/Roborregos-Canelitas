#ifndef ROBOFUNCIONES_H
#define ROBOFUNCIONES_H

#include "RoboVariables.h"
#include <math.h> // Para cálculos trigonométricos

extern MPU6050 gyroscope;

// Función para detener los motores
void DetenerMotores() {
    motor3.drive(0);
    motor4.drive(0);
}

// Función para mover el robot hacia atrás
void MoverAtras(int speed) {
    motor3.drive(-speed); // Motor izquierdo en reversa
    motor4.drive(-speed); // Motor derecho en reversa
}

// Función para mover hacia atrás hasta que comience a subir el sube y baja
void moverHastaSubeYBaja() {
    const int threshold = 2; // Umbral mínimo de inclinación para detectar que el robot ha empezado a subir

    while (true) {
        int16_t ax, ay, az;
        gyroscope.getAcceleration(&ax, &ay, &az);
        int angulo_inclinacion = atan2(ay, az) * 180 / PI; // Calcula el ángulo de inclinación

        // Detecta si el robot ya ha comenzado a subir
        if (abs(angulo_inclinacion) > threshold) {
            DetenerMotores();
            Serial.println("Robot comenzó a subir el sube y baja.");
            break; // Detiene el movimiento hacia atrás y sale del loop
        } else {
            MoverAtras(NormalSpeed); // Continúa moviéndose hacia atrás
        }
    }
}

// Función para mover hacia atrás y detenerse en el centro del sube y baja
void moverAtrasConEquilibrio() {
    const int equilibrio_tolerancia = 5; // Tolerancia para considerar equilibrio
    const int tiempo_equilibrio = 5000; // Tiempo en ms para detenerse en equilibrio (5 segundos)
    const int angulo_objetivo = 0; // Ángulo de equilibrio objetivo
    unsigned long tiempo_inicio_equilibrio = 0;
    bool en_equilibrio = false;

    while (true) {
        int16_t ax, ay, az;
        gyroscope.getAcceleration(&ax, &ay, &az);
        int angulo_inclinacion = atan2(ay, az) * 180 / PI; // Calcula el ángulo de inclinación

        // Ajuste para considerar que el ángulo inicial es de 22 grados
        int angulo_relativo = angulo_inclinacion - 22;

        // Condición de equilibrio en torno al ángulo objetivo
        if (abs(angulo_relativo - angulo_objetivo) <= equilibrio_tolerancia) {
            if (!en_equilibrio) {
                tiempo_inicio_equilibrio = millis(); // Inicia el conteo para el equilibrio
                en_equilibrio = true;
            } else if (millis() - tiempo_inicio_equilibrio >= tiempo_equilibrio) {
                DetenerMotores();
                Serial.println("Robot en equilibrio y detenido.");
                break; // Sale del loop después de cumplir el tiempo
            }
        } else {
            en_equilibrio = false;
            MoverAtras(NormalSpeed); // Continúa moviéndose hacia atrás hasta alcanzar el equilibrio
        }
    }
}

#endif
