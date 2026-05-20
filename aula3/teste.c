#include <stdio.h>
#include <string.h>

int main() {

    char origem[] = "IFPE";
    char destino[10];

    strcpy(destino, origem);

    printf("%s\n", destino);

    return 0;
}
