#include "../Headers/lerArquivo.h"

typedef struct Coordenadas {
    int coord_linha, coord_coluna;
}Coordenadas;

typedef struct TIPO_PILHA *ApontadorPilha;

typedef struct TIPO_PILHA {
    Coordenadas posicaoMatriz;
    ApontadorPilha ptrProx;
    int tamPilha;
} TIPO_PILHA;

void inicializa_PILHA(TIPO_PILHA** stack);

int estaVazia_PILHA(TIPO_PILHA** stack);

int empilha_PILHA(TIPO_PILHA** stack, int linha, int coluna);

int desempilha_PILHA(TIPO_PILHA** stack);

void imprimir_PILHA(TIPO_PILHA* stack);

void free_PILHA(TIPO_PILHA *stack);