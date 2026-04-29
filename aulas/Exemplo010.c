#include <stdio.h>
#include <stdlib.h>

int main() { 

    FILE * in = fopen("nomes.txt", "r");

    if (in == NULL) {
        printf("ERRO: não foi possível abrir o arquivo!\n");
        exit(1);
    }

    int Numero;
    char Nome[100]; 

    while(fscanf(in, "%d %[^\n]\n", &Numero, Nome) == 2) {

        printf("%d \t %s \n", Numero, Nome);

    }

    fclose(in);

    return 0;

}