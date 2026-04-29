#include <stdio.h>
#include <stdlib.h>

int main() {

    system ("cls");

    FILE * Arq;

    Arq = fopen("Arquivo.txt", "w");

    printf("%X", Arq);

    fclose(Arq);
    
    return 0;

}