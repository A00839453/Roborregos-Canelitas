//#include <IngenieroMakerSeguidor16sFC.h>
#include <SparkFun_TB6612.h>

//-.- Funciones para los motores -.-
void MoverAdelante(int speed){
    motor1.drive(speed); 
    //motor2.drive(speed); 
    //motor3.drive(speed); 
    //motor4.drive(speed); 
}

void MoverAtras(int speed){
    motor1.drive(-speed); 
    //motor2.drive(-speed); 
    //motor3.drive(-speed); 
    //motor4.drive(-speed); 
}

void MoverIzquierda(int speed){
    motor1.drive(-speed); 
    motor2.drive(-speed); 
    motor3.drive(speed); 
    motor4.drive(speed); 
}

void MoverDerecha(int speed){
    motor1.drive(speed); 
    motor2.drive(speed); 
    motor3.drive(-speed); 
    motor4.drive(-speed); 
}

//-.- Funciones ultrasonico -.-
int CalcularDistancia(int Trig, int Echo){
  digitalWrite(Trig,LOW);
  delayMicroseconds(2);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig,LOW);
  duration = pulseIn(Echo, HIGH);
  distance = duration*0.034/2;
  return distance;
}

//-.- Sensor Infrarojo -.-
void Leer_Sensores_ir(void) {
 for(int i=0; i<=15;i++)  {       //Leo los 16 canales               
    digitalWrite(S0, i&0x01);
    digitalWrite(S1, i&0x02);
    digitalWrite(S2, i&0x04);
    digitalWrite(S3, i&0x08);
    sensorValores[i] = analogRead(ANALOG_IN); //Guardo los valores de los 16 sensores
    
   Serial.print(sensorValores[i]);  //aqui monitoreamos cada una de las 16 lecturas analogicas
   Serial.print("  ");

  }
}