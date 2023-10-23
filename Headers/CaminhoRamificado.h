#include "../Headers/lerArquivo.h"

typedef struct CaminhoRamificado{

    int RamificadoEsquerda,RamificadoDireita,RamificadoCima,RamificadoBaixo;
    int Ramificado_Coluna,Ramificado_Linha;
    struct CaminhoRamificado *prox;

}CaminhoRamificado;

typedef struct PilhaRamificado{

    CaminhoRamificado *topo;

}PilhaRamificado;

void inicializarRamificacao(PilhaRamificado *ptr);
int estaVazioRamificacao(PilhaRamificado *ptr);
void pushRamificacao(PilhaRamificado *ptr,int line,int collun);
void popRamificacao(PilhaRamificado *ptr);
int EstaPresentePilhaRamificado(PilhaRamificado *ptr,int line ,int collun);
void ApresentarRamificacao(PilhaRamificado *ptr);
void LiberarRamificacao(PilhaRamificado *ptr);