#include "../Headers/lerArquivo.h"

TIPO_MATRIZ criaMatriz(int linhas, int colunas)
{
    TIPO_MATRIZ matriz;

    matriz.mat_LINHAS = linhas;
    matriz.mat_COLUNAS = colunas;

    matriz.mat_CONTEUDO = (char**)malloc(linhas * sizeof(char*));
    
    for(int i = 0; i < linhas; i++){
        matriz.mat_CONTEUDO[i] = (char*)malloc(colunas * sizeof(char));
    }

    return matriz;
}

TIPO_MATRIZ lerMatrizArquivo(const char *arqEntrada)
{
    FILE *file = fopen(arqEntrada, "r");
    if(file == NULL){
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    int linhas, colunas, qtdChaves;
    int t_X, t_Y;

    fscanf(file, "%d %d", &linhas, &colunas);
    fscanf(file, "%d", &qtdChaves);
    fscanf(file, "%d %d", &t_X, &t_Y);

    TIPO_MATRIZ mat = criaMatriz(linhas, colunas);

    for(int i = 0; i< linhas; i++){
        for(int j = 0; j<colunas; j++){
            char celula;

            do{
                fscanf(file, "%c", &celula);
            }while(celula == ' ' || celula == '\n');

            mat.mat_CONTEUDO[i][j] = celula;
            setbuf(stdin, NULL);
        }
    }

    fclose(file);

    mat.mat_CHAVES = qtdChaves;
    mat.mat_tesouroX = t_X;
    mat.mat_tesouroY = t_Y;
    mat.qtdRotas = 0;

    return mat;
}

TIPO_MATRIZ geraMatrizAleatoria(int linhas, int colunas)
{
    TIPO_MATRIZ mat = criaMatriz(linhas, colunas);

    int totalElementos = linhas * colunas;
    // as chaves não serão mais do que 5% + 1 do total de elementos
    int totalChaves = (int)(totalElementos * 0.05) + 1;
    int contaChaves = 0;

    /*
      define aleatoriamente a linha e coluna para X,
      não podendo ser 0 para não coincidir com a posição inicial
    */
    int Tesouro_Linha = rand()%linhas + 1;
    int Tesouro_Coluna = rand()%colunas + 1;

    int numAleatorio;

    //preencher matriz
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            numAleatorio = rand()%3;

            switch (numAleatorio) {
                case 0:
                    mat.mat_CONTEUDO[i][j] = '0';
                    break;
                case 1:
                    mat.mat_CONTEUDO[i][j] = '1';
                    break;
                case 2:
                    if((contaChaves < totalChaves) && (i != 0 && j != 0)){
                        mat.mat_CONTEUDO[i][j] = 'C';
                        contaChaves++;
                    }else{
                        mat.mat_CONTEUDO[i][j] = '0';
                    }
                    break;
                default:
                    mat.mat_CONTEUDO[i][j] = '1';
                    break;
            }

        }
    }

    //define a posição inicial como válida
    mat.mat_CONTEUDO[0][0] = '0';
    mat.mat_CONTEUDO[Tesouro_Linha][Tesouro_Coluna] = 'X';

    mat.mat_tesouroX = Tesouro_Linha;
    mat.mat_tesouroY = Tesouro_Coluna;
    mat.mat_CHAVES = contaChaves;


    return mat;
}


void imprimeMatriz(TIPO_MATRIZ matriz)
{
    printf("\n\n");
    printf("\t ------------ Matriz Lida -------------\n\n");

    for(int i = 0; i < matriz.mat_LINHAS; i++){
        printf("\t");
        
        for(int j = 0; j < matriz.mat_COLUNAS; j++){
            if(matriz.mat_CONTEUDO[i][j] == '0'){
                printf("[%s%c%s] ", GREEN, matriz.mat_CONTEUDO[i][j], RESET);
            }
            else if(matriz.mat_CONTEUDO[i][j] == '1'){
                printf("[%s%c%s] ", RED, matriz.mat_CONTEUDO[i][j], RESET);
            }
            else if(matriz.mat_CONTEUDO[i][j] == 'C'){
                printf("[%s%s%c%s] ", BOLD, CYAN, matriz.mat_CONTEUDO[i][j], RESET);
            }
            else if(matriz.mat_CONTEUDO[i][j] == 'X'){
                printf("[%s%c%s] ", YELLOW, matriz.mat_CONTEUDO[i][j], RESET);
            }
            
        }
        printf("\n");
    }

    printf("\n\t ---------------------------------------\n");
}

void freeMatriz(TIPO_MATRIZ matriz)
{
    for (int i = 0; i < matriz.mat_LINHAS; i++) {
        free(matriz.mat_CONTEUDO[i]);
    }
    free(matriz.mat_CONTEUDO);
}