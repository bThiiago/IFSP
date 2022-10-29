#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    unsigned int prontuario;
    float nota;
    struct no *prox;
    struct no *ant;
} no;

typedef struct lista
{
    no *inicio;
    no *fim;
} lista;

void criar_lista(lista *l)
{
    l->inicio = NULL;
    l->fim = NULL;
}

int lista_vazia(lista *l)
{
    if (l->inicio == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inserir_lista(lista *l, int prontuario, float nota)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->prontuario = prontuario;
    novo->nota = nota;
    novo->prox = NULL;
    novo->ant = NULL;

    if (l->fim == NULL)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        l->fim->ant = novo;
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    novo->ant = l->fim;
}

void mostra_lista(lista *l)
{
    if (lista_vazia(l))
    {
        printf("\nLista vazia!!!\n");
    }
    else
    {
        no *aux = (no *)malloc(sizeof(no));
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("\nProntuario: %d", aux->prontuario);
            printf("\nNota: %.2f\n", aux->nota);
            aux = aux->prox;
        }
        free(aux);
    }
}

/* void buscar_lista(lista *l, char nome[])
{
    if (lista_vazia(l))
    {
        printf("\nLista vazia!!!\n");
    }
    else
    {
        no *aux = (no *)malloc(sizeof(no));
        aux = l->inicio;
        while (aux != NULL)
        {
            if (strcmp(aux->nome_site, nome) == 0)
            {
                printf("\nLink do site: %s\n", aux->link_site);
            }
            aux = aux->prox;
        }
        free(aux);
    }
} */

int main()
{
    lista *l = (lista *)malloc(sizeof(lista));
    criar_lista(l);

    int op;
    int prontuario;
    float nota;

    do
    {
        printf("\n1 - Inserir aluno.\n");
        printf("2 - Alunos ordenados por nota.\n");
        printf("3 - Alunos ordenados por prontuario.\n");
        printf("0 - Sair.\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nProntuario do aluno...: ");
            scanf("%d", &prontuario);

            printf("Nota do aluno.........: ");
            scanf("%f", &nota);

            inserir_lista(l, prontuario, nota);
            break;

        case 2:
            mostra_lista(l);
            break;

        case 3:
            mostra_lista(l);
            break;
        }
    } while (op != 0);
}