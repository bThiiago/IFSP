#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int ddd, dddlig, minutos = 0, tminArea = 0, tminLocal = 0;
float valor = 0, valorlig = 0, temp = 0;

    printf("\nValor da recarga de crédito colocado: ");
    scanf("%f", &valor);

    printf("DDD do celular: ");
    scanf("%d", &ddd);

    while(valor > 0){
        printf("\nQuantidade minutos: ");
        scanf("%d", &minutos);

        printf("DDD para o celular que vai ligar: ");
        scanf("%d", &dddlig);

        if(ddd == dddlig){
            temp = 0.30;
            tminLocal = tminLocal+minutos;
        }else{
            temp = 0.75;
            tminArea = tminArea+minutos;
        }

        valorlig = minutos*temp;
        valor = valor-valorlig;

        printf("Crédito restante: %.2f", valor );
        printf("\n");

    }

    printf("\n\nSaldo final : %.2f", valor);
    printf("\nTotal de minutos utilizados em ligações locais: %d minutos.", tminLocal);
    printf("\nTotal de minutos utilizados em ligações entre areas: %d minutos.\n\n", tminArea);

}
