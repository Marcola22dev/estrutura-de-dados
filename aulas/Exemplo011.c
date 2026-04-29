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

    while(fscanf(in, "%d,%[^,],%d\n", &ID, Nome, &Idade) == 3) {

        printf("%d \t %s \t %d \n", ID, Nome, Idade);

    }

    fclose(in);

    return 0;

}