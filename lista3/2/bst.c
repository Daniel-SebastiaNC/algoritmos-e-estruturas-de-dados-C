#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq;
    struct No *dir;
} No;

No *criar_no(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        fprintf(stderr, "Erro: sem memoria.\n");
        exit(EXIT_FAILURE);
    }
    novo->dado = valor;
    novo->esq  = NULL;
    novo->dir  = NULL;
    return novo;
}

int altura_sub(No *raiz) {
    if (!raiz) return -1;
    int h_esq = altura_sub(raiz->esq);
    int h_dir = altura_sub(raiz->dir);
    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

No *maior(No *raiz) {
    while (raiz->dir) raiz = raiz->dir;
    return raiz;
}

No *menor(No *raiz) {
    while (raiz->esq) raiz = raiz->esq;
    return raiz;
}

No *inserir_rec(No *raiz, int valor) {
    if (!raiz) return criar_no(valor);

    if (valor < raiz->dado)
        raiz->esq = inserir_rec(raiz->esq, valor);
    else if (valor > raiz->dado)
        raiz->dir = inserir_rec(raiz->dir, valor);

    return raiz;
}

void bst_inserir(No **raiz, int valor) {
    *raiz = inserir_rec(*raiz, valor);
}

No *bst_buscar(No *raiz, int valor) {
    if (!raiz)             return NULL;
    if (valor == raiz->dado) return raiz;
    if (valor < raiz->dado)  return bst_buscar(raiz->esq, valor);
    return bst_buscar(raiz->dir, valor);
}

No *remover_rec(No *raiz, int valor) {
    if (!raiz) return NULL;  

    if (valor < raiz->dado) {
        raiz->esq = remover_rec(raiz->esq, valor);
    } else if (valor > raiz->dado) {
        raiz->dir = remover_rec(raiz->dir, valor);
    } else {

        if (!raiz->esq && !raiz->dir) {
            free(raiz);
            return NULL;
        }

        if (!raiz->esq) {
            No *tmp = raiz->dir;
            free(raiz);
            return tmp;
        }

        if (!raiz->dir) {
            No *tmp = raiz->esq;
            free(raiz);
            return tmp;
        }

        int h_esq = altura_sub(raiz->esq);
        int h_dir = altura_sub(raiz->dir);

        if (h_esq >= h_dir) {
            No *pred = maior(raiz->esq);
            raiz->dado = pred->dado;
            raiz->esq  = remover_rec(raiz->esq, pred->dado);
        } else {
            No *suc = menor(raiz->dir);
            raiz->dado = suc->dado;
            raiz->dir  = remover_rec(raiz->dir, suc->dado);
        }
    }

    return raiz;
}

void bst_remover(No **raiz, int valor) {
    *raiz = remover_rec(*raiz, valor);
}

int bst_altura(No *raiz) {
    return altura_sub(raiz);
}

int bst_profundidade(No *raiz, int valor) {
    int prof = 0;
    while (raiz) {
        if (valor == raiz->dado) return prof;
        if (valor < raiz->dado)  raiz = raiz->esq;
        else                     raiz = raiz->dir;
        prof++;
    }
    return -1;   
}

void bst_limpar(No **raiz) {
    if (!(*raiz)) return;
    bst_limpar(&(*raiz)->esq);
    bst_limpar(&(*raiz)->dir);
    free(*raiz);
    *raiz = NULL;
}

void imprimir_inorder(No *raiz) {
    if (!raiz) return;
    imprimir_inorder(raiz->esq);
    printf("%d ", raiz->dado);
    imprimir_inorder(raiz->dir);
}

int main(void) {
    No *arvore = NULL;

    printf("=== Inserindo: 25, 9, 32, 5, 15, 26, 54, 1, 7 ===\n");
    int valores[] = {25, 9, 32, 5, 15, 26, 54, 1, 7};
    int n = sizeof(valores) / sizeof(valores[0]);
    for (int i = 0; i < n; i++)
        bst_inserir(&arvore, valores[i]);

    printf("In-order: ");
    imprimir_inorder(arvore);
    printf("\n\n");

    printf("=== Altura da arvore: %d ===\n\n", bst_altura(arvore));

    int consultas[] = {25, 9, 7, 54, 99};
    printf("=== Profundidades ===\n");
    for (int i = 0; i < 5; i++) {
        int p = bst_profundidade(arvore, consultas[i]);
        if (p >= 0)
            printf("  profundidade(%d) = %d\n", consultas[i], p);
        else
            printf("  profundidade(%d) = nao encontrado (-1)\n", consultas[i]);
    }
    printf("\n");

    printf("=== Busca ===\n");
    No *encontrado = bst_buscar(arvore, 15);
    printf("  buscar(15): %s\n", encontrado ? "encontrado" : "NULL");
    encontrado = bst_buscar(arvore, 42);
    printf("  buscar(42): %s\n\n", encontrado ? "encontrado" : "NULL");

    printf("=== Removendo folha 1 ===\n");
    bst_remover(&arvore, 1);
    printf("In-order: ");
    imprimir_inorder(arvore);
    printf("\nAltura: %d\n\n", bst_altura(arvore));

    printf("=== Removendo no de grau 1: 5 (so tem filho 7) ===\n");
    bst_remover(&arvore, 5);
    printf("In-order: ");
    imprimir_inorder(arvore);
    printf("\nAltura: %d\n\n", bst_altura(arvore));

    printf("=== Removendo no de grau 2: 9 (h_esq == h_dir -> usa esquerda) ===\n");
    bst_remover(&arvore, 9);
    printf("In-order: ");
    imprimir_inorder(arvore);
    printf("\nAltura: %d\n\n", bst_altura(arvore));

    printf("=== Removendo raiz 25 (h_dir > h_esq -> usa direita) ===\n");
    bst_remover(&arvore, 25);
    printf("In-order: ");
    imprimir_inorder(arvore);
    printf("\nAltura: %d\n\n", bst_altura(arvore));

    printf("=== Limpando a arvore ===\n");
    bst_limpar(&arvore);
    printf("Arvore vazia: %s\n", arvore == NULL ? "sim" : "nao");
    printf("Altura: %d\n", bst_altura(arvore));

    return 0;
}