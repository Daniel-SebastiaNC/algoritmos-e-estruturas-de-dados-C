#include <stdio.h>

int main() {
    int nota;

    scanf("%d", &nota);


    if (nota >= 90)
    {
        printf("A");
    } else if (nota >= 70) {
        printf("B");
    } else if (nota >= 50) {
        printf("C");
    } else {
        printf("D");
    }
    
}