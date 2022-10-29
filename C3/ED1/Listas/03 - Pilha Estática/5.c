#define TAM 5
#include <stdio.h>

typedef struct sStack
{
   int itens[TAM];
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

int push(STACK *S, int value)
{
   if (isFull(S))
   {
      printf("ERRO - A Pilha esta cheia.\n");
      return 1;
   }

   S->itens[++S->topo] = value;

   return 0;
}

int pop(STACK *S)
{
   if (isEmpty(S))
   {
      printf("\nERRO - A Pilha esta vazia.\n");
      return -1;
   }

   return S->itens[S->topo--];
}

int stackTop(STACK *S)
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
   int i, tempT, tempB, j = S->topo + 1;

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
}

int main()
{
   STACK S;
   init(&S);
   int temp, i = 0;

   while (i < TAM)
   {
      printf("Digite um valor: ");
      scanf("%d", &temp);

      push(&S, temp);

      i++;
   }

   reverse(&S);

   printf("\nPilha invertida: \n");
   for (i = S.topo; i >= 0; i--)
   {
      printf("Valor: %d.\n", pop(&S));
   }

   return 0;
}
