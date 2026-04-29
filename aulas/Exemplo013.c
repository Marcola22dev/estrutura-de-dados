#include <stdio.h>
#include <stdlib.h>

int main() { 

    FILE * in = fopen("STJ.csv", "r");

    if (in == NULL) {
        printf("ERRO: não foi possível abrir o arquivo!\n");
        exit(1);
    }
   
    // "Saltando" a primeira linha

    char Buffer[10000];
    fscanf(in, "%[^\n]\n", Buffer);
    
    int Contador = 0;

    while(fscanf(in, "%[^\n]\n", Buffer) == 1) {

        Contador++;

    }

    printf("O número de registros da tabela é %d\n", Contador);

    fclose(in);

    return 0;

}