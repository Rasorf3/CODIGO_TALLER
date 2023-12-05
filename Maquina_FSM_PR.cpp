bool pelota, anomalia, recepcion_trayectoria, Maquina_Tracyectoria;
int estado = 0;

#define ledR 5
#define ledG 18
#define ledB 19

void MaquinaFSM(bool pelota, bool anomalia, bool recepcion_trayectoria, bool Maquina_Tracyectoria) {

    switch (estado) {
    case 0:
        Serial.println("Estado: Recepcion de trayectoria");

        if (recepcion_trayectoria == true) {
            anomalia = false;
            estado = 1;
        }
        else (recepcion_trayectoria == false); {
            anomalia = true;
            estado = 3;
            digitalWrite(ledR, 0);
            digitalWrite(ledG, 1);
            digitalWrite(ledB, 0);

        }
        break;

    case 1:
        Serial.println("Estado: Pelota");

        if (pelota == true, anomalia == false) {
            estado = 2;
            digitalWrite(ledR, 0);
            digitalWrite(ledG, 1);
            digitalWrite(ledB, 0);
        }
        else {

            estado = 3;
            digitalWrite(ledR, 1);
            digitalWrite(ledG, 0);
            digitalWrite(ledB, 0);
        }
        break;

    case 2:
        Serial.println("Estado: Ejecucion de trayectoria");

        if (Maquina_Tracyectoria == false) {
            estado = 3;
        }
        else {
            // Realizar la ejecución de trayectoria aquí
            // Por ejemplo:
            digitalWrite(ledR, 1);
            delay(1000);
            digitalWrite(ledG, 1);
            delay(1000);
            digitalWrite(ledB, 1);
            delay(1000);
            digitalWrite(ledR, 0);
            digitalWrite(ledG, 0);
            digitalWrite(ledB, 0);
            estado = 0; // Cambio al estado inicial después de la ejecución
        }
        break;
        Serial.println("Estado: Ejecucion de trayectoria finalizada");
        estado = 2;

    case 3:
        Serial.println("Estado: Alerta de anomalía");
        // Lógica para manejar la alerta de anomalía...
        if (anomalia == true) {
            if (recepcion_trayectoria == false) {
                anomalia = true;
                if (recepcion_trayectoria == true) {
                    anomalia = false;
                    estado = 0;
                    digitalWrite(ledR, 1);
                    digitalWrite(ledG, 0);
                    digitalWrite(ledB, 0);
                }
                if (pelota == false) {
                    anomalia = true;
                    if (pelota == true) {
                        anomalia = false;
                        estado = 0;
                        digitalWrite(ledR, 1);
                        digitalWrite(ledG, 0);
                        digitalWrite(ledB, 0);
                    }
                    estado = 0;
                    if (Maquina_Tracyectoria == false) {
                        estado = 1;
                        estado = 0; // Se reinicia al estado inicial después de la alerta de anomalía
                        break;

    default:
        break;
                    }
                }
            }
        }
    }
}