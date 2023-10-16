#include "../Headers/pilha.h"

typedef struct ConteudoJogador{

    //Representa as direções possíveis, V como caminho válido e I como inválido.
    //No Backtraking fazer o algoritmo seguir apenas uma das direções válidas, caso for um caminho possível
    //até o baú, registrar na pilha
    int NumeroRamificacoes;
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
void Movimentar(Jogador *Ptr,TIPO_MATRIZ *Var_TipoMatriz,PilhaCoordenadas *pilha,PilhaCoordenadas *pilhaChaves);
int backtracking(Jogador *Ptr,TIPO_MATRIZ *Var_TipoMatriz,int *i,int *j,PilhaCoordenadas *pilhaChaves,PilhaCoordenadas *pilha,int *I_Ramificacao,int *J_Ramificacao,int *control);
void DeterminaDirecoes(Jogador *Ptr,int i,int j);
int ExisteRamificacao(Jogador *Ptr,int i,int j);
int LimparMatrizChaves(Jogador *Ptr,PilhaCoordenadas *pilhaChaves);
int LimparMatriz(Jogador *Ptr,PilhaCoordenadas *pilha,int *I_Ramificacao,int *J_Ramificacao);
void Printar(Jogador *Ptr);
//int ExisteBifurcacao(Jogador *Ptr,int i,int j);