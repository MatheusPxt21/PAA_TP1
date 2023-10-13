#include "Headers/lerArquivo.h"
#include "Headers/auxiliares.h"

int main(){

    TIPO_MATRIZ matrix = lerMatrizArquivo("ArquivosTeste/ExemploDoc.txt");

    imprimeMatriz(matrix);

    menu();

    return 0;
}