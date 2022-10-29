#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int i, j, aulas[20], abono[10], presenca[10], faltas=0, presenc=0, reprovado=0, abonos=0;
char situac[10];

    printf("\n\t\t“P” de presença, “F” de falta e “A” de abono.\n");

    for(i = 0; i < 10; i++){
        presenca[i] = 0;
        abono[i] = 0;
    }

    for(j = 0; j < 20; j++){
        printf("\n\tAula %d.\n\n", j);
        for(i = 0; i < 10; i++){
            printf("\tAluno %d: ", i);
            scanf(" %c", &situac[i]);
            switch (situac[i]){

                case 'a':
                case 'A':

                    abono[i] = abono[i]+5;
                    abonos = abonos+1;

                break;

                case 'f':
                case 'F':

                    faltas = faltas+1;

                break;

                case 'p':
                case 'P':

                    presenca[i] = presenca[i]+5;

                break;

                default:
                    printf("\tEntrada inválida.\n");

            }
        }
    }

    for(i = 0; i < 10; i++){
        presenc = presenca[i]+abono[i];
        if(presenc >= 75){
            printf("\n\n\tAluno %d:", i);
            printf("\n\tFrequencia: %d%%", presenc);
            printf("\n\tSituação: aprovado.\n");
        } else if(presenc < 75){
            printf("\n\n\tAluno %d:", i);
            printf("\n\tFrequencia: %d%%", presenc);
            printf("\n\tSituação: reprovado.\n");
            reprovado = reprovado+1;
        }
    }

    printf("\n\n\tHouve um total de %d aluno(s) reprovado(s).\n", reprovado);
    printf("\n\tHouve um total de %d faltas.\n", faltas);
    printf("\n\tHouve um total de %d abonos.\n\n", abonos);

}
