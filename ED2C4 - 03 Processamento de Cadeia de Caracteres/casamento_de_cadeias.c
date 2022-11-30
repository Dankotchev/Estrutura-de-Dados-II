#include <stdio.h>

#define MAXTAMTEXTO     1000
#define MAXTAMPADRAO    10
#define MAXCHAR         256
#define NUMMAXERROS     10
typedef char TipoTexto[MAXTAMTEXTO];
typedef char TipoPadrao[MAXTAMPADRAO];

TipoTexto T;
TipoPadrao P;
long n, m, k, i;

void ForcaBruta(TipoTexto T, long n, TipoPadrao P, long m)
{ long i, j, k;
  for (i = 1; i <= (n - m + 1); i++)
    { k = i;  j = 1;
      while (T[k-1] == P[j-1] && j <= m) { j++; k++; }
      if (j > m) printf("Casamento na posicao: %3ld\n", i);
    }
}

void BMH(TipoTexto T, long n, TipoPadrao P, long m)
{ long i, j, k, d[MAXCHAR + 1];
  for (j = 0; j <= MAXCHAR; j++) d[j] = m;
  for (j = 1; j < m; j++) d[P[j-1]] = m - j;
  i = m;
  while (i <= n)    /*-- Pesquisa --*/
    { k = i;
      j = m;
      while (T[k-1] == P[j-1] && j > 0) { k--; j--; }
      if (j == 0)
      printf("Casamento na posicao: %3ld\n", k + 1);
      i += d[T[i-1]];
    }
}

void ShiftAndExato(TipoTexto T, long n, TipoPadrao P, long m)
{ long Masc[MAXCHAR], i, R = 0;
  for (i = 0; i < MAXCHAR; i++)
    Masc[i] = 0;
  for (i = 1; i <= m; i++)
    Masc[P[i-1] + 127] |= 1 << (m - i);
  for (i = 0; i < n; i++)
    { R = ((((unsigned long)R) >> 1) |
          (1 << (m - 1))) & Masc[T[i] + 127];
      if ((R & 1) != 0)
      printf(" Casamento na posicao %3ld\n", i - m + 2);
    }
}

void ShiftAndAproximado(TipoTexto T, long n,
                        TipoPadrao P, long m, long k)
{ long Masc[MAXCHAR], i, j, Ri, Rant, Rnovo;
  long R[NUMMAXERROS + 1];
  for (i = 0; i < MAXCHAR; i++) Masc[i] = 0;
  for (i = 1; i <= m; i++)
  { Masc[P[i-1] + 127] |= 1 << (m - i); }
  R[0] = 0;
  Ri = 1 << (m - 1);
  for (j = 1; j <= k; j++) R[j] = (1 << (m - j)) | R[j-1];
  for (i = 0; i < n; i++)
    { Rant = R[0];
      Rnovo = ((((unsigned long)Rant) >> 1) | Ri) & Masc[T[i] + 127];
      R[0] = Rnovo;
      for (j = 1; j <= k; j++)
        { Rnovo = ((((unsigned long)R[j]) >> 1) & Masc[T[i] + 127])
                  | Rant | (((unsigned long)(Rant | Rnovo)) >> 1);
          Rant = R[j];
          R[j] = Rnovo | Ri;
        }
      if ((Rnovo & 1) != 0)
      printf(" Casamento na posicao %12ld\n", i + 1);
    }
}

int main(int argc, char **argv)
{ printf(" Tamanho do texto: ");
  scanf("%ld%*[^\n]", &n); getchar();
  printf(" Tamanho do padrao: ");
  scanf("%ld%*[^\n]", &m); getchar();
  printf(" Texto: ");
  for (i = 1; i <= n; i++)
    { T[i-1] = getchar();
      if (T[i-1] == '\n')
      T[i-1] = ' ';
    }
  scanf("%*[^\n]");
  getchar();
  printf(" Padrao: ");
  for (i = 1; i <= m; i++)
    { P[i-1] = getchar();
      if (P[i-1] == '\n')
      P[i-1] = ' ';
    }
  scanf("%*[^\n]"); getchar();
  printf(" Forca bruta: ");
  ForcaBruta(T, n, P, m);
  scanf("%*[^\n]"); getchar();
  printf(" BMH: ");
  BMH(T, n, P, m);
  scanf("%*[^\n]"); getchar();
  printf(" Shift-And-Exato: ");
  ShiftAndExato(T, n, P, m);
  scanf("%*[^\n]"); getchar();
  printf(" Shift-And-Aproximado: ");
  printf("Numero de erros: ");
  scanf("%ld%*[^\n]", &k); getchar();
  ShiftAndAproximado(T, n, P, m, k);
  return 0;
}
