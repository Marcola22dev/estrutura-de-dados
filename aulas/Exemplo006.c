#include <stdio.h>
#include <stdlib.h>

int main() {

    system ("cls");

    FILE * Arq = fopen("ListaTelefonica.csv", "r"); // r = leitura

    if (Arq == NULL) {
        printf("ERRO: o arquivo não existe!!!");
        exit(1);
    }
    printf("%X", Arq);

    fclose(Arq);
    
    return 0;

}