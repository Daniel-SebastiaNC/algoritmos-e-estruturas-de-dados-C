#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    char placa[8];
    char marca[20];
    char modelo[20];
} Carro;

typedef struct {
    Carro dados[MAX];
    int tamanho;
} Lista;

void imprimirtLista(Lista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("index = %d | placa = %s | marca = %s | modelo = %s\n",
        i,
        lista->dados[i].placa,
        lista->dados[i].marca,
        lista->dados[i].modelo
    );
    }
    printf("\n");
}

void inicializacaoLista(Lista *lista) {
    lista->tamanho = 0;
}

int adicionarNoFinal(Lista *lista, Carro carro) {
    if (lista->tamanho >= MAX) {
        return 0;
    }

    lista->dados[lista->tamanho] = carro;
    lista->tamanho++;

    return 1;
}

int insercaoPosicao(Lista *lista, int posicao, Carro c) {
    if (lista->tamanho >= MAX) {
        return 0;
    }

    if (posicao < 0 || posicao > lista->tamanho){
        return 0;
    }

    for (int i = lista->tamanho; i > posicao; i--) {
        lista->dados[i] = lista->dados[i-1];
    }
    
    lista->dados[posicao] = c;
    lista->tamanho++;
    return 1;
}

int remocaocaoPosicao(Lista *lista, int posicao) {
    if (lista->tamanho - 1 >= MAX) {
        return 0;
    }

    if (posicao < 0 || posicao >= lista->tamanho){
        return 0;
    }

    for (int i = posicao; i < lista->tamanho -1; i++) {
        lista->dados[i] = lista->dados[i+1];
    }
    
    lista->tamanho--;
    return 1;
}

int tamanhoLista(Lista *Lista) {
    return Lista->tamanho;
}

int busca(Lista *lista, char texto[], char tipo) {
    for (int i = 0; i < lista->tamanho; i++) {
        int encontrou = 0; 

        if (tipo == 'p') {
            encontrou = (strcasecmp(lista->dados[i].placa, texto) == 0);
        } 
        else if (tipo == 'a') {
            encontrou = (strcasecmp(lista->dados[i].marca, texto) == 0);
        } 
        else { 
            encontrou = (strcasecmp(lista->dados[i].modelo, texto) == 0);
        }

        if (encontrou) {
            return 1;
        }
    }

    return 0; 
}

Carro buscarindice(Lista *lista, int indice){
    Carro vazio = {"", "", ""};

    if (indice > lista->tamanho || indice < 0) {
        return vazio;
    }

    return lista->dados[indice];
    
}

int main() {
    Lista lista;
    inicializacaoLista(&lista);

    Carro c1 = {"1", "ford", "grande"};
    Carro c2 = {"2", "ford", "grande"};
    Carro c3 = {"3", "ford", "grande"};

    adicionarNoFinal(&lista, c1);
    adicionarNoFinal(&lista, c3);

    printf("Tamanho da lista: %d \n", tamanhoLista(&lista));

    imprimirtLista(&lista);

    insercaoPosicao(&lista, 1, c2);

    imprimirtLista(&lista);

    remocaocaoPosicao(&lista, 1);

    imprimirtLista(&lista);

    char placa[] = "1";
    printf("procurando a placa %s\n", placa);

    if (busca(&lista, placa, 'p')) {
        printf("Placa encontrada!\n");
    } else {
        printf("Placa nao encontrada!\n");
    }

    int indice = 1;
    printf("Buscando pelo indice %d", indice);

    Carro recuperado = buscarindice(&lista, indice);

    printf("Carro: \n");
    printf("placa = %s | marca = %s | modelo = %s\n",
        recuperado.placa,
        recuperado.marca,
        recuperado.modelo
    );
    return 0;
}