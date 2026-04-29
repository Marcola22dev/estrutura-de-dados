#include <stdio.h>
#include <stdlib.h>

int main() {

    system ("cls");

    FILE * fp = fopen("Tabuada.txt", "w");

    if (fp == NULL) {
        printf("ERRO: o arquivo não existe!!!");
        exit(1);
    }

    for (int i = 1; i <= 10; i++) {

        fprintf(fp, "7  *  %d  =  %d\n", i, 7 * i);

    }


    
    
    fclose(fp);
    
    return 0;

}