#include <stdio.h>
#include <string.h>

void menu(char alunos[100][100])
{
    char escolha;

    printf("\n\t\t\t----- MENU DE OPCOES: -----\n");

    printf("\n a) Incluir novos nomes de alunos");
    printf("\n b) Localizar a posicao de um aluno da lista");
    printf("\n c) Apresentar uma relacao com todos os alunos");
    printf("\n d) Buscar alunos pela letra inicial");
    printf("\n e) Buscar alunos que iniciam por uma sequencia de caracteres");
    printf("\n f) Buscar alunos que tenham uma sequencia de caracteres no nome, não importando se for no início, meio ou fim.");
    printf("\n g) Encerrar o programa\n");

    while (escolha != 'g' || escolha != 'G')
    {
        printf("\nEscolha uma opcao: ");
        scanf(" %c", &escolha);
        printf("\n");

        switch (escolha)
        {
        case 'a':
        case 'A':
            ler_nomes(alunos);
            break;

        case 'b':
        case 'B':
            localizar_posicao(alunos);
            break;

        case 'c':
        case 'C':
            apresentar_relacao();
            break;

        case 'd':
        case 'D':
            buscar_inicial();
            break;

        case 'e':
        case 'E':
            buscar_sequencia_inicio();
            break;

        case 'f':
        case 'F':
            buscar_sequencia();
            break;

        case 'g':
        case 'G':
            printf("\n\tAte a proxima...\n\n");
            return 0;
            break;
        }
    }
}

void ler_nomes(char aluno[100][100])
{
    fflush(stdin);
    printf("\nInforme o nome do aluno: ");
    gets(aluno);
}

void localizar_posicao(char aluno[100][100])
{
    puts(aluno);
}

void apresentar_relacao()
{
}

void buscar_inicial()
{
}

void buscar_sequencia_inicio()
{
}

void buscar_sequencia()
{
}

void main()
{
    char alunos[100][100] = {0};

    menu(alunos);
}
