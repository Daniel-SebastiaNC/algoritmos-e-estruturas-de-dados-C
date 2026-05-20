#include <stdio.h>

int main() {
    int num;

    printf("digite um numero: \n");
    scanf("%d", &num);

    printf("num: %d", num);
    printf("\ndobro: %d", num*2);
    printf("\ntriplo: %d", num*3);

    return 0;
}