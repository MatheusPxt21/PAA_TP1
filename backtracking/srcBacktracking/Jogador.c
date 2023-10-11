#include "../headersBacktracking/Jogador.h"

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
void movimentar(JOGADOR *PtrJogador,MATRIZTABULEIRO *PtrTabuleiro, PilhaCoordenadas *PtrPilha){
    int line = PtrJogador->JogadorLine;
    int collun = PtrJogador->JogadorCollun;
    initialize(PtrPilha);
    backtraking(&line,&collun,PtrJogador,PtrTabuleiro,PtrPilha);
}
//Colocar função para verificar se tem apenas uma via,bloqueado por 3 lados
int backtraking(int *i,int *j,JOGADOR *PtrJogador,MATRIZTABULEIRO *PtrTabuleiro,PilhaCoordenadas *PtrPilha){
    //for (int x = 0; x < PtrTabuleiro->lineMatriz; x++) {
        //for(int y = 0;y< PtrTabuleiro->collunMatriz;y++){
          //  printf("%c ",PtrJogador->PercursoJogador[x][y]);
        //}
      //  printf("\n");
    //}
        if(PtrJogador->PercursoJogador[(*i)][(*j)] == '0'){
            PtrJogador->PercursoJogador[(*i)][(*j)] = 'V';
            push(PtrPilha,(*i),(*j));
        }else if(PtrJogador->PercursoJogador[(*i)][(*j)]== 'C'){
            PtrJogador->ChavesColetadas +=1;
            PtrJogador->PercursoJogador[(*i)][(*j)] = 'V';
        }else if(PtrJogador->PercursoJogador[(*i)][(*j)]=='X') {
            if(PtrJogador->ChavesColetadas==PtrTabuleiro->numeroChaves){
                push(PtrPilha,(*i),(*j));
                printf("O jogador encontrou o bau!\n");
                return 1;
            }else if(PtrJogador->ChavesColetadas!=PtrTabuleiro->numeroChaves){
                printf("O Jogador nao possui todas as chaves\n");
                printf("Continue Procurando....\n\n");
            }
        }
        if(Direita((*i),(*j),PtrJogador)){
                    (*j) = (*j) + 1;
                    backtraking(i,j,PtrJogador,PtrTabuleiro,PtrPilha);
        }
        if(Cima((*i),(*j),PtrJogador)){
                    (*i) = (*i) -1;
                    backtraking(i,j,PtrJogador,PtrTabuleiro,PtrPilha);
        }
        if(Baixo((*i),(*j),PtrJogador)){
                    (*i) = (*i) + 1;
                    backtraking(i,j,PtrJogador,PtrTabuleiro,PtrPilha);
        }
        if(Esquerda((*i),(*j),PtrJogador)){
            (*j) = (*j) -1;
            backtraking(i,j,PtrJogador,PtrTabuleiro,PtrPilha);
        }
        if(PtrJogador->PercursoJogador[*i][*j]!='X'){
            PtrJogador->PercursoJogador[*i][*j] = 'I';
            pop(PtrPilha);
        }
        if(VoltarCima((*i),(*j),PtrJogador)){
            (*i) = (*i) - 1;
            backtraking(i,j,PtrJogador,PtrTabuleiro,PtrPilha);
        }
        if(VoltarBaixo((*i),(*j),PtrJogador)){
            (*i) = (*i) + 1;
            backtraking(i,j,PtrJogador,PtrTabuleiro,PtrPilha);
        }
        if(VoltarDireita((*i),(*j),PtrJogador)){
            (*j) = (*j) + 1;
            backtraking(i,j,PtrJogador,PtrTabuleiro,PtrPilha);
        }
        if(VoltarEsquerda((*i),(*j),PtrJogador)){
            (*j) = (*j) - 1;
            backtraking(i,j,PtrJogador,PtrTabuleiro,PtrPilha);
        }

    return 0;
}
int Direita(int i, int j, JOGADOR *PtrJogador){
    if(j<PtrJogador->PercursoJogadorCollun-1){
        if(PtrJogador->PercursoJogador[i][j + 1] == '0' || PtrJogador->PercursoJogador[i][j + 1] == 'C'|| PtrJogador->PercursoJogador[i][j + 1] == 'X'){
            return 1;
        }
    }
    return 0;
}

int Esquerda(int i, int j, JOGADOR *PtrJogador){
    if(j > 0){
        if(PtrJogador->PercursoJogador[i][j - 1] == '0' || PtrJogador->PercursoJogador[i][j - 1] == 'C'|| PtrJogador->PercursoJogador[i][j -1] == 'X'){
            return 1;
        }
    }
    return 0;
}

int Cima(int i, int j, JOGADOR *PtrJogador){
    if(i>0 && i <= PtrJogador->PercursoJogadorLine - 1){
        if(PtrJogador->PercursoJogador[i - 1][j] == '0' || PtrJogador->PercursoJogador[i - 1][j] == 'C'|| PtrJogador->PercursoJogador[i-1][j] == 'X'){
            return 1;
        }
    }
    return 0;
}

