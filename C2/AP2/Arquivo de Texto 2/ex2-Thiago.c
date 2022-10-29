#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *arq, *arq2;

    char c;
    int quant = 0, pro = 0, i = 0, retorno;
    float valor = 0, total = 0, subtotal = 0;
    char produto[26];

    arq = fopen("ex2-ler.txt", "r");

    if (arq == NULL)
    {
        printf("o arquivo nao existe.");
        exit(1);
    }

    arq2 = fopen("ex2-notafiscal.txt", "a");

    retorno = fscanf(arq, "%s\n%f %d\n", produto, &valor, &quant);

    fprintf(arq2, "=========================================================\n");
    fprintf(arq2, "Supermercado Periférico\n");
    fprintf(arq2, "=========================================================\n");
    fprintf(arq2, "               NOTA FISCAL AO CONSUMIDOR                 \n");
    fprintf(arq2, "---------------------------------------------------------\n");
    fprintf(arq2, "Produto                      Valor      Quant    Subtotal\n");
    fprintf(arq2, "---------------------------------------------------------");

    while (retorno != EOF)
    {
        subtotal = valor * quant;
        total = total + subtotal;
        for (i = 0; i < 99; i++)
        {
            if (produto[i] == '_')
            {
                produto[i] = ' ';
            }
        }
        fprintf(arq2, "\n%-25s %7.2f %9d %12.2f", produto, valor, quant, subtotal);
        retorno = fscanf(arq, "%s\n%f %d\n", produto, &valor, &quant);
    }

    fprintf(arq2, "\n---------------------------------------------------------\n");
    fprintf(arq2, "Total da Nota Fiscal %35.2f\n", total);
    fprintf(arq2, "=========================================================\n\n");

    printf("\nSua nota fiscal foi gerada!\n");

    fclose(arq);
    fclose(arq2);

    exit(0);
}