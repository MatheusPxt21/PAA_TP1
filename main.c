//#include "Headers/lerArquivo.h"
#include "Headers/jogador.h"
//#include "Headers/auxiliares.h"

int main(){

    Jogador PtrJogador;
    TIPO_PILHA PtrPilha;
    TIPO_MATRIZ matrix = lerMatrizArquivo("ArquivosTeste/Exemplo02.txt");

    imprimeMatriz(matrix);

    inicializarJogador(&PtrJogador,matrix);
    Movimentar(&PtrJogador,matrix,&PtrPilha);

    //menu();

    return 0;
}