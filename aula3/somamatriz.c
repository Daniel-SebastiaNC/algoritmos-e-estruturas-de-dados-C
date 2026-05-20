#include <stdio.h>

int main() {

    int vetor[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int v = 0;
            scanf("%d", &v);
            vetor[i][j] = v;
        }
    }

    int soma = 0;
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            soma += vetor[i][j];
        }
        //printf("%d ", vetor[i]);
    }

    printf("soma: %d", soma);

    return 0;
}