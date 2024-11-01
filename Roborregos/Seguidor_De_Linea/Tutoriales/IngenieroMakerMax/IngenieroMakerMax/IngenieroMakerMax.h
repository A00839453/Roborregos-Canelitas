/*
	IngenieroMakerMax - Libreria para control de drivers MAX14870
	diseñada para tarjetas de Ingeniero Maker.
*/
#ifndef IngenieroMakerMax_h
#define IngenieroMakerMax_h

#include "Arduino.h";

class IngenieroMakerMax{
	public:
		IngenieroMakerMax();
		void motorIzq(int velocidad);
		void motorDer(int velocidad);
		void motores(int izq, int der);
		void freno(boolean sentido, int velocidad);
	private:
		int _velocidad;
		boolean _sentido;
		int _izq;
		int _der;
};

#endif
