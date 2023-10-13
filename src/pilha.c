#include "../Headers/pilha.h"

void inicializa_PILHA(TIPO_PILHA** stack)
{
    *stack = (TIPO_PILHA*)malloc(sizeof(TIPO_PILHA));
    (*stack)->tamPilha = 0;
    (*stack)->ptrProx = NULL;
}

int estaVazia_PILHA(TIPO_PILHA** stack)
{
    if(stack == NULL) return 1;
    if(*stack == NULL) return 1;
    
    return 0;
}

int empilha_PILHA(TIPO_PILHA** stack, int linha, int coluna)
{

    if(stack == NULL) return 0;

    TIPO_PILHA* cord = (TIPO_PILHA*)malloc(sizeof(TIPO_PILHA));
    if(cord == NULL){
        printf("\n %sErro durante alocacao da pilha %s", B_RED, RESET);
        return 0;
    }

    cord->posicaoMatriz.coord_linha = linha;
    cord->posicaoMatriz.coord_coluna = coluna;
    cord->ptrProx = (*stack);
    cord->tamPilha = (*stack)->tamPilha;

    *stack = cord;
    (*stack)->tamPilha++;

    return 1;
}

int desempilha_PILHA(TIPO_PILHA** stack)
{

    if (isEmpty(stack)) {
        printf("\n %sErro ao remover: Pilha vazia%s \n", B_RED, RESET);
        return 0;
    }

    TIPO_PILHA* cord = (*stack);
    (*stack) = cord->ptrProx;
    free(cord);

    return 1;

}

void imprimir_PILHA(TIPO_PILHA* stack)
{
/*
    
    TIPO_PILHA* cord = stack->posicaoMatriz;
    
    printf("\n %d || %d \n", stack->posicaoMatriz.coord_linha, stack->posicaoMatriz.coord_coluna);
    while(cord != NULL){
        if(cord->posicaoMatriz.coord_linha != 0){
            printf("\n %d || %d \n", cord->posicaoMatriz.coord_linha, cord->posicaoMatriz.coord_coluna);
        }

        cord = cord->ptrProx;
    }
*/
}

void free_PILHA(TIPO_PILHA *stack)
{
    if(stack != NULL){
        free(stack);
    }
}