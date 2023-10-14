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
        Ptr->PtrJ->ConteudoJogador[i][j].NumeroRamificacoes +=1;
    }else if(i>0 && Ptr->PtrJ->ConteudoJogador[i-1][j].Valor!='0'){
        Ptr->PtrJ->ConteudoJogador[i][j].Cima = 'I';
    }

    if(j>0 && Ptr->PtrJ->ConteudoJogador[i][j-1].Valor!='1'&& Ptr->PtrJ->ConteudoJogador[i][j-1].Valor!='V'){
        Ptr->PtrJ->ConteudoJogador[i][j].Esquerda = 'V';
        Ptr->PtrJ->ConteudoJogador[i][j].NumeroRamificacoes +=1;
    }else if(j>0 && Ptr->PtrJ->ConteudoJogador[i][j-1].Valor!='0'){
        Ptr->PtrJ->ConteudoJogador[i][j].Esquerda = 'I';
    }

    if(i<Ptr->TamanhoJogadorX-1 && Ptr->PtrJ->ConteudoJogador[i+1][j].Valor!='1'&& Ptr->PtrJ->ConteudoJogador[i+1][j].Valor!='V'){
        Ptr->PtrJ->ConteudoJogador[i][j].Baixo = 'V';
        Ptr->PtrJ->ConteudoJogador[i][j].NumeroRamificacoes +=1;
    }else if(i<Ptr->TamanhoJogadorX-1 && Ptr->PtrJ->ConteudoJogador[i+1][j].Valor!='0'){
        Ptr->PtrJ->ConteudoJogador[i][j].Baixo = 'I';
    }

    if(j<Ptr->TamanhoJogadorY-1 && Ptr->PtrJ->ConteudoJogador[i][j+1].Valor!='1'&& Ptr->PtrJ->ConteudoJogador[i][j+1].Valor!='V'){
        Ptr->PtrJ->ConteudoJogador[i][j].Direita = 'V';
        Ptr->PtrJ->ConteudoJogador[i][j].NumeroRamificacoes +=1;
    }else if(j<Ptr->TamanhoJogadorY-1 && Ptr->PtrJ->ConteudoJogador[i][j+1].Valor!='0'){
        Ptr->PtrJ->ConteudoJogador[i][j].Direita = 'I';
    }
}
void Movimentar(Jogador *Ptr,TIPO_MATRIZ Var_TipoMatriz,TIPO_PILHA *pilha){
    int X,Y;
    int a,b;
    a = Var_TipoMatriz.mat_LINHAS;
    b = Var_TipoMatriz.mat_COLUNAS;
    X = Y = 0;
    inicializa_PILHA(&pilha);
    backtracking(Ptr,Var_TipoMatriz,&X,&Y,pilha,&a,&b);
}

