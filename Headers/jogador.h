#include "../Headers/pilha.h"

typedef struct ConteudoJogador{

    char Valor;

}ConteudoJogador;

typedef struct MatrizJogador{
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
void Movimentar(Jogador *Ptr,TIPO_MATRIZ *Var_TipoMatriz,PilhaCoordenadas *pilha,PilhaCoordenadas *pilhaChaves,PilhaRamificado *pilhaRamificacao,FilaPilhas *Fila);
int backtracking(Jogador *Ptr,TIPO_MATRIZ *Var_TipoMatriz,int *i,int *j,PilhaCoordenadas *pilhaChaves,PilhaCoordenadas *pilha,int *I_Ramificacao,int *J_Ramificacao,int *control,PilhaRamificado *pilhaRamificacao,FilaPilhas *Fila);
int ExisteRamificacao(Jogador *Ptr,int i,int j);
int EstaPresentePilhaChaves(Jogador *Ptr,PilhaCoordenadas *pilhaChaves,int line,int collun);
int LimparMatriz(Jogador *Ptr,PilhaCoordenadas *pilha,PilhaCoordenadas *pilhachaves,int *I_Ramificacao,int *J_Ramificacao);
void Printar(Jogador *Ptr);

int ExisteDireita(Jogador *Ptr,int i,int j);
int ExisteEsquerda(Jogador *Ptr,int i,int j);
int ExisteBaixo(Jogador *Ptr,int i,int j);
int ExisteCima(Jogador *Ptr,int i,int j);