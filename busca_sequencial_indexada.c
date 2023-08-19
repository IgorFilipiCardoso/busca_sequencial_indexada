#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000
#define TABLE_SIZE 11

struct type_tabela
{
    int chave;
    int position;
};

int busca_sequencial(int dataset[], struct type_tabela tabela[], int position, int key);
int table_ind_find(struct type_tabela tabela[], int tamanho, int key);
void index_values(struct type_tabela table[], int array[], int tamanho_tabela, int tamanho_array);
void carrega_vetor_ordenado2(int colecao[], int tamanho);
void carrega_vetor_ordenado1(int colecao[], int valor_inicial, int tamanho);

int main()
{

    int table_pos;
    int key, busca;
    int *array = (int *)malloc(sizeof(int) * SIZE);
    struct type_tabela tabela[TABLE_SIZE];

    carrega_vetor_ordenado1(array, 5, SIZE);

    index_values(tabela, array, TABLE_SIZE, SIZE);

    printf("\nDigite a chave: ");
    scanf("%d", &key);

    table_pos = table_ind_find(tabela, TABLE_SIZE, key);

    if (table_pos != -1)
    {
        busca = busca_sequencial(array, tabela, table_pos, key);

        if (busca != -1)
        {
            printf("\nEncontrado entre %d e %d", tabela[table_pos - 1].chave, tabela[table_pos].chave);            
            printf("\nPos: %d | Valor: %d", busca, array[busca]);
        }
        else
        {
            printf("\nNao achei aqui");
        }
    }

    return 0;
}

void carrega_vetor_ordenado1(int colecao[], int valor_inicial, int tamanho)
{
    int i;
    srand((unsigned)time(NULL));
    for (colecao[0] = valor_inicial, i = 1; i < tamanho; i++)
    {
        colecao[i] = colecao[i - 1] + (rand() % 10);
        // printf("[%d] : %d\n", i, colecao[i]);
    }
}

void index_values(struct type_tabela table[], int array[], int tamanho_tabela, int tamanho_array)
{
    int i;
    int positions;

    for (i = 0; i < tamanho_tabela - 1; i++)
    {
        positions = ((tamanho_array / 9)) * i;
        table[i].position = positions;
        table[i].chave = array[positions];

        // printf("\nKey: %.3d", table[i].chave);
        // printf(" | Pos: %.3d", table[i].position);
    }
}

int table_ind_find(struct type_tabela tabela[], int tamanho, int key)
{
    int i = -1;
    int find = 0;

    while (i < tamanho && !find)
    {
        i++;

        if (key <= tabela[i].chave)
        {
            find = 1;
        }
    }

    if (find)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int busca_sequencial(int dataset[], struct type_tabela tabela[], int position, int key)
{
    int i;
    int find = 0;

    i = tabela[position - 1].position - 1;

    while (i <= tabela[position].position && !find)
    {
        i++;

        if (key == dataset[i])
        {
            find = 1;
        }
    }

    if (find)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
