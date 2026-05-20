# include <stdio.h>

int main() {
    int inteiro = 12;
    double decimal = 12.12;
    char caracter = 'd';

    int *pInteiro = &inteiro;
    double *pDecimal = &decimal;
    char *pCaracter = &caracter;

    printf("Antes da mudaca: \n");
    printf("inteiro: %d (e = %p)\n", inteiro, pInteiro);
    printf("Double: %.2f (e = %p)\n", decimal, pDecimal);
    printf("inteiro: %c (e = %p)\n", caracter, pCaracter);

    *pInteiro = 10;
    *pDecimal = 10.10;
    *pCaracter = 'D';

    printf("Depois da mudaca: \n");
    printf("inteiro: %d (e = %p)\n", inteiro, pInteiro);
    printf("Double: %.2f (e = %p)\n", decimal, pDecimal);
    printf("inteiro: %c (e = %p)\n", caracter, pCaracter);
    return 0;
}