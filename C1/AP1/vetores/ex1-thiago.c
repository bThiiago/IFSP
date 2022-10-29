#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int vetor[5], i, menor = 0, maior = 0;
float soma = 0, media= 0;

    printf("\n Digite 5 valores.\n\n");

    for(i = 0; i < 5; i++){
        printf("Informe um valor: ");
        scanf("%d", &vetor[i]);
        soma = soma+vetor[i];
    }

    media = soma/5;
    maior = vetor[0];
    menor = vetor[0];

    for(i = 0; i < 5; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
        }else if(vetor[i] < menor){
            menor = vetor[i];
        }
    }

    printf("\nMenor valor: %d.", menor);
    printf("\nMaior valor: %d.", maior);
    printf("\nSoma dos valores: %.2f.", soma);
    printf("\nMédia dos valores: %.2f.\n\n", media);

    for(i = 0; i < 5; i++){
        printf("Vetor[%d]: %d \n", i, vetor[i]);
    }



}
