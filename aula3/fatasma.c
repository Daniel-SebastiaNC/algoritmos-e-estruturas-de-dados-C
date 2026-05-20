#include <stdio.h>

int main() {
    int idade;
    char nome[20];

    printf("Idade: ");
    scanf("%d", &idade);

    getchar();

    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Nome digitado: %s", nome);
}