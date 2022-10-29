#include <stdio.h>
#include <string.h>

struct Tecnicos
{
    int prontuario;
    char nome[100];
    int ramal;
    char status;
};

struct Equipamentos
{
    int numero;
    char descricao[200];
    int num_laboratorio;
    int num_maquina;
    char situacao[1];
    char status;
};

struct Manutencoes
{
    int dia;
    int mes;
    int equip;
    int tecnico;
    char problema[100];
    char solucao[100];
    char situacao[1];
    char status;
};

void gravar_novo_tecnico(struct Tecnicos t)
{
    FILE *arquivo;

    arquivo = fopen("tecnicos.dat", "ab");

    if (arquivo == NULL)
    {
        printf("\nNao eh possivel criar ou abrir esse arquivo.\n");
    }

    t.status = 'A';

    fwrite(&t, sizeof(struct Tecnicos), 1, arquivo);

    fclose(arquivo);
}

void gravar_novo_equipamento(struct Equipamentos e)
{
    FILE *arquivo;

    arquivo = fopen("equipamentos.dat", "ab");

    if (arquivo == NULL)
    {
        printf("\nNao eh possivel criar ou abrir esse arquivo.\n");
    }

    e.status = 'A';

    fwrite(&e, sizeof(struct Equipamentos), 1, arquivo);

    fclose(arquivo);
}

void gravar_nova_manutencao(struct Manutencoes m)
{
    FILE *arquivo;

    arquivo = fopen("manutencoes.dat", "ab");

    if (arquivo == NULL)
    {
        printf("\nNao eh possivel criar ou abrir esse arquivo.\n");
    }

    m.status = 'A';

    fwrite(&m, sizeof(struct Manutencoes), 1, arquivo);

    fclose(arquivo);
}

struct Tecnicos ler_tecnicos(int posicao)
{
    FILE *arquivo;

    struct Tecnicos t;

    arquivo = fopen("tecnicos.dat", "rb");

    if (arquivo == NULL)
    {
        printf("\nErro na abertura do arquivo para leitura.\n");
        t.prontuario = 0;
    }
    else
    {
        fseek(arquivo, posicao * sizeof(struct Tecnicos), SEEK_SET);

        fread(&t, sizeof(struct Tecnicos), 1, arquivo);

        fclose(arquivo);
    }
    return t;
};

int localizar_tecnico(int prontuario)
{
    FILE *arquivo;

    struct Tecnicos t;

    int posicao = -1, i = 0;

    arquivo = fopen("tecnicos.dat", "rb");

    if (arquivo == NULL)
    {
        printf("\nNao foi possivel abrir o arquivo ou nao existem tecnicos a serem impressos\n");
    }
    else
    {
        fread(&t, sizeof(struct Tecnicos), 1, arquivo);

        while (!feof(arquivo) && posicao == -1)
        {
            if (t.prontuario == prontuario)
            {
                posicao = i;
                if (t.status == 'E')
                    posicao = -2;
            }
            fread(&t, sizeof(struct Tecnicos), 1, arquivo);
            i++;
        }

        fclose(arquivo);
    }
    return posicao;
}

struct Equipamentos ler_equip(int posicao)
{
    FILE *arquivo;

    struct Equipamentos e;

    arquivo = fopen("equipamentos.dat", "rb");

    if (arquivo == NULL)
    {
        printf("\nErro na abertura do arquivo para leitura.\n");
        e.numero = 0;
    }
    else
    {
        fseek(arquivo, posicao * sizeof(struct Equipamentos), SEEK_SET);

        fread(&e, sizeof(struct Equipamentos), 1, arquivo);

        fclose(arquivo);
    }
    return e;
};

int localizar_equip(int numero)
{
    FILE *arquivo;

    struct Equipamentos e;

    int posicao = -1, i = 0;

    arquivo = fopen("equipamentos.dat", "rb");

    if (arquivo == NULL)
    {
        printf("\nNao foi possivel abrir o arquivo ou nao existem equipamentos a serem impressos\n");
    }
    else
    {
        fread(&e, sizeof(struct Equipamentos), 1, arquivo);

        while (!feof(arquivo) && posicao == -1)
        {
            if (e.numero == numero)
            {
                posicao = i;
                if (e.status == 'E')
                    posicao = -2;
            }
            fread(&e, sizeof(struct Equipamentos), 1, arquivo);
            i++;
        }

        fclose(arquivo);
    }
    return posicao;
}

struct Manutencoes ler_manu(int posicao)
{
    FILE *arquivo;

    struct Manutencoes m;

    arquivo = fopen("manutencoes.dat", "rb");

    if (arquivo == NULL)
    {
        printf("\nErro na abertura do arquivo para leitura.\n");
        m.dia = 0;
        m.mes = 0;
        m.equip = 0;
    }
    else
    {
        fseek(arquivo, posicao * sizeof(struct Manutencoes), SEEK_SET);

        fread(&m, sizeof(struct Manutencoes), 1, arquivo);

        fclose(arquivo);
    }
    return m;
};

