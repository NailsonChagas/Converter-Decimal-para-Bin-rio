#include <stdio.h>
#include <stdlib.h>
#include "decimalBinario.h"

int main()
{
    int dec;
    char *binario;

    scanf("%d", &dec);

    binario = converter_int_para_binario(dec);

    printf("%s", binario);

    return 0;
}
