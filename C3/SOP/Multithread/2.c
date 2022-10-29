#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>

static char caracter[1];
static int contadorthr=0;

void print(int n) {
    while(1){
        printf("\n%d - %s", n, caracter);
        if ( kbhit() ){
            caracter[0] = getch();
        }
    }
}

void main(void)
{
    int qtdthr=0, n;

    printf("Informe a quantidade de threads: ");
    scanf("%d", &qtdthr);

    fflush(stdin);
    printf("Informe um caractere: ");
    gets(caracter);

    for(n = 0; n < qtdthr; n++)
        _beginthread(print, NULL, n);
    while(1);
}