all:
	gcc main.c Headers/lerArquivo.h src/lerArquivo.c Headers/cores.h Headers/auxiliares.h src/auxiliares.c

Linux:
	./a.out
Windows:
	./a.exe
