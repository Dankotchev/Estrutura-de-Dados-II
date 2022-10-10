#include <stdio.h>
#include <stdlib.h>
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
    long n = MAXTAMANHOTEXTO;
    long m = MAXTAMANHOPADRAO;


    printf("%s\n", textoT);
    printf("%s\n", padraoP);


    lerTexto(textoT, n+1);
    lerPadrao(padraoP, m+1);

    printf("%s\n", textoT);
    printf("%s\n", padraoP);

    forcaBruta(textoT, padraoP, n, m);





    return 0;
}
