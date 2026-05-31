#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[20];
    char matricula[20];
    int idade;
    char cpf[20];
} Aluno;

typedef struct No {
    struct No *proximo;
    Aluno dado;
} No;

typedef struct {
    int tamanho;
    No *topo;
} Fila;

void inicializarFila(Fila *Fila) {
    Fila->tamanho = 0;
    Fila->topo = NULL;
}

void imprimirFila(Fila *Fila) {
    printf("Show:\n");
    No *atual = Fila->topo;

    while (atual != NULL) {
        Aluno aluno = atual->dado;
        printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, CPF: %s\n", aluno.id, aluno.nome, aluno.matricula, aluno.idade, aluno.cpf);
        atual = atual->proximo;
    }
}

void push(Fila *Fila, Aluno aluno) {
   No *novo = malloc(sizeof(No));

    if(novo == NULL) {
        return;
    }

    novo->dado = aluno;
    novo->proximo = Fila->topo;

    Fila->topo = novo;

    Fila->tamanho++;
}

Aluno pop(Fila *Fila) {
    Aluno aluno = {};
    if (Fila->topo == NULL) {
        return aluno;
    }

    No *remover = Fila->topo;

    Fila->topo = remover->proximo;

    aluno = remover->dado;
    free(remover);
    Fila->tamanho--;

    return aluno;
}

Aluno peak(Fila *Fila) {
    return Fila->topo->dado;
}

int size(Fila *Fila) {
    return Fila->tamanho;
}

int isEmpty(Fila *Fila) {
    if (Fila->tamanho == 0) 
        return 1;
    return 0;
}

int clear(Fila *Fila) {
    No *atual = Fila->topo;

    while (atual != NULL) {
        No *remover = atual;

        atual = atual->proximo;

        free(remover);
    }

    Fila->tamanho = 0;
    Fila->topo = NULL;

    return 1;
}

int main() {
    Fila Fila;
    inicializarFila(&Fila);

    if (isEmpty(&Fila)) {
        printf("A Fila esta vazia\n");
    } else {
        printf("A Fila nao esta vazia\n");
    }

    Aluno aluno1 = {1, "Daniel", "0001", 20, "00000000"};
    Aluno aluno2 = {2, "Beatriz", "0002", 21, "11111111"};
    Aluno aluno3 = {3, "Carlos", "0003", 19, "22222222"};
    Aluno aluno4 = {4, "Fernanda", "0004", 22, "33333333"};
    Aluno aluno5 = {5, "Guilherme", "0005", 20, "44444444"};
    Aluno aluno6 = {6, "Mariana", "0006", 23, "55555555"};
    
    push(&Fila, aluno1);

    if (isEmpty(&Fila)) {
        printf("A Fila esta vazia\n");
    } else {
        printf("A Fila nao esta vazia\n");
    }

    push(&Fila, aluno2);
    push(&Fila, aluno3);

    imprimirFila(&Fila);

    Aluno aluno = pop(&Fila);

    printf("Aluno que foi atendido: \n");
    printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, CPF: %s\n", aluno.id, aluno.nome, aluno.matricula, aluno.idade, aluno.cpf);

    imprimirFila(&Fila);
    printf("Tamanho da fila: %d\n", size(&Fila));

    printf("Proximo Aluno: \n");
    aluno = peak(&Fila);

    printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, CPF: %s\n", aluno.id, aluno.nome, aluno.matricula, aluno.idade, aluno.cpf);

    clear(&Fila);

    printf("Tamanho da fila: %d\n", size(&Fila));
    imprimirFila(&Fila);

    return 0;
}