#include <stdio.h>
#include <string.h>

struct produto
{
    char nome_produto[100];
    int cod_fornecedor;
    float preco;
    int quant_estoque;
    int quant_minima;
};

struct fornecedor
{
    int cod_fornecedor;
    char nome_fornecedor[100];
    char contato[16];
};

struct produto incluir_produtos()
{
    struct produto produtos;

    fflush(stdin);
    printf("\nNome do produto: ");
    gets(produtos.nome_produto);
    printf("Codigo do fornecedor: ");
    scanf("%d", &produtos.cod_fornecedor);
    printf("Preco: ");
    scanf("%f", &produtos.preco);
    printf("Quantidade Estoque: ");
    scanf("%d", &produtos.quant_estoque);
    printf("Quantidade Minima: ");
    scanf("%d", &produtos.quant_minima);

    return produtos;
}

int preco_quantidade(int nprodutos, struct produto produtos[])
{
    int i;

    for (i = 0; i < nprodutos; i++)
    {
        printf("\nProduto: %s", produtos[i].nome_produto);
        printf("\nPreco: %.2f R$", produtos[i].preco);
        printf("\nQuantidade: %d\n", produtos[i].quant_estoque);
    }
    printf("\n");
}

int respectivos_fornecedores(int nprodutos, struct produto produtos[], struct fornecedor fornecedor[])
{
    int i;
    int j;

    for (i = 0; i < nprodutos; i++)
    {
        printf("\n\nProduto: %s", produtos[i].nome_produto);
        for (j = 0; j < 7; j++)
        {
            if (produtos[i].cod_fornecedor == fornecedor[j].cod_fornecedor)
            {
                printf("\nFornecedor: %s", fornecedor[j].nome_fornecedor);
            }
        }
    }
    printf("\n");
}

int um_fornecedor(int nprodutos, struct produto produtos[], struct fornecedor fornecedor[])
{
    int i;
    int escolha;

    printf("\nDigite o codigo do fornecedor para ver seus respectivos produtos: ");
    scanf("%d", &escolha);

    printf("\nProdutos do fornecedor %s:", fornecedor[escolha - 1].nome_fornecedor);
    for (i = 0; i < nprodutos; i++)
    {
        if (produtos[i].cod_fornecedor == escolha)
        {
            printf("\n%s", produtos[i].nome_produto);
        }
    }
    printf("\n");
}

int estoque_baixo(int nprodutos, struct produto produtos[])
{
    int i;

    printf("\nProdutos com estoque baixo: ");
    for (i = 0; i < nprodutos; i++)
    {
        if (produtos[i].quant_estoque < produtos[i].quant_minima)
        {
            printf("\n%s", produtos[i].nome_produto);
        }
    }
    printf("\n");
}

int produto_fornecedor(int nprodutos, struct produto produtos[], struct fornecedor fornecedor[])
{
    char procura[100];
    int i;
    int aux = 0;

    fflush(stdin);
    printf("\nDigite o nome do produto: ");
    gets(procura);

    for (i = 0; i < nprodutos; i++)
    {
        if (strcmp(procura, produtos[i].nome_produto) == 0)
        {
            printf("\nProduto: %s", produtos[i].nome_produto);
            printf("\nCodigo fornecedor: %d", produtos[i].cod_fornecedor);
            printf("\nPreco: %.2f R$", produtos[i].preco);
            printf("\nQuantidade em estoque: %d", produtos[i].quant_estoque);
            printf("\nQuantidade minima: %d", produtos[i].quant_minima);

            aux = produtos[i].cod_fornecedor - 1;

            printf("\n\nFornecedor: %s", fornecedor[aux].nome_fornecedor);
            printf("\nCodigo: %d", fornecedor[aux].cod_fornecedor);
            printf("\nContato: %s", fornecedor[aux].contato);
        }
    }
    printf("\n");
}

int balanco_estoque(int nprodutos, struct produto produtos[])
{
    int i;
    float total_cada = 0;
    float total_estoque = 0;

    for (i = 0; i < nprodutos; i++)
    {
        total_cada = total_cada + produtos[i].preco;
        total_estoque = total_estoque + (produtos[i].preco * produtos[i].quant_estoque);
    }

    printf("\nTotal em dinheiro de cada produto: %.2f R$", total_cada);
    printf("\nValor total do estoque: %.2f R$\n", total_estoque);
}

