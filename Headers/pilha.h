#include "../Headers/CaminhoRamificado.h"

typedef struct Coordenadas {
    int line, collun;
    int QuantidadeElementos;
    struct Coordenadas* next;
} Coordenadas;

typedef struct PilhaCoordenadas {
    //int qtd;
    Coordenadas* topo;
} PilhaCoordenadas;
//FILA DE Pilhas
typedef struct Node {
    PilhaCoordenadas pilha;
    struct Node* next;
} Node;

typedef struct FilaPilhas {
    Node* front;
    Node* rear;
} FilaPilhas;

void initialize(PilhaCoordenadas* ptr);
int isEmpty(PilhaCoordenadas* ptr);
void push(PilhaCoordenadas* ptr, int ptrLine, int ptrCollun);
void pop(PilhaCoordenadas* ptr);
void ApresentarCoordenadas(PilhaCoordenadas* ptr);
void LiberarPilha(PilhaCoordenadas* ptr);

void initializeFilaPilhas(FilaPilhas* fila);
int isEmptyFilaPilhas(FilaPilhas* fila);
int pilhaEqual(PilhaCoordenadas* pilha1, PilhaCoordenadas* pilha2);
void InserirFilaPilhas(FilaPilhas* fila, PilhaCoordenadas* pilha);
void RetirarFilaPilhas(FilaPilhas* fila);
void imprimirFilaPilhas(FilaPilhas* fila);
void pilhaComMenorQtd(FilaPilhas* fila);
void liberarFilaPilhas(FilaPilhas* fila);