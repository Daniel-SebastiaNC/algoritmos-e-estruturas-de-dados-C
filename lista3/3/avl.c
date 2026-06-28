#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_MAX 100
#define CPF_MAX   15  

typedef struct {
    int  chave;
    char nome[NOME_MAX];
    char cpf[CPF_MAX];
} Estudante;

typedef struct No {
    Estudante   dados;
    int         altura;
    struct No  *esq;
    struct No  *dir;
} No;

int max2(int a, int b) { return a > b ? a : b; }

int altura(No *n) {
    return n ? n->altura : -1;
}

void atualizar_altura(No *n) {
    if (n)
        n->altura = 1 + max2(altura(n->esq), altura(n->dir));
}

int fb(No *n) {
    return n ? altura(n->esq) - altura(n->dir) : 0;
}

No *criar_no(Estudante e) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) { fprintf(stderr, "Sem memoria.\n"); exit(EXIT_FAILURE); }
    novo->dados  = e;
    novo->altura = 0;
    novo->esq    = NULL;
    novo->dir    = NULL;
    return novo;
}

No *rotacionar_direita(No *y) {
    No *x  = y->esq;
    No *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    atualizar_altura(y);
    atualizar_altura(x);
    return x;
}

No *rotacionar_esquerda(No *x) {
    No *y  = x->dir;
    No *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    atualizar_altura(x);
    atualizar_altura(y);
    return y;
}

No *rebalancear(No *n) {
    atualizar_altura(n);
    int f = fb(n);

    if (f > 1) {
        if (fb(n->esq) >= 0) {
            return rotacionar_direita(n);
        } else {
            n->esq = rotacionar_esquerda(n->esq);
            return rotacionar_direita(n);
        }
    }

    if (f < -1) {
        if (fb(n->dir) <= 0) {
            return rotacionar_esquerda(n);
        } else {
            n->dir = rotacionar_direita(n->dir);
            return rotacionar_esquerda(n);
        }
    }

    return n;   
}

No *inserir_rec(No *raiz, Estudante e) {
    if (!raiz) return criar_no(e);

    if (e.chave < raiz->dados.chave)
        raiz->esq = inserir_rec(raiz->esq, e);
    else if (e.chave > raiz->dados.chave)
        raiz->dir = inserir_rec(raiz->dir, e);
    else {
        raiz->dados = e;
        return raiz;
    }

    return rebalancear(raiz);
}

void avl_inserir(No **raiz, Estudante e) {
    *raiz = inserir_rec(*raiz, e);
}

Estudante *avl_buscar(No *raiz, int chave) {
    if (!raiz)               return NULL;
    if (chave == raiz->dados.chave) return &raiz->dados;
    if (chave  < raiz->dados.chave) return avl_buscar(raiz->esq, chave);
    return avl_buscar(raiz->dir, chave);
}

No *minimo(No *n) {
    while (n->esq) n = n->esq;
    return n;
}

No *remover_rec(No *raiz, int chave) {
    if (!raiz) return NULL;

    if (chave < raiz->dados.chave) {
        raiz->esq = remover_rec(raiz->esq, chave);
    } else if (chave > raiz->dados.chave) {
        raiz->dir = remover_rec(raiz->dir, chave);
    } else {
        if (!raiz->esq || !raiz->dir) {
            No *filho = raiz->esq ? raiz->esq : raiz->dir;
            free(raiz);
            return filho;   
        }
        No *suc    = minimo(raiz->dir);
        raiz->dados = suc->dados;
        raiz->dir   = remover_rec(raiz->dir, suc->dados.chave);
    }

    return rebalancear(raiz);
}

void avl_remover(No **raiz, int chave) {
    *raiz = remover_rec(*raiz, chave);
}

void imprimir_inorder(No *raiz) {
    if (!raiz) return;
    imprimir_inorder(raiz->esq);
    printf("  [chave=%d | nome=%-20s | CPF=%s | h=%d | FB=%+d]\n",
           raiz->dados.chave, raiz->dados.nome, raiz->dados.cpf,
           raiz->altura, fb(raiz));
    imprimir_inorder(raiz->dir);
}

void avl_imprimir(No *raiz) {
    if (!raiz) { printf("  (arvore vazia)\n"); return; }
    imprimir_inorder(raiz);
}

void avl_limpar(No **raiz) {
    if (!(*raiz)) return;
    avl_limpar(&(*raiz)->esq);
    avl_limpar(&(*raiz)->dir);
    free(*raiz);
    *raiz = NULL;
}

Estudante est(int chave, const char *nome, const char *cpf) {
    Estudante e;
    e.chave = chave;
    strncpy(e.nome, nome, NOME_MAX - 1); e.nome[NOME_MAX - 1] = '\0';
    strncpy(e.cpf,  cpf,  CPF_MAX  - 1); e.cpf[CPF_MAX  - 1] = '\0';
    return e;
}

int main(void) {
    No *avl = NULL;

    printf("=== Inserindo estudantes (ordem que provoca rotacoes) ===\n");
    avl_inserir(&avl, est(50, "Alice",   "111.111.111-11"));
    avl_inserir(&avl, est(30, "Bruno",   "222.222.222-22"));
    avl_inserir(&avl, est(70, "Carla",   "333.333.333-33"));
    avl_inserir(&avl, est(20, "Diego",   "444.444.444-44"));
    avl_inserir(&avl, est(40, "Eduarda", "555.555.555-55"));
    avl_inserir(&avl, est(60, "Felipe",  "666.666.666-66"));
    avl_inserir(&avl, est(80, "Gabi",    "777.777.777-77"));

    avl_inserir(&avl, est(10, "Hugo",    "888.888.888-88"));
    avl_inserir(&avl, est(90, "Iris",    "999.999.999-99"));
    avl_inserir(&avl, est(35, "Jonas",   "000.000.000-00"));
    avl_inserir(&avl, est(65, "Karen",   "123.456.789-09"));

    printf("\nIn-order (deve estar em ordem crescente de chave):\n");
    avl_imprimir(avl);
    printf("Altura da raiz: %d\n\n", altura(avl));

    printf("=== Busca ===\n");
    Estudante *encontrado;

    encontrado = avl_buscar(avl, 40);
    if (encontrado)
        printf("  buscar(40): nome=%s, CPF=%s\n",
               encontrado->nome, encontrado->cpf);
    else
        printf("  buscar(40): NULL\n");

    encontrado = avl_buscar(avl, 99);
    printf("  buscar(99): %s\n\n", encontrado ? "encontrado" : "NULL");

    printf("=== Removendo folha (chave=10) ===\n");
    avl_remover(&avl, 10);
    avl_imprimir(avl);
    printf("Altura da raiz: %d\n\n", altura(avl));

    printf("=== Removendo no com um filho (chave=20) ===\n");
    avl_remover(&avl, 20);
    avl_imprimir(avl);
    printf("Altura da raiz: %d\n\n", altura(avl));

    printf("=== Removendo no com dois filhos (chave=30) ===\n");
    avl_remover(&avl, 30);
    avl_imprimir(avl);
    printf("Altura da raiz: %d\n\n", altura(avl));

    printf("=== Removendo raiz (chave=50) ===\n");
    avl_remover(&avl, 50);
    avl_imprimir(avl);
    printf("Altura da raiz: %d\n\n", altura(avl));

    printf("=== Removendo chave inexistente (chave=42) ===\n");
    avl_remover(&avl, 42);
    avl_imprimir(avl);
    printf("\n");

    avl_limpar(&avl);
    printf("=== Apos limpar ===\n");
    avl_imprimir(avl);

    return 0;
}