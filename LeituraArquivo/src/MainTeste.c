#include "../headers/FunctionsArquivo.h"
#include "../../Cores/cores.h"

//FuncoesArquivo

int main(void){
    MATRIZTABULEIRO Ptr;
    ReceberArquivo("ArquivosTexto/ExemploDoc.txt",&Ptr);
    for (int i = 0; i < Ptr.lineMatriz; i++) {
        for(int j = 0;j< Ptr.collunMatriz;j++){
            printf("%s %s %c %s", B_WHITE, CYAN, Ptr.MatrizJogo[i][j], RESET);
        }
        printf("\n");
    }
    return 0;
}
