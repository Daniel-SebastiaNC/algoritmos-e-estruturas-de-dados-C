#include <stdio.h>
#include <string.h>

int main() {
    char string[10];

    char caracter;
    fgets(string, sizeof(string), stdin);

    scanf("%c", &caracter);

    int cont = 0;
    for (int i = 0; string[i] != '\0' && string[i] != '\n'; i++) {
        if (string[i] == caracter)
            cont++;
    }

    printf("caracter apeareceu: %d", cont);
}