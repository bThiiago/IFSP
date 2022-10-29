#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int fichadois, fichad = 0, fichacinco, fichac = 0, pessoas = 1;
char pergunta;

    printf("Quantas fichas de 2,00 R$ o cliente comprou? ");
    scanf("%d", &fichadois);

    fichad = fichad + fichadois;

    printf("Quantas fichas de 5,00 R$ o cliente comprou? ");
    scanf("%d", &fichacinco);

    fichac = fichac + fichacinco;

    printf("\n       Responda com 'S' caso haja.");
    printf("\nAinda há alguma pessoa querendo comprar fichas? ");
    scanf("%s", &pergunta);

    if(pergunta=='S'){

        while(pergunta=='S'){

            pessoas = pessoas + 1;

            printf("\nQuantas fichas de 2,00 R$ o cliente comprou? ");
            scanf("%d", &fichadois);

            fichad = fichad + fichadois;

            printf("Quantas fichas de 5,00 R$ o cliente comprou? ");
            scanf("%d", &fichacinco);

            fichac = fichac + fichacinco;

            printf("\n       Responda com 'S' caso haja.");
            printf("\nAinda há alguma pessoa querendo comprar fichas? ");
            scanf("%s", &pergunta);

        }

    }

    printf("\n\nQuantidade de pessoas que compraram fichas: %d", pessoas);
    printf("\nFichas de 2,00 R$ vendidas: %d", fichad);
    printf("\nFichas de 5,00 R$ vendidas: %d\n\n", fichac);

}
