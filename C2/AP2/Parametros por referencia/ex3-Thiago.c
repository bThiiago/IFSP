#include <stdio.h>
#include <locale.h>

void compra_um(float cp1[20], int *qnt1){

    int i;

    printf("\n\t  PRIMEIRA COMPRA\n");
    printf("\n  Quantos produtos serão registrados: ");
    scanf("%d", qnt1);
    printf("\n");

    for(i=0; i<*qnt1; i++){
        printf("\tValor do produto %d: ", i);
        scanf("%f", &cp1[i]);
    }
}

void compra_dois(float cp2[20], int *qnt2){

    int i;

    printf("\n\t  SEGUNDA COMPRA\n");
    printf("\n  Quantos produtos serão registrados: ");
    scanf("%d", qnt2);
    printf("\n");

    for(i=0; i<*qnt2; i++){
        printf("\tValor do produto %d: ", i);
        scanf("%f", &cp2[i]);
    }
}

void maior_compra(float cp1[20], float cp2[20], int qnt1, int qnt2){

    int i;
    float soma1=0, soma2=0;

    for(i=0; i<qnt1; i++){
        soma1 = soma1+cp1[i];
    }

    for(i=0; i<qnt2; i++){
        soma2 = soma2+cp2[i];
    }

    if(soma1 > soma2){
        printf("\n\n\nA compra de maior valor foi a primeira, com %.2f reais gastos.\n", soma1);
    }else if(soma1 < soma2){
        printf("\n\n\nA compra de maior valor foi a segunda, com %.2f reais gastos.\n", soma2);
    }else if(soma1 == soma2){
        printf("\n\n\nAmbas compras tiveram o mesmo valor gasto, sendo %.2f reais.\n", soma1);
    }
}

void mais_caro(float cp1[20], float cp2[20], int qnt1, int qnt2){

    int i1, i2, a1=0, a2=0;
    float mais1, mais2;

    mais1 = cp1[0];
    mais2 = cp2[0];

    printf("\n\nProduto mais caro da primeira compra: \n");
    for(i1=0; i1<qnt1; i1++){
        if (mais1 < cp1[i1]){
            mais1 = cp1[i1];
            a1 = i1;
        }
    }
    printf("Produto %d: %.2f reais.", a1, mais1);

    printf("\n\nProduto mais caro da segunda compra: \n");
    for(i2=0; i2<qnt2; i2++){
        if (mais2 < cp2[i2]){
            mais2 = cp2[i2];
            a2 = i2;
        }
    }
    printf("Produto %d: %.2f reais.\n", a2, mais2);
}

void todas_compras1(float cp1[20], int qnt1){

    int i;

    printf("\n\n\tRELATORIO PRIMEIRA COMPRA\n");
    for(i=0; i<qnt1; i++){
        printf("\n\t Valor do produto %d: %.2f", i, cp1[i]);
    }
}

void todas_compras2(float cp2[20], int qnt2){

    int i;

    printf("\n\n\n\tRELATORIO SEGUNDA COMPRA\n");
    for(i=0; i<qnt2; i++){
        printf("\n\t Valor do produto %d: %.2f", i, cp2[i]);
    }
    printf("\n\n");
}

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

float compra1[20]={0}, compra2[20]={0};
int qnt1, qnt2;

    compra_um(compra1, &qnt1);
    compra_dois(compra2, &qnt2);

    maior_compra(compra1, compra2, qnt1, qnt2);
    mais_caro(compra1, compra2, qnt1, qnt2);

    todas_compras1(compra1, qnt1);
    todas_compras2(compra2, qnt2);
}
