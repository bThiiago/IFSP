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

    arq2 = fopen("ex4-texto.txt", "w");

    if (arq2 == NULL)
    {
        printf("Nao foi possivel criar o arquivo.");
        exit(1);
    }

    c = fgetc(arq);

    while (c != EOF)
    {
        if (c == 'a' || c == 'A')
            fputc('x', arq2);
        else if (c == 'x' || c == 'X')
            fputc('a', arq2);
        else if (c == 'e' || c == 'E')
            fputc('s', arq2);
        else if (c == 's' || c == 'S')
            fputc('e', arq2);
        else if (c == 'r' || c == 'R')
            fputc('i', arq2);
        else if (c == 'i' || c == 'I')
            fputc('r', arq2);
        else if (c == 'o' || c == 'O')
            fputc('g', arq2);
        else if (c == 'g' || c == 'G')
            fputc('o', arq2);
        else
            fputc(c, arq2);

        c = fgetc(arq);
    }

    printf("Arquivo gerado com sucesso!!!");
    fclose(arq);
    fclose(arq2);

    printf("\n");
}