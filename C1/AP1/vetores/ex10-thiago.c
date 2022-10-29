#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int i = 0, casa, energia[25], maisN, menosN, total = 0, menos = 99999999999;
float valor, gasto = 0, mais = 0, icms;

    printf("\n Qual o valor do kWh? ");
    scanf("%f", &valor);

    printf("\n");

    for(i = 0; i < 25; i++){
        printf("Quanto de energia a casa %d gastou (kWh): ", i);
        scanf("%d", &energia[i]);
    }

    for(i = 0; i < 25; i++){
        total = total+energia[i];
    }

    for(i = 0; i < 25; i++){

        if(energia[i] > mais){
            mais = energia[i];
            maisN = i;
        }

        if(energia[i] < menos){
            menos = energia[i];
            menosN = i;
        }

    }

    gasto = mais*valor;
    icms = (total*valor)/4;

    printf("\n\nA casa %d gastou %d kWh, portanto foi a com menor gasto.",menosN, menos);
    printf("\nA casa %d gastou %.2f R$ em sua conta, portanto foi a mais cara.",maisN, gasto);
    printf("\nTotal de %d kWh gastos de energia.\n", total);

    printf("\nValor total de todas as residências: %.2f R$", total*valor);
    printf("\nValor pago de ICMS: %.2f R$\n\n", icms);

}
