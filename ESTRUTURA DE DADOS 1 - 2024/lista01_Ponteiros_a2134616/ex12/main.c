#include <stdio.h>
#include <stdlib.h>

int *create_vector(int n)
{
    // Aloca memória para n inteiros
    int *vector = (int *)malloc(n * sizeof(int));
    if (vector == NULL)
    {
        // Verifica se a alocação foi bem-sucedida
        fprintf(stderr, "Erro ao alocar memória.\n");
        return NULL;
    }

    // Inicializa todos os elementos com zero
    for (int i = 0; i < n; i++)
    {
        vector[i] = 0;
    }

    return vector;
}

void print_vector(int n, int *vector)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", vector[i]);
        if (i < n - 1)
        {
            printf(",");
        }
    }
    printf("\n");
}

int main()
{
    int *v1 = create_vector(7); // aloca array de 7 inteiros na heap
    if (v1 != NULL)
    {
        print_vector(7, v1); // imprime 0,0,0,0,0,0,0
        free(v1);            // libera array alocado na heap
    }
    return 0;
}
