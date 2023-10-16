//#include "Headers/lerArquivo.h"
#include "Headers/jogador.h"
//#include "Headers/auxiliares.h"

int main(){

    Jogador PtrJogador;
    PilhaCoordenadas PtrPilha;
    PilhaCoordenadas PtrPilhaChaves;
    PilhaRamificado PtrRamificado;
    TIPO_MATRIZ matrix = lerMatrizArquivo("ArquivosTeste/Exemplo02.txt");

    imprimeMatriz(matrix);

    inicializarJogador(&PtrJogador,matrix);
    Movimentar(&PtrJogador,&matrix,&PtrPilha,&PtrPilhaChaves,&PtrRamificado);
    printf("[Caminhos Encontrados: %d] \n",matrix.qtdRotas);

    //menu();

    return 0;
}
