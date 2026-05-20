#include <stdio.h>

int main() {

    int vetor[7];

    for (int i = 0; i < 7; i++) {
        int v = 0;
        scanf("%d", &v);
        vetor[i] = v;
    }

    printf("digite x: ");
    int pesquisa;
    scanf("%d", &pesquisa);

    int contator = 0;
    for(int i = 0; i < 7; i++) {
        if (pesquisa == vetor[i]) {
            printf("valor encontrado no indice: %d\n", i);
            contator = 1;
        }
    }

    if (!contator) {
        printf("nao encontrado");
    }

    return 0;
}