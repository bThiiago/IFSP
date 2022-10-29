#include <stdio.h>
#include <locale.h>
#include <string.h>

void tamanho_string()
{
    char palavra[100] = {0};
    int i, qnt = 0;

    printf("\n\t   -----TAMANHO STRING-----\n");

    printf("\n\t");
    strcpy(palavra, "Perdi a sanidade mental");
    printf("Palavra: %s", palavra);

    for (i = 0; i < palavra[i]; i++)
    {
        qnt++;
    }
    printf("\n\tQuantidade de caracteres: %d.\n", qnt);
}

void inicializa_string()
{
    char palavra[100] = {0};
    int i;

    printf("\n\t   -----INICIALIZA STRING-----\n");

    strcpy(palavra, "Perdi a sanidade mental");

    for (i = 0; i < palavra[i]; i++)
    {
        palavra[i] = 0;
    }

    printf("\n\tVetor zerado.\n");
}

void copia_string()
{
    char palavra1[100] = {0};
    char palavra2[100] = {0};

    printf("\n\t   -----COPIA STRING-----");

    strcpy(palavra1, " familia.");
    strcpy(palavra2, "Salve salve");

    printf("\n\n\tPalavra 1 = %s", palavra1);
    printf("\n\tPalavra 2 = %s\n", palavra2);

    strncat(palavra2, palavra1, 15);

    printf("\tPalavra 2+1 = %s\n", palavra2);
}

void concatena_string()
{
    char palavra1[100] = {0};
    char palavra2[100] = {0};

    printf("\n\t   -----CONCATENA STRING-----\n");

    strcpy(palavra1, "Salve salve");
    strcpy(palavra2, " familia.");

    printf("\n\tPalavra 1 = %s", palavra1);
    printf("\n\tPalavra 2 = %s\n", palavra2);

    strncat(palavra1, palavra2, 15);

    printf("\tPalavra 1+2 = %s\n", palavra1);
}

void separa_email()
{
    char email[100] = {0};
    char user[100] = {0}, end[100] = {0};
    int i, ia;

    printf("\n\t   -----SEPARA EMAIL-----");

    printf("\n\n\tInforme seu email: ");
    gets(email);

    while (email[i] != '@')
    {
        user[i] = email[i];
        i++;
    }

    if (email[i] == '@')
    {
        ia = i;
        for (i = ia; i < 100; i++)
        {
            end[i - ia] = email[i];
        }
    }

    printf("\n\tNome de usuario: ");
    for (i = 0; i < 100; i++)
    {
        printf("%c", user[i]);
    }

    printf("\n\tEndereco do servidor: ");
    for (i = 0; i < 100; i++)
    {
        printf("%c", end[i]);
    }
}

void conta_palavras()
{
    char texto[200] = {0};
    int i, pala = 1;

    printf("\n\t   -----CONTA PALAVRAS-----");

    printf("\n\t");
    strcpy(texto, "O sucesso nasce do querer, da determinacao e persistencia em se chegar a um objetivo. Mesmo nao atingindo o alvo, quem busca e vence obstaculos, no minimo fara coisas admiraveis.");
    printf("\n\tTexto: %s", texto);
    printf("\n\t");

    for (i = 0; i < 200; i++)
    {
        if (texto[i] == ' ')
        {
            pala = pala + 1;
        }
    }

    printf("\n\tQuantidade de palavras: %d.\n", pala);
}

void conta_caracter()
{
    char palavra[100] = {0}, caracter[100] = {0};
    int i, cont = 0;

    printf("\n\t   -----CONTA CARACTER-----");

    printf("\n\n\tDigite uma frase de ate 100 caracteres: ");
    gets(palavra);

    printf("\tDigite algum caractere para ver suas ocorrencias na frase acima: ");
    gets(caracter);

    for (i = 0; i < 100; i++)
    {
        if (palavra[i] == caracter[0])
        {
            cont++;
        }
    }

    if (cont == 0)
    {
        printf("\n\tNao existem ocorrencias para o caractere %s.\n", caracter);
    }
    else
    {
        printf("\n\tExistem %d ocorrencias para o caractere %s.\n", cont, caracter);
    }
}

void pega_ultima_palavra()
{
    char palavra1[100] = {0};
    char palavra2[100] = {0};

    printf("\n\t   -----PEGA ULTIMA PALAVRA-----\n");

    strcpy(palavra1, "Malakoi do hebraico");
    strcpy(palavra2, "Malakoi ");

    printf("\n\tPalavra 1: %s", palavra1);
    printf("\n\tPalavra 2: %s", palavra2);

    strncat(palavra2, strrchr(palavra1, ' ') + 1, 20);

    printf("\n\tResultado: %s.\n", palavra2);
}

void pega_primeira_palavra()
{
    char palavra1[100] = {0};
    char palavra2[100] = {0};

    printf("\n\t   -----PEGA PRIMEIRA PALAVRA-----\n");

    strcpy(palavra1, "Malakoi do hebraico");
    strcpy(palavra2, "Malakoi ");

    printf("\n\tPalavra 1: %s", palavra1);
    printf("\n\tPalavra 2: %s", palavra2);

    strncat(palavra2, strrchr(palavra1, palavra1[0]), 7);

    printf("\n\tResultado: %s.\n", palavra2);
}

void retorna_iniciais()
{
    char nome[100] = {0};
    char ini[1] = {0}, rest[50] = {0};
    int i;

    printf("\n\t   -----RETORNA INICIAIS-----\n");

    printf("\n\tDigite seu nome completo: ");
    fgets(nome, 99, stdin);

    for (i = 0; nome[i + 1] != '\0'; i++)
    {
        if (i == 0)
        {
            ini[0] = nome[0];
            printf("\t%c", ini[i]);
        }
        if (nome[i] == ' ')
        {
            rest[i] = nome[i + 1];
            printf(" %c", rest[i]);
        }
    }
}

void localiza_caracter()
{
    char str1[50] = {0};
    char str2[10] = {0};
    char *ocor;

    printf("\n\n\t   -----LOCALIZA CARACTER-----\n");

    strcpy(str1, "Bom dia para todos, menos para alguns.");

    printf("\n\tPalavra: %s", str1);
    printf("\n\tDigite um caractere: ");
    gets(str2);

    ocor = strpbrk(str1, str2);
    if (ocor)
    {
        printf("\n\tPrimeira ocorrencia: %c\n", *ocor);
    }
    else
    {
        printf("\n\tNao houve nenhuma ocorrencia\n");
    }
}

void excluir_posicao()
{
    char str[100] = {0};
    int i = 0, posi = 0;

    printf("\n\t   -----EXCLUIR POSICAO-----\n");

    fflush(stdin);
    printf("\n\tDigite uma frase: ");
    gets(str);

    printf("\n\tPalavra: %s", str);
    printf("\n\tDigite um numero inteiro: ");
    scanf("%d", &posi);

    for (i = 0; i < str[i] != '\0'; i++)
    {
        if (posi == i)
        {
            for (i = posi; i < str[i] != '\0'; i++)
            {
                str[i] = str[i + 1];
            }
        }
    }

    printf("\n\t");
    puts(str);
}

void main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    tamanho_string();
    inicializa_string();
    copia_string();
    concatena_string();
    separa_email();
    conta_palavras();
    conta_caracter();
    pega_ultima_palavra();
    pega_primeira_palavra();
    retorna_iniciais();
    localiza_caracter();
    excluir_posicao();
}