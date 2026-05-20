#include <stdio.h>

int main() {
    int a, b;

    printf("a: ");
    scanf("%d", &a);

    printf("b: ");
    scanf("%d", &b);

    int *ea, *eb;
    ea = &a;
    eb = &b;

    if (ea > eb) {
        printf("%d - %ld \n",*ea, (long int) ea);
        printf("%d - %ld", *eb, (long int) eb);
    } else {
        printf("%d - %ld \n", *eb, (long int) eb);
        printf("%d - %ld",*ea, (long int) ea);
    }

    //printf("%d %d", a, b);

    return 0;
}