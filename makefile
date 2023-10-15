all:
	gcc main.c Headers/lerArquivo.h src/lerArquivo.c Headers/cores.h Headers/auxiliares.h src/auxiliares.c Headers/pilha.h src/pilha.c Headers/jogador.h src/jogador.c

Linux:
	./a.out
Windows:
	./a.exe

t:
	gcc testeGeraMatriz.c Headers/lerArquivo.h src/lerArquivo.c