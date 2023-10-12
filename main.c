#include "Headers/lerArquivo.h"

int main(){

    TIPO_MATRIZ matrix = lerMatrizArquivo("ArquivosTeste/ExemploDoc.txt");

    imprimeMatriz(matrix);

    return 0;
}