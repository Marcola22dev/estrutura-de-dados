#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Item {

    char Titulo[40];
    char Autor[100];
    int Ano;

    struct Item *anterior;
    struct Item *proximo;
}Item;

typedef Item Musica; // renomeando tudo acima para música

typedef struct Lista
{
    int tamanho; // numero de elementos inseridos no conjunto
    Item * inicio; // endereco de memória ou referência aponta pra o primeiro
    Item * fim; // referencia para o ultimo elemento
}Lista;

// Implementando funções

Item * CriarItem(char *titulo, char *autor, int ano);
void ExibirLista (Musica * i);
Lista * CriarLista();

int main() {

    system("cls");

// 
    
    Musica * D = CriarItem("Aquarela", "Toquinho", 1983);
    Musica * E = CriarItem("Romaria", "Renato Teixeira", 1978);
    Musica * F = CriarItem("Eu nasci há dez mil anos atrás", "Raul Seixas", 1976);
    Musica * G = CriarItem("Cálice", "Chico Buarque e Gilberto Gil", 1978);
    Musica * H = CriarItem("Tempo Perdido", "Remato Russo", 1986);

// encadeando os elementos

    D->anterior = NULL;
    D->proximo = G;

    G->anterior = D;
    G->proximo = F;

    F->anterior = G;
    F->proximo = E;

    E->anterior = F;
    E->proximo = H;

    H->anterior = E;
    H->proximo = NULL;

// exibindo a lista

    ExibirLista(D);

    Lista * playlist = CriarLista();

    playlist->inicio = D;
    playlist->tamanho = 5;

// como acessar o 3 elemento da lista a partir da variável playlist usando ponteiros temporários

    Item * Atual = playlist->inicio; // Atual = D]
    Atual = Atual->proximo; // atual aponta para o item 2
    Atual = Atual->proximo; // Atual no item 3

    printf("\n\n%s\n", Atual->proximo);

// Outra maneira de acessar o item desejado sem alocar ponteiros temporários

    printf("%s \n", playlist->inicio->proximo->proximo->Titulo); 

    return 0;

}

// função CriarItem

Musica * CriarItem(char *titulo, char *autor, int ano){
    Musica * i = (Musica *) malloc(sizeof(Musica));

    if(i == NULL){
        printf("Erro na alocação de memória!\n");
        return NULL;
    }

    strcpy(i->Titulo, titulo);
    strcpy(i->Autor, autor);
    i->Ano = ano;
    i->anterior = NULL;
    i->proximo = NULL;

    return i;

}

// Função exibirLista

void ExibirLista (Musica * i) {

    Musica * Atual = i;

    while (Atual != NULL) {
        printf("%x | %s", Atual, Atual->Autor);
        Atual = Atual->proximo;

    }
}

// função CriarLista

Lista * CriarLista(){
    Lista * L = (Lista *) malloc(sizeof(Lista));

    if (L == NULL ){
        printf("Erro");
        return NULL;
    }

    L->inicio = NULL;
    L->tamanho = 0;

    return L;  

}