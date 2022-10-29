#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void matriz(int mat[5][5]){

    int lin, col;

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

}

void maior_menor(int mat[5][5], int somaMaior[5], int somaMenor[5]){

    int lin, col,
    maior, menor,
    linMaior, colMaior,
    linMenor, colMenor;

    maior = mat[0][0];
    menor = mat[0][0];

    for(lin=0;lin<5;lin++){
        for(col=0;col<5;col++){
            somaMaior[lin] = somaMaior[lin]+mat[lin][col];
            somaMenor[col] = somaMenor[col]+mat[lin][col];
            if(mat[lin][col] > maior){
                maior = mat[lin][col];
                linMaior = lin;
                colMaior = col;
            }else if(mat[lin][col] < menor){
                menor = mat[lin][col];
                linMenor = lin;
                colMenor = col;
            }
        }
    }

    printf("\n\nMaior valor: Mat[%d][%d] = %d \n", linMaior, colMaior, maior);
    printf("Menor valor: Mat[%d][%d] = %d \n", linMenor, colMenor, menor);
}

void linha(int somaMaior[5]){

    int lin,
        linAux,
        maiorAux;

    maiorAux = somaMaior[0];
    for(lin=0;lin<5;lin++){
        if(maiorAux < somaMaior[lin]){
            maiorAux = somaMaior[lin];
            linAux = lin;
        }
    }
    printf("A linha %d tem o valor %d portanto tem a maior soma.\n", linAux, maiorAux);
}

void coluna(int somaMenor[5]){

    int col,
        colAux,
        menorAux;

    menorAux = somaMenor[0];
    for(col=0;col<5;col++){
        if(menorAux > somaMenor[col]){
            menorAux = somaMenor[col];
            colAux = col;
        }
    }
    printf("A coluna %d tem o valor %d portanto tem a menor soma.\n", colAux, menorAux);
}

void soma_todos(int mat[5][5]){

    int lin, col,
        soma=0;

    for(lin=0;lin<5;lin++){
        for(col=0;col<5;col++){
            soma = soma+mat[lin][col];
        }
    }
    printf("A soma de todos os elementos é %d. \n", soma);
}

void soma_diag(int mat[5][5]){

    int lin, col,
        diagPri=0,
        diagSec=0,
        somaDiag=0;

    for(lin=0;lin<5;lin++){
        for(col=0;col<5;col++){
            if(lin == col){
                diagPri = diagPri+mat[lin][col];
            }else if(lin == 0 && col == 4 || lin == 1 && col == 3 || lin == 2 && col == 2 || lin == 3 && col == 1 || lin == 4 && col == 0){
                diagSec = diagSec+mat[lin][col];
            }
        }
    }
    somaDiag = diagPri+diagSec;
    printf("A soma das duas diagonais é %d. \n", somaDiag);
}

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

    int mat[5][5]={{0}}, somaMaior[5]={{0}}, somaMenor[5]={{0}};

    matriz(mat);

    maior_menor(mat, somaMaior, somaMenor);

    linha(somaMaior);

    coluna(somaMenor);

    soma_todos(mat);

    soma_diag(mat);

}
