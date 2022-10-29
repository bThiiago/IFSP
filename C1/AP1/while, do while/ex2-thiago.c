#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int quantidade;
float doacao, valor, assist;

    printf("Ajude João das Contas a arrecadar 20 mil reais para sua campanha!!\n");

    do{

        printf("\nDigite o valor de sua doação: ");
        scanf("%f", &doacao);

        assist = doacao;
        valor += assist++;
        quantidade = quantidade+1;

    }while(valor <= 20000);

    printf("\n\nValor arrecadado das doações: %.2f R$\n", valor);
    printf("Total de pessoas que doaram: %d\n\n", quantidade);

}
