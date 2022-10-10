#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTAMANHOTEXTO 1000
#define MAXTAMANHOPADRAO 10
#define MAXCHAR 256
#define NUMMAXERROS 10

typedef char tipoTexto[MAXTAMANHOTEXTO];
typedef char tipoPadrao[MAXTAMANHOPADRAO];

#include "00_Auxiliares.h"

void forcaBruta(tipoTexto TEXTO, tipoPadrao PADRAO, long n, long m)
{
    long i, j, k;
    for (i = 1; i <= (n - m + 1); i++)
    {
        k = i;
        j = 1;
        while (TEXTO[k-1] == PADRAO[j-1] && j <= m)
        {
            j++;
            k++;
        }
        if (j > m)
        {
            printf("Casamento na posicao %3ld\n", i);
        }
    }
}

int main()
{
    tipoTexto textoT = "os testes fizeram os alunos tremerem";
    tipoPadrao padraoP = "testes";
    long n = strlen(textoT);
    long m = strlen(padraoP);

    //lerTexto(textoT, n+1);
    //n = strlen(textoT);
    //lerPadrao(padraoP, m+1);
    //m = strlen(padraoP);

    forcaBruta(textoT, padraoP, n, m);

    return 0;
}
