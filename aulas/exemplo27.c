#include <stdlib.h>
#include <stdio.h>

// definindo cada item de uma lista duplamente encadeada

typedef struct Item {

    int Chave;
    struct Item * Proximo; // endereço de memória próximo item
    struct Item * Anterior; // endereço de memória item anterior

} Item;

Item * CriarItem(int Chave);

int main() {
    system("cls");

    Item * A = CriarItem(10);
    Item * B = CriarItem(20);
    Item * C = CriarItem(30);
    Item * D = CriarItem(40);
    Item * E = CriarItem(50);
    Item * F = CriarItem(60);

    A->Anterior = NULL; 
    A->Proximo = B;

    B->Anterior = A; 
    B->Proximo = C;

    C->Anterior = B; 
    C->Proximo = D;

    D->Anterior = C; 
    D->Proximo = E;

    E->Anterior = D; 
    E->Proximo = F;

    F->Anterior = E; 
    F->Proximo = NULL;

    // como ir para o Item B, a partir de D?

    Item * Atual; 

    Atual = D; // definindo que o D é onde estamos no sistema
    Atual = Atual->Anterior; // o Atual que é o D aponta para C
    Atual = Atual->Anterior; // Do Item C vai para B

    printf("Item D para B\n");
    printf("solucao 1: %d\n", Atual->Chave);
    printf("Solucao 2: %d\n\n", D->Anterior->Anterior->Chave);

    // ITEM E, A PARTIR DO ITEM C

    printf("Solucao Item C para E\n");
    printf("Solucao:  %d", C->Proximo->Proximo->Chave);


    return 0;
}

Item *CriarItem(int Chave) {

    Item * I = (Item *) malloc(sizeof(Item));

    if (I == NULL) {

        printf("Erro na alocação de memória");
        return NULL;
    }

    I->Chave = Chave;
    I->Proximo = NULL;
    I->Anterior = NULL;


    return I;
}

