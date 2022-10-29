#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int mat[5][5]={{0}}, somaMaior[5]={{0}}, somaMenor[5]={{0}},
    col, lin,
    linMaior=0, linMenor=0,
    colMaior=0, colMenor=0,
    maior=0, menor=0,
    maiorAux, linAux,
    menorAux, colAux,
    soma=0, somaDiag=0,
    diagPri=0, diagSec=0;

    srand(time(NULL));

    printf("\n");
    for(lin=0;lin<5;lin++){
            printf("\n");
        for(col=0;col<5;col++){
            mat[lin][col] = rand()%100+1;
            printf("\t%d", mat[lin][col]);
        }
            printf("\n");
    }

    maior = mat[0][0];
    menor = mat[0][0];

    for(lin=0;lin<5;lin++){
        for(col=0;col<5;col++){
            somaMaior[lin] = somaMaior[lin]+mat[lin][col];
            somaMenor[col] = somaMenor[col]+mat[lin][col];
            soma = soma+mat[lin][col];
            if(mat[lin][col] > maior){
                maior = mat[lin][col];
                linMaior = lin;
                colMaior = col;
            }else if(mat[lin][col] < menor){
                menor = mat[lin][col];
                linMenor = lin;
                colMenor = col;
            }
            if(lin == col){
                diagPri = diagPri+mat[lin][col];
            }else if(lin == 0 && col == 4 || lin == 1 && col == 3 || lin == 2 && col == 2 || lin == 3 && col == 1 || lin == 4 && col == 0){
                diagSec = diagSec+mat[lin][col];
            }
        }
    }

    printf("\n\nMaior valor: Mat[%d][%d] = %d \n", linMaior, colMaior, maior);
    printf("Menor valor: Mat[%d][%d] = %d \n", linMenor, colMenor, menor);

    maiorAux = somaMaior[0];
    menorAux = somaMenor[0];
    somaDiag = diagPri+diagSec;

    for(lin=0;lin<5;lin++){
        if(maiorAux < somaMaior[lin]){
            maiorAux = somaMaior[lin];
            linAux = lin;
        }
    }

    for(col=0;col<5;col++){
        if(menorAux > somaMenor[col]){
            menorAux = somaMenor[col];
            colAux = col;
        }
    }

    printf("A linha %d tem o valor %d portanto tem a maior soma.\n", linAux, maiorAux);
    printf("A coluna %d tem o valor %d portanto tem a menor soma.\n", colAux, menorAux);
    printf("A soma de todos os elementos é %d. \n", soma);
    printf("A soma das duas diagonais é %d. \n", somaDiag);

}
