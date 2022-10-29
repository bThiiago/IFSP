#include <stdio.h>
#include <locale.h>

void ler_nome(char vetor[30]){

    char nome;
    int i=0;

    printf("\nDigite seu nome: ");
    do{
        scanf("%c", &nome);

        if(nome != 10){
           vetor[i] = nome;
           i++;
        }

    }while(i < 30 && nome != 10);
}

void palavras(char vetor[30], int *palavra){

    int i;

    for(i = 0; i < vetor[i]; i++){
        *palavra = *palavra+1;
    }
    printf("\nTem um total de %d palavras em seu nome.", *palavra);
}

void letras(char vetor[30], int palavra){

    int i, espaco=0;

    for(i = 0; i < vetor[i]; i++){
        if(vetor[i] == ' '){
            espaco = espaco+1;
        }
    }

    espaco = palavra-espaco;
    printf("\nTem um total de %d letras em seu nome.\n", espaco);
}

void primeiro_nome(char vetor[30]){

    int i;

    printf("\nPrimeiro nome: ");
    for(i = 0; i < vetor[i]; i++){
        if(vetor[i] != ' '){
            printf("%c", vetor[i]);
        }else{
            printf("\n");
            return 0;
        }
    }

}

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

char vetor[30];
int palavra=0;

    ler_nome(vetor);
    palavras(vetor, &palavra);
    letras(vetor, palavra);
    primeiro_nome(vetor);

}
