#include "lerArquivo.h"

typedef struct ConteudoJogador{

    //Representa as direções possíveis, V como caminho válido e I como inválido.
    //No Backtraking fazer o algoritmo seguir apenas uma das direções válidas, caso for um caminho possível
    //até o baú, registrar na pilha
    char Esquerda,Direita,Cima,Baixo;
    char Valor;

}ConteudoJogador;

typedef struct MatrizJogador{

    int JogadorX,JogadorY;
    //Posição atual do jogador
    //A matriz Jogador
    ConteudoJogador **ConteudoJogador;
}MatrizJogador;

typedef struct Jogador{
    //Chaves coletadas, inicia com 0
    //Dimensões da matriz jogador
    int ChavesColetadas,TamanhoJogadorX,TamanhoJogadorY;
    //Interação com a struct MatrizJogador
    MatrizJogador *PtrJ;
}Jogador;

void inicializarJogador(Jogador *Ptr,TIPO_MATRIZ Var_TipoMatriz);
void DeterminaDirecoes(Jogador *Ptr,int i,int j);
//int ExisteBifurcacao(Jogador *Ptr,int i,int j);