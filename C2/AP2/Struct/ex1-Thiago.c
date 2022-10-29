#include <stdio.h>
#include <string.h>

struct disciplina
{
    char nome[100];
    float nota1;
    float nota2;
    float frequencia;
    float media;
};

struct disciplina ler_disciplina()
{
    struct disciplina disciplinas;

    fflush(stdin);
    printf("Nome: ");
    gets(disciplinas.nome);
    printf("Primeira nota: ");
    scanf("%f", &disciplinas.nota1);
    printf("Segunda nota: ");
    scanf("%f", &disciplinas.nota2);
    printf("Frequencia: ");
    scanf("%f", &disciplinas.frequencia);

    return disciplinas;
}

int boletim(int ndisciplinas, struct disciplina disciplinas[10])
{
    int i;
    float global = 0;

    printf("\tBOLETIM");
    for (i = 0; i < ndisciplinas; i++)
    {
        disciplinas[i].media = (disciplinas[i].nota1 + disciplinas[i].nota2) / 2;
        printf("\n\nDisciplina: %s", disciplinas[i].nome);
        printf("\nNota1: %.2f", disciplinas[i].nota1);
        printf("\nNota2: %.2f", disciplinas[i].nota2);
        printf("\nFrequencia: %.2f", disciplinas[i].frequencia);
        printf("\nMedia: %.2f", disciplinas[i].media);
        if (disciplinas[i].media < 6)
        {
            printf("\nSituacao: retido por nota.");
        }
        if (disciplinas[i].frequencia < 75)
        {
            printf("\nSituacao: retido por frequencia.");
        }
        else if (disciplinas[i].media >= 6 && disciplinas[i].frequencia >= 75)
        {
            printf("\nSituacao: aprovado.");
        }
        global = global + disciplinas[i].media;
    }
    global = global / ndisciplinas;
    printf("\n\nMedia global: %.2f", global);
    printf("\n");
}

int localizar_disciplina(int ndisciplinas, struct disciplina disciplinas[10])
{
    char nome[100];
    int i;

    fflush(stdin);
    printf("Informe o nome da disciplina que quer localizar: ");
    gets(nome);

    for (i = 0; i < ndisciplinas; i++)
    {
        if (strcmp(nome, disciplinas[i].nome) == 0)
        {
            printf("\nDisciplina: %s.", disciplinas[i].nome);
            printf("\nNota1: %.2f", disciplinas[i].nota1);
            printf("\nNota2: %.2f", disciplinas[i].nota2);
            printf("\nFrequencia: %.2f%%", disciplinas[i].frequencia);
        }
    }
    printf("\n");
}

int menor_nota(int ndisciplinas, struct disciplina disciplinas[10])
{
    int i, aux = 0;
    float menor;

    menor = disciplinas[0].media;
    for (i = 0; i < ndisciplinas; i++)
    {
        if (disciplinas[i].media < menor)
        {
            aux = i;
        }
    }
    printf("Disciplina com menor nota: %s.\n", disciplinas[aux].nome);
}

int maior_nota(int ndisciplinas, struct disciplina disciplinas[10])
{
    int i, aux = 0;
    float maior;

    maior = disciplinas[0].media;
    for (i = 0; i < ndisciplinas; i++)
    {
        if (disciplinas[i].media > maior)
        {
            aux = i;
        }
    }
    printf("Disciplina com maior nota: %s.\n", disciplinas[aux].nome);
}

int aprovacoes(int ndisciplinas, struct disciplina disciplinas[10])
{
    int i;
    float media;

    printf("DISCIPLINAS COM APROVACOES:");
    for (i = 0; i < ndisciplinas; i++)
    {
        media = (disciplinas[i].nota1 + disciplinas[i].nota2) / 2;

        if (media >= 6 && disciplinas[i].frequencia >= 75)
        {
            printf("\n%s", disciplinas[i].nome);
        }
        media = 0;
    }
    printf("\n");
}

int main()
{
    int ndisciplinas = 0;
    struct disciplina disciplinas[10];

    char escolha;
    while (escolha != 'g' || escolha != 'G')
    {
        printf("\n a) Cadastrar disciplina");
        printf("\n b) Apresentar o boletim geral");
        printf("\n c) Localizar uma determinada disciplina");
        printf("\n d) Apresentar a disciplina com a menor nota");
        printf("\n e) Apresentar a disciplina com a maior nota");
        printf("\n f) Apresentar as disciplinas com aprovacao");
        printf("\n g) Encerrar o programa\n");

        printf("\nEscolha uma opcao: ");
        scanf(" %c", &escolha);
        printf("\n");

        switch (escolha)
        {
        case 'a':
        case 'A':
            disciplinas[ndisciplinas] = ler_disciplina();
            ndisciplinas++;
            break;

        case 'b':
        case 'B':
            boletim(ndisciplinas, disciplinas);
            break;

        case 'c':
        case 'C':
            localizar_disciplina(ndisciplinas, disciplinas);
            break;

        case 'd':
        case 'D':
            menor_nota(ndisciplinas, disciplinas);
            break;

        case 'e':
        case 'E':
            maior_nota(ndisciplinas, disciplinas);
            break;

        case 'f':
        case 'F':
            aprovacoes(ndisciplinas, disciplinas);
            break;

        case 'g':
        case 'G':
            printf("\n\tAte a proxima...\n\n");
            return 0;
            break;

        default:
            printf("\n\tEsta opcao nao existe.");
            break;
        }
    }
}