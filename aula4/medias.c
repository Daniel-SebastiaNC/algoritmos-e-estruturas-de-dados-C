#include <stdio.h>

float media(float n1, float n2, float n3, char tipoMedia) {
    float resultado;
    if (tipoMedia == 'A') {
        resultado = (n1 + n2 + n3)/3;
    } else {
        resultado = ((n1*5)+(n2*3)+(n3*2))/10;
    }

    return resultado;
}

int main() {
    char v = 'P';
    float n1 = 10;
    float n2 = 8;
    float n3 = 7;

    printf("meida das notas: %.2f", media(n1, n2, n3, v));

    return 0;
}