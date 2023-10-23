#include "../Headers/auxiliares.h"
#include "../Headers/cores.h"

void menu() {
    Jogador PtrJogador;
    PilhaCoordenadas PtrPilha;
    PilhaCoordenadas PtrPilhaChaves;
    PilhaRamificado PtrRamificado;
    TIPO_MATRIZ matrix;
    FilaPilhas filaPilhas;
    int resposta = 0,COLUNA,LINHA;

    char nomeArq[50], arqEntrada[90];

    while (resposta != 3) {
        printf("\n\t %s%s            Indiana Jones             %s", B_YELLOW, GREEN, RESET);
        printf("\n\t+--------------------------------------+");
        printf("\n\t| %s Insira o que deseja fazer: %s         |", YELLOW, RESET);
        printf("\n\t+--------------------------------------+");
        printf("\n\t| %s 1 - Ler arquivo com matriz de jogo %s |", GREEN, RESET);
        printf("\n\t| %s 2 - Criar um novo Labirinto e Jogar %s|", GREEN, RESET);
        printf("\n\t| %s 3 - Sair %s                           |", RED, RESET);
        printf("\n\t+--------------------------------------+");
        printf("\n\t %sInsira sua escolha: \n\t --> %s", YELLOW, RESET);

        scanf("%d", &resposta);

        switch (resposta) {
            case 1:
                printf("%s\tInsira o nome do arquivo que deseja testar: %s\n", YELLOW, RESET);
                printf("%s\t(É necessário que este arquivo se encontre na pasta ArquivosTeste)%s\n\t", YELLOW, RESET);

                scanf("%s", nomeArq);

                snprintf(arqEntrada, sizeof(arqEntrada), "ArquivosTeste/%s", nomeArq);

                matrix = lerMatrizArquivo(arqEntrada);

                inicializarJogador(&PtrJogador, matrix);

                Movimentar(&PtrJogador, &matrix, &PtrPilha, &PtrPilhaChaves, &PtrRamificado,&filaPilhas);

                menu2(matrix, filaPilhas);
                printf("\n\t%sContador Backtracking: %d%s\n", BLUE, PtrJogador.contadorBacktracking, RESET);

                break;

            case 2:
                printf("\t%sDigite o numero de colunas e linhas:\n\t %s", YELLOW, RESET);
                scanf("%d %d",&LINHA,&COLUNA);

                matrix = geraMatrizAleatoria(LINHA,COLUNA);
                imprimeMatriz(matrix);

                inicializarJogador(&PtrJogador, matrix);

                Movimentar(&PtrJogador, &matrix, &PtrPilha, &PtrPilhaChaves, &PtrRamificado,&filaPilhas);

                menu2(matrix, filaPilhas);
                printf("\n\t%sContador Backtracking: %d%s\n", BLUE, PtrJogador.contadorBacktracking, RESET);

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


void menu2(TIPO_MATRIZ matrix, FilaPilhas filaPilhas)
{
    int resposta;

    if (matrix.qtdRotas != 0) {
        printf("\n\t%s+-------------------------------+%s", YELLOW, RESET);
        printf("\n\t%s|%s%s\tTesouro Encontrado!\t%s%s|%s", YELLOW, BOLD,GREEN, BOLD, YELLOW, RESET);
        printf("\n\t%s+-------------------------------+%s", YELLOW, RESET);
        printf("\n\t%s|%s   [Caminhos Encontrados:%s %d%s]   %s|%s", YELLOW,RESET, GREEN, matrix.qtdRotas, RESET, YELLOW, RESET);
        printf("\n\t%s+-------------------------------+%s", YELLOW, RESET);
        printf("\n");
        printf("\n\t%s+----------------------------------------------+%s", YELLOW, RESET);
        printf("\n\t%s|%s           %sQual a saida desejada?%s             %s|%s", YELLOW, CYAN, BOLD, RESET, YELLOW, RESET);
        printf("\n\t%s|%s[1] Apresentar Melhor Caminho                 %s|%s", YELLOW, GREEN, YELLOW, RESET);
        printf("\n\t%s|%s[2] Apresentar Todos os Caminhos Disponiveis  %s|%s", YELLOW, GREEN, YELLOW, RESET);
        printf("\n\t%s+----------------------------------------------+%s", YELLOW, RESET);

        printf("\n\t %sInsira sua escolha: \n\t --> %s", YELLOW, RESET);
        scanf("%d",&resposta);
        if(resposta==1){
            pilhaComMenorQtd(&filaPilhas);
        }else if(resposta==2){
            imprimirFilaPilhas(&filaPilhas);
        }
    } else {
        printf("\n\t%s%sIndiana Jones nao consegue abrir o bau :(%s\n", B_RED, BLACK, RESET);
    }
}