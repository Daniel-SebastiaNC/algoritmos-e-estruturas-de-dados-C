#include <stdio.h>

int main() {
    int idade = 20;

    int status;

    if (idade >= 18) {
        status = 1;
    } else {
        status = 0;
    }

    printf("%d", status);
}