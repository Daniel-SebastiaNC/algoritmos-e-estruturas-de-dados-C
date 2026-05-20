#include <stdio.h>
#include <string.h>

int main() {
    char string[10];
    char nova[10];

    fgets(string, sizeof(string), stdin);

    int cont = 0;
    for (int i = 0; string[i] != '\0' && string[i] != '\n'; i++) {
        if (string[i] != ' '){
            nova[cont] = string[i];
            cont++;
        }
    }

    printf("%s", nova);
    return 0;
}
