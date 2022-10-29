#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int vezes=0, nrand=0, n1, n1check=0, n2, n2check=0;

    printf("\nInforme um número entre 1 e 75: ");
    scanf("%d", &n1);

    printf("Informe outro número entre 1 e 75: ");
    scanf("%d", &n2);
    printf("\n");

    srand(time(NULL));

    while(n1check != n1 || n2check != n2){

        nrand = rand()%75 + 1;

        if(n1check != n1){
            n1check = nrand;
        }

        if(n2check != n2){
            n2check = nrand;
        }

        printf("%d - ", nrand);
        vezes = vezes+1;

    }

    printf("\n\nForam necessários %d sorteios para acertar os números.\n\n", vezes);

}

