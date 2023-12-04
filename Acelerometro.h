#ifndef ACELEROMETRO_H
#define ACELEROMETRO_H

#include "Arduino.h"

extern float voltajex;
extern float voltajey;
extern float voltajez;

extern float aceleracionx;
extern float aceleraciony;
extern float aceleracionz;

extern float velocidadx;
extern float velocidady;

extern float posicionx;
extern float posiciony;

#define ejex 34
#define ejey 35
#define ejez 36

void aceleracion();
void velocidad();
void posicion();
bool deteccionAnomalia(float);

#endif