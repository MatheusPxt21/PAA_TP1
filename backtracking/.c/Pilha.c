#include "C:\Users\mathe\Documents\CC++\C\Proprios\Trabalhos_PAA\TP1\.h\Pilha.h"
void initialize(PilhaCoordenadas* ptr) {
    ptr->topo = NULL;
}

int isEmpty(PilhaCoordenadas* ptr) {
    return ptr->topo == NULL;
}

void push(PilhaCoordenadas* ptr, int ptrLine, int ptrCollun) {
    Coordenadas* PtrVar = (Coordenadas*)malloc(sizeof(Coordenadas));
    if (PtrVar == NULL) {
        printf("Ocorreu um erro na alocação de memória.\n");
        return;
    }
    PtrVar->line = ptrLine;
    PtrVar->collun = ptrCollun;
    PtrVar->next = ptr->topo;
    ptr->topo = PtrVar;
}

void pop(PilhaCoordenadas* ptr) {
    if (isEmpty(ptr)) {
        printf("Erro: Pilha vazia\n");
        return;
    }
    Coordenadas* PtrVar = ptr->topo;
    ptr->topo = PtrVar->next;
    free(PtrVar);
}

void ApresentarCoordenadas(PilhaCoordenadas* ptr) {
    if (isEmpty(ptr)) {
        printf("Pilha vazia\n");
    } else {
        Coordenadas* PtrVar = ptr->topo;
        printf("Coordenadas: ");
        while (PtrVar != NULL) {
            printf("[%d|%d] ", PtrVar->line, PtrVar->collun);
            PtrVar = PtrVar->next;
        }
        printf("\n");
    }
}
