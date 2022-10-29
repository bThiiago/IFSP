#include <stdio.h>

struct Produto
{
   int id, qtdDisponivel;
   float precoVenda;
   char nome[50];
};

struct Produto lerProduto()
{
   struct Produto produtos;

   fflush(stdin);
   printf("Nome....: ");
   gets(produtos.nome);
   printf("Id......: ");
   scanf("%d", &produtos.id);
   printf("Qtd.....: ");
   scanf("%d", &produtos.qtdDisponivel);
   printf("Preco...: ");
   scanf("%f", &produtos.precoVenda);

   return produtos;
}

int maiorPreco(int nprodutos, struct Produto produtos[10])
{
   int i, aux = 0;
   float maior;

   maior = produtos[0].precoVenda;
   for (i = 0; i < nprodutos; i++)
   {
      if (produtos[i].precoVenda > maior)
      {
         aux = i;
      }
   }
   printf("Produto com maior preco de venda: %s.\n", produtos[aux].nome);
   printf("Preco de venda: %.2f.\n", produtos[aux].precoVenda);
}

int maiorEstoque(int nprodutos, struct Produto produtos[10])
{
   int i, aux = 0;
   float maior;

   maior = produtos[0].qtdDisponivel;
   for (i = 0; i < nprodutos; i++)
   {
      if (produtos[i].qtdDisponivel > maior)
      {
         aux = i;
      }
   }
   printf("Produto com maior estoque: %s.\n", produtos[aux].nome);
   printf("Quantidade no estoque: %d.\n", produtos[aux].qtdDisponivel);
}

int main()
{
   int nprodutos = 0;
   struct Produto produtos[10];

   char escolha;
   while (escolha != 'x' || escolha != 'X')
   {
      printf("\n a) Cadastrar produto");
      printf("\n b) Produto com maior valor de venda");
      printf("\n c) Produto com maior estoque");
      printf("\n x) Encerrar o programa\n");

      printf("\nEscolha uma opcao: ");
      scanf(" %c", &escolha);
      printf("\n");

      switch (escolha)
      {
      case 'a':
      case 'A':
         produtos[nprodutos] = lerProduto();
         nprodutos++;
         break;

      case 'b':
      case 'B':
         maiorPreco(nprodutos, produtos);
         break;

      case 'c':
      case 'C':
         maiorEstoque(nprodutos, produtos);
         break;

      case 'x':
      case 'X':
         printf("Ate a proxima...");
         return 0;
         break;

      default:
         printf("\nEsta opcao nao existe.\n");
         break;
      }
   }
}