#include <stdio.h>

int main() {

    int vetor[5];

    for (int i = 0; i < 5; i++) {
        int v = 0;
        scanf("%d", &v);
        vetor[i] = v;
    }

    int soma = 0;
    for(int i = 0; i < 5; i++) {
        soma += vetor[i];
        //printf("%d ", vetor[i]);
    }

    printf("soma: %d", soma);

    return 0;
}