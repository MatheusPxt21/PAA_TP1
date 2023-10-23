cmake_minimum_required(VERSION 3.26)
project(TP_PAA C)

set(CMAKE_C_STANDARD 11)

add_executable(TP_PAA main.c
        src/auxiliares.c
        src/CaminhoRamificado.c
        src/jogador.c
        src/lerArquivo.c
        src/pilha.c
        ArquivosTeste/ExemploDoc.txt)
