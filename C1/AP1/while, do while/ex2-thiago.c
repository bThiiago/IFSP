#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int quantidade;
float doacao, valor, assist;

    printf("Ajude Jo�o das Contas a arrecadar 20 mil reais para sua campanha!!\n");

    do{

        printf("\nDigite o valor de sua doa��o: ");
        scanf("%f", &doacao);

        assist = doacao;
        valor += assist++;
        quantidade = quantidade+1;

    }while(valor <= 20000);

    printf("\n\nValor arrecadado das doa��es: %.2f R$\n", valor);
    printf("Total de pessoas que doaram: %d\n\n", quantidade);

}
