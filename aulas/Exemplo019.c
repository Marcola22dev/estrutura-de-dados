#include <stdio.h>
#include <stdlib.h>

// Definindo cada ITEM de uma lista ENCADEADA

typedef struct Item {

    int Chave; // Ou qualquer informação de interesse
    struct Item * Proximo;

} Item;

// Utilizando a estrutura para criar um novo Item

int main() {

    system("cls");

    Item * A = (Item *) malloc (sizeof(Item));
    
    if (A == NULL) {
        printf("ERRO: não foi possível alocar memória para o item!\n");
        exit(1);
    }

    A->Chave = 25;
    A->Proximo = NULL;

    printf("%X \t %d \t %X \n", A, A->Chave, A->Proximo);

    return 0;

}