#include <stdio.h>
#include <stdlib.h>

int ehPrimo(int N); // Protótipo da função ehPrimo

int main() {

    system("cls");

    int Numero;

    INICIO:

        printf("Digite um número: ");
        scanf("%d", &Numero);

        if (ehPrimo(Numero) == 1) printf("%d eh PRIMO.\n", Numero);
        else printf("%d NAO é primo!\n", Numero);

        goto INICIO;

    return 0;

}

// Implementação da função ehPrimo.

int ehPrimo(int N) {

    if (N <= 1) return 0;

    int Contador = 0;

    for (int i = 2; i < N; i++) {

        Contador++;
        if(N % i == 0){
            printf("%d ifs \t ", Contador);
            return 0;
        }
    }

    printf("%d ifs \t ", Contador);
    return 1; // Se todos os testes (ifs) falharem, o número é PRIMO!

}