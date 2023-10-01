#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct MATRIZTABULEIRO{
    int lineMatriz,collunMatriz,lineTesouro,collunTesouro;
    int numeroChaves;
    char **MatrizJogo;
}MATRIZTABULEIRO;

//Recebe o arquivo e pega as informações necessárias para a matriz
void ReceberArquivo(char *FilePath,MATRIZTABULEIRO *PtrTabuleiro);
