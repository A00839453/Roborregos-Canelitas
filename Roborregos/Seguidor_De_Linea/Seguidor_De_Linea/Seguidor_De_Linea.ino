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
  //ControlPID();
  MoverAdelante(100);
}
