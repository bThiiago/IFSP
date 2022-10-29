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

void lista_concatenar(CELULA *L1, CELULA *L2)
{
    int i;
    CELULA *aux;

    aux=L2;

    while(aux != NULL) {
        L1 = insereFim(L1, aux->info);
        aux = aux->next;
    }
    return L1;
}

void imprimir(CELULA *list) {
    CELULA *aux;

    aux=list;

    while(aux != NULL) {
        printf("%d\n", aux->info);
        aux=aux->next;
    }

    printf("\n");
}

int main() {
    CELULA *l1, *l2;

    l1 = inicializa(l1);
    l2 = inicializa(l2);

    int num;
    do
    {
        scanf("%d", &num);
        if (num != -1)
        {
            l1 = insereInicio(l1, num);
        }
    } while (num != -1);

    do
    {
        scanf("%d", &num);
        if (num != -1)
        {
            l2 = insereInicio(l2, num);
        }
    } while (num != -1);

    lista_concatenar(l1, l2);
    printf("\nLista Concatenada: \n");
    imprimir(l1);

    return 0;
}