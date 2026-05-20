#include <stdio.h>

int main() {
    printf("for: ");
    for (int i = 1; i <=10; i++) {
        printf("%d ", i);
    }

    printf("\n");
    printf("while: ");
    int j = 1;

    while (j <=10)
    {
        printf("%d ", j);

        j++;
    }

    printf("\n");
    printf("do while: ");
    int k = 1;

    do {
        printf("%d ", k);

        k++;
    } while (k <=10);

    
    return 0;
}