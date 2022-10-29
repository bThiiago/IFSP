#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int vetorA[5], vetorAu[5], vetorB[5], vetorC[10], i, somaA = 0, somaB = 0, numero, multi, aux = 0;
char escolha;

    printf("\n\t\t\t----- MENU DE OPÇÕES: -----\n");

    printf("\n a) Ler dois vetores inteiros a e b, com 5 elementos");
    printf("\n b) Colocar os elementos dos dois vetores a e b, em um terceiro vetor c com tamanho de 10 elementos");
    printf("\n c) Imprimir qual dos dois (a e b) tem a maior soma de elementos");
    printf("\n d) Multiplicar os elementos do vetor c(10) por um valor x(inteiro) digitado pelo usuário e apresentar esse vetor");
    printf("\n e) Trocar os elementos entre os vetores a e b");
    printf("\n f) Apresentar os elementos dos vetores a e b");
    printf("\n g) Encerrar o programa\n");

    while (escolha != 'g'){

    printf("\n\nEscolha uma opção: ");
    scanf(" %c", &escolha);
    printf("\n");

    switch (escolha){

        case 'a':
        case 'A':

            printf("\n\t\t\t----- Opção A escolhida: -----\n\n");

            for(i = 0; i < 5; i++){
                printf("Informe um valor inteiro para A: ");
                scanf("%d", &vetorA[i]);
                somaA = somaA+vetorA[i];
            }

            printf("\n");

            for(i = 0; i < 5; i++){
                printf("Informe um valor inteiro para B: ");
                scanf("%d", &vetorB[i]);
                somaB = somaB+vetorB[i];
            }

        break;


        case 'b':
        case 'B':

            printf("\n\t\t\t----- Opção B escolhida: -----\n");

            for(i = 0; i < 10; i++){
                vetorC[i] = vetorB[i-5];
            }

            for(i = 0; i < 5; i++){
                vetorC[i] = vetorA[i];
            }

            printf("\nElementos implementados!\n");

            for(i = 0; i < 10; i++){
                printf("Vetor C [%d]: %d \n", i, vetorC[i]);
            }

        break;


        case 'c':
        case 'C':

            printf("\n\t\t\t----- Opção C escolhida: -----\n");

            if(somaA > somaB){
                printf("\nO vetor A tem uma soma maior de elementos, sendo: %d\n", somaA);
            }else if(somaB > somaA){
                printf("\nO vetor B tem uma soma maior de elementos, sendo: %d\n", somaB);
            }else{
                printf("\nOs elementos tem o mesmo valor de soma: %d\n", somaA);
            }

        break;


        case 'd':
        case 'D':

            printf("\n\t\t\t----- Opção D escolhida: -----\n");

            printf("\nDigite um valor inteiro para multiplicar os elementos: ");
            scanf("%d", &numero);

            printf("\n");

            for(i = 0; i < 10; i++){
                vetorC[i] = numero*vetorC[i];
                printf("Vetor C [%d]: %d \n", i, vetorC[i]);
            }

        break;


        case 'e':
        case 'E':

            printf("\n\t\t\t----- Opção E escolhida: -----\n\n");

            for(i = 0; i < 5; i++){
                vetorAu[aux+1] = vetorB[i];
                aux++;
                printf("Vetor A [%d]: %d \n", i, vetorAu[aux]);
            }

            printf("\n");

            for(i = 0; i < 5; i++){
                vetorB[aux+1] = vetorA[i];
                aux++;
                printf("Vetor B [%d]: %d \n", i, vetorB[aux]);
            }

        break;


        case 'f':
        case 'F':

            printf("\n\t\t\t----- Opção F escolhida: -----\n\n");

            for(i = 0; i < 5; i++){
                printf("Vetor A [%d]: %d \n", i, vetorA[i]);
            }

            printf("\n");

            for(i = 0; i < 5; i++){
                printf("Vetor B [%d]: %d \n", i, vetorB[i]);
            }

        break;

        case 'g':
        case 'G':
            printf("\n Até a próxima...\n");
            return 0;
        break;

    }

    }

}
