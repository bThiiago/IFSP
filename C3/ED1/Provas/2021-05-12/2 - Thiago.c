#include <stdio.h>
#include <string.h>

#define TAMMAX 200

typedef struct sAluno
{
    char nome[50];
    int prontuario;
} Aluno;

typedef struct sFila
{
    Aluno alunos[200];
    int inicio, fim;
} Fila;

void inicializa(Fila *f)
{
    f->inicio = TAMMAX - 1;
    f->fim = TAMMAX - 1;
}

int vazia(Fila *f)
{
    return f->fim == f->inicio ? 1 : 0;
}

int cheia(Fila *f)
{
    return f->fim == f->inicio ? 1 : 0;
}

void enfileirar(Fila *f, Aluno aluno)
{

    if (f->inicio == 0)
    {
        f->inicio = TAMMAX - 1;
    }
    else
    {
        f->inicio--;
    }
    if (cheia(f))
    {
        printf("\nERRO: Fila cheia.\n");
        f->inicio = (f->inicio + 1) % TAMMAX;
        return;
    }
    f->alunos[(f->inicio + 1) % TAMMAX] = aluno;
}

Aluno desenfileirar(Fila *f)
{
    Aluno aux;

    if (!vazia(f))
    {
        if (f->fim == 0)
        {
            f->fim == TAMMAX - 1;
        }
        else
        {
            f->fim--;
        }
        aux = f->alunos[f->fim];
    }
    else
    {
        printf("ERRO: Fila Vazia.\n");
    }

    return aux;
}

void imprimir(Fila *f)
{
    if (vazia(f))
    {
        printf("\nFila vazio.\n");
        return;
    }

    int i = (f->inicio + 1) % TAMMAX;
    while (i != ((f->fim + 1) % TAMMAX))
    {
        printf("\nNome: %s.\n", f->alunos[i].nome);
        printf("Prontuario: %d.\n", f->alunos[i].prontuario);
        i = (i + 1) % TAMMAX;
    }
}

Aluno criaAluno(char nome[], int *pront)
{
    Aluno a;
    strcpy(a.nome, nome);
    a.prontuario = *pront;

    return a;
};

int main()
{
    int opcao;
    int temp;
    char nome[50];

    Fila fila;
    inicializa(&fila);

    Aluno alunos;
    do
    {
        printf("\n1 - Inserir.\n");
        printf("2 - Remover.\n");
        printf("3 - Imprimir.\n");
        printf("0 - Finalizar.\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            fflush(stdin);
            printf("\nNome do aluno.........: ");
            gets(nome);

            printf("Prontuario do aluno...: ");
            scanf("%d", &temp);

            enfileirar(&fila, criaAluno(nome, &temp));
            break;

        case 2:
            desenfileirar(&fila);
            break;

        case 3:
            imprimir(&fila);
            break;

        default:
            break;
        }
    } while (opcao != 0);

    return 0;
}