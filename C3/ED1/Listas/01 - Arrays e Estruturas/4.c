#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buscaPosicao(int vetor[10], int x)
{
   int i;
   for (i = 0; i < 10; i++)
   {
      if (vetor[i] == x)
         return i;
   }

   return -1;
}

void excluiPosicao(int vetor[10], int pos)
{
   int i;

   for (i = pos; i < 9; i++)
   {
      vetor[i] = vetor[i + 1];
   }
   vetor[9] = 0;
}

void apresentaVetor(int vetor[16])
{
   int i;

   for (i = 0; i < 10; i++)
   {
      printf("\nVetor[%d]: %d.", i, vetor[i]);
   }
}

int main()
{
   int vetor[10], i, x;

   for (i = 0; i < 10; i++)
   {
      printf("Vetor[%d]: ", i);
      scanf("%d", &vetor[i]);
   }

   printf("Informe um valor para busca: ");
   scanf("%d", &x);

   int pos = buscaPosicao(vetor, x);

   if (pos == -1)
   {
      printf("\nPosicao nao encontrada.\n");
   }
   else
   {
      printf("\nExcluindo a posicao %d do vetor.\n", pos);
      excluiPosicao(vetor, pos);

      printf("\nNovo vetor:");
      apresentaVetor(vetor);
   }

   return 0;
}