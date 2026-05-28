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

int removerirNoInicio(Lista *lista) {
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
    if (posicao > lista->tamanho || posicao < 0) {
        return 0;
    }

    if (posicao == 0) {
        removerirNoInicio(lista);
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

    removerirNoInicio(&lista);
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