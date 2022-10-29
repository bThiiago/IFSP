#include <stdio.h>
#include <locale.h>

void pessoas_reg(int idade[], int *qnt){

    int i;

    printf("\n\t   Quantidade de pessoas para registrar: ");
    scanf("%d", qnt);
    printf("\n");
    for(i=0; i<*qnt; i++){
        printf("\t\t\tIdade: ");
        scanf("%d", &idade[i]);
    }

}

void gratuito(int idade[], int qnt){

    int i, gratuito=0;

    for(i=0; i<qnt; i++){
        if(idade[i] >= 65){
            gratuito++;
        }
    }
    printf("\n\t   Foram cedidas %d entradas gratu�tas.\n", gratuito);
}

void meias(int idade[], int qnt, int *meia, float *crianca){

    int i;

    for(i=0; i<qnt; i++){
        if(idade[i] <= 12 && idade[i] >= 1){
            *meia = *meia+9;
            *crianca = *crianca+1;
        }
    }
}

void inteira(int idade[], int qnt, int meia, float crianca){

    int i, inteira=0, total=0;
    float porcent=0, adulto=0;

    for(i=0; i<qnt; i++){
        if(idade[i] <= 64 && idade[i] >= 13){
            inteira = inteira+18;
            adulto = adulto+1;
        }
    }
    total = inteira+meia;
    porcent = crianca/(adulto+crianca)*100;

    printf("\t   Valor total arrecadado: %d R$.", total);
    printf("\n\t   Percentual de crian�as: %.2f\n", porcent);
}

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int pessoas[200]={0}, qnt=0, meia=0;
float crianca=0;

    pessoas_reg(pessoas, &qnt);
    gratuito(pessoas, qnt);
    meias(pessoas, qnt, &meia, &crianca);
    inteira(pessoas, qnt, meia, crianca);
}
