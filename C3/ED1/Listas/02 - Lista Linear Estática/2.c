#define TAMF 10
#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
   int valor[TAMF], n;
} LISTA;

int lista_cheia(LISTA *L)
{
   return (L->n + 1) == TAMF ? 1 : 0;
}

int lista_vazia(LISTA *L)
{
   return (L->n + 1) == 0 ? 1 : 0;
}

void inicializa_lista(LISTA *L)
{
   L->n = -1;
}

int lista_inserir_final(LISTA *L, int valor)
{
   if (lista_cheia(L) == 1)
   {
      printf("\nERRO - Lista cheia.\n");
      return 1;
   }

   L->valor[L->n + 1] = valor;
   L->n += 1;

   return 0;
};

int lista_inserir_inicio(LISTA *L, int valor)
{
   if (lista_cheia(L) == 1)
   {
      printf("\nERRO - Lista cheia.\n");
      return 1;
   }

   int i;
   for (i = (L->n + 1); i > 0; i--)
   {
      L->valor[i] = L->valor[i - 1];
   }

   L->valor[0] = valor;
   L->n += 1;

   return 0;
};

int lista_remover_inicio(LISTA *L, int posicao)
{
   if (lista_vazia(L) == 1)
   {
      printf("\nERRO - Lista vazia.\n");
      return 1;
   }
   if (posicao > (L->n + 1) || posicao < 0)
   {
      printf("\nERRO - Fora dos limites.\n");
      return 1;
   }

   int i;
   for (i = posicao; i < L->n + 1; i++)
   {
      L->valor[i] = L->valor[i + 1];
   }

   L->n -= 1;
   return 0;
};

int lista_remover_final(LISTA *L, int posicao)
{
   if (lista_vazia(L) == 1)
   {
      printf("\nERRO - Lista vazia.\n");
      return 1;
   }
   if (posicao > (L->n + 1) || posicao < 0)
   {
      printf("\nERRO - Fora dos limites.\n");
      return 1;
   }

   int i;
   for (i = posicao; i < L->n + 1; i++)
   {
      L->valor[i] = L->valor[i + 1];
   }

   L->n -= 1;
   return 0;
};

int lista_apresenta(LISTA *L)
{
   if (lista_vazia(L) == 1)
   {
      printf("\nERRO - Lista vazia.\n");
      return 1;
   }
   int i;
   for (i = 0; i < (L->n + 1); i++)
   {
      printf("Lista[%d] - %d.\n", i, L->valor[i]);
   }

   return 0;
}

int main()
{
   int opcao, temp;

   LISTA lista;
   inicializa_lista(&lista);

   do
   {
      printf("\n1 - Inserir no inicio.\n");
      printf("2 - Inserir no final.\n");
      printf("3 - Remover no inicio.\n");
      printf("4 - Remover no final.\n");
      printf("5 - Apresentar.\n");
      printf("0 - Finalizar");

      printf("\n\nEscolha uma opcao: ");
      scanf("%d", &opcao);

      switch (opcao)
      {
      case 1:
         printf("\nEscolha o valor: ");
         scanf("%d", &temp);
         lista_inserir_inicio(&lista, temp);
         break;

      case 2:
         printf("\nEscolha o valor: ");
         scanf("%d", &temp);
         lista_inserir_final(&lista, temp);
         break;

      case 3:
         lista_remover_inicio(&lista, temp);
         break;

      case 4:
         lista_remover_final(&lista, temp);
         break;

      case 5:
         printf("Lista: \n");
         lista_apresenta(&lista);

      default:
         break;
      }
   } while (opcao != 0);

   return 0;
}
