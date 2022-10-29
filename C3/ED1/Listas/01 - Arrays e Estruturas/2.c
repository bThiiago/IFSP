#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocaPosicoes(int vetor[16])
{
   int i, aux;

   for (i = 0; i < 8; i++)
   {
      aux = vetor[i];
      vetor[i] = vetor[i + 8];
      vetor[i + 8] = aux;
   }
}

void apresentaVetor(int vetor[16])
{
   int i;

   for (i = 0; i < 16; i++)
   {
      printf("\nVetor[%d]: %d", i, vetor[i]);
   }
   printf("\n");
}

int main()
{
   srand(time(NULL));
   int vetor[16], i;

   for (i = 0; i < 16; i++)
   {
      printf("Vetor[%d]: ", i);
      scanf("%d", &vetor[i]);
   }

   trocaPosicoes(vetor);

   printf("\n\nVetor trocado:\n");
   apresentaVetor(vetor);

   return 0;
}