#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int vetor[9], i, j, k, cont = 0;

    for(i = 0; i < 9; i++){
        printf("Informe um valor: ");
        scanf("%d", &vetor[j-1]);
    }

    for(i = 0; i < 9; i++){
        if(vetor[j] <= 0){
            printf("\nUtilizar valor ZERO ou NEGATIVO não é permitido.\n");
            return 0;
        }
    }

    printf("\n");

    for(i = 0; i < 9; i++){
        vetor[8] = 0;
        printf("Vetor[%d]: valor %d.\n", i, vetor[j]);
    }

    for(i = 0; i < 9; i++){
            cont = 0;
        for(j = 0; j < 9; j++){
            if(vetor[i] == vetor[j] && i != j){
                for(k = i + 1; k < 9; k++){
                    if(vetor[i] == vetor[k]){
                       cont++;
                    }
                }
                printf("O valor %d se repete %d vezes.\n", vetor[j], cont);
            }
        }
    }

}
