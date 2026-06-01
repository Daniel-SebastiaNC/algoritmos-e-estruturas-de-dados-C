//1. Implemente uma Lista a partir de um vetor estático, considerando todos os métodos da interface da lista descrita.

/*

#include <stdio.h>
#include <string.h>

#define MAX 20

typedef struct {
    int id;
    char nome[20];
    char matricula[20];
    int idade;
    char cpf[20];
} Aluno;

typedef struct {
    int tamanho;
    Aluno dados[MAX];
} Lista;

void inicializarLista(Lista *lista) {
    lista->tamanho = 0;
}

void imprimirLista(Lista *lista) {
    printf("Show:\n");
    for (int i = 0; i < lista->tamanho; i++) {
        Aluno aluno = lista->dados[i];
        printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, CPF: %s\n", aluno.id, aluno.nome, aluno.matricula, aluno.idade, aluno.cpf);
    }
}

int inserirNoInicio(Lista *lista, Aluno aluno) {
    if (lista->tamanho >= MAX) {
        return 0;
    }

    if (lista->tamanho != 0) {
        for (int i = lista->tamanho; i > 0; i--) {
            lista->dados[i] = lista->dados[i-1];
        }
    }

    lista->dados[0] = aluno;
    lista->tamanho++;

    return 1;
}

int inserirNoFinal(Lista *lista, Aluno aluno) {
    if (lista->tamanho >= MAX) {
        return 0;
    }

    lista->dados[lista->tamanho] = aluno;
    lista->tamanho++;

    return 1;
}

int inserirEmPosicao(Lista *lista, Aluno aluno, int posicao) {
    if (lista->tamanho >= MAX) {
        return 0;
    }

    if (posicao > lista->tamanho || posicao < 0) {
        return 0;
    }

    if (posicao == lista->tamanho) {
        inserirNoFinal(lista, aluno);
        return 1;
    }

    if (posicao == 0) {
        inserirNoInicio(lista, aluno);
        return 1;
    }

    for (int i = lista->tamanho; i > posicao; i --) {
        lista->dados[i] = lista->dados[i-1];
    }

    lista->dados[posicao] = aluno;
    lista->tamanho++;
    return 1;
}

int removerNoInicio(Lista *lista) {
    for (int i = 0; i < lista->tamanho ;i++) {
        lista->dados[i] = lista->dados[i+1];
    }

    lista->tamanho--;
    return 1;
}

int removerNoFinal(Lista *lista) {
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

    for (int i = posicao; i < lista->tamanho; i++) {
        lista->dados[i] = lista->dados[i+1];
    }

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
    for (int i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->dados[i].cpf, cpf) == 0) {
            return 1;
        }
    }

    return 0;
}

Aluno recuperarPorPosicao(Lista *lista, int posicao) {
    Aluno alunoReturn = {};
    if (posicao > lista->tamanho || posicao < 0) {
        return alunoReturn;
    }

    alunoReturn = lista->dados[posicao];

    return alunoReturn;
}

int limparLista(Lista *lista) {
    lista->tamanho = 0;
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

*/


//2. Implemente uma Lista a partir de um vetor dinâmico, considerando todos os métodos da interface da lista descrita.

