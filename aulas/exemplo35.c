#include <stdio.h>
#include <stdlib.h>

// Implementar uma fila array (vetor)

typedef struct {
    int chave;
}Item;

Item CriarItem(int chave);


int main () {

    system("cls");

// Como criar variáveis do tipo Item

    Item A = CriarItem(137);
    Item B = CriarItem(241);
    Item C = CriarItem(339);

    Item fila[3]; // Alocação estática
    
    fila[0] = A;
    fila[1] = B;
    fila[2] = C;

// Exibindo vetor de Itens

    for(int i = 0; i < 3; i++) {
        printf("%d\t", fila[i]);
    }

    return 0;
}

// Uma fila é uma estrutura de dados do tipo FIFO – First In, First Out, ou seja, o primeiro elemento que entra
// é o primeiro a sair. Nas filas, a operação Inserção (enfileirar) ocorre em uma extremidade da fila
// (geralmente chamada de traseira ou fim), e a Remoção (desenfileirar) ocorre na outra extremidade
// (chamada de frente ou início).

// FUNÇÕES  

Item CriarItem(int chave) { 

    Item I; // variável de retorno

    I.chave = chave; // criando um Item
 // (.) é utilizado pq declaramos uma variável
    return I;
}