#include "../Headers/lerArquivo.h"

typedef struct MatrizJogador{

    int JogadorX,JogadorY;
    //Posição atual do jogador

    //Representa as direções possíveis,0 como caminho válido e 1 como inválido.
    //No Backtraking fazer o algoritmo seguir apenas uma das direções válidas,caso for um caminho possível
    //até o baú, registrar na pilha
    int Esquerda,Direita,Cima,Baixo;
    //A matriz Jogador
    char **JogadorMatriz;
}MatrizJogador;

typedef struct Jogador{
    //Chaves coletadas, inicia com 0
    //Dimensões da matriz jogador
    int ChavesColetadas,TamanhoJogadorX,TamanhoJogadorY;
    //Interação com a struct MatrizJogador
    MatrizJogador *PtrJ;
}Jogador;

void inicializarJogador(Jogador *Ptr,TIPO_MATRIZ *Var_TipoMatriz);
