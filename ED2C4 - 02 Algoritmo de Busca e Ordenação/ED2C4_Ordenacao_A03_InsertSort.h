// Compara um valor com a subarray para encontrar a posição de inserção
long int insertSort(int *vetor, int tamanho)
{
    int i, j;              // Percorrer os laços de repetição passando por todas posições
    int memoria;           // Armazena o valor atual de comparação
    long int contador = 0; // Contar os comparações realizados (para efeitos de comparação)

    for (i = 1; i < tamanho; i++)
    {
        memoria = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > memoria)
        {
            contador++;
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = memoria;
    }
    return contador;
}