#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../Headers/cores.h"

typedef struct{

    int mat_LINHAS, mat_COLUNAS, mat_CHAVES, mat_tesouroX, mat_tesouroY;
    char **mat_CONTEUDO;
    
    char **solucao;
    int qtdRotas;

}TIPO_MATRIZ;

TIPO_MATRIZ criaMatriz(int linhas, int colunas);

TIPO_MATRIZ lerMatrizArquivo(const char *arqEntrada);

void imprimeMatriz(TIPO_MATRIZ matriz);

void freeMatriz(TIPO_MATRIZ matriz);


