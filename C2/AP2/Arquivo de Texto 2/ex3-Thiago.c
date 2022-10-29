#include <stdio.h>

int main()
{
    FILE *arq, *arq2;

    char c;
    int i, pos;

    arq = fopen("ex3-original.txt", "r");

    if (arq == NULL)
    {
        printf("o arquivo nao existe.");
        exit(1);
    }

    arq2 = fopen("ex3-inverso.txt", "w");

    fseek(arq, 0, SEEK_END);

    pos = ftell(arq);

    i = 0;
    while (i < pos)
    {
        i++;
        fseek(arq, -i, SEEK_END);
        c = fgetc(arq);
        fputc(c, arq2);
    }

    fclose(arq);
    fclose(arq2);
    exit(0);
}