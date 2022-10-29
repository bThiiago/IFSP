#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int idade, menor=0, maior=0, entre=0;

    printf("\n    Digite 0 para encerrar a entrada de idades!\n\n");

    while(idade > 0){

        printf("Informe a idade da pessoa: ");
        scanf("%d", &idade);

        if(idade < 18){

            menor = menor+1;

        }else if(idade > 60){

            maior = maior+1;

        }else if(idade >= 18 && idade <= 60){

            entre = entre+1;

        }

    }

    printf("\n\n  %d pessoa(s) possuem idade inferior a 18 anos.", menor-1);
    printf("\n  %d pessoa(s) possuem idade superior a 60 anos.", maior);
    printf("\n  %d pessoa(s) possuem idade entre 18 e 60 anos.\n\n", entre);

}
