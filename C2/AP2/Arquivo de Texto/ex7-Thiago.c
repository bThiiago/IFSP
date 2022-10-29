#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   char c;
   int identificadores = 0;
   int classes = 0;
   int redefinicoes = 0;

   FILE *arq;

   arq = fopen("css.txt", "r");
   if (arq == NULL)
   {
      printf("Erro na abertura do arquivo.");
      exit(1);
   }

   c = fgetc(arq);
   while (c != EOF)
   {
      if (c == '#')
      {
         identificadores++;
         printf("Identificador: ");
      }
      else
      {
         if (c == '.')
         {
            classes++;
            printf("Classe: ");
         }
         else
         {
            printf("Redefinicao: ");
            redefinicoes++;
         }
      }

      while (c != EOF && c != '{')
      {
         printf("%c", c);
         c = fgetc(arq);
      }

      while (c != EOF && c != '}')
      {
         c = fgetc(arq);
      }

      c = fgetc(arq);
      c = fgetc(arq);
      printf("\n");
   }

   printf("\nQuantidade de redefinicoes: %d.\n", redefinicoes);
   printf("Quantidade de identificadores: %d.\n", identificadores);
   printf("Quantidade de classes: %d.\n", classes);

   fclose(arq);

   exit(0);
}