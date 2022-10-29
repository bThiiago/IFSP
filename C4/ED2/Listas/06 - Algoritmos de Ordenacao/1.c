#include <stdio.h>
#include <stdlib.h>

#define tamanho 20

void ler_vetor(int vet[])
{
    int i;
    printf("\n");
    for (i = 0; i < tamanho; i++)
    {
        printf("Informe o valor %d: ", i + 1);
        fflush(stdin);
        scanf("%d", &vet[i]);
    }
}

void buble_sort(int vetor[])
{
    int i, j, aux, cont = 0;
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho - 1; j++)
        {
            if (vetor[j] > vetor[i])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
            cont++;
        }
        cont++;
    }
    printf("\nVetor ordenado: ");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\nQuantidade de iteracoes: %d\n", cont);
}

void select_sort(int vetor[])
{
    int i, j, aux, cont = 0;
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho - 1; j++)
        {
            if (vetor[j] > vetor[i])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
            cont++;
        }
        cont++;
    }
    printf("\nVetor ordenado: ");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\nQuantidade de iteracoes: %d\n", cont);
}

int busca_sequencial(int v[], int pesq)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (v[i] == pesq)
        {
            return i;
        }
    }
    return -1;
}

int busca_binaria(int v[], int pesq)
{
    int comeco = 0;
    int final = tamanho - 1;
    int cont = 0;

    int meio;
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

    int op, sequencial, binario, pos;
    int vet[tamanho] = {0};

    do
    {
        printf("\n1 - Ler vetor \n");
        printf("2 - Ordenar vetor por Buble-Sort \n");
        printf("3 - Ordenar vetor por Select-Sort \n");
        printf("4 - Ordenar vetor por Insert-Sort \n");
        printf("5 - Ordenar vetor por Heap-Sort \n");
        printf("6 - Ordenar vetor por Shell-Sort \n");
        printf("7 - Ordenar vetor por Quick-Sort \n");
        printf("8 - Realizar Busca Sequencial \n");
        printf("9 - Realizar Busca Binaria \n");
        printf("0 - Sair \n");

        printf("Informe a opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            ler_vetor(vet);
            break;
        case 2:
            buble_sort(vet);
            break;
        case 3:
            select_sort(vet);
            break;

        case 8:
            printf("\nDigite um valor para pesquisar: ");
            scanf("%d", &sequencial);

            pos = busca_sequencial(vet, sequencial);
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
        case 9:
            printf("\nDigite um valor para pesquisar: ");
            scanf("%d", &binario);

            pos = busca_binaria(vet, binario);
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