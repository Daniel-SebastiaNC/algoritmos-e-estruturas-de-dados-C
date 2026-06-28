package com.algoritmos;

/**
 * Implementação dos algoritmos de Ordenação:
 * Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort.
 *
 * Todos os métodos recebem uma CÓPIA do array para não modificar o original.
 */
public class Ordenacoes {

    // ─────────────────────────────────────────────
    // Bubble Sort — O(n²) médio/pior, O(n) melhor
    // ─────────────────────────────────────────────
    /**
     * Compara pares adjacentes e "borbulha" o maior para o final.
     * Complexidade: O(n²) — dois laços aninhados.
     */
    public static void bubbleSort(int[] v) {
        int n = v.length;
        for (int i = 0; i < n - 1; i++) {
            boolean trocou = false;
            for (int j = 0; j < n - 1 - i; j++) {
                if (v[j] > v[j + 1]) {
                    int tmp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = tmp;
                    trocou = true;
                }
            }
            if (!trocou) break; // otimização: já ordenado
        }
    }

    // ─────────────────────────────────────────────
    // Selection Sort — O(n²) sempre
    // ─────────────────────────────────────────────
    /**
     * Seleciona o mínimo da parte não ordenada e coloca na posição correta.
     * Complexidade: O(n²) — independente da entrada.
     */
    public static void selectionSort(int[] v) {
        int n = v.length;
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (v[j] < v[minIdx]) {
                    minIdx = j;
                }
            }
            int tmp = v[minIdx];
            v[minIdx] = v[i];
            v[i] = tmp;
        }
    }

    // ─────────────────────────────────────────────
    // Insertion Sort — O(n²) médio/pior, O(n) melhor
    // ─────────────────────────────────────────────
    /**
     * Insere cada elemento na posição correta dentro da parte já ordenada.
     * Complexidade: O(n²) — eficiente para entradas quase ordenadas.
     */
    public static void insertionSort(int[] v) {
        int n = v.length;
        for (int i = 1; i < n; i++) {
            int chave = v[i];
            int j = i - 1;
            while (j >= 0 && v[j] > chave) {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = chave;
        }
    }

    // ─────────────────────────────────────────────
    // Merge Sort — O(n log n) sempre
    // ─────────────────────────────────────────────
    /**
     * Divide e conquista: divide o array ao meio, ordena recursivamente
     * e mescla as duas metades ordenadas.
     * Complexidade: O(n log n) — estável e consistente.
     */
    public static void mergeSort(int[] v, int esq, int dir) {
        if (esq < dir) {
            int meio = esq + (dir - esq) / 2;
            mergeSort(v, esq, meio);
            mergeSort(v, meio + 1, dir);
            merge(v, esq, meio, dir);
        }
    }

    private static void merge(int[] v, int esq, int meio, int dir) {
        int n1 = meio - esq + 1;
        int n2 = dir - meio;

        int[] L = new int[n1];
        int[] R = new int[n2];

        System.arraycopy(v, esq, L, 0, n1);
        System.arraycopy(v, meio + 1, R, 0, n2);

        int i = 0, j = 0, k = esq;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) v[k++] = L[i++];
            else               v[k++] = R[j++];
        }
        while (i < n1) v[k++] = L[i++];
        while (j < n2) v[k++] = R[j++];
    }

    // ─────────────────────────────────────────────
    // Quick Sort — O(n log n) médio, O(n²) pior
    // ─────────────────────────────────────────────
    /**
     * Divide e conquista: escolhe um pivô e particiona o array ao redor dele.
     * Usa pivô mediana-de-três para minimizar chance do pior caso.
     * Complexidade: O(n log n) médio — O(n²) no pior caso (já ordenado com pivô fixo).
     */
    public static void quickSort(int[] v, int esq, int dir) {
        if (esq < dir) {
            int pi = particionar(v, esq, dir);
            quickSort(v, esq, pi - 1);
            quickSort(v, pi + 1, dir);
        }
    }

    private static int particionar(int[] v, int esq, int dir) {
        // Mediana de três para escolha do pivô
        int meio = esq + (dir - esq) / 2;
        if (v[esq] > v[meio])  trocar(v, esq, meio);
        if (v[esq] > v[dir])   trocar(v, esq, dir);
        if (v[meio] > v[dir])  trocar(v, meio, dir);
        trocar(v, meio, dir - 1);
        int pivo = v[dir - 1];

        int i = esq;
        int j = dir - 1;
        while (true) {
            while (v[++i] < pivo);
            while (j > esq && v[--j] > pivo);
            if (i >= j) break;
            trocar(v, i, j);
        }
        trocar(v, i, dir - 1);
        return i;
    }

    private static void trocar(int[] v, int a, int b) {
        int tmp = v[a]; v[a] = v[b]; v[b] = tmp;
    }
}