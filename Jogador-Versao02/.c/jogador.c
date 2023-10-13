#include "../Headers/jogador.h"

void inicializarJogador(Jogador *Ptr,TIPO_MATRIZ *Var_TipoMatriz){
    //Inicia com 0 o número de chaves
    Ptr->ChavesColetadas = 0;
    //Dimensões definidas para a matriz jogador
    //Linhas
    Ptr->TamanhoJogadorX = Var_TipoMatriz->mat_LINHAS;
    //Colunas
    Ptr->TamanhoJogadorY = Var_TipoMatriz->mat_COLUNAS;
    //Cria a matriz Jogador
    Ptr->PtrJ->JogadorMatriz = (char**)malloc((Var_TipoMatriz->mat_LINHAS)*sizeof(char*));
    for(int i = 0;i<Var_TipoMatriz->mat_COLUNAS;i++){
        Ptr->PtrJ->JogadorMatriz[i] = (char*)malloc(Var_TipoMatriz->mat_COLUNAS * sizeof(char));
    }
    for(int i = 0;i<Ptr->TamanhoJogadorX;i++){
        for(int j = 0;j<Ptr->TamanhoJogadorY;j++){
            if(i == 0 && j ==0){
                Ptr->PtrJ->JogadorMatriz[i][j] = Var_TipoMatriz->mat_CONTEUDO[i][j];
                //Posição inválida
                Ptr->PtrJ->Cima = 1;
                //Posição inválida
                Ptr->PtrJ->Esquerda = 1;
                //Posições Válidas
                Ptr->PtrJ->Direita = 1;
                Ptr->PtrJ->Baixo = 1;
                //Pensei em fazer isso para cada posição da matriz,representa os caminhos viáveis ainda não explorados,
                //caso encontrar algum beco sem saída,caminho sem chave,etc, a posição é incializada como 1
                //caso contrátrio como 0
            }
        }
    }
    //Inicializando a posição inicial do jogador
    Ptr->PtrJ->JogadorX = 0;
    Ptr->PtrJ->JogadorY = 0;

}
