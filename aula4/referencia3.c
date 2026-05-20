#include <stdio.h>

int soma(int *n1, int n2, int n3) {
    *n1 = *n1 + n2 + n3; 
}

int main() {
    int resultado = 2;
    int n2 = 5;
    int n3 = 3;

    soma(&resultado, n2, n3);

    printf("resultado: %d", resultado);
    return 0;
}