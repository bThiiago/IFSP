#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void localiza_maior(int vetor[20]){

    int i, maior=vetor[0];

    for(i=0; i<20; i++){
        if(maior < vetor[i]){
            maior = vetor[i];
        }
    }
    printf("\n\t\tMaior valor do vetor: %d.", maior);
}

void localiza_menor(int vetor[20]){

    int i, menor=vetor[0];

    for(i=0; i<20; i++){
        if(menor > vetor[i]){
            menor = vetor[i];
        }
    }
    printf("\n\t\tMenor valor do vetor: %d.\n", menor);

}

void localiza_maiores(int vetor[20]){

    int i, num, cont=0;

    num = rand()%31;

    printf("\n\tNúmero sorteado para encontrar maiores que ele: %d.\n", num);

    for(i=0; i<20; i++){
        if(num < vetor[i]){
            cont++;
        }
    }
    printf("\tQuantidade de números maiores que %d: %d.\n", num, cont);
}

void localiza_intervalo(int vetor[20], int *a, int *b){

    int i, qtd=0;

    printf("\n\tDigite um valor para A: ");
    scanf("%d", a);
    printf("\tDigite um valor para B: ");
    scanf("%d", b);

    for(i=0;i<20;i++){
        if(*a > *b){
            if(vetor[i]<*a && vetor[i]>*b){
                qtd++;
            }
        }
        else if(*b > *a){
            if(vetor[i]<*b && vetor[i]>*a){
                qtd++;
            }
        }
    }
    printf("\n\tQuantidade de elementos que estão no intervalo de %d e %d: %d.\n", *a, *b, qtd);
}

void soma_intervalo(int vetor[20], int a, int b){

    int i, soma=0;

    for(i=0;i<20;i++){
        if(a > b){
            if(vetor[i]<a && vetor[i]>b){
                soma = soma+vetor[i];
            }
        }
        else if(b > a){
            if(vetor[i]<b && vetor[i]>a){
                soma = soma+vetor[i];
            }
        }
    }
    printf("\tSoma dos elementos do intervalo: %d.\n", soma);
}

void localiza_elemento(int vetor[20]){

    int i, achar, aux=-1;

    printf("\n\n\tDigite um valor para encontrar sua posição dentro do vetor: ");
    scanf("%d", &achar);

    for(i=0; i<20; i++){
        if(achar == vetor[i]){
            aux = i;
        }
    }
    printf("\n\tO valor %d está localizado em Vetor[%d].\n", achar, aux);
}

void preenche_vetor(int vetor[20]){

    int i;

    srand(time(NULL));

    for(i=0; i<20; i++){
        vetor[i] = rand()%31;
    }

}

void apresenta_vetor(int vetor[20]){

    int i;

    printf("\n\t");
    for(i=0; i<20; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int vetor[20], a=0, b=0;

    preenche_vetor(vetor);
    apresenta_vetor(vetor);

    localiza_maior(vetor);
    localiza_menor(vetor);
    localiza_maiores(vetor);
    localiza_intervalo(vetor, &a, &b);

    soma_intervalo(vetor, a, b);
    localiza_elemento(vetor);

}
