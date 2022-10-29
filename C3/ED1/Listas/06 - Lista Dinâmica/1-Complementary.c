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

CELULA* removeFim(CELULA *list){
	CELULA *ultimo;
	CELULA *penultimo;

	if(vazia(list)){
        printf("\nErro: lista vazia.\n");
        return NULL;
    }
    else{
        ultimo = list->next;
		penultimo = list->next;
        while(ultimo->next != NULL){
            penultimo = ultimo;
            ultimo = ultimo->next;
        }
        penultimo->next = NULL;
    }
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
    CELULA *l1;

    l1 = inicializa(l1);

    int num;
    do
    {
        scanf("%d", &num);
        if (num != -1)
        {
            l1 = insereInicio(l1, num);
        }
    } while (num != -1);

    removeFim(l1);
    printf("\nLista com o ultimo elemento removido: \n");
    imprimir(l1);

    return 0;
}