#include <stdio.h>

typedef struct cell {
    int info;
    struct cell *next;
} CELULA;

CELULA* inicializa(CELULA *list) {
    list=NULL;
    return list;
}

CELULA* getnode() {
    return (CELULA*) malloc(sizeof(CELULA));
}

void freenode(CELULA *q) {
    free(q);
}

int vazia(CELULA *list) {
    if (list==NULL) return 1;
    return 0;
}

CELULA* insereInicio(CELULA *list, int x) {
    CELULA *q;

    q=getnode();

    if(q !=NULL) {
        q->info=x;
        q->next=list;
        list=q;
        return list;
    }

    else {
        printf("\nErro na alocação do nó.\n");
        return NULL;
    }
}

CELULA* insereFim(CELULA *list, int x) {
    CELULA *q;
    CELULA *aux;

    q=getnode();

    if(q !=NULL) {
        q->info=x;
        q->next=NULL;

        if(vazia(list)) {
            list=q;
        }

        else {
            aux=list;

            while(aux->next !=NULL) {
                aux=aux->next;
            }

            aux->next=q;
        }

        return list;
    }

    else {
        printf("\nErro na alocação do nó.\n");
        return NULL;
    }
}

CELULA* removeInicio(CELULA *list) {
    CELULA *q;

    q=list;

    if(!vazia(list)) {
        list=q->next;
        freenode(q);
        return list;
    }

    else {
        printf("\nERRO: lista vazia.\n");
        return NULL;
    }
}

CELULA* procura(CELULA *list, int x) {
    CELULA *q;

    if(!vazia(list)) {
        q=list;

        while(q !=NULL) {
            if(q->info==x) return q;
            q=q->next;
        }
    }

    return NULL;
}

CELULA* removeValor(CELULA *list, int x) {
    CELULA *q;
    CELULA *aux;

    if((q=procura(list, x)) !=NULL) {
        aux=list;
        if(aux==q) removeInicio(list);

        else {
            while(aux->next !=q) aux=aux->next;
            aux->next=q->next;
            freenode(q);
        }

        return list;
    }

    return NULL;
}

void imprimir(CELULA *list) {
    CELULA *aux;

    aux=list;

    while(aux !=NULL) {
        printf("%d\t", aux->info);
        aux=aux->next;
    }

    printf("\n");
}

int main() {
    CELULA *lista;
    lista=inicializa(lista);
    lista=insereInicio(lista, 7);
    lista=insereFim(lista, 3);
    lista=insereFim(lista, 9);
    imprimir(lista);
    lista=removeValor(lista, 3);
    imprimir(lista);
    getch();
    return 0;
}