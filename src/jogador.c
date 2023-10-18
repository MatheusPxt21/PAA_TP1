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

    //Inicializando a posição inicial do jogador
    Ptr->PtrJ->JogadorX = 0;
    Ptr->PtrJ->JogadorY = 0;

}
void DeterminaDirecoes(Jogador *Ptr,int i,int j){
    Ptr->PtrJ->ConteudoJogador[i][j].NumeroRamificacoes = 0;
    if(Ptr->PtrJ->ConteudoJogador[i][j].Valor=='1'){
        Ptr->PtrJ->ConteudoJogador[i][j].Cima = 'I';
        Ptr->PtrJ->ConteudoJogador[i][j].Esquerda = 'I';
        Ptr->PtrJ->ConteudoJogador[i][j].Direita = 'I';
        Ptr->PtrJ->ConteudoJogador[i][j].Baixo = 'I';
    }

    if(i == 0){
        Ptr->PtrJ->ConteudoJogador[i][j].Cima = 'I';
    }

    if(j==0){
        Ptr->PtrJ->ConteudoJogador[i][j].Esquerda = 'I';
    }

    if(j==Ptr->TamanhoJogadorY-1){
        Ptr->PtrJ->ConteudoJogador[i][j].Direita = 'I';
    }

    if(i==Ptr->TamanhoJogadorX-1){
        Ptr->PtrJ->ConteudoJogador[i][j].Baixo = 'I';
    }

    if(i>0 && Ptr->PtrJ->ConteudoJogador[i-1][j].Valor!='1'&& Ptr->PtrJ->ConteudoJogador[i-1][j].Valor!='V'){
        Ptr->PtrJ->ConteudoJogador[i][j].Cima = 'V';
        if(Ptr->PtrJ->ConteudoJogador[i-1][j].Valor!='X'){
            Ptr->PtrJ->ConteudoJogador[i][j].NumeroRamificacoes +=1;
        }
    }else if(i>0 && Ptr->PtrJ->ConteudoJogador[i-1][j].Valor!='0'){
        Ptr->PtrJ->ConteudoJogador[i][j].Cima = 'I';
    }

    if(j>0 && Ptr->PtrJ->ConteudoJogador[i][j-1].Valor!='1'&& Ptr->PtrJ->ConteudoJogador[i][j-1].Valor!='V'){
        if(Ptr->PtrJ->ConteudoJogador[i][j-1].Valor!='X'){
            Ptr->PtrJ->ConteudoJogador[i][j].NumeroRamificacoes +=1;
        }
        Ptr->PtrJ->ConteudoJogador[i][j].Esquerda = 'V';
    }else if(j>0 && Ptr->PtrJ->ConteudoJogador[i][j-1].Valor!='0'){
        Ptr->PtrJ->ConteudoJogador[i][j].Esquerda = 'I';
    }

    if(i<Ptr->TamanhoJogadorX-1 && Ptr->PtrJ->ConteudoJogador[i+1][j].Valor!='1'&& Ptr->PtrJ->ConteudoJogador[i+1][j].Valor!='V'){
        if(Ptr->PtrJ->ConteudoJogador[i+1][j].Valor!='X'){
            Ptr->PtrJ->ConteudoJogador[i][j].NumeroRamificacoes +=1;
        }
        Ptr->PtrJ->ConteudoJogador[i][j].Baixo = 'V';
    }else if(i<Ptr->TamanhoJogadorX-1 && Ptr->PtrJ->ConteudoJogador[i+1][j].Valor!='0'){
        Ptr->PtrJ->ConteudoJogador[i][j].Baixo = 'I';
    }

    if(j<Ptr->TamanhoJogadorY-1 && Ptr->PtrJ->ConteudoJogador[i][j+1].Valor!='1'&& Ptr->PtrJ->ConteudoJogador[i][j+1].Valor!='V'){
        Ptr->PtrJ->ConteudoJogador[i][j].Direita = 'V';
        if(Ptr->PtrJ->ConteudoJogador[i][j+1].Valor!='X'){
            Ptr->PtrJ->ConteudoJogador[i][j].NumeroRamificacoes +=1;
        }
    }else if(j<Ptr->TamanhoJogadorY-1 && Ptr->PtrJ->ConteudoJogador[i][j+1].Valor!='0'){
        Ptr->PtrJ->ConteudoJogador[i][j].Direita = 'I';
    }
}
void  Movimentar(Jogador *Ptr,TIPO_MATRIZ *Var_TipoMatriz,PilhaCoordenadas *pilha,PilhaCoordenadas *pilhaChaves,PilhaRamificado *pilhaRamificacao){
    int X,Y;
    int a,b;
    int control = 0;
    a = Var_TipoMatriz->mat_LINHAS;
    b = Var_TipoMatriz->mat_COLUNAS;
    X = Y = 0;
    initialize(pilha);
    initialize(pilhaChaves);
    inicializarRamificacao(pilhaRamificacao);
    backtracking(Ptr,Var_TipoMatriz,&X,&Y,pilhaChaves,pilha,&a,&b,&control,pilhaRamificacao);
}

