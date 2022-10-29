#include <stdio.h>
#include <stdlib.h>

#define tamanho 10

void ler_vetor(int vet[])
{
    int i;
    printf("\n");
    for (i = 0; i < tamanho; i++)
    {
        printf("Informe o valor %d: ", i);
        fflush(stdin);
        scanf("%d", &vet[i]);
    }
}

int busca_sequencial(int v[], int pesq, int chave, int pos[])
{
    int i, cont = 0;

    for (i = 0; i < tamanho; i++)
    {
        if (v[i] == chave)
        {
            pos[i] = v[i];
            cont++;
        }
    }
    if (cont == 0)
    {
        printf("\nNao existem ocorrencias de chave no vetor.\n");
    }
    else
    {
        printf("\nQuantidade de ocorrencias da chave no vetor: %d\n", cont);
    }

    for (i = 0; i < tamanho; i++)
    {
        if (v[i] == pesq)
        {
            return i;
        }
    }
    return -1;
}

int busca_binaria(int v[], int pesq, int chave, int pos[])
{
    int comeco = 0, i;
    int final = tamanho - 1;
    int cont = 0;
    int conta = 0;
    int meio;

    for (i = 0; i < tamanho; i++)
    {
        if (v[i] == chave)
        {
            pos[i] = v[i];
            cont++;
        }
    }
    if (cont == 0)
    {
        printf("\nNao existem ocorrencias de chave no vetor.\n");
    }
    else
    {
        printf("\nQuantidade de ocorrencias da chave no vetor: %d\n", cont);
    }

    while (comeco <= final)
    {
        meio = (comeco + final) / 2;
        if (pesq == v[meio])
        {
            printf("\nValor encontrado na posicao %d", meio + 1);
            return cont;
        }
        else if (pesq < v[meio])
        {
            final = meio - 1;
        }
        else
        {
            comeco = meio + 1;
        }
        cont++;
    }
    return -1;
}

int main()
{

    int op, sequencial, binario, pos, chave;
    int vet[tamanho] = {0};
    int posi[tamanho] = {0};

    do
    {
        printf("\n1 - Ler vetor \n");
        printf("2 - Realizar Busca Sequencial \n");
        printf("3 - Realizar Busca Binaria \n");
        printf("0 - Sair \n");

        printf("Informe a opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            ler_vetor(vet);
            break;
        case 2:
            printf("\nDigite um valor para pesquisar: ");
            scanf("%d", &sequencial);
            printf("Digite a chave: ");
            scanf("%d", &chave);

            pos = busca_sequencial(vet, sequencial, chave, posi);
            if (pos == -1)
            {
                printf("\nValor nao encontrado no vetor!\n");
            }
            else
            {
                printf("\nValor encontrado na posicao %d", pos + 1);
                printf("\nQuantidade de iteracoes: %d\n", pos);
            }
            break;
        case 3:
            printf("\nDigite um valor para pesquisar: ");
            scanf("%d", &binario);
            printf("Digite a chave: ");
            scanf("%d", &chave);

            pos = busca_binaria(vet, binario, chave, posi);
            if (pos == -1)
            {
                printf("\nValor nao encontrado no vetor!\n");
            }
            else
            {
                printf("\nQuantidade de iteracoes: %d\n", pos);
            }
            break;
        }
    } while (op != 0);
}