#include <stdio.h>
#include <string.h>

struct tecnicos
{
    int prontuario;
    char nome[100];
    int ramal;
};

struct equipamentos
{
    int numero;
    char descricao[200];
    int num_laboratorio;
    int num_maquina;
    char situacao[1];
};

struct manutencoes
{
    int dia;
    int mes;
    int equip;
    int tecnico;
    char problema[100];
    char solucao[100];
    char situacao[1];
};

struct tecnicos incluir_tecnicos(ntec)
{
    struct tecnicos tecnico;

    printf("\nProntuario: %d\n", ntec + 1);
    fflush(stdin);
    printf("Nome: ");
    gets(tecnico.nome);
    printf("Ramal: ");
    scanf("%d", &tecnico.ramal);

    return tecnico;
}

struct equipamentos incluir_equipamentos()
{
    struct equipamentos equipamento;

    printf("\nNumero: ");
    scanf("%d", &equipamento.numero);
    fflush(stdin);
    printf("Descricao: ");
    gets(equipamento.descricao);
    printf("Numero do laboratorio: ");
    scanf("%d", &equipamento.num_laboratorio);
    printf("Numero da maquina: ");
    scanf("%d", &equipamento.num_maquina);
    strcpy(equipamento.situacao, "F");

    return equipamento;
}

struct manutencoes novo_chamado(struct tecnicos tecnico[], int ntecnico, struct equipamentos equipamento[], int nequip)
{
    struct manutencoes manutencao;
    int i;

    printf("\nDia: ");
    scanf("%d", &manutencao.dia);
    printf("Mes: ");
    scanf("%d", &manutencao.mes);
    printf("Codigo equipamento: ");
    scanf("%d", &manutencao.equip);
    printf("\nTECNICOS: \n");
    for (i = 0; i < ntecnico; i++)
    {
        printf("\nNome: %s.", tecnico[i].nome);
        printf("\nProntuario: %d.\n", tecnico[i].prontuario);
    }
    printf("\nProntuario: ");
    scanf("%d", &manutencao.tecnico);
    fflush(stdin);
    printf("Problema: ");
    gets(manutencao.problema);
    fflush(stdin);
    printf("Solucao: ");
    gets(manutencao.solucao);
    strcpy(manutencao.situacao, "P");
    for (i = 0; i < nequip; i++)
    {
        if (manutencao.equip == equipamento[i].numero)
        {
            strcpy(equipamento[i].situacao, "M");
        }
    }

    return manutencao;
}

