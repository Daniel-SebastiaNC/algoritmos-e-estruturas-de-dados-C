#include <stdio.h>

int main() {
    char texto[20];

    printf("digite um texto: \n");
    //scanf("%s", texto);
    fgets(texto, 20, stdin);

    printf("texto: %s", texto);

    return 0;
}