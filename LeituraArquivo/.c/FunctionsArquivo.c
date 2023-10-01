#include "C:\Users\mathe\Documents\CC++\C\Proprios\Trabalhos_PAA\TP1\.h\FunctionsArquivo.h"

void ReceberArquivo(char *FilePath, MATRIZTABULEIRO *PtrTabuleiro) {
    FILE *Pointer_File;
    Pointer_File = fopen(FilePath, "r");
    if (Pointer_File == NULL) {
        printf("Erro ao abrir o arquivo!\n");
    } else {
        char buffer[100];
        int linha = 1, Flag = 0, AuXLine = 0, AuXCollun = 0;
        char *AUX_Palavra;
        while (fgets(buffer, 100, Pointer_File) != NULL) {
            AUX_Palavra = strtok(buffer, " \t\n");
            while (AUX_Palavra != NULL) {
                if (Flag == 0 && linha == 1) {
                    PtrTabuleiro->lineMatriz = strtol(AUX_Palavra, NULL, 10);
                    PtrTabuleiro->MatrizJogo = (char **)malloc(PtrTabuleiro->lineMatriz * sizeof(char *));
                    Flag = 1;
                } else if (Flag == 1 && linha == 1) {
                    PtrTabuleiro->collunMatriz = strtol(AUX_Palavra, NULL, 10);
                    for (int i = 0; i < PtrTabuleiro->lineMatriz; i++) {
                        PtrTabuleiro->MatrizJogo[i] = (char *)malloc(PtrTabuleiro->collunMatriz * sizeof(char));
                    }
                    Flag = 0;
                } else if (linha == 2) {
                    PtrTabuleiro->numeroChaves = strtol(AUX_Palavra, NULL, 10);
                } else if (linha == 3 && Flag == 0) {
                    PtrTabuleiro->lineTesouro = strtol(AUX_Palavra, NULL, 10);
                    Flag = 1;
                } else if (linha == 3 && Flag == 1) {
  
                    PtrTabuleiro->collunTesouro = strtol(AUX_Palavra, NULL, 10);
                    Flag = 0;
                } else if (linha >= 4) {
                    PtrTabuleiro->MatrizJogo[AuXLine][AuXCollun] = AUX_Palavra[0];
                    AuXCollun += 1;
                }
                AUX_Palavra = strtok(NULL, " \t\n");
            }
            if (linha >= 4) {
                AuXCollun = 0;
                AuXLine += 1;
            }
            linha++;
        }
        fclose(Pointer_File);
    }
}
