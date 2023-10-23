all:
	gcc main.c Headers/lerArquivo.h src/lerArquivo.c Headers/cores.h Headers/auxiliares.h src/auxiliares.c Headers/pilha.h src/pilha.c  Headers/CaminhoRamificado.h src/CaminhoRamificado.c Headers/jogador.h src/jogador.c

Linux:
	./a.out
Windows:
	./a.exe
