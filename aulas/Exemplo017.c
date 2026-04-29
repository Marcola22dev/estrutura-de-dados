#include <stdio.h>
#include <stdlib.h>

// Definição dos DADOS do TAD Fração

typedef struct {
    int Numerador;
    int Denominador;
} Fracao;

// Definição das OPERAÇÕES (funções) do TAD Fração

Fracao criarFracao(int N, int D);
void exibirFracao(Fracao F);
Fracao inverterFracao(Fracao F);

// Implementação da função principal (main)

int main() {

    system("cls");

    Fracao F1 = criarFracao(3, 7);
    Fracao F2 = criarFracao(12, 20);
    Fracao F3 = criarFracao(6, 4);

    exibirFracao(F1);
    exibirFracao(F2);
    exibirFracao(F3);

    Fracao F4 = inverterFracao(F1);
    exibirFracao(F4);

    exibirFracao(inverterFracao(F2));
    exibirFracao(inverterFracao(F3));
    
}

Fracao criarFracao(int N, int D) {

    if (D == 0) {
        printf("ERRO: não é possível criar fração com denominador 0!\n");
        exit(1);
    }

    Fracao F;
    F.Numerador = N;
    F.Denominador = D;
    return F;

}

void exibirFracao(Fracao F) {

    printf("%d / %d \n", F.Numerador, F.Denominador);

}

Fracao inverterFracao(Fracao F) {

    Fracao G;

    G.Numerador = F.Denominador;
    G.Denominador = F.Numerador;

    return G;

}