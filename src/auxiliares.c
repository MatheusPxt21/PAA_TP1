#include "../Headers/auxiliares.h"
#include "../Headers/cores.h"
#include <string.h>

void menu(){
    int resposta;
    char nomeArq[20];

    while(resposta != 2){
        printf("\n\t %s%s            Indiana Jones             %s",B_YELLOW, GREEN, RESET);
        printf("\n\t+--------------------------------------+");
        printf("\n\t| %s Insira o que deseja fazer: %s         |", YELLOW, RESET);
        printf("\n\t+--------------------------------------+");
        printf("\n\t| %s 1 - Ler arquivo com matriz de jogo %s |", GREEN, RESET);
        printf("\n\t| %s 2 - Sair %s                           |", RED, RESET);
        printf("\n\t+--------------------------------------+");
        printf("\n\t Insira sua escolha: \n\t --> ");
        
        
        scanf("%d", &resposta);

        switch (resposta) {
            
            case 1:
                printf("Insira o nome do arquivo que deseja testar: \n");
                printf("E preciso que este arquivo se encontre na pasta ArquivosTeste.\n");

                scanf("%s", nomeArq);
                
                
            
                break;
            
            case 2:
                printf("\n\t%sSaindo do programa... %s \n\n\n", RED, RESET);
                break;

            default:
                printf("\n\t%sValor desconhecido, tente novamente... %s\n\n\n", YELLOW, RESET);
                break;
        }
    }
}