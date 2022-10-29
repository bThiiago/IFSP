#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int totali;
float preco, sub, suba, total = 0;

    printf("Caso tenha informado o valor de todos os produtos digite 0.");

    do {

        printf("\n\nInforme o valor do produto: ");
        scanf("%f", &preco);

        suba = preco;
        sub += suba++;
        totali = totali+1;

        if(preco>0){
            printf("Subtotal: %.2f R$", sub);
        }else{
            totali = totali-1;
        }

    }while (preco > 0);

    total = sub;

    printf("\n\nTotal da compra: %.2f R$\n", total);
    printf("Total de itens comprados: %d\n\n", totali);

}
