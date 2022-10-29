#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
   char placa[50];
   int n;
} LISTA;

int lista_cheia(LISTA *L) {
   return (L - > n + 1) == TAMF ? 1 : 0;
}

int lista_vazia(LISTA *L) {
   return (L - > n + 1) == 0 ? 1 : 0;
}

void inicializa_lista(LISTA *L) {
   L - > n = -1;
}

int lista_inserir(LISTA *L, int valor) {
   if (lista_cheia(L) == 1) {
      printf("\nERRO - Lista cheia.\n");
      return 1;
   }

   int posicao;

   posicao = L - > n + 1;
   if (lista_vazia(L)) {
      posicao = 0;
   }

   int i;
   for (i = 0; i < (L - > n + 1); i++) {
      if (L - > placa[i] > placa) {
         posicao = i;
         break;
      }
   }

   for (i = (L - > n + 1); i > posicao; i--) {
      L - > valor[i] = L - > valor[i - 1];
   }

   L - > valor[posicao] = valor;
   L - > n += 1;

   return 0;
}

typedef struct pilha {
   char placa[50];
   int topo;
} PILHA;

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

int push(STACK *S, char value)
{
   if (isFull(S))
   {
      printf("ERRO - A Pilha esta cheia.\n");
      return 1;
   }

   S->itens[++S->topo] = value;

   return 0;
}

char pop(STACK *S)
{
   if (isEmpty(S))
   {
      printf("\nERRO - A Pilha esta vazia.\n");
      return -1;
   }

   return S->itens[S->topo--];
}

char stackTop(STACK *S)
{
   if (isEmpty(S))
   {
      printf("\nERRO - A Pilha esta vazia.\n");
      return -1;
   }

   return S->itens[S->topo];
}

int main() {
   int opcao;
   char type[10], placa[50];

   printf("\nQual o tipo de tecnica a ser utilizada (Lista, Pilha ou Fila): ");
   gets(type);

   if (strcmp(type, "Lista") == 0) {
      printf("\n1 - Estacionar o carro.\n");
      printf("2 - Retirar o carro.\n");
      printf("3 - Olhar o carro.\n");
      printf("0 - Finalizar.");

      printf("\n\nEscolha uma opcao: ");
      scanf("%d", &opcao);

      switch (opcao) {
         case 1:
            printf("\nPlaca do carro: ");
            gets(placa);
            lista_inserir(&lista, placa[]);
            break;

         case 2:
            printf("\nPlaca do carro: ");
            gets(placa);
            lista_remover(&lista, placa[]);
            break;

         case 3:
            printf("\nCarros: \n");
            lista_apresenta(&lista);

         default:
            break;
      }
   } else if (strcmp(type, "Pilha") == 0) {
      printf("\n1 - Estacionar o carro.\n");
      printf("2 - Retirar o carro.\n");
      printf("3 - Olhar o carro.\n");
      printf("0 - Finalizar.");

      printf("\n\nEscolha uma opcao: ");
      scanf("%d", & opcao);

      switch (opcao) {
         case 1:
            printf("\nPlaca do carro: ");
            gets(placa);
            pilha_inserir(&pilha, placa[]);
            break;

         case 2:
            printf("\nPlaca do carro: ");
            gets(placa);
            pilha_remover(&pilha, placa[]);
            break;

         case 3:
            printf("\nCarros: \n");
            pilha_apresenta(&pilha);

         default:
            break;
      }
   } else if (strcmp(type, "Fila") == 0) {
      printf("\n1 - Estacionar o carro.\n");
      printf("2 - Retirar o carro.\n");
      printf("3 - Olhar o carro.\n");
      printf("0 - Finalizar.");

      printf("\n\nEscolha uma opcao: ");
      scanf("%d", & opcao);

      switch (opcao) {
         case 1:
            printf("\nPlaca do carro: ");
            gets(placa);
            fila_inserir(&fila, placa[]);
            break;

         case 2:
            printf("\nPlaca do carro: ");
            gets(placa);
            fila_remover(&fila, placa[]);
            break;

         case 3:
            printf("\nCarros: \n");
            fila_apresenta(&fila);

         default:
            break;
      }
   } else {
      printf("\nOpcao inexistente.\n");
      return 0;
   }
}