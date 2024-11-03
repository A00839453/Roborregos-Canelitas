#include "RoboFunciones.h"
#include "RoboVariables.h"

//En este codigo solo esta la parte del giroscopio, no hice la otra parte de la pista C
void setup() {
    Serial.begin(9600);
    Wire.begin(); // Inicia la comunicación I2C en pines predeterminados para el Mega (20 y 21)
    gyroscope.initialize(); // Inicializa el giroscopio

    if (gyroscope.testConnection()) { // Verifica la conexión con el giroscopio
        Serial.println("Giroscopio conectado.");
    } else {
        Serial.println("Error al conectar el giroscopio.");
    }

    // Mueve el robot hacia atrás hasta que comience a subir el sube y baja
    moverHastaSubeYBaja();
}

void loop() {
    moverAtrasConEquilibrio(); // Ejecuta la función para moverse atrás y detenerse en el centro
}
