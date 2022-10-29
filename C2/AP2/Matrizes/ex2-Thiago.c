#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int cliente[20], produto[10],
    cli, pro,
    tl, tl2,
    i, j,
    mais, maisAux;

char escolha;

    printf("\n\tQuantidade de clientes: ");
    scanf("%d", &tl2);

    if(tl2 > 20){
        printf("\n\n\tQuantidade de clientes maior que 20.\n\n");
        return 0;
    }

    for(i=0;i<tl2;i++){
        printf("\n\tCliente %d.", i);
        printf("\nQuantidade de produtos para registrar: ");
        scanf("%d", &tl);

        if(tl > 10){
            printf("\n\n\tQuantidade de produtos maior que 10.\n\n");
            return 0;
        }

        for(j=0;j<tl;j++){
            printf("Código do produto: ");
            scanf("%d", &produto[j]);
        }
    }

    mais = produto[0];

    for(i=0;i<tl2;i++){
        for(j=0;j<tl;j++){
            if(mais < produto[j]){
                mais = produto[j];
                maisAux = i;
            }
        }
    }

    printf("\n\tCLIENTE QUE MAIS COMPROU PRODUTOS:");
    printf("\n\tO cliente %d comprou um total de %d produtos.\n", maisAux, mais);

}
