#include <stdio.h>
#include <stdlib.h>

int main() {

    system ("cls");

    FILE * fp = fopen("Bloco.txt", "r");

    if (fp == NULL) {
        printf("ERRO: o arquivo não existe!!!");
        exit(1);
    }

    int Numero;
    char Nome[50];


    for (int i = 1; i <= 3; i++) {
        fscanf(fp, "%d %[^\n]", &Numero, Nome);
        printf("%d) %d \t %s \n", i, Numero, Nome); 
    }
    

    fclose(fp);
    
    return 0;

}