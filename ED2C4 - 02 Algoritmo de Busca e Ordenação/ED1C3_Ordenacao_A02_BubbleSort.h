long int bubbleSort(int *vetor, int tamanho)
{
    int i, j;              // Percorrer os laços de repetição passando por todas posições
    int auxiliar;          // Auxiliar, para realizar a troca de valores
    long int contador = 0; // Contar os comparações realizados (para efeitos de comparação)

    for (i = tamanho - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            contador++;
            if (vetor[j] > vetor[j + 1])
            {
                auxiliar = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = auxiliar;
            }
        }
    }
    return contador;
}