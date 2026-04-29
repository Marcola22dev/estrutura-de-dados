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

Item * CriarItem(int Chave); // Função que aloca memória para a estrutura de um item
Lista * CriarLista(); // Função que aloca memória para a estrutura de uma lista
void InserirItem(Lista * L, Item * I, int Posicao);

// Utilizando a estrutura para criar um novo Item

int main() {

    system("cls");

    Lista * M = CriarLista();

    InserirItem(M, CriarItem(25), 0);
    InserirItem(M, CriarItem(36), 1);
    InserirItem(M, CriarItem(40), 2);
    InserirItem(M, CriarItem(10), 3);

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

void InserirItem(Lista * L, Item * I, int Posicao) {

    if (Posicao < 0 || Posicao > L->Tamanho) {
        printf("ERRO: ... \n");
        return ;
    }

    if (Posicao == 0) {
        I->Proximo = L->Inicio;
        L->Inicio = I;
    }
    else {
        Item * Atual = L->Inicio;
        for (int i = 0; i < Posicao - 1; i++) Atual = Atual->Proximo;
        I->Proximo = Atual->Proximo;
        Atual->Proximo = I;
    }

    L->Tamanho++;

}