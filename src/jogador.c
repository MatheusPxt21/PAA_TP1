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

}

void Movimentar(Jogador *Ptr,TIPO_MATRIZ *Var_TipoMatriz,PilhaCoordenadas *pilha,PilhaCoordenadas *pilhaChaves,PilhaRamificado *pilhaRamificacao,FilaPilhas *Fila){
    int X,Y;
    int a,b;
    int control = 0;
    a = Var_TipoMatriz->mat_LINHAS;
    b = Var_TipoMatriz->mat_COLUNAS;
    X = Y = 0;
    initialize(pilha);
    initialize(pilhaChaves);
    inicializarRamificacao(pilhaRamificacao);
    initializeFilaPilhas(Fila);

    backtracking(Ptr,Var_TipoMatriz,&X,&Y,pilhaChaves,pilha,&a,&b,&control,pilhaRamificacao,Fila);

}

int backtracking(Jogador *Ptr,TIPO_MATRIZ *Var_TipoMatriz,int *i,int *j,PilhaCoordenadas *pilhaChaves,PilhaCoordenadas *pilha,int *I_Ramificacao,int *J_Ramificacao,int *control,PilhaRamificado *pilhaRamificacao,FilaPilhas *Fila){

    //Posição válida
    if(Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='C'){
        push(pilhaChaves,*i,*j);
        Ptr->ChavesColetadas +=1;
    }
    if(*control==0&&Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='X' && Ptr->ChavesColetadas==Var_TipoMatriz->mat_CHAVES){

        push(pilha,*i,*j);

        InserirFilaPilhas(Fila,pilha);

        pop(pilha);
        *control = 1;

        return 1;
    }

    if(Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='0' || Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='C'){
        Ptr->PtrJ->ConteudoJogador[*i][*j].Valor = 'V';
        //Empilhar o valor válido
        push(pilha,*i,*j);
        if((*i==*I_Ramificacao && *j==*J_Ramificacao)|(ExisteRamificacao(Ptr,*i,*j)==1)){
            *I_Ramificacao = *i;
            *J_Ramificacao = *j;
            pushRamificacao(pilhaRamificacao,*I_Ramificacao,*J_Ramificacao);

            //Uma ramificação foi indentificada
            // Lógica para lidar com bifurcações.

            if(pilhaRamificacao->topo->RamificadoDireita == -1 && ExisteDireita(Ptr,*i,*j)&& pilhaRamificacao->topo->RamificadoDireita != 1){

                pilhaRamificacao->topo->RamificadoDireita = 1;
                // Avança para a sala à direita
                (*j) = (*j) + 1;
                backtracking(Ptr, Var_TipoMatriz, i, j,pilhaChaves, pilha, I_Ramificacao, J_Ramificacao,control,pilhaRamificacao,Fila);

                if(*control==1){
                    Var_TipoMatriz->qtdRotas+=1;
                }

                if(isEmpty(pilha)==0){
                    LimparMatriz(Ptr,pilha,pilhaChaves,I_Ramificacao,J_Ramificacao);

                }

                *control = 0;
                (*i) = (*I_Ramificacao);
                (*j) = (*J_Ramificacao);
            }else{

                pilhaRamificacao->topo->RamificadoDireita = 0;
            }

            if(pilhaRamificacao->topo->RamificadoBaixo == -1 && ExisteBaixo(Ptr,*i,*j) && pilhaRamificacao->topo->RamificadoBaixo != 1){

                pilhaRamificacao->topo->RamificadoBaixo = 1;

                //Avança para a posição de baixo
                (*i) = (*i) + 1;
                backtracking(Ptr, Var_TipoMatriz, i, j,pilhaChaves, pilha, I_Ramificacao, J_Ramificacao,control,pilhaRamificacao,Fila);

                if(*control==1){
                    Var_TipoMatriz->qtdRotas+=1;
                }

                if(isEmpty(pilha)==0){
                    LimparMatriz(Ptr,pilha,pilhaChaves,I_Ramificacao,J_Ramificacao);

                }

                *control = 0;
                (*i) = (*I_Ramificacao);
                (*j) = (*J_Ramificacao);

            }else{
                pilhaRamificacao->topo->RamificadoBaixo = 0;
            }

            if(pilhaRamificacao->topo->RamificadoEsquerda == -1 && ExisteEsquerda(Ptr,*i,*j) && pilhaRamificacao->topo->RamificadoEsquerda != 1){

                // Avança para a posição à esquerda
                pilhaRamificacao->topo->RamificadoEsquerda = 1;
                (*j) = (*j) - 1;
                backtracking(Ptr, Var_TipoMatriz, i, j,pilhaChaves, pilha, I_Ramificacao, J_Ramificacao,control,pilhaRamificacao,Fila);

                if(*control==1){

                    Var_TipoMatriz->qtdRotas+=1;

                }

                if(isEmpty(pilha)==0){
                    LimparMatriz(Ptr,pilha,pilhaChaves,I_Ramificacao,J_Ramificacao);
                }

                *control = 0;
                (*i) = (*I_Ramificacao);
                (*j) = (*J_Ramificacao);

            }else{
                pilhaRamificacao->topo->RamificadoEsquerda = 0;
            }
            if(pilhaRamificacao->topo->RamificadoCima == -1 && ExisteCima(Ptr,*i,*j) && pilhaRamificacao->topo->RamificadoCima != 1){
                // Avança para a posição de Cima
                pilhaRamificacao->topo->RamificadoCima = 1;
                (*i) = (*i) - 1;
                backtracking(Ptr, Var_TipoMatriz, i, j,pilhaChaves, pilha, I_Ramificacao, J_Ramificacao,control,pilhaRamificacao,Fila);
                if(*control==1){
                    Var_TipoMatriz->qtdRotas+=1;
                }
                if(isEmpty(pilha)==0){
                    LimparMatriz(Ptr,pilha,pilhaChaves,I_Ramificacao,J_Ramificacao);
                }
                *control = 0;
                (*i) = (*I_Ramificacao);
                (*j) = (*J_Ramificacao);

            }else{
                pilhaRamificacao->topo->RamificadoCima = 0;
            }

            if(estaVazioRamificacao(pilhaRamificacao)==0){
                LimparMatriz(Ptr,pilha,pilhaChaves,I_Ramificacao,J_Ramificacao);
                popRamificacao(pilhaRamificacao);
                if(estaVazioRamificacao(pilhaRamificacao)==0){
                    *I_Ramificacao = pilhaRamificacao->topo->Ramificado_Linha;
                    *J_Ramificacao = pilhaRamificacao->topo->Ramificado_Coluna;
                    LimparMatriz(Ptr,pilha,pilhaChaves,I_Ramificacao,J_Ramificacao);
                }

            }
            *i = (*I_Ramificacao);
            *j = (*J_Ramificacao);
            backtracking(Ptr, Var_TipoMatriz, i, j,pilhaChaves, pilha, I_Ramificacao, J_Ramificacao,control,pilhaRamificacao,Fila);
        }else{
            //Apenas uma das direções é possível, sem o risco de repetir o mesmo padrão de movimento
            //Avança para a posição em baixo
            if (*control == 0 && ExisteBaixo(Ptr,*i,*j)  && ((*i==*I_Ramificacao && *j==*J_Ramificacao)==0)) {
                (*i) = (*i) + 1;
                backtracking(Ptr, Var_TipoMatriz, i, j, pilhaChaves, pilha, I_Ramificacao, J_Ramificacao, control,pilhaRamificacao,Fila);
            }
            //Avança para a posição de cima
            if (*control == 0 && ExisteCima(Ptr,*i,*j) && ((*i==*I_Ramificacao && *j==*J_Ramificacao)==0)) {
                (*i) = (*i) - 1;
                backtracking(Ptr, Var_TipoMatriz, i, j, pilhaChaves, pilha, I_Ramificacao, J_Ramificacao, control,pilhaRamificacao,Fila);
            }
            //Avança para a posição da esquerda
            if (*control == 0 && ExisteEsquerda(Ptr,*i,*j)  && ((*i==*I_Ramificacao && *j==*J_Ramificacao)==0)) {
                (*j) = (*j) - 1;
                backtracking(Ptr, Var_TipoMatriz, i, j, pilhaChaves, pilha, I_Ramificacao, J_Ramificacao, control,pilhaRamificacao,Fila);
            }
            //Avança para a posição da direita
            if (*control == 0 && ExisteDireita(Ptr,*i,*j) && ((*i==*I_Ramificacao && *j==*J_Ramificacao)==0)) {
                (*j) = (*j) + 1;
                backtracking(Ptr, Var_TipoMatriz, i, j, pilhaChaves, pilha, I_Ramificacao, J_Ramificacao, control,pilhaRamificacao,Fila);
            }
        }
    }

    return 0; // sem caminho
}
int ExisteRamificacao(Jogador *Ptr,int i,int j){

    int CIMA,DIREITA,ESQUERDA,BAIXO,Flag;

    DIREITA = ExisteDireita(Ptr,i,j);
    ESQUERDA = ExisteEsquerda(Ptr,i,j);
    CIMA = ExisteCima(Ptr,i,j);
    BAIXO = ExisteBaixo(Ptr,i,j);
    Flag = DIREITA+ESQUERDA+CIMA+BAIXO;

    if(Flag>1){
        return 1;
    }
    return 0;

}

