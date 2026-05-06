#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // declarando tamnho máximo que será usado no vetor

// Implementar uma fila array (vetor)

    typedef struct {
        int chave;
    }Item;

    typedef struct{
        Item * Dados; // Vetor de daod
        int Inicio;
        int Fim; 
        int Tamanho; // tamanho da fila
        int Capacidade; // quantidade máxima de elementos

    }Fila;

    Item CriarItem(int chave);
    Fila * CriarFIla(int Capacidade);
    void DestruirFila(Fila * F);
    void Enfileirar(Fila * F, Item I);
    void ExibirFila(Fila * F);

    int main () {

        system("cls");

// Como criar variáveis do tipo Item

        Item * Fila = (Item *) malloc(MAX * sizeof(Item)); // Alocação dinamica em tempo de execução
        
        Fila[0] = CriarItem(137);
        Fila[1] = CriarItem(241); 
        Fila[2] = CriarItem(339);

        DestruirFila(Fila);

// Inserir elementos na fila

        Enfileirar(Fila, CriarItem(10));
        Enfileirar(Fila, CriarItem(20));
        Enfileirar(Fila, CriarItem(30));
        Enfileirar(Fila, CriarItem(40));

        ExibirFila(Fila);



        return 0;
    }

// FUNÇÕES  

    Item CriarItem(int chave) { 

        Item I; // variável de retorno

        I.chave = chave; // criando um Item
    // (.) é utilizado pq declaramos uma variável
        return I;
    }

// criar fila

    Fila * CriarFIla(int Capacidade) {

        Fila * F = (Fila *) malloc (sizeof(Fila));

        if (F == NULL) {

            return NULL;
        }

        F->Capacidade = Capacidade;
        F->Tamanho = 0;
        F->Inicio = -1;
        F->Fim = -1;
        F->Dados = (Item *) malloc (Capacidade * sizeof(Item));

        if(F->Dados == NULL) {
            free(F); // liberando memória da estrutura da lista
            return NULL;
        }

        return F;
    }

// Excluir fila
    void DestruirFila(Fila * F) {
        if (F = NULL) return;

        free(F->Dados);
        free(F);
    }
    
// Inserir Item na fila

    void Enfileirar(Fila * F, Item I) {
        
        if (F->Fim == F->Capacidade - 1) {
            return; // overflow - tentanto utilizar além da capacidade
        }
        if (F->Inicio == - 1) F->Inicio = 0; 

        F->Fim = F->Fim + 1;
        F->Dados[F->Fim] = I;
        F->Tamanho++;
    }

    void ExibirFila(Fila * F){
        for (int i = F->Inicio; i <= F->Fim; i++) {
            printf("%d\t", F->Dados[i].chave);
        }
        printf("\n");
    }

    
