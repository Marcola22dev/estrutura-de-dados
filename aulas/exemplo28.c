#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// definindo cada item de uma lista duplamente encadeada

typedef struct Item {

    int Time[20];
    struct Item * Proximo; // endereço de memória próximo item
    struct Item * Anterior; // endereço de memória item anterior

} Item;

Item * CriarItem(char * Time);

int main() {
    system("cls");

    

    


    return 0;
}

Item *CriarItem(char * Time) {

    Item * I = (Item *) malloc(sizeof(Item));

    if (I == NULL) {
        printf("Erro na alocação de memória");
        return NULL;
    }

    strcpy(I->Time, Time); //Copiou o ponteiro Time em I->Time
    I->Anterior = NULL;
    I->Proximo = NULL;

    return I;
}

void ExibirLista(Item *I) {

    Item *Atual = I; // atual aponta para o ínicio da lista

    printf("\n");

    while (Atual != NULL) {
        Printf("%s", Atual->Time);
        Atual = Atual->Proximo; // avançar para a próxima posição
    }
}

