#include <stdio.h>
#include <stdlib.h>

#define tamanho 10

void buble_sort(int vetor[]) {
    int i, j, aux;
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho - 1; j++){
            if(vetor[j] > vetor[i]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    printf("\n");
    for(i = 0; i < tamanho; i++){
        
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void select_sort(int vetor[]) {
    int i, j, aux;
    for(i = 0; i < tamanho; i++){
        for(j = 0; j < tamanho - 1; j++){
            if(vetor[j] > vetor[i]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    printf("\n");
    for(i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int busca_sequencial(int v[], int pesq) {
    int i;
    for(i = 0;i < tamanho;i++)
    {
        if(v[i]==pesq)
        {
            return i;
        }
    }
    return -1;
}

int busca_binaria(int v[], int pesq) {
    int comeco = 0;
    int final = tamanho-1;

    int meio;
    while (comeco <= final)
    {
        meio = (comeco + final)/2;
        if (pesq == v[meio])
            return meio;
        else if (pesq < v[meio])
            final = meio-1;
        else
            comeco = meio+1;
    }
    return -1;
}

void ler_vetor(int vet[]) {
      int i;
      for (i = 0;i < tamanho;i++)
      {
          printf("Informe o valor %d: ", i+1);
          fflush(stdin);
          scanf("%d", &vet[i]);
      }
}

int main() {

    int op, sequencial, binario, pos;
    int vet[tamanho];
    ler_vetor(vet);

    do {
        printf("\n1 - Ordenar vetor por Buble-Sort \n");
        printf("2 - Ordenar vetor por Select-Sort \n");
        printf("3 - Realizar Busca Sequencial \n");
        printf("4 - Realizar Busca Binaria \n");
        printf("0 - Sair \n");

        printf("Informe a opcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                buble_sort(vet);
                break;
            case 2:
                select_sort(vet);
                break;
            case 3:
                printf ("\nDigite um valor para pesquisar: ");
                scanf("%d",&sequencial);
                
                pos=busca_sequencial(vet, sequencial);
                if (pos==-1)
                {
                    printf("\nValor nao encontrado no vetor!\n");
                }
                else
                {
                    printf("\nValor encontrado na posicao %d\n", pos+1);    
                }
                break;
            case 4:
                printf ("\nDigite um valor para pesquisar: ");
                scanf("%d",&binario);

                pos=busca_binaria(vet, binario);
                if (pos==-1)
                {
                    printf("\nValor nao encontrado no vetor!\n");
                }
                else
                {
                    printf("\nValor encontrado na posicao %d\n", pos+1);
                }
                break;
        }
    } while (op != 0);
}