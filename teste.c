#include <stdio.h>

#define MAX_LINHAS 100
#define MAX_COLUNAS 100

int linhas, colunas; // Dimensões da matriz
int chavesNecessarias; // Quantidade de chaves necessárias
int metaLinha, metaColuna; // Coordenadas da sala com o baú
char labirinto[MAX_LINHAS][MAX_COLUNAS]; // Matriz do labirinto

// Define as direções possíveis: cima, baixo, esquerda, direita
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// Função para verificar se uma posição é válida
int ehSeguro(int x, int y) {
    return (x >= 0 && x < linhas && y >= 0 && y < colunas && labirinto[x][y] != '1');
}

// Função de backtracking para encontrar o caminho
int encontraCaminho(int x, int y, int chavesColetadas) {
    // Se encontrou o baú com chaves suficientes, retorna verdadeiro
    if (x == metaLinha && y == metaColuna && chavesColetadas == chavesNecessarias) {
        return 1;
    }

    // Verifica todas as direções possíveis
    for (int i = 0; i < 4; i++) {
        int novoX = x + dx[i];
        int novoY = y + dy[i];

        // Verifica se a próxima posição é válida
        if (ehSeguro(novoX, novoY)) {
            // Verifica se a próxima posição contém uma chave
            if (labirinto[novoX][novoY] == 'C') {
                chavesColetadas++;
            }

            // Marca a posição como visitada
            labirinto[novoX][novoY] = '1';

            // Recursivamente tenta encontrar o caminho a partir da próxima posição
            if (encontraCaminho(novoX, novoY, chavesColetadas)) {
                return 1;
            }

            // Desmarca a posição se o caminho não for encontrado
            labirinto[novoX][novoY] = '0';

            // Se a posição tinha uma chave, decrementa a contagem de chaves
            if (labirinto[novoX][novoY] == 'C') {
                chavesColetadas--;
            }
        }
    }

    return 0; // Caminho não encontrado
}

int main() {
    // Leitura dos dados do mapa
    scanf("%d %d", &linhas, &colunas);
    scanf("%d", &chavesNecessarias);
    scanf("%d %d", &metaLinha, &metaColuna);

    for (int i = 0; i < linhas; i++) {
        scanf("%s", labirinto[i]);
    }

    // Inicializa a posição de Indiana Jones
    int linhaInicial = 0, colunaInicial = 0;

    // Encontra a posição inicial de Indiana Jones
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (labirinto[i][j] == '0') {
                linhaInicial = i;
                colunaInicial = j;
                break;
            }
        }
    }

    // Inicializa a matriz como não visitada
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (labirinto[i][j] == '1') {
                labirinto[i][j] = '0';
            }
        }
    }

    // Chama a função de backtracking a partir da posição inicial
    if (encontraCaminho(linhaInicial, colunaInicial, 0)) {
        // Caminho encontrado, imprima-o aqui
        // ...
    } else {
        // Caso sem solução
        printf("Indiana Jones nao consegue abrir o bau :(\n");
    }

    return 0;
}
