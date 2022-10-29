#include "include-controller.c"

struct Tecnicos ler_dados_tecnico()
{
    struct Tecnicos t;

    printf("Prontuario..: ");
    scanf("%d", &t.prontuario);

    fflush(stdin);
    printf("Nome........: ");
    gets(t.nome);

    printf("Ramal.......: ");
    scanf("%d", &t.ramal);

    return t;
}

void incluir_tecnico()
{
    struct Tecnicos t;

    printf("\n=========================\n");
    printf("   Inclusao de Tecnico\n");
    printf("=========================\n\n");

    t = ler_dados_tecnico();

    gravar_novo_tecnico(t);
}

struct Equipamentos ler_dados_equip()
{
    struct Equipamentos e;

    printf("Numero.......: ");
    scanf("%d", &e.numero);

    fflush(stdin);
    printf("Descricao....: ");
    gets(e.descricao);

    printf("Laboratorio..: ");
    scanf("%d", &e.num_laboratorio);

    printf("Maquina......: ");
    scanf("%d", &e.num_maquina);

    fflush(stdin);
    printf("Situacao.....: ");
    gets(e.situacao);

    return e;
}

void incluir_equip()
{
    struct Equipamentos e;

    printf("\n=========================\n");
    printf(" Inclusao de Equipamento\n");
    printf("=========================\n\n");

    e = ler_dados_equip();

    gravar_novo_equipamento(e);
}

struct Manutencoes ler_dados_manu()
{
    struct Manutencoes m;

    printf("Dia.......: ");
    scanf("%d", &m.dia);

    printf("Mes.......: ");
    scanf("%d", &m.mes);

    printf("Equip.....: ");
    scanf("%d", &m.equip);

    printf("Tecnico...: ");
    scanf("%d", &m.tecnico);

    fflush(stdin);
    printf("Problema..: ");
    gets(m.problema);

    fflush(stdin);
    printf("Solucao...: ");
    gets(m.solucao);

    fflush(stdin);
    printf("Situacao..: ");
    gets(m.situacao);

    return m;
}

void incluir_manu()
{
    struct Manutencoes m;

    printf("\n=========================\n");
    printf(" Inclusao de Manutencoes\n");
    printf("=========================\n\n");

    m = ler_dados_manu();

    gravar_nova_manutencao(m);
}

void apresentar_dados_tecnico(struct Tecnicos t)
{
    if (t.status == 'E')
    {
        printf("\nTecnico deletado.\n");
    }
    else if (t.status == 'A')
    {
        printf("\nProntuario..: %d\n", t.prontuario);
        printf("Nome........: %s\n", t.nome);
        printf("Ramal.......: %d\n", t.ramal);
    }
}

void buscar_tecnico()
{
    int prontuario, posicao;
    struct Tecnicos t;

    printf("\nProntuario do tecnico: ");
    scanf("%d", &prontuario);

    posicao = localizar_tecnico(prontuario);

    if (posicao == -1)
    {
        printf("\nNao existe um tecnico com esse prontuario.\n");
    }
    else if (t.status == 'E')
    {
        printf("\nTecnico esta deletado.\n");
    }
    else
    {
        t = ler_tecnicos(posicao);
        apresentar_dados_tecnico(t);
    }
}

void apresentar_dados_equip(struct Equipamentos e)
{
    if (e.status == 'E')
    {
        printf("\nEquipamento deletado.\n");
    }
    else if (e.status == 'A')
    {
        printf("\nNumero.......: %d\n", e.numero);
        printf("Descricao....: %s\n", e.descricao);
        printf("Laboratorio..: %d\n", e.num_laboratorio);
        printf("Maquina......: %d\n", e.num_maquina);
        printf("Situacao.....: %s\n", e.situacao);
    }
}

void buscar_equip()
{
    int numero, posicao;
    struct Equipamentos e;

    printf("\nNumero do equipamento: ");
    scanf("%d", &numero);

    posicao = localizar_equip(numero);

    if (posicao == -1)
    {
        printf("\nNao existe um equipamento com esse numero.\n");
    }
    else if (e.status == 'E')
    {
        printf("\nEquipamento esta deletado.\n");
    }
    else
    {
        e = ler_equip(posicao);
        apresentar_dados_equip(e);
    }
}