int Baixo(int i, int j, JOGADOR *PtrJogador){
    if((i < PtrJogador->PercursoJogadorLine - 1 )){
        if(PtrJogador->PercursoJogador[i + 1][j] == '0' || PtrJogador->PercursoJogador[i + 1][j] == 'C'|| PtrJogador->PercursoJogador[i+1][j] == 'X'){
            return 1;
        }
    }
    return 0;
}
int VoltarDireita(int i,int j,JOGADOR *PtrJogador){
    if(j<PtrJogador->PercursoJogadorCollun - 1){
        if(j>0 && i>0 && i<PtrJogador->PercursoJogadorLine-1){
            if(PtrJogador->PercursoJogador[i][j-1]!='V'&&PtrJogador->PercursoJogador[i-1][j]!='V' && PtrJogador->PercursoJogador[i][j+1]=='V' && PtrJogador->PercursoJogador[i+1][j]!='V'){
                return 1;
            }
        }else if(i>0 && i<PtrJogador->PercursoJogadorLine-1){
            if((PtrJogador->PercursoJogador[i][j+1]=='C' ||PtrJogador->PercursoJogador[i][j+1]=='V')&&PtrJogador->PercursoJogador[i+1][j]=='V' && PtrJogador->PercursoJogador[i-1][j]!='V'){
                return 1;
            }
        }else if(i<PtrJogador->PercursoJogadorLine-1){
            if((PtrJogador->PercursoJogador[i][j+1]=='C' ||PtrJogador->PercursoJogador[i][j+1]=='V') &&PtrJogador->PercursoJogador[i+1][j]!='V'){
                return 1;
            }
        }
    }
    return 0;
}
int VoltarEsquerda(int i,int j,JOGADOR *PtrJogador){
    if(j>0){
        if(j<PtrJogador->PercursoJogadorCollun - 1 && i>0 && i<PtrJogador->PercursoJogadorLine-1){
            if((PtrJogador->PercursoJogador[i][j-1]=='C' ||PtrJogador->PercursoJogador[i][j-1]=='V')&&PtrJogador->PercursoJogador[i-1][j]!='V' && PtrJogador->PercursoJogador[i][j+1]!='V' && PtrJogador->PercursoJogador[i+1][j]!='V'){
                return 1;
            }
        }else if(i>0 && i<PtrJogador->PercursoJogadorLine-1){
            if((PtrJogador->PercursoJogador[i][j-1]=='C' ||PtrJogador->PercursoJogador[i][j-1]=='V')&&PtrJogador->PercursoJogador[i-1][j]!='V' && PtrJogador->PercursoJogador[i][j-1]!='V'){
                return 1;
            }
        }else if(i<PtrJogador->PercursoJogadorLine-1){
            if((PtrJogador->PercursoJogador[i][j-1]=='C' ||PtrJogador->PercursoJogador[i][j-1]=='V')&&PtrJogador->PercursoJogador[i-1][j]!='V'){
                return 1;
            }
        }
    }
    return 0;
}

int VoltarCima(int i,int j,JOGADOR *PtrJogador){
    if(i>0){
        if(j<0 && j<PtrJogador->PercursoJogadorCollun-1 && i<PtrJogador->PercursoJogadorLine-1){
            if((PtrJogador->PercursoJogador[i-1][j]=='C' ||PtrJogador->PercursoJogador[i-1][j]=='V')&& PtrJogador->PercursoJogador[i][j-1]!='V' && PtrJogador->PercursoJogador[i][j+1]!='V' && PtrJogador->PercursoJogador[i+1][j]!='V'){
                return 1;
            }
        }else if(j<PtrJogador->PercursoJogadorCollun-1 && i<PtrJogador->PercursoJogadorLine-1){
            if((PtrJogador->PercursoJogador[i-1][j]=='C' ||PtrJogador->PercursoJogador[i-1][j]=='V')&& PtrJogador->PercursoJogador[i][j+1]!='V' && PtrJogador->PercursoJogador[i+1][j]!='V'){
                return 1;
            }
        }else if(i<PtrJogador->PercursoJogadorLine-1){
            if((PtrJogador->PercursoJogador[i-1][j]=='C' ||PtrJogador->PercursoJogador[i-1][j]=='V')&&PtrJogador->PercursoJogador[i+1][j]!='V'){
                return 1;
            }
        }
    }
    return 0;
}
int VoltarBaixo(int i,int j,JOGADOR *PtrJogador){
    if(i<PtrJogador->PercursoJogadorLine-1){
        if(i>0 && j> 0 && j<PtrJogador->PercursoJogadorCollun - 1){
            if((PtrJogador->PercursoJogador[i+1][j]=='C' ||PtrJogador->PercursoJogador[i+1][j]=='V')&&PtrJogador->PercursoJogador[i-1][j]!='V' && PtrJogador->PercursoJogador[i][j+1]!='V' && PtrJogador->PercursoJogador[i][j-1]){
                return 1;
            }
        }else if(j> 0 && j<PtrJogador->PercursoJogadorCollun - 1){
            if((PtrJogador->PercursoJogador[i+1][j]=='C' ||PtrJogador->PercursoJogador[i+1][j]=='V')&&PtrJogador->PercursoJogador[i][j+1]!='V' && PtrJogador->PercursoJogador[i][j-1]!='V'){
                return 1;
            }
        }else if(j<PtrJogador->PercursoJogadorCollun - 1){
            if((PtrJogador->PercursoJogador[i+1][j]=='C' ||PtrJogador->PercursoJogador[i+1][j]=='V')&&PtrJogador->PercursoJogador[i][j+1]!='V'){
                return 1;
            }
        }
    }
    return 0;
}

