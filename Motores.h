#ifndef MOTORES_H
#define MOTORES_H

#include "Arduino.h"



//Definicion de pines para LEDS
#define ledR 5
#define ledG 18
#define ledB 19

// Definicion de pines del motor izquierdo
#define motorIzquierdo1  13
#define motorIzquierdo2  12
#define velocidadIzquierdo 14
// Definicion de pines del motor derecho
#define motorDerecho1  27
#define motorDerecho2  26
#define velocidadDerecho 25

void avanzar();

void retroceder();

void girarIzquierda();

void girarDerecha();

void parar();
#endif
