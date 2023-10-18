#include "../Headers/auxiliares.h"
#include "../Headers/cores.h"

void menu() {
    Jogador PtrJogador;
    PilhaCoordenadas PtrPilha;
    PilhaCoordenadas PtrPilhaChaves;
    PilhaRamificado PtrRamificado;
    TIPO_MATRIZ matrix;
    int resposta = 0,COLUNA,LINHA;

    char nomeArq[20];

    while (resposta != 2) {
        printf("\n\t %s%s            Indiana Jones             %s", B_YELLOW, GREEN, RESET);
        printf("\n\t+--------------------------------------+");
        printf("\n\t| %s Insira o que deseja fazer: %s         |", YELLOW, RESET);
        printf("\n\t+--------------------------------------+");
        printf("\n\t| %s 1 - Ler arquivo com matriz de jogo %s |", GREEN, RESET);
        printf("\n\t| %s 2 - Criar um novo Tabuleiro e Jogar %s |", GREEN, RESET);
        printf("\n\t| %s 3 - Sair %s                           |", RED, RESET);
        printf("\n\t+--------------------------------------+");
        printf("\n\t Insira sua escolha: \n\t --> ");

        scanf("%d", &resposta);

        switch (resposta) {
            case 1:
                printf("Insira o nome do arquivo que deseja testar: \n");
                printf("É necessário que este arquivo se encontre na pasta ArquivosTeste.\n");
                scanf("%s", nomeArq);

                matrix = lerMatrizArquivo(nomeArq);
                inicializarJogador(&PtrJogador, matrix);
                //printf("Caminhos Possiveis: \n");
                Movimentar(&PtrJogador, &matrix, &PtrPilha, &PtrPilhaChaves, &PtrRamificado);

                if (matrix.qtdRotas != 0) {
                    printf("[Caminhos Encontrados: %d]\n", matrix.qtdRotas);
                } else {
                    printf("O Jogador Não Conseguiu Encontrar o Baú!\n");
                }
                break;
            case 2:
                printf("Digite o numero de colunas e linhas: ");
                scanf("%d %d",&LINHA,&COLUNA);
                matrix = geraMatrizAleatoria(LINHA,COLUNA);
                imprimeMatriz(matrix);
                inicializarJogador(&PtrJogador, matrix);
                //printf("Caminhos Possiveis: \n");
                printf("[Caminhos Encontrados: %d]\n", matrix.qtdRotas);
                Movimentar(&PtrJogador, &matrix, &PtrPilha, &PtrPilhaChaves, &PtrRamificado);
                if (matrix.qtdRotas != 0) {
                    printf("[Caminhos Encontrados: %d]\n", matrix.qtdRotas);
                } else {
                    printf("O Jogador Não Conseguiu Encontrar o Baú!\n");
                }

                break;
            case 3:
                printf("\n\t%sSaindo do programa... %s\n\n\n", RED, RESET);
                break;

            default:
                printf("\n\t%sValor desconhecido, tente novamente... %s\n\n\n", YELLOW, RESET);
                break;
        }
    }
}
