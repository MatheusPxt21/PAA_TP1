all:
	gcc main.c Headers/lerArquivo.h src/lerArquivo.c Headers/cores.h

Linux:
	./a.out
Windows:
	./a.exe
