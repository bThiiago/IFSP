#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
setlocale (LC_ALL, "Portuguese_Brazil");

int vetor[100], n = 0, i, pront[100], p = 0, benef = 0;

    printf("\n     LEMBRE-SE, para prontuários de final X utilize 0.");

    do{
        printf("\n\nInforme quantos alunos querem o auxílio: ");
        scanf("%d", &n);
    }while(n == 0);

    do{
        printf("Informe quantos alunos serão beneficiados: ");
        scanf("%d", &benef);
    }while(benef == 0);

    printf("\n");

    for(i = 0; i < n; i++){
        printf("Prontuário do aluno: ");
        scanf("%d", &pront[i]);
        printf("Posição do aluno: %d.\n\n", i);
    }

    printf("\n   Classificação dos alunos que serão beneficiados: \n");
    for(i = 0; i < benef; i++){
        printf("Aluno %d: PE-%d.\n",i , pront[i]);
    }

    printf("\n   Classificação completa:\n");
    for(i = 0; i < n; i++){
        printf("Aluno %d: PE-%d.\n",i , pront[i]);
    }

}
