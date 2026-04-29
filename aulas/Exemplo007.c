#include <stdio.h>
#include <stdlib.h>

int main() {

    system ("cls");

    FILE * fp = fopen("Bloco.txt", "a");

    if (fp == NULL) {
        printf("ERRO: o arquivo não existe!!!");
        exit(1);
    }

    int Numero = 312;
    char Frase[] = "Neste semestre, os TP serão em grupos de 4 alunos!\n";

    fprintf(fp, "%d\t", Numero);
    fprintf(fp, "%s", Frase);
    fprintf(fp, "\n");
    
    fclose(fp);
    
    return 0;

}