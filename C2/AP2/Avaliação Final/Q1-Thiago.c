#include <stdio.h>
#include <string.h>

struct Produtos
{
    int codigo;
    char descricao[100];
    float preco;
    int estoque;
};

struct vendas
{
    int produto;
    int qtde;
};

void item_b()
{
    FILE *arquivo;

    struct Produtos p;

    int i, produto, qnt, q = 0;
    char confirm;

    arquivo = fopen("produtos.dat", "rb+");

    if (arquivo == NULL)
    {
        printf("Nao eh possivel criar esse arquivo.");
        exit(1);
    }

    printf("\n -- VENDA -- \n");

    printf("Codigo do produto: ");
    scanf("%d", &produto);

    fread(&p, sizeof(struct Produtos), 1, arquivo);

    while (!feof(arquivo))
    {
        if (produto == p.codigo)
        {
            printf("\nDescricao: %s\n ", p.descricao);
            printf("Preco: %.2f\n ", p.preco);
            q = 1;

            do
            {
                printf("\nQuantidade a ser vendida: ");
                scanf("%d", &qnt);

                if (qnt <= p.estoque)
                {
                    fflush(stdin);
                    printf("\nConfirmar venda (S ou N): ");
                    gets(confirm);

                    fread(&p, sizeof(struct Produtos), 1, arquivo);

                    switch (confirm)
                    {
                    case 'S':
                        p.estoque = p.estoque - qnt;
                        fwrite(&p, sizeof(struct Produtos), 1, arquivo);
                        break;

                    case 'N':
                        exit(1);
                        break;

                    default:
                        printf("Opcao inexistente");
                        break;
                    }
                }
                else if (qnt > p.estoque)
                {
                    printf("\nO estoque eh menor que a quantidade solicitada.");
                }
            } while (qnt > p.estoque);
        }
        else
        {
        }
        fread(&p, sizeof(struct Produtos), 1, arquivo);
    }

    if (q = 0)
    {
        printf("\nO produto nao existe.\n");
        exit(1);
    }

    fclose(arquivo);
}

void item_c()
{
    FILE *arquivo, *arquivo2;

    struct Produtos p;

    int i, produtos;

    arquivo = fopen("produtos.txt", "r");

    if (arquivo == NULL)
    {
        printf("Nao eh possivel abrir esse arquivo.");
        exit(1);
    }

    arquivo2 = fopen("produtos.dat", "ab+");

    if (arquivo2 == NULL)
    {
        printf("Nao eh possivel criar esse arquivo.");
        exit(1);
    }

    fscanf(arquivo, "%d\n", &produtos);

    for (i = 0; i < produtos; i++)
    {
        fscanf(arquivo, "%d\n", &p.codigo);
        fgets(p.descricao, 99, arquivo);
        if (p.descricao[strlen(p.descricao) - 1] == 10)
        {
            p.descricao[strlen(p.descricao) - 1] = '\0';
        }
        fscanf(arquivo, "%f %d\n", &p.preco, &p.estoque);

        fwrite(&p, sizeof(struct Produtos), 1, arquivo2);
    }

    fclose(arquivo);
    fclose(arquivo2);
}

void main()
{
    struct Produtos p;

    item_c();
    item_b();
}