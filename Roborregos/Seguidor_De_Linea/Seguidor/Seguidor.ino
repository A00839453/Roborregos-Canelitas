#include "RoboVariables.h"
#include "RoboFunciones.h"

void setup() {
    Serial.begin(9600);
    pinMode(SL0, OUTPUT);
    pinMode(SL1, OUTPUT);
    pinMode(SL2, OUTPUT);
    pinMode(SL3, OUTPUT);
}

void loop() {
    int posicionLinea = LeerPosicionLinea(); // Lee la posición de la línea
    const int target = 750;

    if (posicionLinea < target - 50) {
        // Si la línea está a la izquierda, gira a la izquierda
        GirarIzquierda();
    } else if (posicionLinea > target + 50) {
        // Si la línea está a la derecha, gira a la derecha
        GirarDerecha();
    } else {
        // Si está en el centro, avanza en línea recta
        MoverAdelante();
    }
}


