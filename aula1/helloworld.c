#include <stdio.h>

struct Produto
    {
        char id;
        float valor;
    };

int main() {

    struct Produto produto1;
    
    produto1.id = 1;
    produto1.valor = 12.90;

    printf("Id: %d\n", produto1.id);
    printf("Valor: %.2f\n\n", produto1.valor);

    int x = 2;

    int *p;

    p = &x;

    printf("endereco: %d\n", &x);
    printf("valor no poteiro: %d\n", *p);
    printf("endereco referencia poteiro: %d\n", p);

    return 0;
} 