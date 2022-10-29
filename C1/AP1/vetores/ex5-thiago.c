#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int i, vetor[8], soma = 0, maior = 0, posicao = 0;

    for(i = 0; i < 8; i++){
        printf("Informe um valor inteiro [Posição %d]: ", i);
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < 8; i++){
        soma = soma + vetor[i];
    }

    for(i = 0; i < 8; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
            posicao = i;
        }
    }

    printf("\n\n  Soma dos valores apresentados: %d.", soma);
    printf("\n  Maior valor apresentado: %d.", maior);
    printf("\n  Posicao que o maior numero se encontra: %d.\n\n", posicao);

}
