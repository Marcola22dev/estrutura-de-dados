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
}Lista;

// Implementando funções

Item * CriarItem(char *titulo, char *autor, int ano);
void ExibirLista (Lista * L);
Lista * CriarLista();
void inserirItem(Lista *L, int Posicao, Item *I);

int main() {

    system("cls");

// 
    
    Musica * D = CriarItem("Aquarela", "Toquinho", 1983);
    Musica * E = CriarItem("Romaria", "Renato Teixeira", 1978);
    Musica * F = CriarItem("Eu nasci há dez mil anos atrás", "Raul Seixas", 1976);
    Musica * G = CriarItem("Cálice", "Chico Buarque e Gilberto Gil", 1978);
    Musica * H = CriarItem("Tempo Perdido", "Renato Russo", 1986);

// encadeamento: D -> E -> F -> G -> H

    D->anterior = NULL;
    D->proximo = E;

    E->anterior = D;
    E->proximo = F;

    F->anterior = E;
    F->proximo = G;

    G->anterior = F;
    G->proximo = H;

    H->anterior = G;
    H->proximo = NULL;

// Inserindo uma nova musica na playlist

    Item * I = CriarItem("É", "Gonzaguinha", 1990);

    G->proximo = I;
    I->anterior = G;
    I->proximo = H;
    H->anterior = I;

    Item * J = CriarItem("Velha Infancia", "Nando Reis", 2002);

    H->proximo = J;
    J->anterior = H;
    J->proximo = NULL;
    
    Item * K = CriarItem("A vida é um moinho", "Cartola", 1962);

    K->anterior = NULL;
    K->proximo = D;
    D->anterior = K;
    


// exibindo a lista

    Lista * playlist = CriarLista();

    playlist->inicio = K;
    playlist->tamanho = 8;

    ExibirLista(playlist);

// como acessar o 3 elemento da lista a partir da variável playlist usando ponteiros temporários

    Item * Atual = playlist->inicio; // Atual = D
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

void ExibirLista (Lista * L) {

    Musica * Atual = L->inicio;

    while (Atual != NULL) {
        printf("%x | %s\n", Atual, Atual->Titulo);
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

void inserirItem(Lista *L, int Posicao, Item *I){
    if (Posicao == 0){
        I->proximo = L->inicio;
        if (L->inicio != NULL) L->inicio->anterior = I;
        L->inicio - I;
    }
}