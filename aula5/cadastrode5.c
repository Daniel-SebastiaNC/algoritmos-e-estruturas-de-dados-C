#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
    char endereco[50];
} Pessoa;

int main() {
    Pessoa pessoas[5];
    
    for (int i = 0; i < 5; i++){
        printf("Pessoa %d\n", i+1);
        printf("nome: ");
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
    
        printf("idade: ");
        scanf("%d", &pessoas[i].idade);
    
        getchar();
    
        printf("endereco: ");
        fgets(pessoas[i].endereco, sizeof(pessoas[i].endereco), stdin);

        printf("\n");
    }

    printf("acabou\n");

    
    
    for (int i = 0; i < 5; i++) {
        printf("nome p1 = %s", pessoas[i].nome);
        printf("idade p1 = %d\n", pessoas[i].idade);
        printf("endereco p1 = %s\n", pessoas[i].endereco);
    }

    return 0;
}