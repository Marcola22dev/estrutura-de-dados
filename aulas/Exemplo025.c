#include <stdio.h>
#include <stdlib.h>

// Definindo cada ITEM de uma lista ENCADEADA

typedef struct Item {

    int Chave; // Ou qualquer informação de interesse
    struct Item * Proximo;

} Item;

typedef struct {

    int Tamanho;
    Item * Inicio;

} Lista;

Item * CriarItem(int Chave);
Lista * CriarLista();

int ContarPares(Item * I); // I é 1° item da lista

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

    Lista * M = CriarLista();
    
    M->Inicio = A;
    M->Tamanho = 4;

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

    return I;

}

int ContarPares(Item * I) {

    int Contador = 0;

    while(I != NULL) {
        if (I->Chave % 2 == 0) Contador++;
        I = I->Proximo;
    }

    return Contador;

}


Lista * CriarLista() {

    Lista * L = (Lista *) malloc (sizeof(Lista));

    if (L == NULL) {
        printf("ERRO: não existe memória para armazenar a Lista!\n");
        return NULL;
    }

    printf("A lista está armazenada no endereço %X.\n", L);

    L->Tamanho = 0;
    L->Inicio = NULL;

    return L;

}