#ifndef MAQUINA_TRACYECTORIA_H
#define MAQUINA_TRACYECTORIA_H

#include "Arduino.h"

enum Estado_tr {
  INICIO,
  ESTADO_1,
  ESTADO_2,
  ESTADO_3
};
extern unsigned long tiempo;
extern unsigned long tiempo2;

void ejecucionTrayectoria(bool,bool);
#endif