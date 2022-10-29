#include <stdio.h>
#include <locale.h>

void quantos_querem(int *pontn)
{

    printf("\n\t\tLEMBRE-SE, para prontu�rios de final X utilize 0.");

    printf("\n\nInforme quantos alunos querem o aux�lio: ");
    scanf("%d", pontn);
}

void quantos_serao(int *pontb)
{

    printf("Informe quantos alunos ser�o beneficiados: ");
    scanf("%d", pontb);

    printf("\n");
}

void ler_alunos(int p[100], int n)
{

    int i;

    for (i = 0; i < n; i++)
    {
        printf("Prontu�rio do aluno: ");
        scanf("%d", &p[i]);
        printf("Posi��o do aluno: %d.\n\n", i);
    }
}

void beneficiados(int p[100], int b)
{

    int i;

    printf("\n  Classifica��o dos alunos que ser�o beneficiados: \n\n");
    for (i = 0; i < b; i++)
    {
        printf("\tAluno %d: PE-%d.\n", i, p[i]);
    }
}

void classificacao(int p[100], int n)
{

    int i;

    printf("\n  Classifica��o completa:\n\n");
    for (i = 0; i < n; i++)
    {
        printf("\tAluno %d: PE-%d.\n", i, p[i]);
    }
}

void main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int pront[100] = {0};
    int n, b;

    quantos_querem(&n);
    quantos_serao(&b);

    ler_alunos(pront, n);
    beneficiados(pront, b);
    classificacao(pront, n);
}
