#include <stdio.h>
#include <stdlib.h>

int main() {

    int *v = calloc(5, sizeof(int));

    if (v == NULL) {
        printf("ERRO!");
        exit(1);
    }

    for (int i = 0; i < 5; i++) {
        printf("valo %d: ", i+1);
        scanf("%d", &v[i]);
    }
     
    for (int i = 0; i < 5; i++) {
        printf("%d \n", v[i]);
    }

    free(v);

    return 0;
}