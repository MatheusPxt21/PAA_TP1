#include "C:\Users\mathe\Documents\CC++\C\Proprios\Trabalhos_PAA\TP1\.h\FunctionsArquivo.h"
#include <stdbool.h>
typedef struct JOGADOR{
    int ChavesColetadas,JogadorCollun,JogadorLine,PercursoJogadorLine,PercursoJogadorCollun;
    char **PercursoJogador;
}JOGADOR;

void InicializaJogador(JOGADOR *PtrJogador,MATRIZTABULEIRO *PtrTabuleiro);
void movimentar(JOGADOR *PtrJogador,MATRIZTABULEIRO *PtrTabuleiro);
void backtraking(int *i,int *j,JOGADOR *PtrJogador,MATRIZTABULEIRO *PtrTabuleiro);
int Direita(int i,int j,JOGADOR *PtrJogador);
int Esquerda(int i,int j,JOGADOR *PtrJogador);
int Cima(int i,int j,JOGADOR *PtrJogador);
int Baixo(int i,int j,JOGADOR *PtrJogador);
int Retornar(int i,int j,JOGADOR *PtrJogador);
int SemCaminho(int i,int j,JOGADOR *PtrJogador);
