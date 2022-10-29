#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int tl = 0, i, letra = 0;
char vetor[20], palavra;

    printf("\n   Digite uma frase de até 20 caracteres!\n\n");

    do{
    scanf("%c", &palavra);

        if(palavra != 10){
           vetor[tl] = palavra;
           tl++;
        }

    }while(tl < 20 && palavra != 10);

    printf("\n");

    printf("Frase: ");
    for(i = 0; i < tl; i++){
        if(vetor[i] == 'a' || vetor[i] == 'A'){
            letra = letra+1;
        }
        printf("%c", vetor[i]);

    }

    printf("\nTotal de %d letras A.\n", letra);

    printf("Frase invertida: ");
    for(i = tl-1; i >= 0; i--){
        printf("%c", vetor[i]);
    }

    printf("\n");

}
