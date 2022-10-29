#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int tl, i;
float elements[30], media, soma=0, maior, menor;
char escolha;

    printf("\n\tInforme quantos elementos serão digitados (Entre 1 e 30): ");
    scanf("%d", &tl);

    printf("\n");
    if (tl > 0 && tl < 31){
        for(i = 0; i < tl; i++){
            printf("Informe o valor do elemento: ");
            scanf("%f", &elements[i]);
            soma = soma + elements[i];
        }
    } else {
        printf("O valor informado não é permitido...\n");
        system("pause");
        return 0;
    }

    media = soma / tl;
    menor = elements[0];
    maior = elements[0];

    for(i = 0; i < tl; i++){

        if(elements[i] < menor){
            menor = elements[i];
        }

        if(elements[i] > maior){
            maior = elements[i];
        }
    }

    printf("\n\t\t\t----- MENU DE OPÇÕES: -----\n");

    printf("\n a) Apresentar o menor e o maior elemento");
    printf("\n b) Apresentar a soma e a média dos elementos");
    printf("\n c) Apresentar o vetor inteiro");
    printf("\n d) Encerrar o programa\n");

    while (escolha != 'd'){

    printf("\n\nEscolha uma opção: ");
    scanf(" %c", &escolha);
    printf("\n");

        switch (escolha){

            case 'a':
            case 'A':

                printf("Maior valor: %.2f.", maior);
                printf("\nMenor valor: %.2f.\n", menor);

            break;


            case 'b':
            case 'B':

                printf("Soma dos valores: %.2f.", soma);
                printf("\nMédia dos valores: %.2f.\n", media);

            break;


            case 'c':
            case 'C':

                for(i = 0; i < tl; i++){
                    printf("Vetor[%d]: %.2f.\n", i, elements[i]);
                }

            break;


            case 'd':
            case 'D':
                printf("\n\tAté a próxima...\n\n");
                system("pause");
                return 0;
            break;

        }

    }

}
