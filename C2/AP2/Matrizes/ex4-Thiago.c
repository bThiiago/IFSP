#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int mat[10][5]={{0}},
    lin, col,
    i=0, qnt=0,
    colAux=0,
    escolha;

    srand(time(NULL));

    do{
        lin = rand()%10+1;
        col = rand()%5+1;

        qnt = qnt+1;

        if(mat[lin][col] == 0){
            mat[lin][col] = qnt;
        }else{
            lin = rand()%10+1;
            col = rand()%5+1;
            if(mat[lin][col] == 0){
                mat[lin][col] = qnt;
            }else{
                lin = rand()%10+1;
                col = rand()%5+1;
                if(mat[lin][col] == 0){
                    mat[lin][col] = qnt;
                }
            }
        }

        i++;
    }while(i<20);

    printf("\n\tInforme o número do pacote que deseja: ");
    scanf("%d", &escolha);

    printf("\n");

    for(lin=0;lin<10;lin++){
            printf("\n");
        for(col=0;col<5;col++){
            printf("\t%d", mat[lin][col]);
        }
            printf("\n");
    }

    printf("\n");
    printf("\n");

    for(lin=0;lin<10;lin++){
        for(col=0;col<5;col++){
            if(mat[lin][col] > 0 && mat[lin][col] < 21){
            printf("\n\tPacote %d: Linha[%d] Coluna[%d]", mat[lin][col], lin, col);
            }
        }
    }

    printf("\n");
    printf("\n");
    printf("\n");

    printf("\tPACOTES EM CADA COLUNA!\n");
    for(col=0;col<5;col++){
        printf("\tColuna %d: ", col);
        for(lin=0;lin<10;lin++){
            if(mat[lin][col] > 0 && mat[lin][col] < 21){
                printf("%d, ", mat[lin][col]);
            }
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");
    printf("\tPACOTES EM CADA LINHA!\n");

    for(lin=0;lin<10;lin++){
        printf("\tLinha %d: ", lin);
        for(col=0;col<5;col++){
            if(mat[lin][col] > 0 && mat[lin][col] < 21){
                printf("%d, ", mat[lin][col]);
            }
        }
        printf("\n");
    }

    printf("\n");

    for(lin=0;lin<10;lin++){
        for(col=0;col<5;col++){
            if(mat[lin][col] == escolha){
            printf("\n\tPacote informado pelo usuario: %d - Linha[%d] Coluna[%d]", escolha, lin, col);
            }
        }
    }

    printf("\n");

}
