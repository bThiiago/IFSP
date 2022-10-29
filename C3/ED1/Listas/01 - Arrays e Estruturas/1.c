#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   srand(time(NULL));
   int vetor[12], i, x, y;

   printf("Preencha o vetor:\n");
   for (i = 0; i < 12; i++)
   {
      printf("Vetor[%d]: ", i);

      vetor[i] = rand() % 20;
      printf("%d.\n", vetor[i]);
   }

   printf("\nInforme uma posicao do vetor: ");
   scanf("%d", &x);

   printf("Informe outra posicao do vetor: ");
   scanf("%d", &y);

   if (x > 11 || y > 11)
   {
      printf("Valores invalidos encerrando o programa.\n");
   }
   else
   {
      printf("%d + %d = %d\n", vetor[x], vetor[y], vetor[x] + vetor[y]);
   }

   return 0;
}