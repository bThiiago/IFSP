#include <stdio.h>
#include <string.h>

int main()
{
    FILE *arquivo1, *arquivo2;
    char c;

    arquivo1 = fopen("q2-texto.txt", "rt");

    if (arquivo1 == NULL)
    {
        printf("Arquivo nao existe.");
        exit(1);
    }

    arquivo2 = fopen("q2-copia.txt", "w");

    if (arquivo2 == NULL)
    {
        printf("Nao foi possivel criar o arquivo.");
        exit(1);
    }

    c = fgetc(arquivo1);

    while (c != EOF)
    {
        if (c != 'A' && c != 'a' && c != 'E' && c != 'e' && c != 'I' && c != 'i' && c != 'O' && c != 'o' && c != 'U' && c != 'u')
        {

            fputc(c, arquivo2);
        }
        c = fgetc(arquivo1);
    }

    fputc(10, arquivo2);
    fseek(arquivo1, 0, SEEK_SET);
    c = fgetc(arquivo1);

    while (c != EOF)
    {
        if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u')
        {
            fputc(c, arquivo2);
        }
        c = fgetc(arquivo1);
    }

    printf("Texto copiado.");

    fclose(arquivo1);
    fclose(arquivo2);

    return 0;
}