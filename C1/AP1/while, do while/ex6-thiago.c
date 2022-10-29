#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<time.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int pt1=0, pt2=0, jogador1, jogador2;

    while(pt1 < 11 || pt2 < 11){

    srand(time(NULL));
    jogador1 = rand()% 100;
    jogador2 = rand()% 100;

    printf("\nJogador 1 tirou %d pontos.", jogador1);
    printf("\nJogador 2 tirou %d pontos.\n", jogador2);

    pt1 += jogador1;
    pt2 += jogador2;

    }

    if(pt1 > pt2 && pt1 >= 11){
        printf("\nJogador 1 ganhou com %d pontos.\n", pt1);
    }else if(pt2 > pt1 && pt2 >= 11){
        printf("\nJogador 2 ganhou com %d pontos.\n", pt2);
    }

}
