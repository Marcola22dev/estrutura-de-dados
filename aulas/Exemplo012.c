#include <stdio.h>
#include <stdlib.h>

int main() { 

    FILE * in = fopen("dados.csv", "r");

    if (in == NULL) {
        printf("ERRO: não foi possível abrir o arquivo!\n");
        exit(1);
    }

    int ID;
    char Nome[100];
    int Idade;
    
    // "Saltando" a primeira linha

    char Buffer[100];
    fscanf(in, "%[^\n]\n", Buffer);
    
    int Contador = 0;

    while(fscanf(in, "%d,%[^,],%d\n", &ID, Nome, &Idade) == 3) {

        Contador++;

    }

    printf("O número de registros da tabela é %d\n", Contador);

    fclose(in);

    return 0;

}