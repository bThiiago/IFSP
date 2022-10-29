#include <stdio.h>
#include <locale.h>

void ler_string(char str[100])
{
    printf("Digite alguma palavra: ");
    gets(str);
}

void trocar_caracter(char str[100])
{
    int i;
    char palavra = 0;
    char troca = 0;

    printf("\nDigite qual caractere quer substituir: ");
    scanf(" %c", &palavra);

    printf("Digite o novo caractere: ");
    scanf(" %c", &troca);

    for (i = 0; i < 100; i++)
    {
        if (str[i] == palavra)
        {
            str[i] = troca;
        }
    }

    printf("\nPalavra alterada: ");
    puts(str);
}

void trocar_conteudo(char str1[50], char str2[50])
{
    char aux[100] = {0};
    int i;

    printf("\nstr1 antes: ");
    puts(str1);

    printf("str2 antes: ");
    puts(str2);

    for (i = 0; i < 100; i++)
    {
        aux[i] = str2[i];
    }

    for (i = 0; i < 100; i++)
    {
        str2[i] = str1[i];
    }

    for (i = 0; i < 100; i++)
    {
        str1[i] = aux[i];
    }

    printf("\nstr1 depois: ");
    puts(str1);

    printf("str2 depois: ");
    puts(str2);
}

void inverter_string(char string[50])
{
    char aux[50];
    int a, b;

    fflush(stdin);
    printf("\nDigite a frase que quer inverter: ");
    gets(string);

    for (a = 0; string[a] != '\0'; a++)
    {
        b = a;
    }

    for (a = 0; string[a] != '\0'; a++)
    {
        aux[b] = string[a];
        b--;
    }
    aux[a] = '\0';

    printf("A frase inversa e: %s\n", aux);
}

void main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    char str[100] = {0};
    char string[50] = {0};
    char string1[50] = "bom dia";
    char string2[50] = "para todos";

    ler_string(str);
    trocar_caracter(str);
    trocar_conteudo(string1, string2);
    inverter_string(string);
}