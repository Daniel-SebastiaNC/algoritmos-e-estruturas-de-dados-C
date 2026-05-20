#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v = calloc(1500, sizeof(int));

    if (v == NULL) {
        printf("ERRO!");
        exit(1);
    }

        
    return 0;
}