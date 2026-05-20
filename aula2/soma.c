#include <stdio.h>

int main() {
    int soma = 0;

    for (int i = 0; i < 5; i++) {
        int v;
        printf("digite um numero: ");
        scanf("%d", &v);

        soma += v;
    }

    printf("soma: %d", soma);

    return 0;
}