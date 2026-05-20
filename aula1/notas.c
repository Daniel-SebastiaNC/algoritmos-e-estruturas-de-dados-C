#include <stdio.h>

int main() {
    float nota1;
    float nota2;

    printf("Diite a 1 nota:\n");
    scanf("%f", &nota1);

    printf("Diite a 2 nota:\n");
    scanf("%f", &nota2);

    float media = (nota1 + nota2)/2;
    printf("Media das notas: %.2f", media);
}