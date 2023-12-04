#include "Motores.h"

void avanzar() {
  analogWrite(velocidadIzquierdo,255);
  analogWrite(velocidadDerecho,255);
	digitalWrite(motorIzquierdo1, 1);
	digitalWrite(motorIzquierdo2, 0);
	digitalWrite(motorDerecho1, 1);
	digitalWrite(motorDerecho2, 0);
}

void retroceder() {
  analogWrite(velocidadIzquierdo,255);
  analogWrite(velocidadDerecho,255);
	digitalWrite(motorIzquierdo1, 0);
	digitalWrite(motorIzquierdo2, 1);
	digitalWrite(motorDerecho1, 0);
	digitalWrite(motorDerecho2, 1);
}

void girarIzquierda() {
  analogWrite(velocidadIzquierdo,255);
  analogWrite(velocidadDerecho,255);
	digitalWrite(motorIzquierdo1, 0);
	digitalWrite(motorIzquierdo2, 1);
	digitalWrite(motorDerecho1, 1);
	digitalWrite(motorDerecho2, 0);
}

void girarDerecha() {
  analogWrite(velocidadIzquierdo,255);
  analogWrite(velocidadDerecho,255);
	digitalWrite(motorIzquierdo1, 1);
	digitalWrite(motorIzquierdo2, 0);
	digitalWrite(motorDerecho1, 0);
	digitalWrite(motorDerecho2, 1);
}

void parar(){
  analogWrite(velocidadIzquierdo,0);
  analogWrite(velocidadDerecho,0);
	digitalWrite(motorIzquierdo1, 0);
	digitalWrite(motorIzquierdo2, 0);
	digitalWrite(motorDerecho1, 0);
	digitalWrite(motorDerecho2, 0); 
};