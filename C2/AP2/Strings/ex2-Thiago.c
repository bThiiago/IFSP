#include <stdio.h>
#include <locale.h>

void ler_nome(char nome[100])
{
    char ini[1] = {0}, rest[50] = {0};
    int i;

    printf("\n\tDigite seu nome: ");
    gets(nome);

    for (i = 0; nome[i + 1] != '\0'; i++)
    {
        if (i == 0)
        {
            ini[0] = nome[0];
            printf("\tIniciais do nome: %c", ini[i]);
        }
        if (nome[i] == ' ')
        {
            rest[i] = nome[i + 1];
            printf(" %c", rest[i]);
        }
    }
}

void saber_nomes(char nome[100])
{
    int i, cont = 1;

    for (i = 0; i < nome[i]; i++)
    {
        if (nome[i] == ' ')
        {
            cont++;
        }
    }

    printf("\n\n\tVoce possui %d nomes.\n\n", cont);
}

void quantidade_caracteres(char nome[100])
{
    int *qnt;

    qnt = strlen(nome);

    printf("\tO nome possui %d caracteres.", qnt);
}

void possivel_email(char nome[100])
{
    char pri[100] = {0};
    char *end;
    int i, tam = 0;

    for (i = 0; i < nome[i]; i++)
    {
        if (nome[i] == ' ')
        {
            tam = i;
        }
    }

    strncat(pri, strrchr(nome, nome[0]), tam);
    end = strrchr(nome, ' ') + 1;

    printf("\n\n\tPossivel email: %s%s@gmail.com", pri, end);
}

void retirar_espacos(char nome[100])
{
    int i;

    printf("\n\n\t");
    for (i = 0; i < 100; i++)
    {
        if (nome[i] != ' ')
        {
            printf("%c", nome[i]);
        }
    }
    printf("\n\n");
}

void quantidade_letras(char nome[100])
{
    int *qnt;
    int i, esp = 0;

    for (i = 0; i < 100; i++)
    {
        if (nome[i] == ' ')
        {
            esp++;
        }
    }

    qnt = strlen(nome) - esp;

    printf("\n\tO nome possui %d letras.", qnt);
}

void main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    char nome[100] = {0};

    ler_nome(nome);
    saber_nomes(nome);
    quantidade_caracteres(nome);
    quantidade_letras(nome);
    possivel_email(nome);
    retirar_espacos(nome);
}