void apresentar_dados_manu(struct Manutencoes m)
{
    if (m.status == 'E')
    {
        printf("\nManutencao deletada.\n");
    }
    else if (m.status == 'A')
    {
        printf("\nDia..........: %d\n", m.dia);
        printf("Mes..........: %d\n", m.mes);
        printf("Equipamento..: %d\n", m.equip);
        printf("Tecnico......: %d\n", m.tecnico);
        printf("Problema.....: %s\n", m.problema);
        printf("Solucao......: %s\n", m.solucao);
        printf("Situacao.....: %s\n", m.situacao);
    }
}

void buscar_manu()
{
    int dia, mes, equipamento, posicao;
    struct Manutencoes m;

    printf("\nDia da manutencao..: ");
    scanf("%d", &dia);

    printf("Mes da manutencao....: ");
    scanf("%d", &mes);

    printf("Num. Equipamento.....: ");
    scanf("%d", &equipamento);

    posicao = localizar_manu(dia, mes, equipamento);

    if (posicao == -1)
    {
        printf("\nNao existe esta manutencao.\n");
    }
    else if (m.status == 'E')
    {
        printf("\nEquipamento esta deletado.\n");
    }
    else
    {
        m = ler_manu(posicao);
        apresentar_dados_manu(m);
    }
}

void alterar_tecnico()
{
    int prontuario, posicao;
    struct Tecnicos t, novo;

    printf("\nProntuario a alterar...: ");
    scanf("%d", &prontuario);

    posicao = localizar_tecnico(prontuario);

    if (posicao == -1)
    {
        printf("Nao existe um tecnico com esse prontuario.");
    }
    else
    {
        t = ler_tecnicos(posicao);
        apresentar_dados_tecnico(t);

        novo = ler_dados_tecnico();
        alterar_tecnic(novo, posicao);
    }
}

void alterar_equip()
{
    int numero, posicao;
    struct Equipamentos e, novo;

    printf("\nNumero a alterar...: ");
    scanf("%d", &numero);

    posicao = localizar_equip(numero);

    if (posicao == -1)
    {
        printf("Nao existe um equipamento com esse numero.");
    }
    else
    {
        e = ler_equip(posicao);
        apresentar_dados_equip(e);

        novo = ler_dados_equip();
        alterar_equi(novo, posicao);
    }
}

void alterar_manu()
{
    int dia, mes, equipamento, posicao;
    struct Manutencoes m, novo;

    printf("\nDia da manutencao..: ");
    scanf("%d", &dia);

    printf("Mes da manutencao....: ");
    scanf("%d", &mes);

    printf("Num. Equipamento.....: ");
    scanf("%d", &equipamento);

    posicao = localizar_manu(dia, mes, equipamento);

    if (posicao == -1)
    {
        printf("Nao existe esta manutencao.");
    }
    else
    {
        m = ler_manu(posicao);
        apresentar_dados_manu(m);

        novo = ler_dados_manu();
        alterar_man(novo, posicao);
    }
}

void imprimir_tecnico(struct Tecnicos t)
{
    printf("%d\t%-20s\t%d\n", t.prontuario, t.nome, t.ramal);
}

void imprimir_equip(struct Equipamentos e)
{
    printf("%d\t%-40s\t%d\t%d\t%-2s\n", e.numero, e.descricao, e.num_laboratorio, e.num_maquina, e.situacao);
}

void imprimir_manu(struct Manutencoes m)
{
    printf("%d\t%d\t%d\t%d\t%-20s\t%-20s\t%-2s\n", m.dia, m.mes, m.equip, m.tecnico, m.problema, m.solucao, m.situacao);
}

