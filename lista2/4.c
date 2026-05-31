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
    struct No *anterior;
    Aluno dado;
} No;

typedef struct {
    int tamanho;
    No *inicio;
    No *fim;
} Lista;

void inicializarLista(Lista *lista) {
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
}

void imprimirLista(Lista *lista) {
    printf("Show:\n");
    No *atual = lista->inicio;

    while (atual != NULL) {
        Aluno aluno = atual->dado;
        printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, CPF: %s\n", aluno.id, aluno.nome, aluno.matricula, aluno.idade, aluno.cpf);
        atual = atual->proximo;
    }
}

int inserirNoInicio(Lista *lista, Aluno aluno) {
    No *novo = malloc(sizeof(No));

    if(novo == NULL) {
        return 0;
    }

    novo->dado = aluno;
    novo->proximo = lista->inicio;
    novo->anterior = NULL;
    
    
    if (lista->tamanho == 0) {
        lista->fim = novo;
    } else {
        lista->inicio->anterior = novo;
    }

    lista->inicio = novo;
    lista->tamanho++;

    return 1;
}

int inserirNoFinal(Lista *lista, Aluno aluno) {
    No *novo = malloc(sizeof(No));

    if(novo == NULL) {
        return 0;
    }

    novo->dado = aluno;
    novo->proximo = NULL;
    novo->anterior = NULL;

    if (lista->tamanho == 0) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->proximo = novo;
        novo->anterior = lista->fim;
        lista->fim = novo;
    }

    lista->tamanho++;

    return 1;
}

int inserirEmPosicao(Lista *lista, Aluno aluno, int posicao) {
    if(posicao < 0 || posicao > lista->tamanho)
        return 0;
    
    if (posicao == 0) {
        inserirNoInicio(lista, aluno);
        return 1;
    }
    
    if (posicao == lista->tamanho) {
        inserirNoFinal(lista, aluno);
        return 1;
    }

    No *atual = lista->inicio;
    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    No *anterior = atual->anterior;
    No *novo = malloc(sizeof(No));
    if(novo == NULL) return 0;

    novo->dado = aluno;
    novo->proximo = atual;
    novo->anterior = anterior; 
    anterior->proximo = novo;
    atual->anterior = novo;     

    lista->tamanho++;
    return 1;
}

int removerNoInicio(Lista *lista) {
    if (lista->inicio == NULL) return 0;

    No *remover = lista->inicio;
    lista->inicio = remover->proximo;

    if (lista->inicio != NULL) {  
        lista->inicio->anterior = NULL;
    } else {
        lista->fim = NULL;
    }

    free(remover);
    lista->tamanho--;
    return 1;
}

int removerNoFinal(Lista *lista) {
    if (lista->inicio == NULL) {
        return 0;
    }

    if (lista->inicio == lista->fim) {
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho--;
        return 1;
    }

    No *atual = lista->inicio;

    for (int i = 0; i < lista->tamanho-1; i++) {
        atual = atual->proximo;
    }

    No *anterior = atual->anterior;

    No *remover = lista->fim;

    anterior->proximo = NULL; 
    lista->fim = anterior;

    free(remover);
    lista->tamanho--;

    return 1;
}

int removerEmPosicao(Lista *lista, int posicao) {
    if (posicao >= lista->tamanho || posicao < 0) {
        return 0;
    }

    if (posicao == 0) {
        removerNoInicio(lista);
        return 1;
    }

    if (posicao == lista->tamanho-1) {
        removerNoFinal(lista);
        return 1;
    }

    No *atual = lista->inicio;

    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    No *anterior = atual->anterior;

    anterior->proximo = atual->proximo;
    atual->proximo->anterior = anterior;

    free(atual);
    
    lista->tamanho--;
    return 1;
}

int tamanhoLista(Lista *lista) {
    return lista->tamanho;
}

int estaVazia(Lista *lista) {
    if (lista->tamanho == 0) 
        return 1;
    return 0;
}

int contemAluno(Lista *lista, char cpf[]) {
    No *atual = lista->inicio;

    while (atual != NULL) {
        if (strcmp(atual->dado.cpf, cpf) == 0) {
            return 1;
        }

        atual = atual->proximo;
    }

    return 0;
}

Aluno recuperarPorPosicao(Lista *lista, int posicao) {
    Aluno alunoReturn = {};
    if (posicao > lista->tamanho || posicao < 0) {
        return alunoReturn;
    }

    No *atual = lista->inicio;

    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    alunoReturn = atual->dado;

    return alunoReturn;
}

int limparLista(Lista *lista) {
    No *atual = lista->inicio;

    while (atual != NULL) {
        No *remover = atual;

        atual = atual->proximo;

        free(remover);
    }

    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->fim = NULL;

    return 1;
}

int main() {
    Lista lista;
    inicializarLista(&lista);

    if (estaVazia(&lista)) {
        printf("A lista esta vazia\n");
    } else {
        printf("A lista nao esta vazia\n");
    }

    Aluno aluno1 = {1, "Daniel", "0001", 20, "00000000"};
    Aluno aluno2 = {2, "Beatriz", "0002", 21, "11111111"};
    Aluno aluno3 = {3, "Carlos", "0003", 19, "22222222"};
    Aluno aluno4 = {4, "Fernanda", "0004", 22, "33333333"};
    Aluno aluno5 = {5, "Guilherme", "0005", 20, "44444444"};
    Aluno aluno6 = {6, "Mariana", "0006", 23, "55555555"};

    inserirNoInicio(&lista, aluno1);
    inserirNoInicio(&lista, aluno2);

    imprimirLista(&lista);

    inserirNoFinal(&lista, aluno3);
    imprimirLista(&lista);

    inserirEmPosicao(&lista, aluno4, 1);
    imprimirLista(&lista);

    removerNoInicio(&lista);
    imprimirLista(&lista);

    removerNoFinal(&lista);
    imprimirLista(&lista);

    inserirNoFinal(&lista, aluno6);
    imprimirLista(&lista);

    removerEmPosicao(&lista, 1);
    imprimirLista(&lista);

    printf("Tamanho da Lista: %d\n", tamanhoLista(&lista));

    if (estaVazia(&lista)) {
        printf("A lista esta vazia\n");
    } else {
        printf("A lista nao esta vazia\n");
    }

    if (contemAluno(&lista, "33333333")) {
        printf("Existe aluno com esse cpf (33333333)\n");
    } else {
        printf("Nao existe aluno com esse cpf (33333333)\n");
    }

    Aluno aluno = recuperarPorPosicao(&lista, 1);
    
    printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, CPF: %s\n", aluno.id, aluno.nome, aluno.matricula, aluno.idade, aluno.cpf);

    limparLista(&lista);

    imprimirLista(&lista);
    
    return 0;
}