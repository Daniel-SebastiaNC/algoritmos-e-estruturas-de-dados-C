#include <stdio.h>

int main() { 
    int num;

    scanf("%d", &num);
     
    for (int i = num-1; i > 1; i--) {
        num *= i;
        printf("%d \n", i);
    }

    printf("%d", num);
}