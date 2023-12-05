#include <Arduino.h>
extern Serial*Serial; 
extern void digitalWrite(int pin, int value); 
extern void delay(unsigned long ms); 


bool pelota, anomalia, recepcion_trayectoria, Maquina_Tracyectoria;
int estado = 0;


#define ledR 5
#define ledG 18
#define ledB 19

void setup() {
  pinMode(ledR, OUTPUT); // Configura los pines de los LEDs como salidas
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  Serial.begin(9600); // Inicia la comunicación serial
}

void loop() {
  MaquinaFSM(pelota, anomalia, recepcion_trayectoria, Maquina_Tracyectoria);// Llama a la función de la Máquina de Estado
}

