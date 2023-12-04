//VARIABLES GLOBALES
int numeros[18] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int indice_numeros = 0;
float matrizFinal[10] = { 0,0,0,0,0,0,0,0,0,0 };
String cadena = "";

void multiplicarMatrices(float matrizA[2][2], float matrizB[2][2], float resultado[2][2]) {

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}
void multiplicarMatrizPorVectores(float matriz[2][2], float vectores[5][2], float resultados[], int indice, int longitud) {
    if (indice + 9 < longitud) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 2; j++) {
                int suma = 0;
                for (int k = 0; k < 2; k++) {
                    suma += matriz[j][k] * vectores[i][k];
                }
                resultados[indice] = suma;
                indice++;
            }
        }
    }
}

void matriz_cambio()
{
    float baseB[2][2] = { {numeros[0],numeros[1]},{numeros[2],numeros[3]} };
    int baseN[2][2] = { {numeros[4],numeros[5]},{numeros[6],numeros[7]} };
    float matrizCambio[2][2] = {};
    float matrizInversa[2][2] = { {baseN[0][0], baseN[0][1]}, {baseN[1][0], baseN[1][1]} };
    float inversa[2][2] = { {0,0},{0,0} };
    float determinante = matrizInversa[0][0] * matrizInversa[1][1] - matrizInversa[0][1] * matrizInversa[1][0];
    float vectores[5][2] = { {numeros[8],numeros[9]},{numeros[10],numeros[11]},{numeros[12],numeros[13]},{numeros[14],numeros[15]},{numeros[16],numeros[17]} };
    // Verificar si el determinante es cero
    if (determinante != 0) {
        // Calcular la matriz adjunta
        float adjunta[2][2] = { {matrizInversa[1][1], -matrizInversa[0][1]}, {-matrizInversa[1][0], matrizInversa[0][0]} };
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                inversa[i][j] = adjunta[i][j] / determinante;
            }
        }
    }
    multiplicarMatrices(baseB, inversa, matrizCambio);
    multiplicarMatrizPorVectores(matrizCambio, vectores, matrizFinal, 0, 10);
}
