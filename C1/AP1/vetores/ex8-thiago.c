#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int i, espaco = 0, palavra = 0;
char vetor[30], nome;

    printf("\n Informe seu nome: ");

    do{
        scanf("%c", &nome);

        if(nome != 10){
           vetor[i] = nome;
           i++;
        }

    }while(i < 30 && nome != 10);

    for(i = 0; i < vetor[i]; i++){
        palavra = palavra+1;
    }

    for(i = 0; i < vetor[i]; i++){
        if(vetor[i] == ' '){
            espaco = espaco+1;
        }
    }

    espaco = palavra-espaco;

    printf("\n\nTem um total de %d palavras em seu nome.", palavra);
    printf("\nTem um total de %d letras em seu nome.\n", espaco);

    printf("Primeiro nome: ");
    for(i = 0; i < vetor[i]; i++){
        if(vetor[i] != ' '){
            printf("%c", vetor[i]);
        }else{
            printf("\n\n");
            return 0;
        }
    }

}
