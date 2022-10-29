#define TAM 50
#include <stdio.h>
#include <string.h>

typedef struct sLocatario
{
   int cpf;
   char nome[40];
} LOCATARIO;

typedef struct sBarraca
{
   char aluguel;
   LOCATARIO locatario;
   int produto;
} BARRACA;

typedef struct sLista
{
   int n;
   BARRACA barracas[TAM];
} LISTA;

void lista_inicializar(LISTA *L)
{
   L->n = -1;
}

int lista_inserir(LISTA *l, BARRACA item)
{
   if (l->n + 1 == TAM)
   {
      printf("\nERRO - Lista cheia");
      return 1;
   };

   l->barracas[++l->n] = item;

   return 0;
}

void relatorio_inadiplentes(LISTA *l)
{
   int i, conf = 0;
   for (i = 0; i < l->n + 1; i++)
   {
      if (l->barracas[i].aluguel == 'I')
      {
         conf = 1;
         printf("\nBARRACA INADIPLENTE: %d.\n", i + 1);
         printf("CPF: %d.\n", l->barracas[i].locatario.cpf);
         printf("Nome: %s.\n", l->barracas[i].locatario.nome);
      }
   }
   if (conf == 0)
   {
      printf("\nNao existem locatarios inadiplentes.\n");
   }
}

void relatorio_barracas(LISTA *l)
{
   int livres = 0, ocupadas = 0, i;
   for (i = 0; i < TAM; i++)
   {
      printf("\nCodigo: %d.\n", i + 1);
      printf("Situacao: ");
      if (i <= l->n)
      {
         printf("Ocupada.\n");
         ocupadas++;
      }
      else
      {
         livres++;
         printf("Disponivel.\n");
      }
   }

   printf("\nTotal de Barracas Livres: %d.\n", livres);
   printf("Total de Barracas Ocupadas: %d.\n", ocupadas);
}

int main()
{
   LISTA l;
   BARRACA barraca;
   lista_inicializar(&l);

   int opcao;
   do
   {
      printf("\n1 - Cadastrar Nova Barraca.\n");
      printf("2 - Relatorio de Inadiplentes.\n");
      printf("3 - Barracas Livres.\n");
      printf("0 - Sair.\n");

      printf("\nSelecione um item: ");
      scanf("%d", &opcao);

      switch (opcao)
      {
      case 1:
         printf("\nCPF: ");
         scanf("%d", &barraca.locatario.cpf);

         fflush(stdin);
         printf("Nome: ");
         gets(barraca.locatario.nome);

         printf("Situacao do Aluguel (P ou I): ");
         scanf(" %c", &barraca.aluguel);

         printf("\nTipo de Produto: \n");
         printf("1 - Bebida.\n");
         printf("2 - Lanches.\n");
         printf("3 - Artigos Geral.\n");
         printf("Informe o codigo de venda: ");
         scanf("%d", &barraca.produto);

         lista_inserir(&l, barraca);
         break;

      case 2:
         relatorio_inadiplentes(&l);
         break;

      case 3:
         relatorio_barracas(&l);
         break;

      default:
         break;
      }
   } while (opcao != 0);

   return 0;
}