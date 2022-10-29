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
}

int main()
{
   STACK S;
   int i = 0;
   char temp;

   init(&S);

   printf("Informe uma palavra: ");
   do
   {
      scanf("%c", &temp);
      if (temp != 10)
      {
         push(&S, temp);
      }
      i++;
   } while (i < TAM && temp != 10);

   reverseExtremes(&S);

   printf("\nPilha invertida: \n");
   for (i = S.topo; i >= 0; i--)
   {
      printf("%c\n", pop(&S));
   }

   return 0;
}