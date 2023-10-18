#include "../Headers/CaminhoRamificado.h"


void inicializarRamificacao(PilhaRamificado *ptr){
    ptr->topo = NULL;
}
int estaVazioRamificacao(PilhaRamificado *ptr){
    return ptr->topo==NULL;
}
void pushRamificacao(PilhaRamificado *ptr, int line, int collun) {
    CaminhoRamificado *PTRVAR = (CaminhoRamificado *)malloc(sizeof(CaminhoRamificado));
    if (PTRVAR == NULL) {
        printf("Ocorreu um erro na alocação de memória.\n");
        return;
    }

    CaminhoRamificado *PtrVar = ptr->topo;
    while (PtrVar != NULL) {
        if (PtrVar->Ramificado_Linha == line && PtrVar->Ramificado_Coluna == collun) {
            free(PTRVAR); // Liberar memória alocada se já existir na pilha
            return;
        }
        PtrVar = PtrVar->prox;
    }

    PTRVAR->Ramificado_Linha = line;
    PTRVAR->Ramificado_Coluna = collun;
    PTRVAR->RamificadoBaixo = -1;
    PTRVAR->RamificadoCima = -1;
    PTRVAR->RamificadoDireita = -1;
    PTRVAR->RamificadoEsquerda = -1;
    PTRVAR->prox = ptr->topo;
    ptr->topo = PTRVAR;
}

void popRamificacao(PilhaRamificado *ptr){
    if(estaVazioRamificacao(ptr)){
        return;
    }
    CaminhoRamificado *PTRVAR = ptr->topo;
    ptr->topo = PTRVAR->prox;
    free(PTRVAR);
}
void ApresentarRamificacao(PilhaRamificado *ptr){
    if(estaVazioRamificacao(ptr)){
        return;
    }else{
        CaminhoRamificado *PtrVar = ptr->topo;
        printf("Ramificacoes: ");
        while(PtrVar!=NULL){
            printf(" [%d|%d] ", PtrVar->Ramificado_Linha, PtrVar->Ramificado_Coluna);
             PtrVar = PtrVar->prox;
        }
        printf("\n");
    }

}

int EstaPresentePilhaRamificado(PilhaRamificado *ptr, int line, int collun) {
    CaminhoRamificado *temp = ptr->topo;

    // Percorre a pilha e compara as coordenadas
    while (temp != NULL) {
        if (temp->Ramificado_Linha == line && temp->Ramificado_Coluna == collun) {
            printf("Elemento (%d, %d) encontrado na pilha.\n", line, collun);
            return 1;
        }
        temp = temp->prox;
    }

    printf("Elemento (%d, %d) nao encontrado na pilha.\n", line, collun);
    return 0;
}

void LiberarRamificacao(PilhaRamificado *ptr);