void excluir_tecnico()
{
    int prontuario, posicao;
    struct Tecnicos t;
    char confirma;

    printf("Prontuario a excluir...: ");
    scanf("%d", &prontuario);

    posicao = localizar_tecnico(prontuario);

    if (posicao == -1)
    {
        printf("Nao existe um tecnico com esse prontuario.");
    }
    else if (posicao == -2)
    {
        printf("Esse tecnico esta excluido.");
    }
    else
    {
        t = ler_tecnicos(posicao);
        apresentar_dados_tecnico(t);

        printf("Deseja excluir esse tecnico? ");
        scanf(" %c", &confirma);

        if (confirma == 's' || confirma == 'S')
        {
            excluir_tecnic(posicao);
            printf("\nTecnico excluido!\n");
        }
    }
}

void excluir_equip()
{
    int numero, posicao;
    struct Equipamentos e;
    char confirma;

    printf("Num. Equipamento...: ");
    scanf("%d", &numero);

    posicao = localizar_equip(numero);

    if (posicao == -1)
    {
        printf("Nao existe um equipamento com esse numero.");
    }
    else if (posicao == -2)
    {
        printf("Esse numero esta excluido.");
    }
    else
    {
        e = ler_equip(posicao);
        apresentar_dados_equip(e);

        printf("Deseja excluir esse equipamento? ");
        scanf(" %c", &confirma);

        if (confirma == 's' || confirma == 'S')
        {
            excluir_equi(posicao);
            printf("\nEquipamento excluido!\n");
        }
    }
}

void excluir_manu()
{
    int dia, mes, equipamento, posicao;
    struct Manutencoes m;
    char confirma;

    printf("\nDia da manutencao..: ");
    scanf("%d", &dia);

    printf("Mes da manutencao....: ");
    scanf("%d", &mes);

    printf("Num. Equipamento.....: ");
    scanf("%d", &equipamento);

    posicao = localizar_manu(dia, mes, equipamento);

    if (posicao == -1)
    {
        printf("Nao existe esta manutencao.");
    }
    else if (posicao == -2)
    {
        printf("Essa manutencao esta excluida.");
    }
    else
    {
        m = ler_manu(posicao);
        apresentar_dados_manu(m);

        printf("Deseja excluir essa manutencao? ");
        scanf(" %c", &confirma);

        if (confirma == 's' || confirma == 'S')
        {
            excluir_man(posicao);
            printf("\nManutencao excluida!\n");
        }
    }
}

void main()
{
    int opc;

    do
    {
        printf("\n Menu principal\n\n");

        printf("  - Incluir -  \n");
        printf("\t1 - Tecnico\n");
        printf("\t2 - Equipamento\n");
        printf("\t3 - Manutencao\n");
        printf("  - Localizar -  \n");
        printf("\t4 - Tecnico\n");
        printf("\t5 - Equipamento\n");
        printf("\t6 - Manutencao\n");
        printf("  - Alterar -  \n");
        printf("\t7 - Tecnico\n");
        printf("\t8 - Equipamento\n");
        printf("\t9 - Manutencao\n");
        printf("  - Listar -  \n");
        printf("\t10 - Tecnico\n");
        printf("\t11 - Equipamento\n");
        printf("\t12 - Manutencao\n");
        printf("  - Excluir -  \n");
        printf("\t13 - Tecnico\n");
        printf("\t14 - Equipamento\n");
        printf("\t15 - Manutencao\n");
        printf("\n 0 - Sair\n");

        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opc);
        printf("\n");

        switch (opc)
        {
        case 1:
            incluir_tecnico();
            break;

        case 2:
            incluir_equip();
            break;

        case 3:
            incluir_manu();
            break;

        case 4:
            buscar_tecnico();
            break;

        case 5:
            buscar_equip();
            break;

        case 6:
            buscar_manu();
            break;

        case 7:
            alterar_tecnico();
            break;

        case 8:
            alterar_equip();
            break;

        case 9:
            alterar_manu();
            break;

        case 10:
            listar_tecnicos();
            break;

        case 11:
            listar_equip();
            break;

        case 12:
            listar_manu();
            break;

        case 13:
            excluir_tecnico();
            break;

        case 14:
            excluir_equip();
            break;

        case 15:
            excluir_manu();
            break;
        }
    } while (opc != 0);
}