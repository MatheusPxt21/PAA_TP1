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
void  Movimentar(Jogador *Ptr,TIPO_MATRIZ *Var_TipoMatriz,PilhaCoordenadas *pilha,PilhaCoordenadas *pilhaChaves){
    int X,Y;
    int a,b;
    int control = 0;
    a = Var_TipoMatriz->mat_LINHAS;
    b = Var_TipoMatriz->mat_COLUNAS;
    X = Y = 0;
    initialize(pilha);
    initialize(pilhaChaves);
    backtracking(Ptr,Var_TipoMatriz,&X,&Y,pilhaChaves,pilha,&a,&b,&control);
}

int backtracking(Jogador *Ptr,TIPO_MATRIZ *Var_TipoMatriz,int *i,int *j,PilhaCoordenadas *pilhaChaves,PilhaCoordenadas *pilha,int *I_Ramificacao,int *J_Ramificacao,int *control){
    //printf("I ramificacao:%d J ramificacao: %d \n",*I_Ramificacao,*J_Ramificacao);
    //Printar(Ptr);
    DeterminaDirecoes(Ptr,*i,*j);

    //Posição válida
    if(Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='C'){
        push(pilhaChaves,*i,*j);
        Ptr->ChavesColetadas +=1;
    }
    if(*control==0&&Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='X' && Ptr->ChavesColetadas==Var_TipoMatriz->mat_CHAVES){
        //Registrar a rota
        //Inserir no vetor de pilhas
        //Adicionar variável control?
        printf("Caminho ao Tesouro Encontrado!\n");
        //Adicionar a posição do tesouro
        ApresentarCoordenadas(pilha);
        *control = 1;
        return 1;
    }
    if(Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='0' || Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='C'){
        Ptr->PtrJ->ConteudoJogador[*i][*j].Valor = 'V';
        //Empilhar o valor válido
        push(pilha,*i,*j);
        if(ExisteRamificacao(Ptr,*i,*j)==1){
            *I_Ramificacao = *i;
            *J_Ramificacao = *j;
            //Uma ramificação foi indentificada
            // Lógica para lidar com bifurcações.
            if(Ptr->PtrJ->ConteudoJogador[*I_Ramificacao][*J_Ramificacao].Baixo=='V'){
                //Avança para a sala em baixo
                (*i) = (*i) + 1;
                backtracking(Ptr, Var_TipoMatriz, i, j,pilhaChaves, pilha, I_Ramificacao, J_Ramificacao,control);
                Ptr->ChavesColetadas = 0;

                if(*control==1){
                    Var_TipoMatriz->qtdRotas+=1;
                }

                if(isEmpty(pilha)==0){
                    LimparMatriz(Ptr,pilha,I_Ramificacao,J_Ramificacao);
                }

                if(isEmpty(pilhaChaves)==0){
                    LimparMatrizChaves(Ptr,pilhaChaves);
                }

                //Printar(Ptr);
                *control = 0;
                (*i) = (*I_Ramificacao);
                (*j) = (*J_Ramificacao);

            }

            if(Ptr->PtrJ->ConteudoJogador[*I_Ramificacao][*J_Ramificacao].Direita=='V'){

                // Avança para a sala à direita

                (*j) = (*j) + 1;
                backtracking(Ptr, Var_TipoMatriz, i, j,pilhaChaves, pilha, I_Ramificacao, J_Ramificacao,control);
                Ptr->ChavesColetadas = 0;

                if(*control==1){
                    Var_TipoMatriz->qtdRotas+=1;

                }

                if(isEmpty(pilha)==0){
                    LimparMatriz(Ptr,pilha,I_Ramificacao,J_Ramificacao);
                }

                if(isEmpty(pilhaChaves)==0){
                    LimparMatrizChaves(Ptr,pilhaChaves);
                }

                (*i) = (*I_Ramificacao);
                (*j) = (*J_Ramificacao);

            }

            if(Ptr->PtrJ->ConteudoJogador[*I_Ramificacao][*J_Ramificacao].Esquerda=='V'){

                // Avança para a sala à esquerda

                (*j) = (*j) - 1;
                backtracking(Ptr, Var_TipoMatriz, i, j,pilhaChaves, pilha, I_Ramificacao, J_Ramificacao,control);
                Ptr->ChavesColetadas = 0;

                if(*control==1){

                    Var_TipoMatriz->qtdRotas+=1;

                }

                if(isEmpty(pilha)==0){

                    LimparMatriz(Ptr,pilha,I_Ramificacao,J_Ramificacao);
                }

                if(isEmpty(pilhaChaves)==0){

                    LimparMatrizChaves(Ptr,pilhaChaves);
                }

                (*i) = (*I_Ramificacao);
                (*j) = (*J_Ramificacao);

            }

            if(Ptr->PtrJ->ConteudoJogador[*I_Ramificacao][*J_Ramificacao].Cima=='V'){
                // Avança para a sala à direita

                (*i) = (*i) - 1;
                backtracking(Ptr, Var_TipoMatriz, i, j,pilhaChaves, pilha, I_Ramificacao, J_Ramificacao,control);
                Ptr->ChavesColetadas = 0;

                if(*control==1){

                    Var_TipoMatriz->qtdRotas+=1;

                }

                if(isEmpty(pilha)==0){

                    LimparMatriz(Ptr,pilha,I_Ramificacao,J_Ramificacao);
                }

                if(isEmpty(pilhaChaves)==0){

                    LimparMatrizChaves(Ptr,pilhaChaves);
                }

                (*i) = (*I_Ramificacao);
                (*j) = (*J_Ramificacao);

            }

        }else {
            //printf("Entra aqui!\n");
            //Apenas uma das direções é possível, sem o risco de repetir o mesmo padrão de movimento
            //Avança para a sala em baixo
            if (*control == 0 && Ptr->PtrJ->ConteudoJogador[*i][*j].Baixo == 'V') {
                (*i) = (*i) + 1;
                backtracking(Ptr, Var_TipoMatriz, i, j, pilhaChaves, pilha, I_Ramificacao, J_Ramificacao, control);
            }
            //Avança para a sala de cima
            if (*control == 0 && Ptr->PtrJ->ConteudoJogador[*i][*j].Cima == 'V') {
                (*i) = (*i) - 1;
                backtracking(Ptr, Var_TipoMatriz, i, j, pilhaChaves, pilha, I_Ramificacao, J_Ramificacao, control);
            }
            //Avança para a sala da esquerda
            if (*control == 0 && Ptr->PtrJ->ConteudoJogador[*i][*j].Esquerda == 'V') {
                (*j) = (*j) - 1;
                backtracking(Ptr, Var_TipoMatriz, i, j, pilhaChaves, pilha, I_Ramificacao, J_Ramificacao, control);
            }
            //Avança para a sala da direita
            if (*control == 0 && Ptr->PtrJ->ConteudoJogador[*i][*j].Direita == 'V') {
                //printf("Dentro de Direita!\n");
                (*j) = (*j) + 1;
                backtracking(Ptr, Var_TipoMatriz, i, j, pilhaChaves, pilha, I_Ramificacao, J_Ramificacao, control);
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


int LimparMatrizChaves(Jogador *Ptr,PilhaCoordenadas *pilhaChaves) {
    //Restaurar a matriz, sem as chaves
    if (isEmpty(pilhaChaves)) {
        printf("ERRO EM LIMPAR CHAVES!!\n");
        printf("\n %sErro ao remover: Pilha vazia%s \n", B_RED, RESET);
        return -1;
    }

    Coordenadas *cord = (pilhaChaves->topo);
    while (cord != NULL) {
        // Verifica se alcançou a ramificação desejada

        Ptr->PtrJ->ConteudoJogador[cord->line][cord->collun].Valor = 'C';

        // Move para o próximo nó da pilha
        (pilhaChaves->topo) = cord->next;
        free(cord);
        cord = pilhaChaves->topo;
    }

    // Se chegou aqui, não encontrou a ramificação
    return 0;
}

int LimparMatriz(Jogador *Ptr,PilhaCoordenadas *pilha,int *I_Ramificacao,int *J_Ramificacao){
    //Restaurar as chaves da Matriz
    if (isEmpty(pilha)) {
        printf("ERRO EM LIMPAR!!\n");
        printf("\n %sErro ao remover: Pilha vazia%s \n", B_RED, RESET);
        return -1;
    }


    Coordenadas *cord = pilha->topo;
    while (cord != NULL) {
        // Verifica se alcançou a ramificação desejada
        if(cord->line==*I_Ramificacao && cord->collun==*J_Ramificacao){
            return 1;
        }

        Ptr->PtrJ->ConteudoJogador[cord->line][cord->collun].Valor = '0';

        // Move para o próximo nó da pilha
        pilha->topo = cord->next;
        free(cord);
        cord = pilha->topo;
    }

    // Se chegou aqui, não encontrou a ramificação
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