/*

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

typedef struct {
    int tamanho;
    int capacidade;
    Aluno *dados;
} Lista;

void aumentarCapacidade(Lista *lista) {
    int adicionaCapacidade = 2;
    int novaTamanho = sizeof(Aluno) * adicionaCapacidade;

    Aluno *alunos;
    alunos = lista->dados;

    Aluno *realocando = realloc(alunos, novaTamanho + sizeof(lista->tamanho));
    if (realloc == NULL) {
        printf("Erro: n tem memoria");
        exit(1);
    }

    lista->dados = realocando;
    lista->capacidade += adicionaCapacidade;
    free(alunos);
}

void inicializarLista(Lista *lista) {
    lista->tamanho = 0;
    lista->capacidade = 10;
    lista->dados = malloc(lista->capacidade * sizeof(Aluno));

    if (lista->dados == NULL) {
        printf("Erro ao iniciar lista");
    }
}

void imprimirLista(Lista *lista) {
    printf("Show:\n");
    for (int i = 0; i < lista->tamanho; i++) {
        Aluno aluno = lista->dados[i];
        printf("ID: %d, Nome: %s, Matricula: %s, Idade: %d, CPF: %s\n", aluno.id, aluno.nome, aluno.matricula, aluno.idade, aluno.cpf);
    }
}

int inserirNoInicio(Lista *lista, Aluno aluno) {
    if (lista->tamanho >= lista->capacidade) {
        aumentarCapacidade(lista);
    }

    if (lista->tamanho != 0) {
        for (int i = lista->tamanho; i > 0; i--) {
            lista->dados[i] = lista->dados[i-1];
        }
    }

    lista->dados[0] = aluno;
    lista->tamanho++;

    return 1;
}

int inserirNoFinal(Lista *lista, Aluno aluno) {
    if (lista->tamanho >= lista->capacidade) {
        aumentarCapacidade(lista);
    }

    lista->dados[lista->tamanho] = aluno;
    lista->tamanho++;

    return 1;
}

int inserirEmPosicao(Lista *lista, Aluno aluno, int posicao) {
    if (lista->tamanho >= lista->capacidade) {
        aumentarCapacidade(lista);
    }

    if (posicao > lista->tamanho || posicao < 0) {
        return 0;
    }

    if (posicao == lista->tamanho) {
        inserirNoFinal(lista, aluno);
        return 1;
    }

    if (posicao == 0) {
        inserirNoInicio(lista, aluno);
        return 1;
    }

    for (int i = lista->tamanho; i > posicao; i --) {
        lista->dados[i] = lista->dados[i-1];
    }

    lista->dados[posicao] = aluno;
    lista->tamanho++;
    return 1;
}

int removerNoInicio(Lista *lista) {
    for (int i = 0; i < lista->tamanho ;i++) {
        lista->dados[i] = lista->dados[i+1];
    }

    lista->tamanho--;
    return 1;
}

int removerNoFinal(Lista *lista) {
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

    for (int i = posicao; i < lista->tamanho; i++) {
        lista->dados[i] = lista->dados[i+1];
    }

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
    for (int i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->dados[i].cpf, cpf) == 0) {
            return 1;
        }
    }

    return 0;
}

Aluno recuperarPorPosicao(Lista *lista, int posicao) {
    Aluno alunoReturn = {};
    if (posicao > lista->tamanho || posicao < 0) {
        return alunoReturn;
    }

    alunoReturn = lista->dados[posicao];

    return alunoReturn;
}

int limparLista(Lista *lista) {
    lista->tamanho = 0;
    free(lista->dados);
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

*/


//3. Implemente uma Lista encadeada simples considerando todos os métodos da interface da lista descrita.

/*

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

    lista->inicio = novo;

    if (lista->tamanho == 0) {
        lista->fim = novo;
    }

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

    if (lista->tamanho == 0) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->proximo = novo;
        lista->fim = novo;
    }

    lista->tamanho++;

    return 1;
}

No* obterNoAnterior(Lista *lista, int posicao) {
    if(posicao <= 0 || posicao > lista->tamanho)
        return NULL;
    
    No *atual = lista->inicio;

    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    return atual;
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

    No *anterior = obterNoAnterior(lista, posicao);
    if (anterior == NULL) {
        return 0;
    }

    No *novo = malloc(sizeof(No));
    if(novo == NULL) {
        return 0;
    }

    novo->dado = aluno;

    novo->proximo = anterior->proximo;
    anterior->proximo = novo;

    lista->tamanho++;

    return 1;
}

int removerNoInicio(Lista *lista) {

    if (lista->inicio == NULL) {
        return 0;
    }

    No *remover = lista->inicio;

    lista->inicio = remover->proximo;

    if (lista->inicio == NULL) {
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

    No *anterior = obterNoAnterior(lista, lista->tamanho-1);
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

    No *anterior = obterNoAnterior(lista, posicao);

    No *remover = anterior->proximo;

    anterior->proximo = remover->proximo;

    free(remover);

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

    alunoReturn = obterNoAnterior(lista, posicao)->proximo->dado;

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

*/


//4. Implemente uma Lista encadeada dupla considerando todos os métodos da interface da lista descrita.

/*

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

*/

//5. Tomando como base uma das listas implementadas, implemente uma fila com as funcionalidades: void enqueue(Aluno aluno), Aluno dequeue(), Aluno front(), int isEmpty(), int size() e int clear(). 

/*

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

*/

//6. Tomando como base uma das listas implementadas, implemente uma pilha com os métodos/funções: void push(Aluno aluno), Aluno pop(), Aluno peak(), int inEmpty() e int size().

/*

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

*/

//1340 - Eu Posso Adivinhar a Estrutura de Dados!

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1001

typedef struct {
    int data[MAXN];
    int top;
} Stack;

void stack_init(Stack *s) { 
    s->top = -1; 
}
void stack_push(Stack *s, int x) { 
    s->data[++s->top] = x; 
}
int  stack_pop (Stack *s) { 
    return (s->top < 0) ? -1 : s->data[s->top--]; 
}

