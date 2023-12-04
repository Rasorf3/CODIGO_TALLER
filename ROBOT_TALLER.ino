#include "Motores.h"
#include "Maquina_Tracyectoria.h"
#include "Acelerometro.h"

//DECLARACION DE DOS TAREAS PARA TENER MULTINUCLEO EN ESTE CASO 2
TaskHandle_t motores;
TaskHandle_t coneccion;


//FUNCIONES EN DONDE VAN A CORRER NUESTRAS TAREAS EN SIMULTANEO
void Motores(void *pvParameters);
void Coneccion(void *pvParameters);

//DECLARACION DE VARIABLES GLOBALES
unsigned long tiempo;
unsigned long tiempo2 = 0;
float voltajex = 0;
float voltajey = 0;
float voltajez = 0;

float aceleracionx = 0;
float aceleraciony = 0;
float aceleracionz = 0;

float velocidadx = 0;
float velocidady = 0;

float posicionx = 0;
float posiciony = 0;
//DECLARACION DE PINES
//Definicion de pines ACELEROMETRO
#define ejex 34
#define ejey 35
#define ejez 36
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

void setup() {
  Serial.begin(9600);
  //DEFINIENDO LA RESOLUCION
  analogReadResolution(10);
  // Crear tareas
  xTaskCreatePinnedToCore(
    Motores,    // Función de la tarea
    "Control_Motores",   // Nombre de la tarea
    10000,     // Tamaño de la pila
    NULL,      // Parámetros de la tarea
    1,         // Prioridad de la tarea
    &motores,    // Manejador de la tarea
    0          // Núcleo (0 o 1)
  );

  xTaskCreatePinnedToCore(
    Coneccion,    // Función de la tarea
    "Bluetooth_Coneccion",   // Nombre de la tarea
    10000,     // Tamaño de la pila
    NULL,      // Parámetros de la tarea
    1,         // Prioridad de la tarea
    &coneccion,    // Manejador de la tarea
    1          // Núcleo (0 o 1)
  );

  //CONFIGURAR LOS PINES EN SALIDAS O ENTRADAS
  //PINES DE MOTOR
  pinMode(motorIzquierdo1,OUTPUT);
  pinMode(motorIzquierdo2,OUTPUT);
  pinMode(motorDerecho1,OUTPUT);
  pinMode(motorDerecho2,OUTPUT);
  pinMode(velocidadIzquierdo,OUTPUT);
  pinMode(velocidadDerecho,OUTPUT);
  //PINES PARA LEDS
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  //PINES PARA ACELEROMETRO
  pinMode(ejex, OUTPUT);
  pinMode(ejey, OUTPUT);
  pinMode(ejez, OUTPUT);

  
}

void loop() { 
}

void Motores(void *pvParameters) { //TAREA DONDE VA A CORRER LA MAQUINA DE TRAYECTORIA CONTROLANDO LOS MOTORES
  (void) pvParameters; // Evitar advertencia de "no utilizado"
  for(;;) {
    ejecucionTrayectoria(true,false);
    //avanzar();
  }
}

void Coneccion(void *pvParameters) { //TAREA DONDE VA A CORRER EL BLUETOOTH
  (void) pvParameters; // Evitar advertencia de "no utilizado"

  for (;;) {
    /*aceleracion();
    velocidad();
    posicion();*/
  }
}
