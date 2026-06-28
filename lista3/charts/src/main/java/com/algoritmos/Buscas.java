package com.algoritmos;

/**
 * Implementação dos algoritmos de Busca Linear e Busca Binária.
 */
public class Buscas {

    /**
     * Busca Linear — O(n)
     * Percorre o vetor sequencialmente até encontrar o elemento.
     *
     * @param vetor vetor de inteiros (não precisa estar ordenado)
     * @param alvo  elemento a ser buscado
     * @return índice do elemento, ou -1 se não encontrado
     */
    public static int buscaLinear(int[] vetor, int alvo) {
        for (int i = 0; i < vetor.length; i++) {
            if (vetor[i] == alvo) {
                return i;
            }
        }
        return -1;
    }

    /**
     * Busca Binária — O(log n)
     * Requer vetor ordenado. A cada passo descarta metade do espaço de busca.
     *
     * @param vetor vetor de inteiros ORDENADO
     * @param alvo  elemento a ser buscado
     * @return índice do elemento, ou -1 se não encontrado
     */
    public static int buscaBinaria(int[] vetor, int alvo) {
        int esquerda = 0;
        int direita = vetor.length - 1;

        while (esquerda <= direita) {
            int meio = esquerda + (direita - esquerda) / 2;

            if (vetor[meio] == alvo) {
                return meio;
            } else if (vetor[meio] < alvo) {
                esquerda = meio + 1;
            } else {
                direita = meio - 1;
            }
        }
        return -1;
    }
}