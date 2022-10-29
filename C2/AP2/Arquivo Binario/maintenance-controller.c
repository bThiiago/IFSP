#include "include-controller.c"

struct Manutencoes novo_chamado()
{
    struct Tecnicos t;
    struct Equipamentos e;
    struct Manutencoes m;

    FILE *arquivo1;
    FILE *arquivo2;
    FILE *arquivo3;

    arquivo = fopen("tecnicos.dat", "rb");
    arquivo2 = fopen("equipamentos.dat", "rb");
    arquivo3 = fopen("manutencoes.dat", "rb");

    printf("\nDia: ");
    scanf("%d", &m.dia);
    printf("Mes: ");
    scanf("%d", &m.mes);

    fread(&m, sizeof(struct Manutencoes), 1, arquivo1);

    if (arquivo2 == NULL)
    {
        printf("Não foi possível abrir o equipamentos.dat ou não existem equipamentos");
    }
    else
    {
        printf("EQUIPAMENTOS: ");
        imprimir_equip('e');

        printf("Numero equipamento: ");
        scanf("%d", &m.equip);

        fread(&e, sizeof(struct Equipamentos), 1, arquivo2);

        while (!feof(arquivo2))
        {
            if (m.equip == e.numero)
            {
                if (arquivo2 == NULL)
                {
                    printf("Não foi possível abrir o tecnicos.dat ou não existem tecnicos");
                }
                else
                {
                    printf("\nTECNICOS: \n");
                    imprimir_tecnico(t);

                    printf("\nProntuario: ");
                    scanf("%d", &m.tecnico);

                    fread(&t, sizeof(struct Tecnicos), 1, arquivo3);

                    while (!feof(arquivo3))
                    {
                        if (m.tecnico == t.prontuario)
                        {
                            fflush(stdin);
                            printf("Problema: ");
                            gets(m.problema);
                            fflush(stdin);
                            printf("Solucao: ");
                            gets(m.solucao);
                            strcpy(m.situacao, "P");
                        }
                        else
                        {
                            printf("Tecnico não encontrado.");
                        }
                    }
                }
                else
                {
                    printf("Equipamento não encontrado.");
                }
            }
        }
    }
    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);
}

void atendimentos_tecnico(struct tecnicos tecnico[], struct equipamentos equipamento[], struct manutencoes manutencao[], int nmanu, int nequip)
{
    int i, j, pront = 0;

    printf("\nProntuario do tecnico: ");
    scanf("%d", &pront);

    printf("Tecnico: %s.\n", tecnico[pront - 1].nome);
    for (i = 0; i < nmanu; i++)
    {
        if (manutencao[i].tecnico == pront)
        {
            printf("\nData da ocorrencia: %d/%d.", manutencao[i].dia, manutencao[i].mes);
            for (j = 0; j < nequip; j++)
            {
                if (equipamento[j].numero == manutencao[i].equip)
                {
                    printf("\nDescricao: %s.", equipamento[j].descricao);
                    printf("\nLaboratorio: %d.", equipamento[j].num_laboratorio);
                    printf("\nNumero da maquina: %d.", equipamento[j].num_maquina);
                }
            }
            printf("\nProblema: %s.", manutencao[i].problema);
            printf("\nSolucao: %s.\n", manutencao[i].solucao);
        }
    }
}

void atendimentos_laboratorio(struct equipamentos equipamento[], int nequip)
{
    int i, lab = 0, aux = 0;

    printf("\nNumero do laboratorio: ");
    scanf("%d", &lab);

    for (i = 0; i < nequip; i++)
    {
        if (equipamento[i].num_laboratorio == lab)
        {
            aux++;
        }
    }
    printf("O laboratorio %d tem um total de %d atendimentos.\n", lab, aux);
}

void dados_manutencao(struct equipamentos equipamento[], struct manutencoes manutencao[], int nequip, int nmanu)
{
    int i, j;

    printf("\n--EQUIPAMENTOS EM MANUTENCAO--\n");

    for (i = 0; i < nequip; i++)
    {
        if (strcmp("M", equipamento[i].situacao) == 0)
        {
            printf("\nNumero: %d", equipamento[i].numero);
            printf("\nDescricao: %s", equipamento[i].descricao);
            printf("\nNumero do laboratorio: %d", equipamento[i].num_laboratorio);
            printf("\nNumero da maquina: %d", equipamento[i].num_maquina);
            for (j = 0; j < nmanu; j++)
            {
                if (manutencao[j].equip == equipamento[i].numero)
                {
                    if (strcmp("P", manutencao[j].situacao) == 0)
                    {
                        printf("\nProblema: %s.", manutencao[j].problema);
                        printf("\nSolucao: %s.\n", manutencao[j].solucao);
                    }
                }
            }
        }
    }
}

