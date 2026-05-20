#include <stdio.h>

int partes(float *numero) {
    int inter = (int) *numero;
    *numero -= inter;

    return inter;
}

int main() {

    float fracional = 10.22;

    int inteiro = partes(&fracional);

    printf("inteiro = %d e fracional %.2f", inteiro, fracional);

    return 0;
}