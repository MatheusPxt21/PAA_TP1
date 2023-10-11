#include "../../LeituraArquivo/headers/FunctionsArquivo.h"
#include "../headersBacktracking/Pilha.h"

#include <stdbool.h>
typedef struct JOGADOR{
    int ChavesColetadas,JogadorCollun,JogadorLine,PercursoJogadorLine,PercursoJogadorCollun;
    char **PercursoJogador;
}JOGADOR;

void InicializaJogador(JOGADOR *PtrJogador,MATRIZTABULEIRO *PtrTabuleiro);
void movimentar(JOGADOR *PtrJogador,MATRIZTABULEIRO *PtrTabuleiro,PilhaCoordenadas *PtrPilha);
int backtraking(int *control,int *i,int *j,JOGADOR *PtrJogador,MATRIZTABULEIRO *PtrTabuleiro,PilhaCoordenadas *PtrPilha);
int Direita(int i,int j,JOGADOR *PtrJogador);
int Esquerda(int i,int j,JOGADOR *PtrJogador);
int Cima(int i,int j,JOGADOR *PtrJogador);
int Baixo(int i,int j,JOGADOR *PtrJogador);
int Retornar(int i,int j,JOGADOR *PtrJogador);
int SemCaminho(int i,int j,JOGADOR *PtrJogador);

int VoltarDireita(int i,int j,JOGADOR *PtrJogador);
int VoltarEsquerda(int i,int j,JOGADOR *PtrJogador);
int VoltarCima(int i,int j,JOGADOR *PtrJogador);
int VoltarBaixo(int i,int j,JOGADOR *PtrJogador);