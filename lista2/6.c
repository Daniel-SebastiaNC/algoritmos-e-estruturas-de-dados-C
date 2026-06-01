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
} Pilha;

void inicializarpilha(Pilha *Pilha) {
    Pilha->tamanho = 0;
    Pilha->topo = NULL;
}

void imprimirpilha(Pilha *Pilha) {
    printf("Show:\n");
    No *atual = Pilha->topo;

    while (atual != NULL) {
        Aluno aluno = atual->dado;
        printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, CPF: %s\n", aluno.id, aluno.nome, aluno.matricula, aluno.idade, aluno.cpf);
        atual = atual->proximo;
    }
}

void push(Pilha *Pilha, Aluno aluno) {
   No *novo = malloc(sizeof(No));

    if(novo == NULL) {
        return;
    }

    novo->dado = aluno;
    novo->proximo = Pilha->topo;

    Pilha->topo = novo;

    Pilha->tamanho++;
}

Aluno pop(Pilha *Pilha) {
    Aluno aluno = {};
    if (Pilha->topo == NULL) {
        return aluno;
    }

    No *remover = Pilha->topo;

    Pilha->topo = remover->proximo;

    aluno = remover->dado;
    free(remover);
    Pilha->tamanho--;

    return aluno;
}

Aluno peak(Pilha *Pilha) {
    return Pilha->topo->dado;
}

int size(Pilha *Pilha) {
    return Pilha->tamanho;
}

int isEmpty(Pilha *Pilha) {
    if (Pilha->tamanho == 0) 
        return 1;
    return 0;
}

int clear(Pilha *Pilha) {
    No *atual = Pilha->topo;

    while (atual != NULL) {
        No *remover = atual;

        atual = atual->proximo;

        free(remover);
    }

    Pilha->tamanho = 0;
    Pilha->topo = NULL;

    return 1;
}

int main() {
    Pilha Pilha;
    inicializarpilha(&Pilha);

    if (isEmpty(&Pilha)) {
        printf("A Pilha esta vazia\n");
    } else {
        printf("A Pilha nao esta vazia\n");
    }

    Aluno aluno1 = {1, "Daniel", "0001", 20, "00000000"};
    Aluno aluno2 = {2, "Beatriz", "0002", 21, "11111111"};
    Aluno aluno3 = {3, "Carlos", "0003", 19, "22222222"};
    Aluno aluno4 = {4, "Fernanda", "0004", 22, "33333333"};
    Aluno aluno5 = {5, "Guilherme", "0005", 20, "44444444"};
    Aluno aluno6 = {6, "Mariana", "0006", 23, "55555555"};
    
    push(&Pilha, aluno1);

    if (isEmpty(&Pilha)) {
        printf("A Pilha esta vazia\n");
    } else {
        printf("A Pilha nao esta vazia\n");
    }

    push(&Pilha, aluno2);
    push(&Pilha, aluno3);

    imprimirpilha(&Pilha);

    Aluno aluno = pop(&Pilha);

    printf("Aluno que foi atendido: \n");
    printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, CPF: %s\n", aluno.id, aluno.nome, aluno.matricula, aluno.idade, aluno.cpf);

    imprimirpilha(&Pilha);
    printf("Tamanho da Pilha: %d\n", size(&Pilha));

    printf("Proximo Aluno: \n");
    aluno = peak(&Pilha);

    printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, CPF: %s\n", aluno.id, aluno.nome, aluno.matricula, aluno.idade, aluno.cpf);

    clear(&Pilha);

    printf("Tamanho da Pilha: %d\n", size(&Pilha));
    imprimirpilha(&Pilha);

    return 0;
}