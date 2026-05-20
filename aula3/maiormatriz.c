#include <stdio.h>

int main() {

    int vetor[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
                int v = 0;
                scanf("%d", &v);
                vetor[i][j] = v;
        }
    }

    int maior = vetor[0][0];
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (maior < vetor[i][j]) {
                maior = vetor[i][j];
            }
        }
    }

    printf("maior: %d", maior);

    return 0;
}