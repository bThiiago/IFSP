#include <stdio.h>
#include <locale.h>
#include <string.h>

void main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    char tipo[12] = {0},
         nome[50] = {0},
         numero[15] = {0},
         bairro[30] = {0},
         cidade[30] = {0},
         estado[3] = {0},
         estaux[30] = {0},
         aux[250] = {0},
         dois[2] = ": ",
         virg[2] = ", ",
         trac[3] = " - ";

    printf("Tipo de logradouro: ");
    gets(tipo);

    printf("\nNome logradouro: ");
    gets(nome);

    printf("\nNumero da casa: ");
    gets(numero);

    printf("\nBairro: ");
    gets(bairro);

    printf("\nCidade: ");
    gets(cidade);

    printf("\nEstado: ");
    gets(estado);

    if (strcmp(estado, "SP") == 0)
    {
        strcat(estaux, "Sao Paulo.");
    }

    if (strcmp(estado, "MG") == 0)
    {
        strcat(estaux, "Minas Gerais.");
    }

    if (strcmp(estado, "MS") == 0)
    {
        strcat(estaux, "Mato Grosso do Sul.");
    }

    strncat(aux, tipo, 12);
    strncat(aux, dois, 2);
    strncat(aux, nome, 50);
    strncat(aux, virg, 2);
    strncat(aux, numero, 15);
    strncat(aux, trac, 3);
    strncat(aux, bairro, 30);
    strncat(aux, trac, 3);
    strncat(aux, cidade, 30);
    strncat(aux, virg, 2);
    strncat(aux, estaux, 30);

    printf("\n\t%s\n", aux);
}