void equipamento_situacao(struct equipamentos equipamento[], int nequip)
{
    int i;

    printf("\n--LISTA--\n");

    for (i = 0; i < nequip; i++)
    {
        printf("\nEquipamento: %s", equipamento[i].descricao);
        if (strcmp("F", equipamento[i].situacao) == 0)
        {
            printf("\nSituacao: Funcionando.\n");
        }
        else if (strcmp("M", equipamento[i].situacao) == 0)
        {
            printf("\nSituacao: Manutencao.\n");
        }
    }
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
    int ntecnicos = 3;
    struct tecnicos tecnico[100];

    int nequipamentos = 7;
    struct equipamentos equipamento[100];

    int nmanutencoes = 9;
    struct manutencoes manutencao[100];

    tecnico[0].prontuario = 1;
    strcpy(tecnico[0].nome, "Antonio Marcos de Oliveira");
    tecnico[0].ramal = 9589;

    tecnico[1].prontuario = 2;
    strcpy(tecnico[1].nome, "Maria Eduarda de Freitas");
    tecnico[1].ramal = 9590;

    tecnico[2].prontuario = 3;
    strcpy(tecnico[2].nome, "Olavo Siqueira");
    tecnico[2].ramal = 9593;

    equipamento[0].numero = 1;
    strcpy(equipamento[0].descricao, "Microcomputador I5, 8GB, HD 1TB");
    equipamento[0].num_laboratorio = 6;
    equipamento[0].num_maquina = 1;
    strcpy(equipamento[0].situacao, "M");

    equipamento[1].numero = 2;
    strcpy(equipamento[1].descricao, "Microcomputador I5, 8GB, HD 1TB");
    equipamento[1].num_laboratorio = 6;
    equipamento[1].num_maquina = 12;
    strcpy(equipamento[1].situacao, "M");

    equipamento[2].numero = 3;
    strcpy(equipamento[2].descricao, "Microcomputador I5, 8GB, HD 500GB");
    equipamento[2].num_laboratorio = 19;
    equipamento[2].num_maquina = 6;
    strcpy(equipamento[2].situacao, "M");

    equipamento[3].numero = 4;
    strcpy(equipamento[3].descricao, "Microcomputador I7, 16GB, HD 1TB");
    equipamento[3].num_laboratorio = 20;
    equipamento[3].num_maquina = 10;
    strcpy(equipamento[3].situacao, "F");

    equipamento[4].numero = 5;
    strcpy(equipamento[4].descricao, "Microcomputador I7, 16GB, HD 1TB");
    equipamento[4].num_laboratorio = 20;
    equipamento[4].num_maquina = 12;
    strcpy(equipamento[4].situacao, "F");

    equipamento[5].numero = 6;
    strcpy(equipamento[5].descricao, "Microcomputador I7, 16GB, HD 1TB");
    equipamento[5].num_laboratorio = 20;
    equipamento[5].num_maquina = 18;
    strcpy(equipamento[5].situacao, "F");

    equipamento[6].numero = 10;
    strcpy(equipamento[6].descricao, "Microcomputador I5, 8GB, HD 500GTB");
    equipamento[6].num_laboratorio = 19;
    equipamento[6].num_maquina = 15;
    strcpy(equipamento[6].situacao, "F");

    manutencao[0].dia = 3;
    manutencao[0].mes = 4;
    manutencao[0].equip = 3;
    manutencao[0].tecnico = 1;
    strcpy(manutencao[0].problema, "Computador nao liga");
    strcpy(manutencao[0].solucao, "Trocar fonte");
    strcpy(manutencao[0].situacao, "F");

    manutencao[1].dia = 10;
    manutencao[1].mes = 4;
    manutencao[1].equip = 10;
    manutencao[1].tecnico = 2;
    strcpy(manutencao[1].problema, "Nao carrega o windows");
    strcpy(manutencao[1].solucao, "Reinstalar os SOs");
    strcpy(manutencao[1].situacao, "F");

    manutencao[2].dia = 10;
    manutencao[2].mes = 5;
    manutencao[2].equip = 2;
    manutencao[2].tecnico = 3;
    strcpy(manutencao[2].problema, "Computador nao liga");
    strcpy(manutencao[2].solucao, "Placa mae queimada");
    strcpy(manutencao[2].situacao, "P");

    manutencao[3].dia = 20;
    manutencao[3].mes = 5;
    manutencao[3].equip = 3;
    manutencao[3].tecnico = 2;
    strcpy(manutencao[3].problema, "Monitor nao liga");
    strcpy(manutencao[3].solucao, "Placa de video com problemas");
    strcpy(manutencao[3].situacao, "P");

    manutencao[4].dia = 12;
    manutencao[4].mes = 6;
    manutencao[4].equip = 1;
    manutencao[4].tecnico = 3;
    strcpy(manutencao[4].problema, "Trava durante o boot");
    strcpy(manutencao[4].solucao, "Reinstalar o windows");
    strcpy(manutencao[4].situacao, "F");

    manutencao[5].dia = 13;
    manutencao[5].mes = 6;
    manutencao[5].equip = 6;
    manutencao[5].tecnico = 1;
    strcpy(manutencao[5].problema, "Nao acessa a rede");
    strcpy(manutencao[5].solucao, "Reconfigurar a rede");
    strcpy(manutencao[5].situacao, "F");

    manutencao[6].dia = 30;
    manutencao[6].mes = 6;
    manutencao[6].equip = 10;
    manutencao[6].tecnico = 2;
    strcpy(manutencao[6].problema, "Nao acessa a rede");
    strcpy(manutencao[6].solucao, "Trocar placa de rede");
    strcpy(manutencao[6].situacao, "F");

    manutencao[7].dia = 7;
    manutencao[7].mes = 8;
    manutencao[7].equip = 1;
    manutencao[7].tecnico = 2;
    strcpy(manutencao[7].problema, "Computador nao liga");
    strcpy(manutencao[7].solucao, "Trocar fonte");
    strcpy(manutencao[7].situacao, "P");

    manutencao[8].dia = 10;
    manutencao[8].mes = 8;
    manutencao[8].equip = 10;
    manutencao[8].tecnico = 3;
    strcpy(manutencao[8].problema, "Nao carrega o grub");
    strcpy(manutencao[8].solucao, "Reinstalar o grub");
    strcpy(manutencao[8].situacao, "F");

    char escolha;
    while (escolha != 'l' || escolha != 'L')
    {
        printf("\n a) Incluir novos tecnicos");
        printf("\n b) Incluir novos equipamentos");
        printf("\n c) Apresentar a lista de equipamentos com sua situacao");
        printf("\n d) Abrir um novo chamado de atendimento");
        printf("\n e) Apresentar todos atendimentos realizado por um determinado tecnico");
        printf("\n f) Apresentar a quantidade de atendimentos para um determinado laboratorio");
        printf("\n g) Apresentar todos os dados dos equipamentos que estao em manutencao");
        printf("\n h) Realizar o fechamento de um atendimento");
        printf("\n i) Apresentar um historico de atendimento para um determinado equipamento");
        printf("\n j) Apresentar as manutencoes realizadas em um determinado mes");
        printf("\n k) Apresentar o total de manutencoes para cada um dos equipamentos");
        printf("\n l) Encerrar o programa\n");

        printf("\nEscolha uma opcao: ");
        scanf(" %c", &escolha);

        switch (escolha)
        {
        case 'a':
        case 'A':
            tecnico[ntecnicos] = incluir_tecnicos(ntecnicos);
            ntecnicos = ntecnicos + 1;
            break;

        case 'b':
        case 'B':
            equipamento[nequipamentos] = incluir_equipamentos();
            nequipamentos = nequipamentos + 1;
            break;

        case 'c':
        case 'C':
            equipamento_situacao(equipamento, nequipamentos);
            break;

        case 'd':
        case 'D':
            manutencao[nmanutencoes] = novo_chamado(tecnico, ntecnicos, equipamento, nequipamentos);
            nmanutencoes = nmanutencoes + 1;
            break;

        case 'e':
        case 'E':
            atendimentos_tecnico(tecnico, equipamento, manutencao, nmanutencoes, nequipamentos);
            break;

        case 'f':
        case 'F':
            atendimentos_laboratorio(equipamento, nequipamentos);
            break;

        case 'g':
        case 'G':
            dados_manutencao(equipamento, manutencao, nequipamentos, nmanutencoes);
            break;

        case 'h':
        case 'H':
            fechar_atendimento(equipamento, manutencao, nequipamentos, nmanutencoes);
            break;

        case 'i':
        case 'I':
            determinado_historico(equipamento, manutencao, nequipamentos, nmanutencoes);
            break;

        case 'j':
        case 'J':
            determinado_mes(manutencao, nmanutencoes);
            break;

        case 'k':
        case 'K':
            total_manutencoes(equipamento, manutencao, nequipamentos, nmanutencoes);
            break;

        case 'l':
        case 'L':
            printf("\n\n\tAte a proxima...\n\n");
            return 0;
            break;

        default:
            printf("\n\tEsta opcao nao existe.");
            break;
        }
    }
}