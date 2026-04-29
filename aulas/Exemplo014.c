#include <stdio.h>
#include <stdlib.h>

int main() { 

    FILE * in = fopen("carrinho.csv", "r");

    if (in == NULL) {
        printf("ERRO: não foi possível abrir o arquivo!\n");
        exit(1);
    }

    FILE * out = fopen("carrinho.html", "w");

    if (in == NULL) {
        printf("ERRO: não foi possível abrir o arquivo!\n");
        exit(1);
    }

    // "Saltando" a primeira linha

    char Buffer[10000];
    fscanf(in, "%[^\n]\n", Buffer);
    
    int i = 0;

    /* Cabeçalho HTML + CSS simples */
    fprintf(out,
        "<!DOCTYPE html>\n<html lang=\"pt-BR\">\n<head>\n"
        "<meta charset=\"UTF-8\">\n<title>Lista de Compras</title>\n"
        "<style>"
        "body{font-family:Arial,Helvetica,sans-serif;margin:24px}"
        "table{border-collapse:collapse;width:720px;max-width:100%%}"
        "th,td{border:1px solid #ccc;padding:8px;text-align:left}"
        "th{background:#f2f2f2}"
        "tfoot td{font-weight:bold}"
        "tbody tr:nth-child(even){background:#fafafa}"
        "</style>\n</head>\n<body>\n"
        "<h2>Relatório de Compras</h2>\n"
        "<table>\n"
        "<thead><tr>"
        "<th>#</th><th>Produto</th><th>Quantidade</th>"
        "<th>Preço unitário (R$)</th><th>Total do item (R$)</th>"
        "</tr></thead>\n<tbody>\n");

    char Produto[100];
    int Quantidade;
    float Preco;
    float Total = 0.0;

    while(fscanf(in, "%[^,],%d,%f\n", Produto, &Quantidade, &Preco) == 3) {

        i++;
        float SubTotal = Quantidade * Preco;
        Total = Total + SubTotal;
        fprintf(out,
            "<tr><td>%d</td><td>%s</td><td>%d</td>"
            "<td>%.2f</td><td>%.2f</td></tr>\n",
            i, Produto, Quantidade, Preco, SubTotal);
    }

    fprintf(out,
        "</tbody>\n<tfoot>"
        "<tr><td colspan=\"4\">Valor total da compra</td>"
        "<td>R$ %.2f</td></tr>"
        "</tfoot>\n</table>\n</body>\n</html>\n", Total);
    
    fclose(in);
    fclose(out);

    return 0;

}