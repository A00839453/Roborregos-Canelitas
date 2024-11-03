#include <SparkFun_TB6612.h>

// Pines del Puente H1
#define AIN1 25
#define AIN2 24
#define BIN1 22
#define BIN2 23
#define PWMA 12
#define PWMB 13
#define STBY 255  // No se usa en esta configuración, ya que STBY está conectado a VCC

// Pines del Puente H2
#define AIN1_H2 7
#define AIN2_H2 8
#define BIN1_H2 10
#define BIN2_H2 11
#define PWMA_H2 6
#define PWMB_H2 9

const int offsetA = 1;
const int offsetB = 1;

// Configuración de los motores
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);
Motor motor3 = Motor(AIN1_H2, AIN2_H2, PWMA_H2, offsetA, STBY);
Motor motor4 = Motor(BIN1_H2, BIN2_H2, PWMB_H2, offsetB, STBY);

void setup() {
    Serial.begin(9600);  // Inicializar el monitor serial para depuración

    // Ambos motores comienzan a velocidad máxima
    motor1.drive(255); // Motor 1 a máxima velocidad
    motor2.drive(255); // Motor 2 a máxima velocidad
    motor3.drive(255); // Motor 3 a máxima velocidad
    motor4.drive(255); // Motor 4 a máxima velocidad
    delay(2000);  // Mantener la velocidad máxima durante 2 segundos
}

void loop() {
    // Bucle para disminuir la velocidad gradualmente
    for (int speed = 255; speed >= 0; speed--) {
        motor1.drive(speed);  // Reduce la velocidad del motor 1
        motor2.drive(speed);  // Reduce la velocidad del motor 2
        motor3.drive(speed);  // Reduce la velocidad del motor 3
        motor4.drive(speed);  // Reduce la velocidad del motor 4
        delay(50);            // Pausa para ver la reducción de velocidad gradualmente
    }

    delay(1000);  // Pausa de 1 segundo antes de reiniciar el ciclo de nuevo

    // Aumentar nuevamente la velocidad
    for (int speed = 0; speed <= 255; speed++) {
        motor1.drive(speed);  // Aumenta la velocidad del motor 1
        motor2.drive(speed);  // Aumenta la velocidad del motor 2
        motor3.drive(speed);  // Aumenta la velocidad del motor 3
        motor4.drive(speed);  // Aumenta la velocidad del motor 4
        delay(50);            // Pausa para ver el aumento de velocidad gradualmente
    }

    delay(1000);  // Pausa antes de repetir el ciclo
}