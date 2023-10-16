//#include "Headers/lerArquivo.h"
#include "Headers/jogador.h"
//#include "Headers/auxiliares.h"

int main(){

    Jogador PtrJogador;
    PilhaCoordenadas PtrPilha;
    PilhaCoordenadas PtrPilhaChaves;
    TIPO_MATRIZ matrix = lerMatrizArquivo("ArquivosTeste/ExemploDoc.txt");

    imprimeMatriz(matrix);

    inicializarJogador(&PtrJogador,matrix);
    Movimentar(&PtrJogador,&matrix,&PtrPilha,&PtrPilhaChaves);
    printf("[Caminhos Encontrados: %d] \n",matrix.qtdRotas);

    //menu();

    return 0;
}
