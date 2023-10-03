#include "C:\Users\mathe\Documents\CC++\C\Proprios\Trabalhos_PAA\TP1\.h\Jogador.h"

void InicializaJogador(JOGADOR *PtrJogador,MATRIZTABULEIRO *PtrTabuleiro){
    PtrJogador->ChavesColetadas = 0;
    PtrJogador->JogadorLine = PtrJogador->JogadorCollun = 0;
    PtrJogador->PercursoJogador = (char **)malloc(PtrTabuleiro->lineMatriz * sizeof(char *));
    for (int i = 0; i < PtrTabuleiro->lineMatriz; i++) {
        PtrJogador->PercursoJogador[i] = (char *)malloc(PtrTabuleiro->collunMatriz * sizeof(char));
    }
    PtrJogador->PercursoJogadorLine = PtrTabuleiro->lineMatriz;
    PtrJogador->PercursoJogadorCollun = PtrTabuleiro->collunMatriz;
    for(int i = 0;i<PtrTabuleiro->lineMatriz;i++){
        for(int j = 0;j<PtrTabuleiro->collunMatriz;j++){
            PtrJogador->PercursoJogador[i][j] = PtrTabuleiro->MatrizJogo[i][j];
        }
    }
}
void movimentar(JOGADOR *PtrJogador,MATRIZTABULEIRO *PtrTabuleiro){
    int line = PtrJogador->JogadorLine;
    int collun = PtrJogador->JogadorCollun;
    backtraking(&line,&collun,PtrJogador,PtrTabuleiro);
}
//Colocar função para verificar se tem apenas uma via,bloqueado por 3 lados
void backtraking(int *i,int *j,JOGADOR *PtrJogador,MATRIZTABULEIRO *PtrTabuleiro){
    for (int x = 0; x < PtrTabuleiro->lineMatriz; x++) {
        for(int y = 0;y< PtrTabuleiro->collunMatriz;y++){
            printf("%c ",PtrJogador->PercursoJogador[x][y]);
        }
        printf("\n");
    }
    do{
        if(PtrJogador->PercursoJogador[(*i)][(*j)] == '0'){
            //printf("Passou Aqui!");
            PtrJogador->PercursoJogador[(*i)][(*j)] = 'V';
            //printf("Passou Aqui!");
        }else if(PtrJogador->PercursoJogador[(*i)][(*j)]== 'C'){
            PtrJogador->ChavesColetadas +=1;
            PtrJogador->PercursoJogador[(*i)][(*j)] = 'V';
        }else if(PtrJogador->PercursoJogador[(*i)][(*j)]=='X') {
            if(PtrJogador->ChavesColetadas==PtrTabuleiro->numeroChaves){
                printf("O jogador encontrou o baú");
                return;
            }else if(PtrJogador->ChavesColetadas!=PtrTabuleiro->numeroChaves){
                printf("O jogador não encontrou o baú\n\n");
                printf("Continue Procurando....\n\n");
            }
        }
        //printf("Passou Aqui!");
        if(Direita((*i),(*j),PtrJogador)){
                    (*j) = (*j) + 1;
                    backtraking(i,j,PtrJogador,PtrTabuleiro);
        }
        if(Cima((*i),(*j),PtrJogador)){
                    (*i) = (*i) -1;
                    backtraking(i,j,PtrJogador,PtrTabuleiro);
        }
        if(Baixo((*i),(*j),PtrJogador)){
                    (*i) = (*i) + 1;
                    backtraking(i,j,PtrJogador,PtrTabuleiro);
        }
        //Representa um caminho Inválido
        if(SemCaminho(*i,*j,PtrJogador)==1){
            PtrJogador->PercursoJogador[*i][*j] = 'I';
            if(Retornar((*i),(*j),PtrJogador)==1){
                (*i) = (*i) -1;
                backtraking(i,j,PtrJogador,PtrTabuleiro);
            }else if(Retornar((*i),(*j),PtrJogador)==2){
                (*j) = (*j) -1;
                backtraking(i,j,PtrJogador,PtrTabuleiro);
            }else if(Retornar((*i),(*j),PtrJogador)==3){
                (*i) = (*i) +1;
                backtraking(i,j,PtrJogador,PtrTabuleiro);
            }else if(Retornar((*i),(*j),PtrJogador)==4){
                (*j) = (*j) +1;
                backtraking(i,j,PtrJogador,PtrTabuleiro);
            }
        }
    } while (Retornar(*i,*j,PtrJogador)!=-1);
    printf("O jogador nao conseguiu encontrar o tesouro\n");
}
int Direita(int i, int j, JOGADOR *PtrJogador){
    if(j<PtrJogador->PercursoJogadorCollun){
        if(PtrJogador->PercursoJogador[i][j + 1] == '0' || PtrJogador->PercursoJogador[i][j + 1] == 'C'){
            return 1;
        }
    }
    return 0;
}

