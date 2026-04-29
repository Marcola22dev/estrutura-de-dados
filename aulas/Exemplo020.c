#include <stdio.h>
#include <stdlib.h>

// Definindo cada ITEM de uma lista ENCADEADA

typedef struct Item {

    int Chave; // Ou qualquer informação de interesse
    struct Item * Proximo;

} Item;

Item * CriarItem(int Chave);

// Utilizando a estrutura para criar um novo Item

int main() {

    system("cls");

    Item * A = CriarItem(25);
    Item * B = CriarItem(36);
    Item * C = CriarItem(40);
    Item * D = CriarItem(10);

    // Construindo o encadeamento A -> B -> C -> D

    A->Proximo = B;
    B->Proximo = C;
    C->Proximo = D;
    
    return 0;

}


Item * CriarItem(int Chave) {

    Item * I = (Item *) malloc (sizeof(Item));

    if (I == NULL) {
        printf("ERRO: não foi possível alocar memória para o item!\n");
        return NULL;
    }

    I->Chave = Chave;
    I->Proximo = NULL; // Não existe item depois do I

    printf("%X \t %d \t %X \n", I, I->Chave, I->Proximo);

    return I;

}