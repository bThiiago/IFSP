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

int main()
{
   srand(time(NULL));
   int vetor[10], i, x;

   printf("Preencha o vetor:\n");
   for (i = 0; i < 10; i++)
   {
      printf("Vetor[%d]: ", i);
      scanf("%d", &vetor[i]);
   }

   printf("Informe um valor para busca: ");
   scanf("%d", &x);

   printf("\nValor encontrado na posicao %d.\n", buscaPosicao(vetor, x));
   return 0;
}