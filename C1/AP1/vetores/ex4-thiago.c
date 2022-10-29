#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int i, maior = 0;
float notas[10], soma = 0, media;

    for(i = 0; i < 10; i++){
        printf("Informe a nota do aluno: ");
        scanf("%f", &notas[i]);
    }

    for(i = 0; i < 10; i++){
        soma = soma + notas[i];
    }

    media = soma/10;

    for(i = 0; i < 10; i++){
        if(notas[i] > media){
            maior = maior+1;
        }
    }

    printf("\n\n  A soma de todas as notas da classe é de: %.2f", soma);
    printf("\n  A media da turma e de %.2f", media);
    printf("\n  %d alunos tem nota maior que a media da classe.\n\n", maior);

}