int backtracking(Jogador *Ptr,TIPO_MATRIZ *Var_TipoMatriz,int *i,int *j,PilhaCoordenadas *pilhaChaves,PilhaCoordenadas *pilha,int *I_Ramificacao,int *J_Ramificacao,int *control,PilhaRamificado *pilhaRamificacao){
    //Printar(Ptr);
    //printf("Chaves Coletadas: %d\n",Ptr->ChavesColetadas);
    DeterminaDirecoes(Ptr,*i,*j);

    //Posição válida
    if(Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='C'){
        push(pilhaChaves,*i,*j);
        Ptr->ChavesColetadas +=1;
    }
    if(*control==0&&Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='X' && Ptr->ChavesColetadas==Var_TipoMatriz->mat_CHAVES){
        //Registrar a rota
        //Inserir no vetor de pilhas
        printf("Caminho ao Tesouro Encontrado!\n");
        //Adicionar a posição do tesouro
        push(pilha,*i,*j);
        ApresentarCoordenadas(pilha);
        pop(pilha);
        *control = 1;
        //exit(1);
        return 1;
    }
    if(Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='0' || Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='C'){
        Ptr->PtrJ->ConteudoJogador[*i][*j].Valor = 'V';
        //Empilhar o valor válido
        push(pilha,*i,*j);
        if(ExisteRamificacao(Ptr,*i,*j)==1){
            *I_Ramificacao = *i;
            *J_Ramificacao = *j;
            pushRamificacao(pilhaRamificacao,*I_Ramificacao,*J_Ramificacao);
            //printf("Ramificacoes: \n");
            //ApresentarRamificacao(pilhaRamificacao);

            //Uma ramificação foi indentificada
            // Lógica para lidar com bifurcações.
            if(pilhaRamificacao->topo->RamificadoDireita == -1 && Ptr->PtrJ->ConteudoJogador[*I_Ramificacao][*J_Ramificacao].Direita=='V'){

                pilhaRamificacao->topo->RamificadoDireita = 1;
                // Avança para a sala à direita
                (*j) = (*j) + 1;
                backtracking(Ptr, Var_TipoMatriz, i, j,pilhaChaves, pilha, I_Ramificacao, J_Ramificacao,control,pilhaRamificacao);

                if(*control==1){
                    Var_TipoMatriz->qtdRotas+=1;
                }

                if(isEmpty(pilha)==0){
                    LimparMatriz(Ptr,pilha,pilhaChaves,I_Ramificacao,J_Ramificacao);
                    //Printar(Ptr);
                }

                *control = 0;
                (*i) = (*I_Ramificacao);
                (*j) = (*J_Ramificacao);
            }else{

                pilhaRamificacao->topo->RamificadoDireita = 0;
            }
            if(pilhaRamificacao->topo->RamificadoBaixo == -1 && Ptr->PtrJ->ConteudoJogador[*I_Ramificacao][*J_Ramificacao].Baixo=='V'){

                pilhaRamificacao->topo->RamificadoBaixo = 1;
                //Avança para a sala em baixo
                (*i) = (*i) + 1;
                backtracking(Ptr, Var_TipoMatriz, i, j,pilhaChaves, pilha, I_Ramificacao, J_Ramificacao,control,pilhaRamificacao);

                if(*control==1){
                    Var_TipoMatriz->qtdRotas+=1;
                }

                if(isEmpty(pilha)==0){
                    LimparMatriz(Ptr,pilha,pilhaChaves,I_Ramificacao,J_Ramificacao);
                    //Printar(Ptr);
                }

                *control = 0;
                (*i) = (*I_Ramificacao);
                (*j) = (*J_Ramificacao);

            }else{
                pilhaRamificacao->topo->RamificadoBaixo = 0;
            }

            if(pilhaRamificacao->topo->RamificadoEsquerda == -1 && Ptr->PtrJ->ConteudoJogador[*I_Ramificacao][*J_Ramificacao].Esquerda=='V'){

                //printf("Dentro de Esquerda!");
                //printf("[%d %d]\n",*i,*j);
                // Avança para a sala à esquerda
                pilhaRamificacao->topo->RamificadoEsquerda = 1;
                (*j) = (*j) - 1;
                backtracking(Ptr, Var_TipoMatriz, i, j,pilhaChaves, pilha, I_Ramificacao, J_Ramificacao,control,pilhaRamificacao);

                if(*control==1){

                    Var_TipoMatriz->qtdRotas+=1;

                }

                if(isEmpty(pilha)==0){
                    LimparMatriz(Ptr,pilha,pilhaChaves,I_Ramificacao,J_Ramificacao);
                    //Printar(Ptr);
                }

                *control = 0;
                (*i) = (*I_Ramificacao);
                (*j) = (*J_Ramificacao);

            }else{
                pilhaRamificacao->topo->RamificadoEsquerda = 0;
            }
            if(pilhaRamificacao->topo->RamificadoCima == -1 && Ptr->PtrJ->ConteudoJogador[*I_Ramificacao][*J_Ramificacao].Cima=='V'){
                // Avança para a sala de Cima
                pilhaRamificacao->topo->RamificadoCima = 1;
                (*i) = (*i) - 1;
                backtracking(Ptr, Var_TipoMatriz, i, j,pilhaChaves, pilha, I_Ramificacao, J_Ramificacao,control,pilhaRamificacao);
                if(*control==1){
                    Var_TipoMatriz->qtdRotas+=1;
                }
                if(isEmpty(pilha)==0){
                    LimparMatriz(Ptr,pilha,pilhaChaves,I_Ramificacao,J_Ramificacao);
                    //Printar(Ptr);
                }
                *control = 0;
                (*i) = (*I_Ramificacao);
                (*j) = (*J_Ramificacao);

            }else{
                //printf("Dentro Cima %d %d\n ",*I_Ramificacao,*J_Ramificacao);
                pilhaRamificacao->topo->RamificadoCima = 0;
            }

            if(pilhaRamificacao->topo->RamificadoEsquerda != -1 && pilhaRamificacao->topo->RamificadoDireita != -1&& pilhaRamificacao->topo->RamificadoBaixo != -1 && pilhaRamificacao->topo->RamificadoCima !=-1){
                if(isEmpty(pilha)==0){
                    LimparMatriz(Ptr,pilha,pilhaChaves,I_Ramificacao,J_Ramificacao);
                }
            }
            if(estaVazioRamificacao(pilhaRamificacao)==0){
                popRamificacao(pilhaRamificacao);
                LimparMatriz(Ptr,pilha,pilhaChaves,I_Ramificacao,J_Ramificacao);
            }
            //printf("[%d %d]--Antes do Backtracking: %d %d %d %d \n",pilhaRamificacao->topo->Ramificado_Linha,pilhaRamificacao->topo->Ramificado_Coluna,pilhaRamificacao->topo->RamificadoEsquerda,pilhaRamificacao->topo->RamificadoDireita,pilhaRamificacao->topo->RamificadoCima,pilhaRamificacao->topo->RamificadoBaixo);
            if(estaVazioRamificacao(pilhaRamificacao)==0){
                *I_Ramificacao = pilhaRamificacao->topo->Ramificado_Linha;
                *J_Ramificacao = pilhaRamificacao->topo->Ramificado_Coluna;
                if(isEmpty(pilha)==0&&pilhaRamificacao->topo->RamificadoEsquerda != -1 && pilhaRamificacao->topo->RamificadoDireita != -1&& pilhaRamificacao->topo->RamificadoBaixo != -1 && pilhaRamificacao->topo->RamificadoCima !=-1){
                    //LimparMatriz(Ptr,pilha,pilhaChaves,I_Ramificacao,J_Ramificacao);
                    *I_Ramificacao = pilhaRamificacao->topo->Ramificado_Linha;
                    *J_Ramificacao = pilhaRamificacao->topo->Ramificado_Coluna;
                    //LimparMatriz(Ptr, pilha, pilhaChaves, I_Ramificacao, J_Ramificacao);
                }
                *i = (*I_Ramificacao);
                *j = (*J_Ramificacao);
                //printf("[%d %d]--Antes do Backtracking: %d %d %d %d \n",pilhaRamificacao->topo->Ramificado_Linha,pilhaRamificacao->topo->Ramificado_Coluna,pilhaRamificacao->topo->RamificadoEsquerda,pilhaRamificacao->topo->RamificadoDireita,pilhaRamificacao->topo->RamificadoCima,pilhaRamificacao->topo->RamificadoBaixo);
                //printf("Depois: ");
                //ApresentarRamificacao(pilhaRamificacao);
                //printf("\n");
                backtracking(Ptr, Var_TipoMatriz, I_Ramificacao, J_Ramificacao,pilhaChaves, pilha, I_Ramificacao, J_Ramificacao,control,pilhaRamificacao);
            }

        }else {
            //Apenas uma das direções é possível, sem o risco de repetir o mesmo padrão de movimento
            //Avança para a sala em baixo
            if (*control == 0 && Ptr->PtrJ->ConteudoJogador[*i][*j].Baixo == 'V') {
                (*i) = (*i) + 1;
                backtracking(Ptr, Var_TipoMatriz, i, j, pilhaChaves, pilha, I_Ramificacao, J_Ramificacao, control,pilhaRamificacao);
            }
            //Avança para a sala de cima
            if (*control == 0 && Ptr->PtrJ->ConteudoJogador[*i][*j].Cima == 'V') {
                (*i) = (*i) - 1;
                backtracking(Ptr, Var_TipoMatriz, i, j, pilhaChaves, pilha, I_Ramificacao, J_Ramificacao, control,pilhaRamificacao);
            }
            //Avança para a sala da esquerda
            if (*control == 0 && Ptr->PtrJ->ConteudoJogador[*i][*j].Esquerda == 'V') {
                (*j) = (*j) - 1;
                backtracking(Ptr, Var_TipoMatriz, i, j, pilhaChaves, pilha, I_Ramificacao, J_Ramificacao, control,pilhaRamificacao);
            }
            //Avança para a sala da direita
            if (*control == 0 && Ptr->PtrJ->ConteudoJogador[*i][*j].Direita == 'V') {
                //printf("Dentro de Direita!\n");
                (*j) = (*j) + 1;
                backtracking(Ptr, Var_TipoMatriz, i, j, pilhaChaves, pilha, I_Ramificacao, J_Ramificacao, control,pilhaRamificacao);
            }
        }
    }
    return 0; // sem caminho
}
int ExisteRamificacao(Jogador *Ptr,int i,int j){
    DeterminaDirecoes(Ptr,i,j);
    if(Ptr->PtrJ->ConteudoJogador[i][j].NumeroRamificacoes>1){
        return 1;
    }
    return 0;
}

int LimparMatriz(Jogador *Ptr,PilhaCoordenadas *pilha,PilhaCoordenadas *pilhachaves,int *I_Ramificacao,int *J_Ramificacao){
    //printf("Dentro de Limpar Matriz:\n");
    //ApresentarCoordenadas(pilha);
    //printf("Dentro de Limpar Matriz Coordenadas da Ramificacao: %d %d \n", *I_Ramificacao,*J_Ramificacao);
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

void Printar(Jogador *Ptr){
    for(int i = 0;i<Ptr->TamanhoJogadorX;i++){
        for(int j = 0;j<Ptr->TamanhoJogadorY;j++){
            printf("%c ", Ptr->PtrJ->ConteudoJogador[i][j].Valor);
        }
        printf("\n");
    }
    printf("\n");
}