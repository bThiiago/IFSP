#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char c;
    int palavras = 1;

    FILE *arq, *arq2;

    arq = fopen("ex1-texto.txt", "r");

    if (arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo.");
        exit(1);
    }

    arq2 = fopen("ex8-texto.txt", "w");

    if (arq2 == NULL)
    {
        printf("Nao foi possivel criar o arquivo.");
        exit(1);
    }

    c = fgetc(arq);

    while (c != EOF)
    {
        if (c == ' ')
        {
            fputc(10, arq2);
            palavras++;
        }
        else
            fputc(c, arq2);

        c = fgetc(arq);
    }

    printf("\nArquivo gerado com sucesso!!!\n");
    printf("Quantidade de palavras: %d.", palavras);

    fclose(arq);
    fclose(arq2);

    printf("\n");
}