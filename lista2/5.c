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
    No *inicio;
    No *fim;
} Fila;

void inicializarFila(Fila *Fila) {
    Fila->tamanho = 0;
    Fila->inicio = NULL;
    Fila->fim = NULL;
}

void imprimirFila(Fila *Fila) {
    printf("Show:\n");
    No *atual = Fila->inicio;

    while (atual != NULL) {
        Aluno aluno = atual->dado;
        printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, CPF: %s\n", aluno.id, aluno.nome, aluno.matricula, aluno.idade, aluno.cpf);
        atual = atual->proximo;
    }
}

No* obterNoAnterior(Fila *Fila, int posicao) {
    if(posicao <= 0 || posicao > Fila->tamanho)
        return NULL;
    
    No *atual = Fila->inicio;

    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    return atual;
}

void enqueue(Fila *Fila, Aluno aluno) {
   No *novo = malloc(sizeof(No));

    if(novo == NULL) {
        return;
    }

    novo->dado = aluno;
    novo->proximo = Fila->inicio;

    Fila->inicio = novo;

    if (Fila->tamanho == 0) {
        Fila->fim = novo;
    }

    Fila->tamanho++;

}

Aluno dequeue(Fila *Fila) {
    Aluno retornoAluno = {};
    if (Fila->inicio == NULL) {
        return retornoAluno;
    }

    if (Fila->inicio == Fila->fim) {
        retornoAluno = Fila->inicio->dado;
        free(Fila->inicio);
        Fila->inicio = NULL;
        Fila->fim = NULL;
        Fila->tamanho--;
        return retornoAluno;
    }

    No *anterior = obterNoAnterior(Fila, Fila->tamanho-1);
    No *remover = Fila->fim;

    anterior->proximo = NULL; 
    Fila->fim = anterior;

    retornoAluno = remover->dado;
    free(remover);
    Fila->tamanho--;

    return retornoAluno;
}

Aluno front(Fila *Fila) {
    return Fila->fim->dado;
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
    No *atual = Fila->inicio;

    while (atual != NULL) {
        No *remover = atual;

        atual = atual->proximo;

        free(remover);
    }

    Fila->tamanho = 0;
    Fila->inicio = NULL;
    Fila->fim = NULL;

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
    
    enqueue(&Fila, aluno1);

    if (isEmpty(&Fila)) {
        printf("A Fila esta vazia\n");
    } else {
        printf("A Fila nao esta vazia\n");
    }

    enqueue(&Fila, aluno2);
    enqueue(&Fila, aluno3);

    imprimirFila(&Fila);

    Aluno aluno = dequeue(&Fila);

    printf("Aluno que foi atendido: \n");
    printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, CPF: %s\n", aluno.id, aluno.nome, aluno.matricula, aluno.idade, aluno.cpf);

    imprimirFila(&Fila);
    printf("Tamanho da fila: %d\n", size(&Fila));

    printf("Proximo Aluno: \n");
    aluno = front(&Fila);

    printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, CPF: %s\n", aluno.id, aluno.nome, aluno.matricula, aluno.idade, aluno.cpf);

    clear(&Fila);

    printf("Tamanho da fila: %d\n", size(&Fila));
    imprimirFila(&Fila);

    return 0;
}