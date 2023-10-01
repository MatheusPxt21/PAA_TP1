#include "C:\Users\mathe\Documents\CC++\C\Proprios\Trabalhos_PAA\TP1\.h\FunctionsArquivo.h"
//FuncoesArquivo
int main(void){
    MATRIZTABULEIRO Ptr;
    ReceberArquivo("C:\\Users\\mathe\\Documents\\CC++\\C\\Proprios\\Trabalhos_PAA\\TP1\\ArquivosTexto\\ExemploDoc.txt",&Ptr);
    for (int i = 0; i < Ptr.lineMatriz; i++) {
        for(int j = 0;j< Ptr.collunMatriz;j++){
            printf("%c ",Ptr.MatrizJogo[i][j]);
        }
        printf("\n");
    }
    return 0;
}
