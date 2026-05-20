#include <stdio.h>
#include <stdlib.h>

int main() {
    int espaco;
    printf("espaco: ");
    scanf("%d", &espaco);

    int *v = calloc(espaco, sizeof(int));

    if (v == NULL) {
        printf("ERRO!");
        exit(1);
    }

    for (int i = 0; i < espaco; i++) {
        printf("valo %d: ", i+1);
        scanf("%d", &v[i]);
    }
     
    for (int i = 0; i < espaco; i++) {
        printf("%d \n", v[i]);
    }

    free(v);

    return 0;
}