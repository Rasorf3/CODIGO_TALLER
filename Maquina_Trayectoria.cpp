#include "Maquina_Tracyectoria.h"
#include "Motores.h"
Estado_tr estadoActual = INICIO;
//AAAAAA
void ejecucionTrayectoria(bool recepcion, bool anomalia) {
	
	switch (estadoActual) {
	case INICIO:
    
    digitalWrite(ledR, 1);
    digitalWrite(ledG, 0);
    digitalWrite(ledB, 0);
    parar();
    delay(100);
     Serial.println("Estado: INICIO");
    delay(2000);
    if(anomalia == true){
      estadoActual = INICIO;
      recepcion = false;
      parar();
    }
		if (recepcion == true) {
      tiempo2 = millis();
      tiempo = millis();
      
			estadoActual = ESTADO_1;
      
		}
		break;
	case ESTADO_1:
    
    digitalWrite(ledR, 0);
    digitalWrite(ledG, 1);
    digitalWrite(ledB, 0);
    avanzar();
     Serial.println("Estado: ESTADO_1");
    delay(6000);
    parar();
    delay(100);
    /*if((tiempo - tiempo2 >= 100) and (tiempo - tiempo2 < 6000)){
      avanzar();
    }
    if(tiempo - tiempo2 >= 6000 and tiempo - tiempo2 < 8000){
      girarIzquierda();
    }
    if(tiempo - tiempo2 >= 8000 and tiempo - tiempo2 < 14000){
      girarDerecha();
    }
    if(tiempo - tiempo2 >= 14000 and tiempo - tiempo2 < 20000){
      parar();
    }
    if(tiempo - tiempo2 >= 20000){
      estadoActual = ESTADO_1;
      tiempo2 = millis();
    }
    if(anomalia == true){
      estadoActual = INICIO;
      recepcion = false;
    }
    tiempo = millis();*/
    estadoActual = ESTADO_2;
		break;
	case ESTADO_2:
    digitalWrite(ledR, 0);
    digitalWrite(ledG, 0);
    digitalWrite(ledB, 1);
    girarIzquierda();
     Serial.println("Estado: ESTADO_2");
    delay(5000);
    parar();
    delay(100);
		/*if(tiempo - tiempo2 >= 100 and tiempo - tiempo2 < 4000){
      avanzar();
    }
    if(tiempo - tiempo2 >= 4000 and tiempo - tiempo2 < 8000){
      girarIzquierda();
    }
    if(tiempo - tiempo2 >= 8000 and tiempo - tiempo2 < 14000){
      girarDerecha();
    }
    if(tiempo - tiempo2 >= 14000 and tiempo - tiempo2 < 20000){
      parar();
    }
    if(tiempo - tiempo2 >= 20000){
      estadoActual = ESTADO_3;
      tiempo2 = millis();
    }
    if(anomalia == true){
      estadoActual = INICIO;
      recepcion = false;
    }
    tiempo = millis();*/
    estadoActual = ESTADO_3;
		break;
	case ESTADO_3:
		digitalWrite(ledR, 1);
    digitalWrite(ledG, 1);
    digitalWrite(ledB, 0);
    retroceder();
    Serial.println("Estado: ESTADO_3");
    delay(10000);
    parar();
    delay(100);
		/*if(tiempo - tiempo2 >= 100 and tiempo - tiempo2 < 4000){
      avanzar();
    }
    if(tiempo - tiempo2 >= 4000 and tiempo - tiempo2 < 8000){
      girarIzquierda();
    }
    if(tiempo - tiempo2 >= 8000 and tiempo - tiempo2 < 14000){
      girarDerecha();
    }
    if(tiempo - tiempo2 >= 14000 and tiempo - tiempo2 < 20000){
      parar();
    }
    if(tiempo - tiempo2 >= 20000){
      estadoActual = INICIO;
      tiempo2 = millis();
    }
    if(anomalia == true){
      estadoActual = INICIO;
      recepcion = false;
    }
    tiempo = millis();*/
    estadoActual = INICIO;
		break;
	/*case 4:
   
    digitalWrite(ledR, 0);
    digitalWrite(ledG, 1);
    digitalWrite(ledB, 1);
		if(tiempo - tiempo2 >= 100 and tiempo - tiempo2 < 4000){
      avanzar();
    }
    if(tiempo - tiempo2 >= 4000 and tiempo - tiempo2 < 8000){
      girarIzquierda();
    }
    if(tiempo - tiempo2 >= 8000 and tiempo - tiempo2 < 14000){
      girarDerecha();
    }
    if(tiempo - tiempo2 >= 14000 and tiempo - tiempo2 < 20000){
      parar();
    }
    if(tiempo - tiempo2 >= 20000){
      estado = 5;
      tiempo2 = millis();
    }
    if(anomalia == true){
      estado = 0;
      recepcion = false;
    }
    tiempo = millis();
		break;
	case 5:
		digitalWrite(ledR, 1);
    digitalWrite(ledG, 0);
    digitalWrite(ledB, 1);
		if(tiempo - tiempo2 >= 100 and tiempo - tiempo2 < 4000){
      avanzar();
    }
    if(tiempo - tiempo2 >= 4000 and tiempo - tiempo2 < 8000){
      girarIzquierda();
    }
    if(tiempo - tiempo2 >= 8000 and tiempo - tiempo2 < 14000){
      girarDerecha();
    }
    if(tiempo - tiempo2 >= 14000 and tiempo - tiempo2 < 20000){
      parar();
    }
    if(tiempo - tiempo2 >= 20000){
      estado = 0;
      tiempo2 = millis();
      recepcion = false;
    }
    if(anomalia == true){
      estado = 0;
      recepcion = false;
    }
    tiempo = millis();
		break;*/
	}
}