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

int main() {

    system("cls");
    Musica *D, *E, *F, *G, *H;

// Reservando memória para uma musica 

    Musica * D = (Musica *) malloc(sizeof(Musica));

    if (D == NULL) {
        printf("Erro na alocação de memória");
        exit(1); // erro1
    }

    strcpy(D->Titulo, "Aquarela"); 
    strcpy(D->Autor, "Toquinho");
    D->Ano = 1983;

   
    D->anterior = NULL;
    D->proximo = E;

// Musica E

    Musica * E = (Musica *) malloc(sizeof(Musica));

    if (E == NULL) {
        printf("Erro na alocação de memória");
        exit(1); // erro1
    }

    strcpy(E->Titulo, "Romaria"); 
    strcpy(E->Autor, "Renato Teixeira");
    E->Ano = 1978;

   
    E->anterior = D;
    E->proximo = F;

// musica F

    Musica * F = (Musica *) malloc(sizeof(Musica));

    if ( F == NULL) {
        printf("Erro na alocação de memória");
        exit(1); // erro1
    }

    strcpy(F->Titulo, "Eu nasci há dez mil anos atrás"); 
    strcpy(F->Autor, "Raul Seixas");
    F->Ano = 1976;

   
    F->anterior = E;
    F->proximo = G;

// Musica G

    Musica * G = (Musica *) malloc(sizeof(Musica));

    if ( G == NULL) {
        printf("Erro na alocação de memória");
        exit(1); // erro1
    }

    strcpy(G->Titulo, "Cálice"); 
    strcpy(G->Autor, "Chico Buarque e Gilberto Gil");
    G->Ano = 1978;

   
    G->anterior = F;
    G->proximo = H;

// Musica H 

Musica * H = (Musica *) malloc(sizeof(Musica));

    if ( H == NULL) {
        printf("Erro na alocação de memória");
        exit(1); // erro1
    }

    strcpy(H->Titulo, "Tempo Perdido"); 
    strcpy(H->Autor, "Renato Russo");
    H->Ano = 1986;

   
    H->anterior = G;
    H->proximo = NULL;

//Listando as músicas

for(int i = 0; i<=5; i++) {
    Musica * Atual; 
    Atual = Atual->proximo;

    printf("%s\n%s\n%d", Atual->Titulo, Atual->Autor, Atual->Ano);
}



    return 0;

}