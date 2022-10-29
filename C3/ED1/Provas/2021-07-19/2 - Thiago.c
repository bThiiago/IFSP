#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome_site[50];
    char link_site[50];
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

void inserir_lista(lista *l, char nome[], char link[]) {
    no *novo = (no*)malloc(sizeof(no));
    strcpy(novo->nome_site, nome);
    strcpy(novo->link_site, link);
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
            printf("\nNome do site: %s", aux->nome_site);
            printf("\nLink do site: %s\n", aux->link_site);
            aux = aux->prox;
        }
        free(aux);
    }
}

void buscar_lista(lista *l, char nome[]) {
    if (lista_vazia(l)) {
        printf("\nLista vazia!!!\n");
    } else {
        no *aux = (no*)malloc(sizeof(no));
        aux = l->inicio;
        while (aux != NULL) {
            if(strcmp(aux->nome_site, nome) == 0){
                printf("\nLink do site: %s\n", aux->link_site);
            }
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
    char link[50];
    char nome_busca[50];

    do {
        printf("\n1 - Inserir site \n");
        printf("2 - Buscar site \n");
        printf("3 - Mostrar lista \n");
        printf("0 - Sair \n");

        printf("Informe a opcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                
                fflush(stdin);
                printf("\nInforme o link do site: ");
                gets(link);

                fflush(stdin);
                printf("Informe o nome do site: ");
                gets(nome);

                inserir_lista(l, nome, link);
                break;
            case 2:

                fflush(stdin);
                printf("\nInforme o nome do site: ");
                gets(nome_busca);
                buscar_lista(l, nome);
                break;
            case 3:
                mostra_lista(l);
                break;
        }
    } while (op != 0);
}