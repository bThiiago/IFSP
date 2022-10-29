#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char c;

    FILE *arq, *arq2;

    arq = fopen("ex1-texto.txt", "r");

    if (arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo.");
        exit(1);
    }

    arq2 = fopen("ex5-texto.txt", "w");

    if (arq2 == NULL)
    {
        printf("Nao foi possivel criar o arquivo.");
        exit(1);
    }

    c = fgetc(arq);

    while (c != EOF)
    {
        c = c + 28;
        fputc(c, arq2);

        c = fgetc(arq);
    }

    printf("Arquivo gerado com sucesso!!!");
    fclose(arq);
    fclose(arq2);

    printf("\n");
}