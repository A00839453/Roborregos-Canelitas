#ifndef ROBOFUNCIONES_H|
#define ROBOFUNCIONES_H

#include "RoboVariables.h"

// Velocidad base moderada
const int VelocidadBase = 70;

// Función para mover el robot en línea recta
void MoverAdelante() {
    motorIzquierdo.drive(VelocidadBase);
    motorDerecho.drive(VelocidadBase);
}

// Gira el robot hacia la izquierda
void GirarIzquierda() {
    motorIzquierdo.drive(VelocidadBase / 2); // Reduce la velocidad en el lado izquierdo
    motorDerecho.drive(VelocidadBase);       // Mantiene la velocidad en el lado derecho
    delay(300); // Tiempo de giro
}

// Gira el robot hacia la derecha
void GirarDerecha() {
    motorIzquierdo.drive(VelocidadBase);     // Mantiene la velocidad en el lado izquierdo
    motorDerecho.drive(VelocidadBase / 2);   // Reduce la velocidad en el lado derecho
    delay(300); // Tiempo de giro
}

// Detiene el robot
void DetenerMotores() {
    motorIzquierdo.drive(0);
    motorDerecho.drive(0);
}

// Simulación de lectura de la posición de la línea
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

// Control PID para seguir la línea
void ControlPID() {
    static int errorPrevio = 0;
    static int integral = 0;
    int posicionLinea = LeerPosicionLinea();

    // Si no detecta la línea, verificar si estamos en una intersección
    if (posicionLinea == -1) {
        int sensoresActivos = 0;
        for (int i = 0; i <= 15; i++) {
            digitalWrite(SL0, i & 0x01);
            digitalWrite(SL1, i & 0x02);
            digitalWrite(SL2, i & 0x04);
            digitalWrite(SL3, i & 0x08);

            int valorSensor = analogRead(OM);
            if (valorSensor < Muestras[i]) {
                sensoresActivos++;
            }
        }
        // Si una gran cantidad de sensores están detectando línea, consideramos que es una intersección
        if (sensoresActivos > 12) { // Ajustado para detectar intersecciones sin detenerse
            MoverAdelante(VelocidadBase); // Avanzar sin detenerse en la intersección
            return;
        }
    }

    // Cálculo del error y ajuste PID
    int error = posicionLinea - Target;
    integral = constrain(integral + error, -1000, 1000); // Limitar la integral acumulada
    int derivada = error - errorPrevio;
    int ajuste = kp * error + ki * integral + kd * derivada;
    errorPrevio = error;

    // Calcular velocidades de los motores
    int velocidadIzquierda = constrain(VelocidadBase + ajuste, -255, 255);
    int velocidadDerecha = constrain(VelocidadBase - ajuste, -255, 255);

    // Asignar velocidades a los motores
    motor1.drive(velocidadIzquierda);
    motor3.drive(velocidadIzquierda);
    motor2.drive(velocidadDerecha);
    motor4.drive(velocidadDerecha);
}

#endif


