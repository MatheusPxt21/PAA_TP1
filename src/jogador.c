#include "../Headers/jogador.h"

void inicializarJogador(Jogador *Ptr,TIPO_MATRIZ Var_TipoMatriz){
    //Inicia com 0 o número de chaves
    Ptr->ChavesColetadas = 0;
    //Dimensões definidas para a matriz jogador
    //Linhas
    Ptr->TamanhoJogadorX = Var_TipoMatriz.mat_LINHAS;
    //Colunas
    Ptr->TamanhoJogadorY = Var_TipoMatriz.mat_COLUNAS;
    Ptr->PtrJ = (MatrizJogador *)malloc(sizeof(MatrizJogador));
    //Cria a matriz Jogador

    Ptr->PtrJ->ConteudoJogador = (ConteudoJogador **)malloc(Ptr->TamanhoJogadorX * sizeof(ConteudoJogador *));
    for(int i = 0;i<Ptr->TamanhoJogadorX;i++){
        Ptr->PtrJ->ConteudoJogador[i] = (ConteudoJogador *)malloc(Ptr->TamanhoJogadorY * sizeof(ConteudoJogador));
    }
    //Copia o conteúdo
    for(int i = 0;i<Ptr->TamanhoJogadorX;i++){
        for(int j = 0;j<Ptr->TamanhoJogadorY;j++){
            Ptr->PtrJ->ConteudoJogador[i][j].Valor = Var_TipoMatriz.mat_CONTEUDO[i][j];
        }
    }

    //Inicializando a posição inicial do jogador
    Ptr->PtrJ->JogadorX = 0;
    Ptr->PtrJ->JogadorY = 0;

}
void DeterminaDirecoes(Jogador *Ptr,int i,int j){
    if(Ptr->PtrJ->ConteudoJogador[i][j].Valor=='1'){
        Ptr->PtrJ->ConteudoJogador[i][j].Cima = 'I';
        Ptr->PtrJ->ConteudoJogador[i][j].Esquerda = 'I';
        Ptr->PtrJ->ConteudoJogador[i][j].Direita = 'I';
        Ptr->PtrJ->ConteudoJogador[i][j].Baixo = 'I';
    }

    if(i == 0){
        Ptr->PtrJ->ConteudoJogador[i][j].Cima = 'I';
    }

    if(j==0){
        Ptr->PtrJ->ConteudoJogador[i][j].Esquerda = 'I';
    }

    if(j==Ptr->TamanhoJogadorY-1){
        Ptr->PtrJ->ConteudoJogador[i][j].Direita = 'I';
    }

    if(i==Ptr->TamanhoJogadorX-1){
        Ptr->PtrJ->ConteudoJogador[i][j].Baixo = 'I';
    }

    if(i>0 && Ptr->PtrJ->ConteudoJogador[i-1][j].Valor!='1'){
        Ptr->PtrJ->ConteudoJogador[i][j].Cima = 'V';
    }else if(i>0 && Ptr->PtrJ->ConteudoJogador[i-1][j].Valor=='1'){
        Ptr->PtrJ->ConteudoJogador[i][j].Cima = 'I';
    }

    if(j>0 && Ptr->PtrJ->ConteudoJogador[i][j-1].Valor!='1'){
        Ptr->PtrJ->ConteudoJogador[i][j].Esquerda = 'V';
    }else if(j>0 && Ptr->PtrJ->ConteudoJogador[i][j-1].Valor=='1'){
        Ptr->PtrJ->ConteudoJogador[i][j].Esquerda = 'I';
    }

    if(i<Ptr->TamanhoJogadorX-1 && Ptr->PtrJ->ConteudoJogador[i+1][j].Valor!='1'){
        Ptr->PtrJ->ConteudoJogador[i][j].Baixo = 'V';
    }else if(i<Ptr->TamanhoJogadorX-1 && Ptr->PtrJ->ConteudoJogador[i+1][j].Valor=='1'){
        Ptr->PtrJ->ConteudoJogador[i][j].Baixo = 'I';
    }

    if(j<Ptr->TamanhoJogadorY-1 && Ptr->PtrJ->ConteudoJogador[i][j+1].Valor!='1'){
        Ptr->PtrJ->ConteudoJogador[i][j].Direita = 'V';
    }else if(j<Ptr->TamanhoJogadorY-1 && Ptr->PtrJ->ConteudoJogador[i][j+1].Valor=='1'){
        Ptr->PtrJ->ConteudoJogador[i][j].Direita = 'I';
    }
}
