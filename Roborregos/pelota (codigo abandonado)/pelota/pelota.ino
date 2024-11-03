#include "RoboVariables.h"
#include "RoboFuncion.h"
#include <Servo.h>

Servo garra;

const int DISTANCIA_PARED = 15;
const int DISTANCIA_PELOTA = 7;

void setup() {
    Serial.begin(9600);
    garra.attach(Pinza);
    garra.write(40);
    pinMode(Trig1, OUTPUT); 
    pinMode(Echo1, INPUT);
    pinMode(Trig2, OUTPUT);
    pinMode(Echo2, INPUT);
    pinMode(Trig3, OUTPUT);
    pinMode(Echo3, INPUT);
    pinMode(Trig4, OUTPUT);
    pinMode(Echo4, INPUT);
}

void loop() {
    if (leerDistancia(Trig2, Echo2) > DISTANCIA_PARED) {
        MoverAdelante(200);
    } else {
        if (leerDistancia(Trig1, Echo1) > DISTANCIA_PARED) {
            GirarIzquierda(200);
            delay(500);
        } else if (leerDistancia(Trig3, Echo3) > DISTANCIA_PARED) {
            GirarDerecha(200);
            delay(500);
        } else {
            MoverAtras(200);
            delay(500);
        }
    }

    if (analogRead(ANALOG_IN) < DISTANCIA_PELOTA) {
        capturarPelota();
        detenerMovimiento();
    }
}

int leerDistancia(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2;
    return distance;
}

void capturarPelota() {
    Serial.println("Pelota detectada. Capturando...");
    garra.write(160);
}

void detenerMovimiento() {
    MoverAdelante(0);
    MoverDerecha(0);
    MoverIzquierda(0);
    MoverAtras(0);
}
