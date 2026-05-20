#include <stdio.h>

int main() {

    int vetor[10];

    for (int i = 0; i < 10; i++) {
        int v = 0;
        scanf("%d", &v);
        vetor[i] = v;
    }

    int maior = vetor[0];
    for(int i = 0; i < 10; i++) {
        if (maior < vetor[i]) {
            maior = vetor[i];
        }
    }

    printf("maior: %d", maior);

    return 0;
}