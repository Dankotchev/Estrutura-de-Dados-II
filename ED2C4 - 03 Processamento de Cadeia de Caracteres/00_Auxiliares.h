void lerTexto(tipoTexto t, long x)
{
    FILE *arquivoTexto;
    arquivoTexto = fopen("01CasamentoDeCaracteresTexto.txt", "r");

    if (arquivoTexto != NULL)
    {
        fgets(t, x - 1, arquivoTexto);
        fclose(arquivoTexto);
    }
    else
    {
        printf("Arquivo nao encontrado.\n");
    }
}

void lerPadrao(tipoPadrao p, long x)
{
    FILE *arquivoTexto;
    arquivoTexto = fopen("01CasamentoDeCaracteresPadrao.txt", "r");

    if (arquivoTexto != NULL)
    {
        fgets(p, x - 1, arquivoTexto);
        fclose(arquivoTexto);
    }
    else
    {
        printf("Arquivo nao encontrado.\n");
    }
}
