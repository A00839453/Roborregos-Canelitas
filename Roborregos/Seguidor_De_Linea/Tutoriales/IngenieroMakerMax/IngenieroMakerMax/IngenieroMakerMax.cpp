#include "Arduino.h"
#include "IngenieroMakerMax.h"

#define pwmIzq 5
#define dirIzq 9
#define pwmDer 3
#define dirDer 6

IngenieroMakerMax::IngenieroMakerMax(){
	pinMode(pwmIzq,OUTPUT);
	pinMode(dirIzq,OUTPUT);
	pinMode(pwmDer,OUTPUT);
	pinMode(dirDer,OUTPUT);
}

void IngenieroMakerMax::motorIzq(int velocidad){
	if(velocidad>0){
		digitalWrite(dirIzq,LOW);
		analogWrite(pwmIzq,velocidad);
	}
	else{
		digitalWrite(dirIzq,HIGH);
		analogWrite(pwmIzq,(-1)*velocidad);	
	}
}

void IngenieroMakerMax::motorDer(int velocidad){
	if(velocidad>0){
		digitalWrite(dirDer,HIGH);
		analogWrite(pwmDer,velocidad);
	}
	else{
		digitalWrite(dirDer,LOW);
		analogWrite(pwmDer,(-1)*velocidad);	
	}
}

void IngenieroMakerMax::motores(int izq, int der){
	motorIzq(izq);
	motorDer(der);
}

void IngenieroMakerMax::freno(boolean sentido, int velocidad){
	if(sentido){
		motorIzq(-velocidad);
		motorDer(velocidad);
	}
	else{
		motorIzq(velocidad);
		motorDer(-velocidad);
	}
}