void troca(int vet[], int i, int j)
{
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

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
		// Maneira de escolher um pivô para um melhor resultado do Quick Sort
		// if (vetor[media] < vetor[iniArray])
		// 	troca(vetor, media, iniArray);
		// if (vetor[fimArray] < vetor[iniArray])
		// 	troca(vetor, fimArray, iniArray);
		// if (vetor[media] < vetor[fimArray])
		// 	troca(vetor, media, fimArray);

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