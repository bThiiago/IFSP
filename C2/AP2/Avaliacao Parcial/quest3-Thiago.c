#include <stdio.h>
#include <locale.h>

void ler_respostas(char resp[3][15])
{
    int lin = 0,
        col = 0;

    for (lin = 0; lin < 3; lin++)
    {
        printf("\n\tAluno %d.\n\n", lin);
        for (col = 0; col < 15; col++)
        {
            fflush(stdin);
            printf("Resposta %d: ", col);
            scanf(" %c", &resp[lin][col]);
        }
    }
}

void gabarito(char gaba[15])
{
    int i;

    printf("\n\tGABARITO\n");
    for (i = 0; i < 15; i++)
    {
        fflush(stdin);
        printf("Resposta da questao %d: ", i);
        scanf(" %c", &gaba[i]);
    }
}

void respostas_corretas(char resp[3][15], char gaba[15], int acertos[3])
{
    int lin = 0,
        col = 0;

    for (lin = 0; lin < 3; lin++)
    {
        for (col = 0; col < 15; col++)
        {
            if (resp[lin][col] == gaba[col])
            {
                acertos[lin] = acertos[lin] + 1;
            }
        }
        printf("\nQuantidade de respostas certas do aluno %d: %d", lin, acertos[lin]);
    }
}

void aprovado(int acertos[3])
{
    int i, aprov = 0, comp;

    comp = acertos[0];
    for (i = 0; i < 3; i++)
    {
        if (acertos[i] > comp)
        {
            aprov = i;
        }
    }

    printf("\n\nO aluno aprovado foi o aluno na posicao %d.\n", aprov);
}

void main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    char resp[3][15] = {{0}};
    char gaba[15] = {0};
    int acertos[3] = {0};

    ler_respostas(resp);
    gabarito(gaba);
    respostas_corretas(resp, gaba, acertos);
    aprovado(acertos);
}