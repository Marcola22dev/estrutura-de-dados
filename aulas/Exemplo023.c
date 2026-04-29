#include <stdio.h>
#include <stdlib.h>

// Definindo cada ITEM de uma lista ENCADEADA

typedef struct Item {

    int Chave; // Ou qualquer informação de interesse
    struct Item * Proximo;

} Item;

Item * CriarItem(int Chave);
void ExibirLista(Item * I);

// Utilizando a estrutura para criar um novo Item

int main() {

    system("cls");

    Item * A = CriarItem(25);
    Item * B = CriarItem(36);
    Item * C = CriarItem(40);
    Item * D = CriarItem(10);

    // Construindo o encadeamento A -> C -> D -> B (último elemento)

    A->Proximo = C;
    C->Proximo = D;
    D->Proximo = B;

    ExibirLista(A);
    

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

void ExibirLista(Item * I) {

    Item * Atual = I; // Atual aponta para o início da lista (I)

    printf("\n");

    while (Atual != NULL) {
        printf("%X \t %d \t %X \n", Atual, Atual->Chave, Atual->Proximo);
        Atual = Atual->Proximo; // Avançar para a próxima posição
    }

}