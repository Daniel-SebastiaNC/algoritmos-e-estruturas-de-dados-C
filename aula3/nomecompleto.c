#include <stdio.h>
#include <string.h>

int main() {
    char string[20];

    fgets(string, sizeof(string), stdin);

    int tamanho = strlen(string);
    printf("qunatidade de cracter: %d \n", tamanho-1);

    int cont = 0;
    for (int i = 0; string[i] != '\0' && string[i] != '\n'; i++) {
        if(string[i] == 'a' || string[i] == 'A') {
            cont++;
        }
    }

    printf("Quantidade de a e A: %d", cont);

    return 0;
}
