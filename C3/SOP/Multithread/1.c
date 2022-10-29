#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <sys/time.h>

#define TM 10000

static int mat[TM][TM] = {{0}}, contadorthr=0, qtdli=0;

void fill(int li)
{
    int i, j;
    for(i = li; i < li + qtdli; i++){
        for(j = 0; j < TM; j++){
            mat[i][j] = ((i * (j^3)) * (i^4)) * (i^2);
        } 
    }
    contadorthr++;
}

void main(void)
{
    struct timeval ini, fim;
    double tt=0;
    int qtdthr=0, li;

    printf("Informe a quantidade de threads: ");
    scanf("%d",&qtdthr);
    qtdli = TM/qtdthr;

    gettimeofday(&ini, NULL);
    
    for(li = 0; li + qtdli <= TM; li += qtdli)
        _beginthread(fill, NULL, li);

    while(contadorthr<qtdthr);

    gettimeofday(&fim, NULL);

    tt = (double) (fim.tv_usec - ini.tv_usec) / 1000000 + (double) (fim.tv_sec - ini.tv_sec);

    printf ("Tempo de execucao: %f segundos\n", tt);
}