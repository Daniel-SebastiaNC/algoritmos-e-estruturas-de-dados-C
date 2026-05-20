#include <stdio.h>

int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++) {
        if (vetor[i]%2 == 0) {
            printf("%d - %d\n", i, vetor[i]);
        }
    }
}