int backtracking(Jogador *Ptr,TIPO_MATRIZ Var_TipoMatriz,int *i,int *j,TIPO_PILHA *pilha,int *I_Ramificacao,int *J_Ramificacao){

    Printar(Ptr);
    DeterminaDirecoes(Ptr,*i,*j);
    //printf("%c \n", Ptr->PtrJ->ConteudoJogador[*i][*j].Valor);

    //Posição Inválida

    if(*i!=*I_Ramificacao && *j!=*J_Ramificacao && Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='1' || Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='V' || (Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='X' && Ptr->ChavesColetadas!=Var_TipoMatriz.mat_CHAVES)){
        //Retornar ao estado inicial da matriz
        Ptr->PtrJ->ConteudoJogador[*i][*j].Valor='0';
        desempilha_PILHA(&pilha);
        //Desempilha

        return -1;
    }

    //Posição válida
    if(Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='C'){
        Ptr->ChavesColetadas +=1;
    }
    if(Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='X' && Ptr->ChavesColetadas==Var_TipoMatriz.mat_CHAVES){
        //Registrar a rota
        //Inserir no vetor de pilhas
        //Adicionar variável control?
        empilha_PILHA(&pilha,*i,*j);
        imprimir_PILHA(pilha);
        free_PILHA(pilha);
        Var_TipoMatriz.qtdRotas+=1;
        return 1;
    }
    if(Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='0' || Ptr->PtrJ->ConteudoJogador[*i][*j].Valor=='C'){
        Ptr->PtrJ->ConteudoJogador[*i][*j].Valor = 'V';
        //Empilhar o valor válido
        empilha_PILHA(&pilha,*i,*j);
        //printf("%d %d %c [Rami: %d] [%c][%c][%c][%c] ", *i,*j,Ptr->PtrJ->ConteudoJogador[*i][*j].Valor,ExisteRamificacao(Ptr,*i,*j),Ptr->PtrJ->ConteudoJogador[*i][*j].Direita,Ptr->PtrJ->ConteudoJogador[*i][*j].Cima,Ptr->PtrJ->ConteudoJogador[*i][*j].Esquerda,Ptr->PtrJ->ConteudoJogador[*i][*j].Baixo);
        if(ExisteRamificacao(Ptr,*i,*j)==1){
            *I_Ramificacao = *i;
            *J_Ramificacao = *j;
            //Uma ramificação foi indentificada
            // Lógica para lidar com bifurcações.

            if(Ptr->PtrJ->ConteudoJogador[*i][*j].Baixo=='V'&&Ptr->PtrJ->ConteudoJogador[*i][*j].Direita=='V'){
                // Avança para a sala em baixo
                (*i) = (*i) + 1;
                printf("%d %d \n",*I_Ramificacao, *J_Ramificacao);
                int result1 = backtracking(Ptr, Var_TipoMatriz, i, j, pilha, I_Ramificacao, J_Ramificacao);
                if (result1 == -1 || result1 == 1) {
                    Ptr->PtrJ->ConteudoJogador[*i][*j].Valor = '0';
                    desempilha_PILHA(&pilha);

                }
                // Avança para a sala à direita
                (*j) = (*j) + 1;
                int result2 = backtracking(Ptr, Var_TipoMatriz, i, j, pilha, I_Ramificacao, J_Ramificacao);
                if (result2 == -1) {
                    Ptr->PtrJ->ConteudoJogador[*i][*j].Valor = '0';
                    desempilha_PILHA(&pilha);
                }
            }
            // Restaurar as posições após as chamadas recursivas
            (*i) = *I_Ramificacao;
            (*j) = *J_Ramificacao;

            // Desempilhar quando retornar da chamada recursiva
            desempilha_PILHA(&pilha);

        }else{
            //printf("Entra aqui!\n");
            //Apenas uma das direções é possível, sem o risco de repetir o mesmo padrão de movimento
            //Avança para a sala em baixo
            if(Ptr->PtrJ->ConteudoJogador[*i][*j].Baixo=='V'){
                (*i) = (*i) + 1;
                backtracking(Ptr,Var_TipoMatriz,i,j,pilha,I_Ramificacao,J_Ramificacao);
            }
            //Avança para a sala de cima
            if(Ptr->PtrJ->ConteudoJogador[*i][*j].Cima=='V'){
                (*i) = (*i) - 1;
                backtracking(Ptr,Var_TipoMatriz,i,j,pilha,I_Ramificacao,J_Ramificacao);
            }
            //Avança para a sala da esquerda
            if(Ptr->PtrJ->ConteudoJogador[*i][*j].Esquerda=='V'){
                (*j) = (*j) - 1;
                backtracking(Ptr,Var_TipoMatriz,i,j,pilha,I_Ramificacao,J_Ramificacao);
            }
            //Avança para a sala da direita
            if(Ptr->PtrJ->ConteudoJogador[*i][*j].Direita=='V'){
                //printf("Dentro de Direita!\n");
                (*j) = (*j) + 1;
                backtracking(Ptr,Var_TipoMatriz,i,j,pilha,I_Ramificacao,J_Ramificacao);
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

void Printar(Jogador *Ptr){
    for(int i = 0;i<Ptr->TamanhoJogadorX;i++){
        for(int j = 0;j<Ptr->TamanhoJogadorY;j++){
            printf("%c ", Ptr->PtrJ->ConteudoJogador[i][j].Valor);
        }
        printf("\n");
    }
    printf("\n");
}