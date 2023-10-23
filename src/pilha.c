#include "../Headers/pilha.h"

void initialize(PilhaCoordenadas* ptr) {
    ptr->topo = NULL;
}

int isEmpty(PilhaCoordenadas* ptr) {
    return ptr->topo == NULL;
}

void push(PilhaCoordenadas* ptr, int ptrLine, int ptrCollun) {
    Coordenadas* PtrVar = (Coordenadas*)malloc(sizeof(Coordenadas));
    if (PtrVar == NULL) {
        printf("\n\t%sOcorreu um erro na alocação de memória.%s\n", B_RED, RESET);
        return;
    }
    PtrVar->line = ptrLine;
    PtrVar->collun = ptrCollun;
    PtrVar->QuantidadeElementos = (ptr->topo != NULL) ? (ptr->topo->QuantidadeElementos + 1) : 1;
    PtrVar->next = ptr->topo;
    ptr->topo = PtrVar;
}

void pop(PilhaCoordenadas* ptr) {
    if (isEmpty(ptr)) {
        return;
    }
    Coordenadas* PtrVar = ptr->topo;
    PtrVar->QuantidadeElementos -= 1;
    ptr->topo = PtrVar->next;
    free(PtrVar);
}

void ApresentarCoordenadas(PilhaCoordenadas* ptr) {
    if (isEmpty(ptr)) {
        printf("\n\t%sPilha vazia%s\n", RED, RESET);
    } else {
        Coordenadas* PtrVar = ptr->topo;
        printf("\n\t%sCaminho: %s\n\t", CYAN, RESET);
        while (PtrVar != NULL) {
            printf("%s[%s%d%s|%s%d%s]%s ", GREEN, YELLOW, PtrVar->line, GREEN, YELLOW, PtrVar->collun, GREEN, RESET);
            PtrVar = PtrVar->next;
        }
        printf("\n");
    }
}

void LiberarPilha(PilhaCoordenadas* ptr) {
    while (!isEmpty(ptr)) {
        pop(ptr);
    }
}

void initializeFilaPilhas(FilaPilhas* fila) {
    fila->front = NULL;
    fila->rear = NULL;
}

int isEmptyFilaPilhas(FilaPilhas* fila) {
    return fila->front == NULL;
}

int pilhaEqual(PilhaCoordenadas* pilha1, PilhaCoordenadas* pilha2) {
    if (pilha1->topo->QuantidadeElementos != pilha2->topo->QuantidadeElementos) {
        return 0;
    }

    Coordenadas* temp1 = pilha1->topo;
    Coordenadas* temp2 = pilha2->topo;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->line != temp2->line || temp1->collun != temp2->collun) {
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 1;
}

void InserirFilaPilhas(FilaPilhas* fila, PilhaCoordenadas* pilha) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) {
        printf("\n\t%sErro: Memória insuficiente%s\n", B_RED, RESET);
        return;
    }

    PilhaCoordenadas* novaPilha = (PilhaCoordenadas*)malloc(sizeof(PilhaCoordenadas));
    if (novaPilha == NULL) {
        printf("\n\t%sErro: Memória insuficiente%s\n", B_RED, RESET);
        free(novoNode);
        return;
    }

    initialize(novaPilha);

    Coordenadas* temp = pilha->topo;
    while (temp != NULL) {
        push(novaPilha, temp->line, temp->collun);
        temp = temp->next;
    }

    novoNode->pilha = *novaPilha;
    novoNode->next = NULL;

    if (isEmptyFilaPilhas(fila)) {
        fila->front = novoNode;
        fila->rear = novoNode;
    } else {
        Node* temp2 = fila->front;
        while (temp2 != NULL) {
            if (pilhaEqual(&(temp2->pilha), pilha)) {
                free(novoNode);
                return;
            }
            temp2 = temp2->next;
        }
        fila->rear->next = novoNode;
        fila->rear = novoNode;
    }
}

void RetirarFilaPilhas(FilaPilhas* fila) {
    if (!isEmptyFilaPilhas(fila)) {
        Node* temp = fila->front;
        fila->front = fila->front->next;
        free(temp);
    }
}

void imprimirFilaPilhas(FilaPilhas* fila) {
    Node* temp = fila->front;
    while (temp != NULL) {
        ApresentarCoordenadas(&(temp->pilha));
        temp = temp->next;
    }
}

void pilhaComMenorQtd(FilaPilhas* fila) {
    if (isEmptyFilaPilhas(fila)) {
        printf("\n\t%sFila vazia.%s\n\t", RED, RESET);
        return;
    }

    Node* temp = fila->front;
    PilhaCoordenadas* menorPilha = &(temp->pilha);
    temp = temp->next;

    while (temp != NULL) {
        if (temp->pilha.topo->QuantidadeElementos < menorPilha->topo->QuantidadeElementos) {
            menorPilha = &(temp->pilha);
        }
        temp = temp->next;
    }

    if (menorPilha != NULL) {
        printf("\n\t%sMenor caminho encontrado:%s\n", GREEN, RESET);
        ApresentarCoordenadas(menorPilha);
    }
}

void liberarFilaPilhas(FilaPilhas* fila) {
    while (!isEmptyFilaPilhas(fila)) {
        PilhaCoordenadas* pilhaParaLiberar = &(fila->front->pilha);
        LiberarPilha(pilhaParaLiberar);
        RetirarFilaPilhas(fila);
    }
}
