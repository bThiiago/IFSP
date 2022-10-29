#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;

    int quant = 0, pro, i;
    float valor = 0, total = 0, subtotal = 0;
    char produto[20];

    arq = fopen("ex1-notafiscal.txt", "a");

    printf("Quantidade de produtos: ");
    scanf("%d", &pro);

    fprintf(arq, "=========================================================\n");
    fprintf(arq, "Supermercado Periférico\n");
    fprintf(arq, "=========================================================\n");
    fprintf(arq, "               NOTA FISCAL AO CONSUMIDOR                 \n");
    fprintf(arq, "---------------------------------------------------------\n");
    fprintf(arq, "Produto                      Valor      Quant    Subtotal\n");
    fprintf(arq, "---------------------------------------------------------");

    for (i = 0; i < pro; i++)
    {
        fflush(stdin);
        printf("\nNome do produto: ");
        gets(produto);
        printf("Valor: ");
        scanf("%f", &valor);
        printf("Quantidade: ");
        scanf("%d", &quant);

        subtotal = valor * quant;
        total = total + subtotal;

        fprintf(arq, "\n%-25s %7.2f %9d %12.2f", produto, valor, quant, subtotal);
    }
    fprintf(arq, "\n---------------------------------------------------------\n");
    fprintf(arq, "Total da Nota Fiscal %35.2f\n", total);
    fprintf(arq, "=========================================================\n\n");

    printf("\nSua nota fiscal foi gerada!\n");

    fclose(arq);

    exit(0);
}