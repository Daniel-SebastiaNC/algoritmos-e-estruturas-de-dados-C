#include <stdio.h>

int main() {

    int vetor[5][5];
    int b = 1;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("matriz[%d][%d] = ", i, j);
            int v = 0;
            scanf("%d", &v);
            vetor[i][j] = v;
            printf("\n");
        }
    }

    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j != i && vetor[i][j] != 0) {
                b = 0;
                break;
            }
                
            if(j == i && vetor[i][j] != 1) {
                b = 0;
                break;
            }
        }
    }

    if (b) {
        printf("a matriz e identidade");
    } else {
        printf("a matriz nao e identidade");
    }
    

    return 0;
}