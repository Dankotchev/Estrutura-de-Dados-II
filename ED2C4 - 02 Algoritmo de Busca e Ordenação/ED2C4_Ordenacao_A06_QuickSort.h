/*
Escolha um pivo e coloca todos os valores maiores a sua direita, e menores a sua esquerda, finalizando
o pivo em sua posição.
*/
void quickSort(int *vetor, int iniArray, int fimArray, long int *permutacoes)
{
	int i, j, pivo, auxiliar;
	int media = (iniArray + fimArray) / 2;

	if (iniArray < fimArray)
	{

		pivo = iniArray;
		i = iniArray;
		j = fimArray;
		while (i < j)
		{
			while (vetor[i] <= vetor[pivo] && i < fimArray)
				i++;
			while (vetor[j] > vetor[pivo])
				j--;
			if (i < j)
			{
				auxiliar = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = auxiliar;
				*permutacoes = *permutacoes + 1;
			}
		}
		auxiliar = vetor[pivo];
		vetor[pivo] = vetor[j];
		vetor[j] = auxiliar;
		quickSort(vetor, iniArray, j - 1, permutacoes);
		quickSort(vetor, j + 1, fimArray, permutacoes);
	}
}