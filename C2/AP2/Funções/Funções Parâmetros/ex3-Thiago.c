#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void ler_placa(char vetor[7]){

    int i;
    char placa;

    printf("\n\tInforme a placa do veículo: ");

    do{
        scanf("%c", &placa);

        if(placa != 10){
           vetor[i] = placa;
           i++;
        }
    }while(i < 7);
}

void achar_posicao(char vetor[7]){

    int i, placaN=0, placaL=0, posP=-1, posU=10;

    for(i = 0; i < 7; i++){
        if(vetor[i] >= '0' && vetor[i] <= '9'){
            placaN = placaN+1;
            if(posP < 0){
                posP = i;  //Parte que informa a posição do primeiro número (Começa do 0 e vai até o 6)//
            }
            if(posU > 7 && posU || posP){
                posU = i; //Parte que informa a posição do ultimo número (Começa do 0 e vai até o 6)//
            }
        }else{
            placaL = placaL+1;
        }
    }
    printf("\n\t\t   Letras: %d.", placaL);
    printf("\n\t\t   Números: %d.\n", placaN);
    printf("\n\tO primeiro número está na posição: %d.", posP);
    printf("\n\tO último número está na posição: %d.\n", posU);
}

void letras_numeros(char vetor[7]){

    int i;

    printf("\n");
    printf("\t\t   ");
    for(i = 0; i < 7; i++){
        if(vetor[i] >= 'a' && vetor[i] <= 'z' || vetor[i] >= 'A' && vetor[i] <= 'Z'){
            printf("%c", vetor[i]);
        }
    }
    for(i = 0; i < 7; i++){
        if(vetor[i] >= '0' && vetor[i] <= '9'){
            printf("%c", vetor[i]);
        }
    }
    printf("\n");
}

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

    int vetor[7];

    ler_placa(vetor);

    achar_posicao(vetor);

    letras_numeros(vetor);

}
