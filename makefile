all:
	gcc backtracking/headersBacktracking/Jogador.h backtracking/headersBacktracking/Pilha.h backtracking/srcBacktracking/Jogador.c backtracking/srcBacktracking/Pilha.c Cores/cores.h LeituraArquivo/headers/FunctionsArquivo.h LeituraArquivo/src/FunctionsArquivo.c LeituraArquivo/src/MainTeste.c

Linux:
	./a.out

Windows:
	./a.exe
