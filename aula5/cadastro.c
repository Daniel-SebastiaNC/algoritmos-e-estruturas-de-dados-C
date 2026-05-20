#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
    char endereco[50];
} Pessoa;

int main() {
    Pessoa p1;

    printf("nome: ");
    fgets(p1.nome, sizeof(p1.nome), stdin);

    printf("idade: ");
    scanf("%d", &p1.idade);

    getchar();

    printf("endereco: ");
    fgets(p1.endereco, sizeof(p1.endereco), stdin);

    printf("nome p1 = %s", p1.nome);
    printf("idade p1 = %d\n", p1.idade);
    printf("endereco p1 = %s\n", p1.endereco);
}