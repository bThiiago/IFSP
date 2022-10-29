// a: Uma lista com implementação circular, padrão FILO (First In, Last Out).
// Essa é a mais recomendada pois as musicas são organizadas em forma de Fila e toda
// vez que uma musica é tocada, ela vai para o final da Fila.
// b: 99 músicas
#define TAMMAX 100

#include <stdio.h>
#include <string.h>

typedef struct sMusica
{
   char nome[50], genero[50];
} Musica;

typedef struct sPasta
{
   Musica musicas[100];
   int inicio, fim;
} Pasta;

void inicializa(Pasta *p)
{
   p->inicio = TAMMAX - 1;
   p->fim = TAMMAX - 1;
}

int vazia(Pasta *p)
{
   return p->fim == p->inicio ? 1 : 0;
}

int cheia(Pasta *p)
{
   return p->fim == p->inicio ? 1 : 0;
}

void enfileirar(Pasta *p, Musica musica)
{
   if (p->fim == (TAMMAX - 1))
   {
      p->fim = 0;
   }
   else
   {
      p->fim++;
   }
   if (cheia(p))
   {
      printf("\nERRO: Pasta cheia.\n");
      p->fim--;
      if (p->fim == -1)
      {
         p->fim = TAMMAX - 1;
      }
      return;
   }
   p->musicas[p->fim] = musica;
}

Musica desenfileirar(Pasta *p)
{
   Musica aux;

   if (!vazia(p))
   {
      if (p->inicio == TAMMAX - 1)
      {
         p->inicio = 0;
      }
      else
      {
         p->inicio++;
      }
      aux = p->musicas[p->inicio];
   }
   else
   {
      printf("\nERRO: Pasta Vazia.\n");
   }

   return aux;
}

void imprimir(Pasta *p)
{
   int i = (p->inicio + 1) % TAMMAX;
   if (!vazia(p))
   {
      printf("\nPasta: \n");
      while (i != ((p->fim + 1) % TAMMAX))
      {
         printf("Nome: %s.\n", p->musicas[i].nome);
         printf("Genero: %s.\n\n", p->musicas[i].genero);
         i = (i + 1) % TAMMAX;
      }
   }
   else
   {
      printf("\nPasta Vazia.");
   }
}

int main()
{
   Pasta pasta;
   inicializa(&pasta);

   Musica musica;

   strcpy(musica.genero, "Eletronic");
   strcpy(musica.nome, "SLANDER - Kneel before me");
   enfileirar(&pasta, musica);

   strcpy(musica.genero, "Rap");
   strcpy(musica.nome, "Yung Buda - Digimon");
   enfileirar(&pasta, musica);

   strcpy(musica.genero, "Power Metal");
   strcpy(musica.nome, "DragonForce - In a Skyforged Dream");
   enfileirar(&pasta, musica);

   strcpy(musica.genero, "Rock");
   strcpy(musica.nome, "THE KOXX - echo");
   enfileirar(&pasta, musica);

   strcpy(musica.genero, "Dance");
   strcpy(musica.nome, "Bonjr - paranoia ???");
   enfileirar(&pasta, musica);

   imprimir(&pasta);

   enfileirar(&pasta, desenfileirar(&pasta));
   enfileirar(&pasta, desenfileirar(&pasta));

   printf("\nApos tocar duas musicas: \n");
   imprimir(&pasta);

   strcpy(musica.genero, "Metal");
   strcpy(musica.nome, "Enter Shikari - Wall");
   enfileirar(&pasta, musica);

   strcpy(musica.genero, "Indie");
   strcpy(musica.nome, "EDEN - Drugs");
   enfileirar(&pasta, musica);

   enfileirar(&pasta, desenfileirar(&pasta));
   printf("\nApos tocar uma musica: \n");
   imprimir(&pasta);

   enfileirar(&pasta, desenfileirar(&pasta));
   printf("\nApos tocar outra musica: \n");
   imprimir(&pasta);

   return 0;
}