int LimparMatriz(Jogador *Ptr,PilhaCoordenadas *pilha,PilhaCoordenadas *pilhachaves,int *I_Ramificacao,int *J_Ramificacao){

    if (isEmpty(pilha)) {return -1;}

    Coordenadas *cord = pilha->topo;
    while (cord != NULL) {
        if(cord->line==*I_Ramificacao && cord->collun==*J_Ramificacao){
            return 1;
        }

        Ptr->PtrJ->ConteudoJogador[cord->line][cord->collun].Valor = '0';

        if(EstaPresentePilhaChaves(Ptr,pilhachaves,cord->line,cord->collun)){
            Ptr->PtrJ->ConteudoJogador[cord->line][cord->collun].Valor = 'C';
        }
        pilha->topo = cord->next;
        free(cord);
        cord = pilha->topo;
    }

    // Se chegou aqui, não encontrou a ramificação
    return 0;

}

int EstaPresentePilhaChaves(Jogador *Ptr,PilhaCoordenadas *pilhaChaves,int line,int collun){
    if (isEmpty(pilhaChaves)) {return 0;}

    Coordenadas *cord = (pilhaChaves->topo);
    if(cord->line==line && cord->collun==collun){
        Ptr->ChavesColetadas -=1;
        (pilhaChaves->topo) = cord->next;
        free(cord);
        return 1;
    }
    return 0;
}

