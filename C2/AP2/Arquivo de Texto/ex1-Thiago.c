#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *arquivo;
    char c;
    int linhas = 1;
    int digitos = 0;
    int caracteres = 0;
    int espacos = 0;

    arquivo = fopen("ex1-texto.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    c = fgetc(arquivo);

    while (c != EOF)
    {
        printf("%c", c);

        if (c == 10)
        {
            linhas++;
        }
        if (c >= 48 && c <= 57)
        {
            digitos++;
        }
        if (c != 10 && c != ' ')
        {
            caracteres++;
        }
        if (c == ' ')
        {
            espacos++;
        }

        c = fgetc(arquivo);
    }

    printf("\n\nQuantidade de linhas..............: %d ", linhas);
    printf("\nQuantidade de digitos.............: %d ", digitos);
    printf("\nQuantidade de caracteres..........: %d ", caracteres);
    printf("\nQuantidade de espacos em branco...: %d \n", espacos);

    fclose(arquivo);

    exit(0);
}