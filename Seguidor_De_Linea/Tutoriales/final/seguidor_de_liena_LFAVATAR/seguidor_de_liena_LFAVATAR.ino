#include <IngenieroMakerSeguidor16s.h>
#include <U8g2lib.h>
#include <IngenieroMakerMax.h>
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#define BOTON 4
#define LED 13
#define GO 8
int p = 0;
float KP = .2;
float KI = 2;
float KD = .035;
int VelMax = 50;
int VelFreno=120;
int Target = 750;

int error1 = 0;
int error2 = 0;
int error3 = 0;
int error4 = 0;
int error5 = 0;
int error6 = 0;

unsigned int position = 0;

int proporcional = 0;
int integral = 0;
int derivativo = 0;
int diferencial = 0;
int last_prop = 0;


U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);
//control de motores
IngenieroMakerMax Control;
//mapeo de pines de la barra desensores
barra16 Robot;

void setup()
{
  Serial.begin(9600);
  pinMode(BOTON, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(GO,INPUT);
  calibracion();

}

void loop()
{
if (digitalRead(GO)==HIGH)
{
  Robot.Leer_Sensores_ir(0); //linea negra 0   linea blanca 1
  p = Robot.proporcional();
  pid();
  frenos();
}
if (digitalRead(GO)==LOW)
{
  Control.freno(false,0);
}
}
