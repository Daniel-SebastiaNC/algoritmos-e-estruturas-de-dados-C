#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome [50];
    int idade;
} Pessoa;

typedef struct No {
    Pessoa pessoa;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

void inicializar(Lista *lista) {
    lista->fim = NULL;
    lista->inicio = NULL;
    lista->tamanho = 0;
}

int inserirInicio(Lista *lista, Pessoa p) {
    No *novo = malloc(sizeof(No));

    if(novo == NULL) {
        return 0;
    }

    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;

        return 1;
    }

    novo->pessoa = p;
    novo->proximo = lista->inicio;

    lista->inicio = novo;

    return 1;
}

void imprimir(Lista *lista) {
    No *atual = lista->inicio;

    int cont = 0;
    while (atual != lista->fim) {
        printf("indice = %d | nome = %s | idade = %d",
            cont,
            atual->pessoa.nome,
            atual->pessoa.idade
        );

        cont++;
        atual = atual->proximo;
    }
}

int main() {
    Lista lista;

    inicializar(&lista);

    Pessoa pessoa1 = {"pessoa1", 18};
    Pessoa pessoa2 = {"pessoa2", 19};

    inserirInicio(&lista, pessoa2);
    inserirInicio(&lista, pessoa1);

    imprimir(&lista);

    return 0;
}