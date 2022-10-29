#define TAM 20
#include <stdio.h>

typedef struct sStack
{
   char itens[TAM];
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

int reverse(STACK *S)
{
   int tempT, tempB = S->topo + 1;

   if (isEmpty(S))
   {
      printf("\nERRO - A Pilha esta vazia\n");
      return 1;
   }

   STACK S2;
   init(&S2);

   tempT = pop(S);

   while (S->topo != 0)
   {
      push(&S2, pop(S));
   };

   push(S, tempT);

   tempB = pop(S);

   while (S2.topo != -1)
   {
      push(S, pop(&S2));
   }

   push(S, tempB);

   return 0;
};

int reverseExtremes(STACK *S)
{
   int k;

   if (isEmpty(S))
   {
      printf("\nERRO - A Pilha esta vazia.\n");
      return -1;
   }

   if (S->topo == 0)
   {
      printf("\nERRO - A Pilha nao tem valores suficientes.\n");
      return -1;
   }

   STACK S2;
   init(&S2);

   int i, j = S->topo + 1;
   char tempT, tempB;

   tempT = pop(S);

   while (S->topo != 0)
   {
      push(&S2, pop(S));
   };

   push(S, tempT);

   tempB = pop(S);

   while (S2.topo != -1)
   {
      push(S, pop(&S2));
   }

   push(S, tempB);

   return 0;
};

void validate(STACK *S, int value)
{
   STACK S2;
   init(&S2);

   if (value % 2 == 0)
   {
      int j = S->topo + 1;
      int i = 0;
      while (i < j && (stackTop(S) % 2 == 1))
      {
         push(&S2, pop(S));
         i++;
      }
      push(S, value);
      while (S2.topo != -1)
      {
         push(S, pop(&S2));
      }
   }
   else
   {
      push(S, value);
   }
};

int main()
{
   STACK S;
   init(&S);

   int opcao, temp;

   do
   {
      printf("\n1 - Inserir item na pilha.\n");
      printf("2 - Remover item da pilha.\n");
      printf("3 - Inserir item na pilha com validacao.\n");
      printf("4 - Trocar extremos da pilha.\n");
      printf("5 - Inverter pilha.\n");
      printf("0 - Finalizar.\n");

      printf("\nInforme a opcao desejada: ");
      scanf("%d", &opcao);

      switch (opcao)
      {
      case 1:
         printf("\nDigite um valor para inserir na pilha: ");
         scanf("%d", &temp);
         push(&S, temp);
         break;

      case 2:
         printf("\nValor excluido da pilha: %d.\n", pop(&S));
         break;

      case 3:
         printf("\nDigite um valor para inserir na pilha: ");
         scanf("%d", &temp);
         validate(&S, temp);
         break;

      case 4:
         printf("\nInvertendo extremos da Pilha...");
         reverseExtremes(&S);
         printf("\nOperacao concluida.\n");
         break;

      case 5:
         printf("\nInvertendo Pilha...");
         reverse(&S);
         printf("\nOperacao concluida.\n");
         break;

      case 0:
         printf("\nEncerrando o sistema...");
      }
   } while (opcao != 0);
   return 0;
}