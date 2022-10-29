#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int i, codigo[30], quantidade[30], produtos, total=0, maiorQ=0, auxV=0, auxQ=0, auxE=0;
float valor[30], maiorV=0, estoque[30], aux=0;

    for(i = 0; i < 30; i++){
        printf("\n\tCódigo do produto: ");
        scanf("%d", &codigo[i]);

        printf("\tQuantidade: ");
        scanf("%d", &quantidade[i]);

        total = total+quantidade[i];

        printf("\tValor de venda: ");
        scanf("%f", &valor[i]);
    }

    for(i = 0; i < 30; i++){
        if(valor[i] > maiorV){
            maiorV = valor[i];
            auxV = codigo[i];
        }
    }

    for(i = 0; i < 30; i++){
        estoque[i] = quantidade[i]*valor[i];
        if(quantidade[i] > maiorQ){
            maiorQ = quantidade[i];
            auxQ = codigo[i];
        }
    }

    aux = estoque[0];
    auxE = codigo[0];

    for(i = 0; i < 30; i++){
        if(estoque[i] > aux){
            aux = estoque[i];
            auxE = codigo[i];
        }
    }

    printf("\n\n\n\tTotal final do estoque: %d.\n\n", total);

    printf("\n\t-------------PRODUTO MAIS CARO VENDIDO-------------");
    printf("\n\t\t\tCódigo do produto: %d", auxV);
    printf("\n\t\t\tValor: %.2f R$", maiorV);
    printf("\n\t-------------PRODUTO MAIS CARO VENDIDO-------------\n");

    printf("\n\n\t-------------PRODUTO COM MAIS QUANTIDADE-------------");
    printf("\n\t\t\tCódigo do produto: %d", auxQ);
    printf("\n\t\t\tQuantidade: %d.", maiorQ);
    printf("\n\t-------------PRODUTO COM MAIS QUANTIDADE-------------\n");

    printf("\n\n\t-------------PRODUTO COM MAIOR VALOR EM ESTOQUE-------------");
    printf("\n\t\t\tCódigo do produto: %d", auxE);
    printf("\n\t\t\tValor: %.2f R$", aux);
    printf("\n\t-------------PRODUTO COM MAIOR VALOR EM ESTOQUE-------------\n\n");

}
