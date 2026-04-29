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
Item * CriarItem(char *titulo, char *autor, int ano);
void ExibirLista (Musica * i);

int main() {

    system("cls");

// 
    
    Musica * D = CriarItem("Aquarela", "Toquinho", 1983);
    Musica * E = CriarItem("Romaria", "Renato Teixeira", 1978);
    Musica * F = CriarItem("Eu nasci há dez mil anos atrás", "Raul Seixas", 1976);
    Musica * G = CriarItem("Cálice", "Chico Buarque e Gilberto Gil", 1978);
    Musica * H = CriarItem("Tempo Perdido", "Remato Russo", 1986);


//Listando as músicas

// for(int i = 0; i<=5; i++) {
//     Musica * Atual; 
//     Atual = Atual->proximo;

//     printf("%s\n%s\n%d", Atual->Titulo, Atual->Autor, Atual->Ano);

// }

// Encadeando em ordem alfabética

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

// EXIBINDO ELEMENTOS

    Musica * Atual = D;

    while(Atual != NULL) {
        Atual = Atual->proximo;
        printf("%s\n", Atual->Titulo);
        
    }


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

void ExibirLista (Musica * i) {

    Musica * Atual = i;

    while (Atual != NULL) {
        printf("%x | %s", Atual, Atual->Autor);
        Atual = Atual->proximo;

    }
}

