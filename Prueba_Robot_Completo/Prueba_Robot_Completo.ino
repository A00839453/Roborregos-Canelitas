#include "RoboVariables.h"
#include "RoboFunciones.h"

//Codigo para probar cada uno de los componentes de nuestro robot.
//Empecé a progamarlo hasta que estuve seguro de que todo funcionaba relativamente normal.
void setup() {
    Serial.begin(9600);
    // Configuración de pines de los sensores ultrasónicos como salida y entrada
    pinMode(Trig1, OUTPUT);
    pinMode(Echo1, INPUT);
    pinMode(Trig2, OUTPUT);
    pinMode(Echo2, INPUT);
    pinMode(Trig3, OUTPUT);
    pinMode(Echo3, INPUT);
    pinMode(Trig4, OUTPUT);
    pinMode(Echo4, INPUT);
    gripperServo.attach(servoPin);  // Conectar el servomotor al pin asignado
    ConfigurarBarraRGB();  // Configura la barra LED RGB
}

void loop() {
    MoverAdelante(255);
    delay(2000);
    MoverAtras(255);
    delay(2000);
    GirarIzquierda(255);
    delay(2000);
    GirarDerecha(100);
    delay(2000);
    /*DesplazarIzquierda(255);
    delay(5000);
    DesplazarDerecha(255);
    delay(2000);
    ProbarUltrasonicos();
    ProbarPinza();
    Leer_Sensores_ir(); // Lee e imprime los valores de los 16 sensores en el monitor serial
    delay(10000);         // Espera medio segundo para la siguiente lectura
    MostrarEspectroRGB();  // Muestra el espectro de colores en la barra*/
}