int main()
{
    struct fornecedor fornecedor[7];

    int nprodutos = 7;
    struct produto produtos[100];

    strcpy(produtos[0].nome_produto, "Cerveja Antartica");
    produtos[0].cod_fornecedor = 1;
    produtos[0].preco = 8.5;
    produtos[0].quant_estoque = 48;
    produtos[0].quant_minima = 24;

    strcpy(produtos[1].nome_produto, "Cerveja Brahma");
    produtos[1].cod_fornecedor = 1;
    produtos[1].preco = 9.0;
    produtos[1].quant_estoque = 15;
    produtos[1].quant_minima = 30;

    strcpy(produtos[2].nome_produto, "Guarana Antartica");
    produtos[2].cod_fornecedor = 1;
    produtos[2].preco = 6.5;
    produtos[2].quant_estoque = 12;
    produtos[2].quant_minima = 6;

    strcpy(produtos[3].nome_produto, "Coca-Cola 1l");
    produtos[3].cod_fornecedor = 2;
    produtos[3].preco = 6.0;
    produtos[3].quant_estoque = 25;
    produtos[3].quant_minima = 12;

    strcpy(produtos[4].nome_produto, "Fanta Uva 290ml");
    produtos[4].cod_fornecedor = 2;
    produtos[4].preco = 3.5;
    produtos[4].quant_estoque = 3;
    produtos[4].quant_minima = 10;

    strcpy(produtos[5].nome_produto, "Cerveja Bavaria lata");
    produtos[5].cod_fornecedor = 2;
    produtos[5].preco = 8.5;
    produtos[5].quant_estoque = 48;
    produtos[5].quant_minima = 6;

    strcpy(produtos[6].nome_produto, "Agua Mineral 500ml");
    produtos[6].cod_fornecedor = 3;
    produtos[6].preco = 2.5;
    produtos[6].quant_estoque = 24;
    produtos[6].quant_minima = 10;

    fornecedor[0].cod_fornecedor = 1;
    strcpy(fornecedor[0].nome_fornecedor, "Ambev");
    strcpy(fornecedor[0].contato, "(18) 99887-9876");

    fornecedor[1].cod_fornecedor = 2;
    strcpy(fornecedor[1].nome_fornecedor, "Femsa");
    strcpy(fornecedor[1].contato, "(18) 99111-3211");

    fornecedor[2].cod_fornecedor = 3;
    strcpy(fornecedor[2].nome_fornecedor, "Lindoya");
    strcpy(fornecedor[2].contato, "(18) 98352-1121");

    char escolha;
    while (escolha != 'h' || escolha != 'H')
    {
        printf("\n a) Incluir novos produtos");
        printf("\n b) Apresentar todos os produtos, com o preco e a quantidade");
        printf("\n c) Apresentar todos os produtos com os respectivos fornecedores");
        printf("\n d) Apresentar todos os produtos de um fornecedor");
        printf("\n e) Apresentar todos os produtos com estoque baixo");
        printf("\n f) Pesquisar por um produto");
        printf("\n g) Apresentar o balanco de estoque");
        printf("\n h) Encerrar o programa\n");

        printf("\nEscolha uma opcao: ");
        scanf(" %c", &escolha);

        switch (escolha)
        {
        case 'a':
        case 'A':
            produtos[nprodutos] = incluir_produtos();
            nprodutos = nprodutos + 1;
            break;

        case 'b':
        case 'B':
            preco_quantidade(nprodutos, produtos);
            break;

        case 'c':
        case 'C':
            respectivos_fornecedores(nprodutos, produtos, fornecedor);
            break;

        case 'd':
        case 'D':
            um_fornecedor(nprodutos, produtos, fornecedor);
            break;

        case 'e':
        case 'E':
            estoque_baixo(nprodutos, produtos);
            break;

        case 'f':
        case 'F':
            produto_fornecedor(nprodutos, produtos, fornecedor);
            break;

        case 'g':
        case 'G':
            balanco_estoque(nprodutos, produtos);
            break;

        case 'h':
        case 'H':
            printf("\n\n\tAte a proxima...\n\n");
            return 0;
            break;

        default:
            printf("\n\tEsta opcao nao existe.");
            break;
        }
    }
}