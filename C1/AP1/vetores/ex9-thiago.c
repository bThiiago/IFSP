#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int vetor[10], i, pares = 0, positivos = 0;

    for(i = 0; i < 10; i++){
        printf("Informe um valor inteiro: ",vetor[i]);
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < 10; i++){
        if(vetor[i] % 2 == 0){
            pares++;
        }
    }

    for(i = 0; i < 10; i++){
        if(vetor[i] >= 0){
            positivos++;
        }
    }

    printf("\n  Você informou %d valores pares.", pares);
    printf("\n  Você informou %d valores positivos.\n", positivos);

}