int localizar_manu(int dia, int mes, int equipamento)
{
    FILE *arquivo;

    struct Manutencoes m;

    int posicao = -1, i = 0;

    arquivo = fopen("manutencoes.dat", "rb");

    if (arquivo == NULL)
    {
        printf("\nNao foi possivel abrir o arquivo ou nao existem manutencoes a serem impressas\n");
    }
    else
    {
        fread(&m, sizeof(struct Manutencoes), 1, arquivo);

        while (!feof(arquivo) && posicao == -1)
        {
            if (m.dia == dia && m.mes == mes && m.equip == equipamento)
            {
                posicao = i;
                if (m.status == 'E')
                    posicao = -2;
            }
            fread(&m, sizeof(struct Manutencoes), 1, arquivo);
            i++;
        }

        fclose(arquivo);
    }
    return posicao;
}

void alterar_tecnic(struct Tecnicos t, int posicao)
{
    FILE *arquivo;

    arquivo = fopen("tecnicos.dat", "rb+");

    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo para leitura e gravacao.");
    }
    else
    {
        fseek(arquivo, posicao * sizeof(struct Tecnicos), SEEK_SET);

        fwrite(&t, sizeof(struct Tecnicos), 1, arquivo);

        fclose(arquivo);
    }
}

void alterar_equi(struct Equipamentos e, int posicao)
{
    FILE *arquivo;

    arquivo = fopen("equipamentos.dat", "rb+");

    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo para leitura e gravacao.");
    }
    else
    {
        fseek(arquivo, posicao * sizeof(struct Equipamentos), SEEK_SET);

        fwrite(&e, sizeof(struct Equipamentos), 1, arquivo);

        fclose(arquivo);
    }
}

void alterar_man(struct Manutencoes m, int posicao)
{
    FILE *arquivo;

    arquivo = fopen("manutencoes.dat", "rb+");

    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo para leitura e gravacao.");
    }
    else
    {
        fseek(arquivo, posicao * sizeof(struct Manutencoes), SEEK_SET);

        fwrite(&m, sizeof(struct Manutencoes), 1, arquivo);

        fclose(arquivo);
    }
}

void listar_tecnicos()
{
    FILE *arquivo;

    struct Tecnicos t;

    arquivo = fopen("tecnicos.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo ou nao ha tecnicos a serem impressos");
    }
    else
    {
        fread(&t, sizeof(struct Tecnicos), 1, arquivo);

        while (!feof(arquivo))
        {
            if (t.status == 'A')
                imprimir_tecnico(t);

            fread(&t, sizeof(struct Tecnicos), 1, arquivo);
        }
        fclose(arquivo);
    }
}

void listar_equip()
{
    FILE *arquivo;

    struct Equipamentos e;

    arquivo = fopen("equipamentos.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo ou nao ha equipamentos a serem impressos");
    }
    else
    {
        fread(&e, sizeof(struct Equipamentos), 1, arquivo);

        while (!feof(arquivo))
        {
            if (e.status == 'A')
                imprimir_equip(e);

            fread(&e, sizeof(struct Equipamentos), 1, arquivo);
        }
        fclose(arquivo);
    }
}

void listar_manu()
{
    FILE *arquivo;

    struct Manutencoes m;

    arquivo = fopen("manutencoes.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo ou nao ha manutencoes a serem impressas");
    }
    else
    {
        fread(&m, sizeof(struct Manutencoes), 1, arquivo);

        while (!feof(arquivo))
        {
            if (m.status == 'A')
                imprimir_manu(m);

            fread(&m, sizeof(struct Manutencoes), 1, arquivo);
        }
        fclose(arquivo);
    }
}

void excluir_tecnic(int posicao)
{
    FILE *arquivo;

    struct Tecnicos t;

    arquivo = fopen("tecnicos.dat", "rb+");

    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo para leitura e gravacao.");
    }
    else
    {
        fseek(arquivo, posicao * sizeof(struct Tecnicos), SEEK_SET);

        fread(&t, sizeof(struct Tecnicos), 1, arquivo);

        t.status = 'E';

        fseek(arquivo, posicao * sizeof(struct Tecnicos), SEEK_SET);

        fwrite(&t, sizeof(struct Tecnicos), 1, arquivo);

        fclose(arquivo);
    }
}

void excluir_equi(int posicao)
{
    FILE *arquivo;

    struct Equipamentos e;

    arquivo = fopen("equipamentos.dat", "rb+");

    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo para leitura e gravacao.");
    }
    else
    {
        fseek(arquivo, posicao * sizeof(struct Equipamentos), SEEK_SET);

        fread(&e, sizeof(struct Equipamentos), 1, arquivo);

        e.status = 'E';

        fseek(arquivo, posicao * sizeof(struct Equipamentos), SEEK_SET);

        fwrite(&e, sizeof(struct Equipamentos), 1, arquivo);

        fclose(arquivo);
    }
}

void excluir_man(int posicao)
{
    FILE *arquivo;

    struct Manutencoes m;

    arquivo = fopen("manutencoes.dat", "rb+");

    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo para leitura e gravacao.");
    }
    else
    {
        fseek(arquivo, posicao * sizeof(struct Manutencoes), SEEK_SET);

        fread(&m, sizeof(struct Manutencoes), 1, arquivo);

        m.status = 'E';

        fseek(arquivo, posicao * sizeof(struct Manutencoes), SEEK_SET);

        fwrite(&m, sizeof(struct Manutencoes), 1, arquivo);

        fclose(arquivo);
    }
}