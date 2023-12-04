#include "Acelerometro.h"

bool deteccionAnomalia(float ace){

  if(ace >= 1){
    return true;
  }
  else{
    return false;
  }
}
void aceleracion(){
  voltajex = 3.3*analogRead(ejex)/1023;
  voltajey = 3.3*analogRead(ejey)/1023;
  voltajez = 3.3*analogRead(ejez)/1023;

  aceleracionx = (voltajex - 1.41)/0.8;
  aceleraciony = (voltajey + 0.28)/0.8;
  aceleracionz = (voltajez + 0.28)/0.8;
}
void velocidad(){
  velocidadx = 0;
  velocidady = 0;
}
void posicion(){
  posicionx = 0;
  posiciony = 0;
}
