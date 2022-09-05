// Divide o array em janelas e realiza as comparações tal como um Insert Sort
long int shellSort(int *vetor, int tamanho)
{
    int i, j;              // Percorrer os laços de repetição passando por todas posições
    int janela = 1;        // Tamanho das janelas de comparação
    int memoria;           // Armazena o valor atual de comparação
    long int contador = 0; // Contar os comparações realizados (para efeitos de comparação)

    // Definir o tamanho da janela,
    while (janela < tamanho)
    {
        janela = (janela * 3) + 1;
    }
    janela /= 3;

    while (janela > 0)
    {
        for (i = janela; i < tamanho; i++)
        {
            memoria = vetor[i];
            j = i;

            while (j >= janela && vetor[j - janela] > memoria)
            {
                contador++;
                vetor[j] = vetor[j - janela];
                j = j - janela;
            }
            vetor[j] = memoria;
        }
        janela /= 3;
    }
    return contador;
}