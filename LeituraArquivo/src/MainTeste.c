#include "../headers/FunctionsArquivo.h"
//FuncoesArquivo

int main(void){
    MATRIZTABULEIRO Ptr;
    ReceberArquivo("ArquivosTexto/ExemploDoc.txt",&Ptr);
    for (int i = 0; i < Ptr.lineMatriz; i++) {
        for(int j = 0;j< Ptr.collunMatriz;j++){
            printf("%c ",Ptr.MatrizJogo[i][j]);
        }
        printf("\n");
    }
    return 0;
}
