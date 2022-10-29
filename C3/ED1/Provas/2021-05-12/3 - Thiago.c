#define TAM 2
#include <stdio.h>

typedef struct sStack
{
    char nome[50];
    char sexo;
    int idade;
    int itens[TAM];
    int topo;
} STACK;

void init(STACK *S)
{
    S->topo = -1;
}

int isEmpty(STACK *S)
{
    return S->topo == -1 ? 1 : 0;
}

int isFull(STACK *S)
{
    return S->topo + 1 == TAM ? 1 : 0;
}

int push(STACK *S, char nome[], int idade)
{
    if (isFull(S))
    {
        printf("ERRO - A Pilha esta cheia.\n");
        return 1;
    }

    S->itens[++S->topo] = nome;

    return 0;
}

int pop(STACK *S)
{
    if (isEmpty(S))
    {
        printf("\nERRO - A Pilha esta vazia.\n");
        return -1;
    }

    return S->itens[S->topo--];
}

int stackTop(STACK *S)
{
    if (isEmpty(S))
    {
        printf("\nERRO - A Pilha esta vazia.\n");
        return -1;
    }

    return S->itens[S->topo];
}

int main()
{
    STACK PF, PM;
    init(&PF);
    init(&PM);

    int i = 0;
    char nome[50], sexo;
    int idade;

    while (i < TAM)
    {
        fflush(stdin);
        printf("\nNome.........: ");
        gets(nome);

        printf("Sexo (F ou M): ");
        scanf("%c", &sexo);

        printf("Idade........: ");
        scanf("%d", &idade);

        if (sexo == 'F')
        {
            push(&PF, nome, idade);
        }
        else
        {
            if (sexo == 'M')
            {
                push(&PM, nome, idade);
            }
            else
            {
                printf("\nSexo invalido.\n");
                i--;
            }
        };

        i++;
    };

    for (i = PM.topo; i >= 0; i--)
    {
        printf("\n%c", pop(&PM));
    }

    for (i = PF.topo; i >= 0; i--)
    {
        printf("%c\n", pop(&PF));
    }

    return 0;
}