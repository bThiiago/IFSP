#include <stdio.h>

typedef struct sFormando
{
   int prontuario;
   char nome[50];
   char curso[20];
   int ano_ingresso;
   int ano_formatura;
   char endereco[80];
   char telefone[15];
} FORMANDO;

typedef struct cell {
    FORMANDO formandos;
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

FORMANDO* criaFormando(int prontuario, char nome[], char curso[], int ano_ingresso, int ano_formatura, char endereco[], char telefone[])
{
   FORMANDO f;
   f.prontuario = prontuario;
   strcpy(f.nome, nome);
   strcpy(f.curso, curso);
   f.ano_ingresso = ano_ingresso;
   f.ano_formatura = ano_formatura;
   strcpy(f.endereco, endereco);
   strcpy(f.telefone, telefone);

   return f;
};

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
    CELULA *list;
    FORMANDO *form;

    list = inicializa(list);
    form = inicializa(form);

    int opcao;
    
    do
    {
        printf("\n1 - Inserir formando.\n");
        printf("2 - Relatorio por curso.\n");
        printf("3 - Relatorio por ano.\n");
        printf("0 - Finalizar.\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nProntuario do aluno...: ");
            scanf("%d", &list.form.prontuario);

            fflush(stdin);
            printf("Nome do aluno.........: ");
            gets(list.form.nome);

            fflush(stdin);
            printf("Curso do aluno........: ");
            gets(list.form.curso);

            printf("Ano de ingresso.......: ");
            scanf("%d", &list.form.ano_ingresso);

            printf("Ano da formatura......: ");
            scanf("%d", &list.form.ano_formatura);

            fflush(stdin);
            printf("Endereço..............: ");
            gets(list.form.endereco);

            fflush(stdin);
            printf("Telefone..............: ");
            gets(list.form.telefone);

            list = insereInicio(list, form);
            break;

        case 2:
            imprimir(list);
            break;

        case 3:
            
            break;

        default:
            break;
        }
    } while (opcao != 0);

    return 0;
}