#include "Headers/jogador.h"

int main(){

    Jogador PtrJogador;
    PilhaCoordenadas PtrPilha;
    PilhaCoordenadas PtrPilhaChaves;
    PilhaRamificado PtrRamificado;
    TIPO_MATRIZ matrix = lerMatrizArquivo("ArquivosTeste/ExemploDOC.txt");

    imprimeMatriz(matrix);

    inicializarJogador(&PtrJogador,matrix);
    Movimentar(&PtrJogador,&matrix,&PtrPilha,&PtrPilhaChaves,&PtrRamificado);
    if(matrix.qtdRotas!=0){
        printf("[Caminhos Encontrados: %d] \n",matrix.qtdRotas);
    }else{
        printf("O Jogador Nao Conseguiu Encontrar o Bau!\n");
    }


    //menu();

    return 0;
}