typedef struct {
    int data[MAXN];
    int head, tail;
} Queue;

void queue_init(Queue *q) { 
    q->head = q->tail = 0; 
}
void queue_push(Queue *q, int x) {
    q->data[q->tail++] = x; 
}
int  queue_pop (Queue *q) { 
    return (q->head == q->tail) ? -1 : q->data[q->head++]; 
}

typedef struct {
    int data[MAXN];
    int size;
} MaxHeap;

void heap_init(MaxHeap *h) { 
    h->size = 0; 
}

void heap_push(MaxHeap *h, int x) {
    int i = h->size++;
    h->data[i] = x;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p] < h->data[i]) {
            int tmp = h->data[p]; h->data[p] = h->data[i]; h->data[i] = tmp;
            i = p;
        } else break;
    }
}

int heap_pop(MaxHeap *h) {
    if (h->size == 0) return -1;
    int ret = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, largest = i;
        if (l < h->size && h->data[l] > h->data[largest]) largest = l;
        if (r < h->size && h->data[r] > h->data[largest]) largest = r;
        if (largest == i) break;
        int tmp = h->data[i]; h->data[i] = h->data[largest]; h->data[largest] = tmp;
        i = largest;
    }
    return ret;
}

int main(void) {
    int n;
    while (scanf("%d", &n) == 1) {

        Stack   stk;  stack_init(&stk);
        Queue   que;  queue_init(&que);
        MaxHeap heap; heap_init(&heap);

        int ok_stack = 1, ok_queue = 1, ok_heap = 1;

        for (int i = 0; i < n; i++) {
            int op;
            scanf("%d", &op);

            if (op == 1) {
                int x;
                scanf("%d", &x);
                stack_push(&stk,  x);
                queue_push(&que,  x);
                heap_push (&heap, x);
            } else {               
                int x;
                scanf("%d", &x);

                if (stack_pop(&stk)  != x) ok_stack = 0;
                if (queue_pop(&que)  != x) ok_queue = 0;
                if (heap_pop (&heap) != x) ok_heap  = 0;
            }
        }

        int count = ok_stack + ok_queue + ok_heap;

        if (count == 0)      puts("impossible");
        else if (count > 1)  puts("not sure");
        else if (ok_stack)   puts("stack");
        else if (ok_queue)   puts("queue");
        else                 puts("priority queue");
    }
    return 0;
}

*/

//1523 - Estacionamento Linear

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10001
#define MAXK 1001

typedef struct {
    int data[MAXK];
    int top; 
} Stack;

void stk_init(Stack *s)         { s->top = -1; }
int  stk_size(Stack *s)         { return s->top + 1; }
int  stk_full(Stack *s, int k)  { return s->top + 1 >= k; }
int  stk_empty(Stack *s)        { return s->top < 0; }
void stk_push(Stack *s, int id) { s->data[++s->top] = id; }
int  stk_top (Stack *s)         { return s->data[s->top]; }
void stk_pop (Stack *s)         { s->top--; }

typedef struct {
    int time;
    int type; 
    int id;   
} Event;

int cmp_event(const void *a, const void *b) {
    const Event *ea = (const Event *)a;
    const Event *eb = (const Event *)b;
    if (ea->time != eb->time) return ea->time - eb->time;

    return ea->type - eb->type;
}

int main(void) {
    int N, K;
    while (scanf("%d %d", &N, &K) == 2 && (N || K)) {

        int C[MAXN], S[MAXN];
        for (int i = 0; i < N; i++)
            scanf("%d %d", &C[i], &S[i]);

        Event ev[2 * MAXN];
        for (int i = 0; i < N; i++) {
            ev[2*i]   = (Event){ C[i], 1, i }; 
            ev[2*i+1] = (Event){ S[i], 0, i }; 
        }
        qsort(ev, 2*N, sizeof(Event), cmp_event);

        Stack park;
        stk_init(&park);

        int parked[MAXN];
        memset(parked, 0, sizeof(parked));

        int ok = 1;

        for (int e = 0; e < 2*N && ok; e++) {
            int id   = ev[e].id;
            int type = ev[e].type;

            if (type == 1) {
                
                if (stk_full(&park, K)) {
                    ok = 0;
                    break;
                }
                stk_push(&park, id);
                parked[id] = 1;
            } else {

                if (stk_empty(&park) || stk_top(&park) != id) {
                    ok = 0;
                    break;
                }
                stk_pop(&park);
                parked[id] = 0;
            }
        }

        puts(ok ? "Sim" : "Nao");
    }
    return 0;
}
*/
