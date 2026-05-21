#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

void init(Fila *fila) {
    fila->fim = NULL;
    fila->inicio = NULL;
    fila->tamanho = 0;
}

void enqueue(Fila *f, int numero) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("ERROR");
        return;
    }

    novo->valor = numero;
    novo->proximo = NULL;

    if (f->tamanho == 0) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->proximo = novo;
        f->fim = novo;
    }

    f->tamanho++;
}

int dequeue(Fila *fila) {
    No *deletar = fila->inicio;

    fila->inicio = deletar->proximo;


    int retorno = deletar->valor;
    free(deletar);

    fila->tamanho--;
    return retorno;
} 

void imprimir(Fila *fila) {

    No *atual = fila->inicio;

    printf("Show:\n");
    while (atual != NULL)
    {
        printf("%d \n", atual->valor);
        atual = atual->proximo;
    }
    
}

int front(Fila *fila) {
    return fila->inicio->valor;
}

int isEmpty(Fila *fila) {
    if(fila->tamanho == 0) {
        return 1;
    } 

    return 0;
}

int size(Fila *fila) {
    return fila->tamanho;
}

void clear(Fila *fila) {
    No *atual = fila->inicio;

    while (atual != NULL)
    {
        dequeue(fila);
        atual = atual->proximo;
    }
}

int main() {
    
    Fila fila;

    init(&fila);

    enqueue(&fila, 1);
    enqueue(&fila, 2);
    enqueue(&fila, 3);
    enqueue(&fila, 4);

    imprimir(&fila);

    printf("inicio: %d\n", front(&fila));

    printf("Fila andou, cliente atendido: %d\n", dequeue(&fila));

    imprimir(&fila);

    clear(&fila);
    imprimir(&fila);

    return 0;
}