int Esquerda(int i, int j, JOGADOR *PtrJogador){
    if(j > 0){
        if(PtrJogador->PercursoJogador[i][j - 1] == '0' || PtrJogador->PercursoJogador[i][j - 1] == 'C'){
            return 1;
        }
    }
    return 0;
}

int Cima(int i, int j, JOGADOR *PtrJogador){
    if(i>0 && i < PtrJogador->PercursoJogadorLine - 1){
        if(PtrJogador->PercursoJogador[i - 1][j] == '0' || PtrJogador->PercursoJogador[i - 1][j] == 'C'){
            return 1;
        }
    }
    return 0;
}

int Baixo(int i, int j, JOGADOR *PtrJogador){
    if((i < PtrJogador->PercursoJogadorLine - 1 )){
        if(PtrJogador->PercursoJogador[i + 1][j] == '0' || PtrJogador->PercursoJogador[i + 1][j] == 'C'){
            return 1;
        }
    }
    return 0;
}

int Retornar(int i, int j, JOGADOR *PtrJogador){
    if (i > 0 && PtrJogador->PercursoJogador[i-1][j] == 'V') {
        return 1;
    } else if (j > 0 && PtrJogador->PercursoJogador[i][j-1] == 'V') {
        return 2;
    } else if (i < PtrJogador->PercursoJogadorLine - 1 && PtrJogador->PercursoJogador[i+1][j] == 'V') {
        return 3;
    } else if (j < PtrJogador->PercursoJogadorCollun - 1 && PtrJogador->PercursoJogador[i][j+1] == 'V') {
        return 4;
    }
    return -1;
}
int SemCaminho(int i,int j,JOGADOR *PtrJogador){
    if((j<=PtrJogador->PercursoJogadorCollun -1 && i<=PtrJogador->PercursoJogadorLine -1
    &&((PtrJogador->PercursoJogador[i][j+1]=='V' && PtrJogador->PercursoJogador[i][j-1]!='0' &&
    PtrJogador->PercursoJogador[i+1][j]!='0' && PtrJogador->PercursoJogador[i-1][j]!='0' ))
    ||j<=PtrJogador->PercursoJogadorCollun -1 && i<=PtrJogador->PercursoJogadorLine -1
    &&(PtrJogador->PercursoJogador[i][j+1]!='0' && PtrJogador->PercursoJogador[i][j-1]=='V' &&
    PtrJogador->PercursoJogador[i+1][j]!='0' && PtrJogador->PercursoJogador[i-1][j]!='0' )
    ||j<=PtrJogador->PercursoJogadorCollun -1 && i<=PtrJogador->PercursoJogadorLine -1
    &&(PtrJogador->PercursoJogador[i][j+1]!='0' && PtrJogador->PercursoJogador[i][j-1]!='0' &&
    PtrJogador->PercursoJogador[i+1][j]=='V' && PtrJogador->PercursoJogador[i-1][j]!='0' )||
    j<=PtrJogador->PercursoJogadorCollun -1 && i<=PtrJogador->PercursoJogadorLine -1
    &&(PtrJogador->PercursoJogador[i][j+1]!='0' && PtrJogador->PercursoJogador[i][j-1]!='0' &&
    PtrJogador->PercursoJogador[i+1][j]!='0' && PtrJogador->PercursoJogador[i-1][j]=='V' ))){
        return 1;
    }
    return 0;
}