int ExisteDireita(Jogador *Ptr,int i,int j){
    if(j<Ptr->TamanhoJogadorY-1 && Ptr->PtrJ->ConteudoJogador[i][j+1].Valor!='1' && Ptr->PtrJ->ConteudoJogador[i][j+1].Valor!='V'){
        return 1;
    }
    return 0;
}
int ExisteEsquerda(Jogador *Ptr,int i,int j){
    if(j>0 && Ptr->PtrJ->ConteudoJogador[i][j-1].Valor!='1' && Ptr->PtrJ->ConteudoJogador[i][j-1].Valor!='V'){
        return 1;
    }
    return 0;
}
int ExisteBaixo(Jogador *Ptr,int i,int j){
    if(i<Ptr->TamanhoJogadorY-1 && Ptr->PtrJ->ConteudoJogador[i+1][j].Valor!='1' && Ptr->PtrJ->ConteudoJogador[i+1][j].Valor!='V'){
        return 1;
    }
    return 0;
}
int ExisteCima(Jogador *Ptr,int i,int j){
    if(i>0 && Ptr->PtrJ->ConteudoJogador[i-1][j].Valor!='1' && Ptr->PtrJ->ConteudoJogador[i-1][j].Valor!='V'){
        return 1;
    }
    return 0;
}