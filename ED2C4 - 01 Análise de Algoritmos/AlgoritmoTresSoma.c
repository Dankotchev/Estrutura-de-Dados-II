#include <time.h>
#define TAMANHO 8912

long int conta(int *a)
{
    int contador = 0;
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            for (int k = 0; k < TAMANHO; k++)
            {
                if (a[i] + a[j] + a[k] == 0)
                {
                    contador++;
                }
            }
        }
    }
    return contador;
}

int main()
{
    int vetor[TAMANHO];
    srand(time(NULL));
   long int operacoes;
    double tempoDecorrido;

    for (int preencher = 0; preencher < TAMANHO; preencher++)
    {
        vetor[preencher] = rand() / 101;
    }

    // iniciar contagem do tempo
    clock_t begin = clock();
    operacoes = conta(vetor);
    clock_t end = clock();
    // finaliza contagem do tempo


    tempoDecorrido = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("A soma resultou em %ld triplas", operacoes);
    printf("\nA operação demorou %f tempos", tempoDecorrido);
}

