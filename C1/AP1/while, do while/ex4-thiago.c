#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int alibaba=0, alcapone=0, nulo=0, branco=0, voto=0;

    printf("\n                URNA ELETR�NICA, VOTE!");
    printf("\n83-Alibab�, 93-Alcapone, 00-Voto em branco, -1 para finalizar a vota��o.");

    while(voto >= 0){

        printf("\n\nInforme para qual n�mero voc� ir� votar: ");
        scanf("%d", &voto);

        switch(voto){

        case 83: alibaba = alibaba+1;
                 break;

        case 93: alcapone = alcapone+1;
                 break;

        case 00: branco = branco+1;
                 break;

        default: nulo = nulo+1;

        }

        printf("Voto registrado!");

    }

    printf("\n\n\nQuantidade de votos para Alibab�: %d", alibaba);
    printf("\nQuantidade de votos para Alcapone: %d", alcapone);
    printf("\nQuantidade de votos em branco: %d", branco);
    printf("\nQuantidade de votos nulos: %d\n\n", nulo-1);

    if(alibaba > alcapone){
        printf("\nAlibab� venceu a elei��o com %d votos!\n\n", alibaba);
    }else if(alcapone > alibaba){
        printf("\nAlcapone venceu a elei��o com %d votos!\n\n", alcapone);
    }else if(alcapone == alibaba){
        printf("\nA elei��o terminou empatada, segundo turno necess�rio!!!!\n\n");
    }else{
        printf("Oops... Parece que temos dados errados ent�o o resultado est� cancelado.");
    }

}
