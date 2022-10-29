#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int i = 0, correto = 0, percent = 0, rasurado;
char gab[10], resp[10];

        printf("\n\tInforme o gabarito.\n\n");
    for(i = 0; i < 10; i++){
        printf("Questão %d, resposta: ", i+1);
        scanf(" %c", &gab[i+1]);
    }

        printf("\n\n\tInforme as respostas do candidato.\n\n");
    for(i = 0; i < 10; i++){
        printf("Questão %d, resposta: ", i+1);
        scanf(" %c", &resp[i+1]);
    }

    for(i = 0; i < 10; i++){
        if (resp[i+1] == gab[i+1]){
            correto++;
        }
    }

    for(i = 0; i < 10; i++){
        if (resp[i+1] == 'x' || resp[i+1] == 'X'){
            rasurado++;
        }
    }

    percent = correto*10;

    printf("\n\n\tO candidato teve um total de %d respostas certas.", correto);
    printf("\n\tCom um percentual de acerto de %d", percent);
    printf("\n\tTeve um total de %d respostas rasuradas.\n\n", rasurado);

}