void fechar_atendimento(struct equipamentos equipamento[], struct manutencoes manutencao[], int nequip, int nmanu)
{
    int i, j;
    int esc = 0;
    char escolha[2];

    printf("\n--FINALIZANDO ATENDIMENTO--\n");

    printf("\nNumero do equipamento: ");
    scanf("%d", &esc);

    for (i = 0; i < nequip; i++)
    {
        if (equipamento[i].numero == esc)
        {
            for (j = 0; j < nmanu; j++)
            {
                if (manutencao[j].equip == esc)
                {
                    if (strcmp("P", manutencao[j].situacao) == 0)
                    {
                        printf("\nProblema: %s.", manutencao[j].problema);
                        printf("\nSolucao: %s.\n", manutencao[j].solucao);

                        fflush(stdin);
                        printf("\nDeseja finalizar a manutencao? (S ou N): ");
                        gets(escolha);

                        if (strcmp("S", escolha) == 0)
                        {
                            strcpy(equipamento[i].situacao, "F");
                            strcpy(manutencao[i].situacao, "F");
                        }
                    }
                }
            }
        }
    }
}

void determinado_historico(struct equipamentos equipamento[], struct manutencoes manutencao[], int nequip, int nmanu)
{
    int i;
    int esc = 0;

    printf("\n--Historico de atendimento--\n");

    printf("\nNumero do equipamento: ");
    scanf("%d", &esc);

    for (i = 0; i < nequip; i++)
    {
        if (equipamento[i].numero == esc)
        {
            printf("\nEquipamento: %s\n", equipamento[i].descricao);
        }
    }
    for (i = 0; i < nmanu; i++)
    {
        if (manutencao[i].equip == esc)
        {
            printf("\nProblema: %s.", manutencao[i].problema);
            printf("\nSolucao: %s.", manutencao[i].solucao);
            if (strcmp("F", manutencao[i].situacao) == 0)
            {
                printf("\nSituacao: Finalizado.\n");
            }
            if (strcmp("P", manutencao[i].situacao) == 0)
            {
                printf("\nSituacao: Pendente.\n");
            }
        }
    }
}

void determinado_mes(struct manutencoes manutencao[], int nmanu)
{
    int i;
    int mes = 0;

    printf("\nInforme o numero do mes: ");
    scanf("%d", &mes);

    for (i = 0; i < nmanu; i++)
    {
        if (manutencao[i].mes == mes)
        {
            printf("\nDia: %d", manutencao[i].dia);
            printf("\nEquipamento: %d", manutencao[i].equip);
            printf("\nTecnico: %d", manutencao[i].tecnico);
            printf("\nProblema: %s", manutencao[i].problema);
            printf("\nSolucao: %s", manutencao[i].solucao);
            if (strcmp("F", manutencao[i].situacao) == 0)
            {
                printf("\nSituacao: Finalizado.\n");
            }
            if (strcmp("P", manutencao[i].situacao) == 0)
            {
                printf("\nSituacao: Pendente.\n");
            }
        }
    }
}

void total_manutencoes(struct equipamentos equipamento[], struct manutencoes manutencao[], int nequip, int nmanu)
{
    int i, j;
    int manu = 0;

    for (i = 0; i < nequip; i++)
    {
        printf("\nEquipamento: %s", equipamento[i].descricao);
        for (j = 0; j < nmanu; j++)
        {
            if (manutencao[j].equip == equipamento[i].numero)
            {
                manu++;
            }
        }
        printf("\nManutencoes: %d", manu);
        printf("\nNumero: %d\n", equipamento[i].numero);
        manu = 0;
    }
}

int main()
{
    char escolha;

    while (escolha != 'i' || escolha != 'I')
    {
        printf("\n a) Abrir um novo chamado de atendimento");
        printf("\n b) Apresentar todos atendimentos realizado por um determinado tecnico");
        printf("\n c) Apresentar a quantidade de atendimentos para um determinado laboratorio");
        printf("\n d) Apresentar todos os dados dos equipamentos que estao em manutencao");
        printf("\n e) Realizar o fechamento de um atendimento");
        printf("\n f) Apresentar um historico de atendimento para um determinado equipamento");
        printf("\n g) Apresentar as manutencoes realizadas em um determinado mes");
        printf("\n h) Apresentar o total de manutencoes para cada um dos equipamentos");
        printf("\n i) Encerrar o programa\n");

        printf("\nEscolha uma opcao: ");
        scanf(" %c", &escolha);

        switch (escolha)
        {
        case 'a':
        case 'A':
            novo_chamado();
            break;

        case 'b':
        case 'B':
            break;

        case 'c':
        case 'C':
            break;

        case 'd':
        case 'D':
            break;

        case 'e':
        case 'E':
            break;

        case 'f':
        case 'F':
            break;

        case 'g':
        case 'G':
            break;

        case 'h':
        case 'H':
            break;

        case 'i':
        case 'I':
            printf("\n\n\tAte a proxima...\n\n");
            return 0;
            break;

        default:
            printf("\n\tEsta opcao nao existe.");
            break;
        }
    }
}