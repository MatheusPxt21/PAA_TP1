#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Headers/lerArquivo.h"

int main() {

    int linhas = 20; // altere o número de linhas aqui
    int colunas = 20; // altere o número de colunas aqui



    // Inicializar a semente para números aleatórios
    srand(time(NULL));

    TIPO_MATRIZ matriz = geraMatrizAleatoria(linhas, colunas);

    imprimeMatriz(matriz);

    freeMatriz(matriz);

    return 0;
}