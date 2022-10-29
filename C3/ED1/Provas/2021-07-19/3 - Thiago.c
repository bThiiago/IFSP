#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome_astro[50];
    float dimensao;
    int quantidade;
    struct no *prox;
    struct no *ant;
}no;

typedef struct lista {
    no *inicio;
    no *fim;
}lista;

void criar_lista(lista *l) {
    l->inicio = NULL;
    l->fim = NULL;
}

int lista_vazia(lista *l) {
    if (l->inicio == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void inserir_lista(lista *l, char nome[], float dimensao, int quantidade) {
    no *novo = (no*)malloc(sizeof(no));
    no *aux = (no*)malloc(sizeof(no));
    strcpy(novo->nome_astro, nome);
    novo->dimensao = dimensao;
    novo->quantidade = quantidade;
    novo->prox = NULL;
    novo->ant = NULL;

    if (l->fim == NULL) {
        l->inicio = novo;
        l->fim = novo;
    } else {
        l->fim->ant = novo;
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    novo->ant = l->fim;
}

void mostra_lista(lista *l) {
    if (lista_vazia(l)) {
        printf("\nLista vazia!!!\n");
    } else {
        no *aux = (no*)malloc(sizeof(no));
        aux = l->inicio;
        while (aux != NULL) {
            printf("\nNome do astro: %s", aux->nome_astro);
            printf("\nDimensao do astro: %.2f km", aux->dimensao);
            printf("\nQuantidade existente: %d\n", aux->quantidade);
            aux = aux->prox;
        }
        free(aux);
    }
}

int main() {
    lista *l = (lista*)malloc(sizeof(lista));
    criar_lista(l);

    int op;
    char nome[50];
    float dimensao;
    int quantidade;

    do {
        printf("\n1 - Inserir astro \n");
        printf("2 - Mostrar astros \n");
        printf("0 - Sair \n");

        printf("Informe a opcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                
                fflush(stdin);
                printf("\nInforme o nome do astro: ");
                gets(nome);

                printf("Informe a dimensao do astro: ");
                scanf("%f", &dimensao);

                printf("Informe a quantidade existente: ");
                scanf("%d", &quantidade);

                inserir_lista(l, nome, dimensao, quantidade);
                break;
            case 2:
                mostra_lista(l);
                break;
        }
    } while (op != 0);
}