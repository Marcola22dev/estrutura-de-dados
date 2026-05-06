#include <stdio.h>
#include <stdlib.h>
#define MAX 3 // declarando tamnho máximo que será usado no vetor

// Implementar uma fila array (vetor)

typedef struct {
    int chave;
}Item;

Item CriarItem(int chave);

// Simplificando a função principal (eliminando as variaveis a,b,c)

    // Item A = CriarItem(137); -> fila[0] = CriarItem(137);
    // Item B = CriarItem(241); -> fila[1] = CriarItem(241); 
    // Item C = CriarItem(339); -> fila[2] = CriarItem(339);

    // Pode criar em uma variável isolada e outra direto no vetor

int main () {

    system("cls");

// Como criar variáveis do tipo Item

    Item * fila = (Item *) malloc(MAX * sizeof(Item)); // Alocação dinamica em tempo de execução
    
    fila[0] = CriarItem(137);
    fila[1] = CriarItem(241); 
    fila[2] = CriarItem(339);

// Exibindo vetor Structs (Item´s)

    for(int i = 0; i < MAX; i++) {
        printf("%d\t", fila[i].chave);
    }

    return 0;
}

// FUNÇÕES  

Item CriarItem(int chave) { 

    Item I; // variável de retorno

    I.chave = chave; // criando um Item
 // (.) é utilizado pq declaramos uma variável
    return I;
}