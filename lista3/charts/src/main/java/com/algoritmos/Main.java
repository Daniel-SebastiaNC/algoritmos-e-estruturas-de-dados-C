package com.algoritmos;

import java.io.IOException;
import java.util.*;

/**
 * Classe principal — executa todos os experimentos e gera os gráficos.
 *
 * Parte A: Busca Linear vs Busca Binária
 * Parte B: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort
 */
public class Main {

    // Tamanhos dos vetores: pequeno, médio, grande
    private static final int[] TAMANHOS_BUSCA = {
            1_000, 5_000, 10_000, 50_000,
            100_000, 500_000, 1_000_000
    };

    private static final int[] TAMANHOS_ORDENACAO = {
            500, 1_000, 2_500, 5_000,
            10_000, 25_000, 50_000, 100_000
    };

    // Número de repetições para média mais estável
    private static final int REPETICOES = 5;

    public static void main(String[] args) throws IOException {
        System.out.println("==============================================");
        System.out.println("  Análise Empírica de Algoritmos — Java");
        System.out.println("  Medição com System.nanoTime()");
        System.out.println("  Gráficos com JFreeChart 1.5.4");
        System.out.println("==============================================\n");

        parteA_Buscas();
        parteB_Ordenacoes();

        System.out.println("\n✔ Todos os experimentos concluídos!");
    }

    // ══════════════════════════════════════════════
    //  PARTE A — Buscas
    // ══════════════════════════════════════════════
    static void parteA_Buscas() throws IOException {
        System.out.println("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
        System.out.println("  PARTE A — Busca Linear vs Busca Binária");
        System.out.println("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

        // Pontos para o gráfico: [tamanho][tempo_ms]
        double[][] dadosLinear  = new double[TAMANHOS_BUSCA.length][2];
        double[][] dadosBinaria = new double[TAMANHOS_BUSCA.length][2];

        System.out.printf("%-12s  %-18s  %-18s%n",
                "Tamanho", "Linear (ms)", "Binária (ms)");
        System.out.println("-".repeat(52));

        for (int idx = 0; idx < TAMANHOS_BUSCA.length; idx++) {
            int n = TAMANHOS_BUSCA[idx];
            int[] vetor = gerarVetorOrdenado(n);

            // Busca no PIOR CASO: elemento inexistente (força varredura completa)
            int alvo = n + 1;

            Cronometro cr = new Cronometro();

            // Busca Linear
            long totalLinear = 0;
            for (int r = 0; r < REPETICOES; r++) {
                cr.iniciar();
                Buscas.buscaLinear(vetor, alvo);
                cr.parar();
                totalLinear += cr.getTotalNanos();
            }
            double msLinear = (totalLinear / REPETICOES) / 1_000_000.0;

            // Busca Binária
            long totalBinaria = 0;
            for (int r = 0; r < REPETICOES; r++) {
                cr.iniciar();
                Buscas.buscaBinaria(vetor, alvo);
                cr.parar();
                totalBinaria += cr.getTotalNanos();
            }
            double msBinaria = (totalBinaria / REPETICOES) / 1_000_000.0;

            dadosLinear[idx]  = new double[]{n, msLinear};
            dadosBinaria[idx] = new double[]{n, msBinaria};

            System.out.printf("%-12d  %-18.4f  %-18.6f%n", n, msLinear, msBinaria);
        }

        // Gera gráfico
        Map<String, double[][]> series = new LinkedHashMap<>();
        series.put("Busca Linear — O(n)",    dadosLinear);
        series.put("Busca Binária — O(log n)", dadosBinaria);

        GeradorGraficos.gerarGrafico(
                "Busca Linear vs Busca Binária (pior caso)",
                "Tamanho do Vetor (n)",
                "Tempo de Execução (ms)",
                series,
                "grafico_buscas.png"
        );

        // Gráfico adicional só da binária (escala visível)
        Map<String, double[][]> seriesBin = new LinkedHashMap<>();
        seriesBin.put("Busca Binária — O(log n)", dadosBinaria);
        GeradorGraficos.gerarGrafico(
                "Busca Binária — Detalhe (pior caso)",
                "Tamanho do Vetor (n)",
                "Tempo de Execução (ms)",
                seriesBin,
                "grafico_busca_binaria_detalhe.png"
        );
    }

    // ══════════════════════════════════════════════
    //  PARTE B — Ordenações
    // ══════════════════════════════════════════════
    static void parteB_Ordenacoes() throws IOException {
        System.out.println("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
        System.out.println("  PARTE B — Algoritmos de Ordenação");
        System.out.println("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

        int n = TAMANHOS_ORDENACAO.length;
        double[][] dadosBubble    = new double[n][2];
        double[][] dadosSelection = new double[n][2];
        double[][] dadosInsertion = new double[n][2];
        double[][] dadosMerge     = new double[n][2];
        double[][] dadosQuick     = new double[n][2];

        System.out.printf("%-8s  %-12s  %-12s  %-12s  %-12s  %-12s%n",
                "N", "Bubble(ms)", "Select(ms)", "Insert(ms)", "Merge(ms)", "Quick(ms)");
        System.out.println("-".repeat(74));

        Cronometro cr = new Cronometro();

        for (int idx = 0; idx < n; idx++) {
            int tam = TAMANHOS_ORDENACAO[idx];

            long tBubble = 0, tSelection = 0, tInsertion = 0, tMerge = 0, tQuick = 0;

            for (int r = 0; r < REPETICOES; r++) {
                int[] base = gerarVetorAleatorio(tam);

                // Bubble Sort
                int[] v = Arrays.copyOf(base, tam);
                cr.iniciar(); Ordenacoes.bubbleSort(v); cr.parar();
                tBubble += cr.getTotalNanos();

                // Selection Sort
                v = Arrays.copyOf(base, tam);
                cr.iniciar(); Ordenacoes.selectionSort(v); cr.parar();
                tSelection += cr.getTotalNanos();

                // Insertion Sort
                v = Arrays.copyOf(base, tam);
                cr.iniciar(); Ordenacoes.insertionSort(v); cr.parar();
                tInsertion += cr.getTotalNanos();

                // Merge Sort
                v = Arrays.copyOf(base, tam);
                cr.iniciar(); Ordenacoes.mergeSort(v, 0, v.length - 1); cr.parar();
                tMerge += cr.getTotalNanos();

                // Quick Sort (protege de StackOverflow com vetor grande quase ordenado)
                v = Arrays.copyOf(base, tam);
                cr.iniciar(); Ordenacoes.quickSort(v, 0, v.length - 1); cr.parar();
                tQuick += cr.getTotalNanos();
            }

            double msBubble    = (tBubble    / REPETICOES) / 1_000_000.0;
            double msSelection = (tSelection / REPETICOES) / 1_000_000.0;
            double msInsertion = (tInsertion / REPETICOES) / 1_000_000.0;
            double msMerge     = (tMerge     / REPETICOES) / 1_000_000.0;
            double msQuick     = (tQuick     / REPETICOES) / 1_000_000.0;

            dadosBubble[idx]    = new double[]{tam, msBubble};
            dadosSelection[idx] = new double[]{tam, msSelection};
            dadosInsertion[idx] = new double[]{tam, msInsertion};
            dadosMerge[idx]     = new double[]{tam, msMerge};
            dadosQuick[idx]     = new double[]{tam, msQuick};

            System.out.printf("%-8d  %-12.2f  %-12.2f  %-12.2f  %-12.4f  %-12.4f%n",
                    tam, msBubble, msSelection, msInsertion, msMerge, msQuick);
        }

        // Gráfico 1: todos os algoritmos
        Map<String, double[][]> todos = new LinkedHashMap<>();
        todos.put("Bubble Sort — O(n²)",    dadosBubble);
        todos.put("Selection Sort — O(n²)", dadosSelection);
        todos.put("Insertion Sort — O(n²)", dadosInsertion);
        todos.put("Merge Sort — O(n log n)", dadosMerge);
        todos.put("Quick Sort — O(n log n)", dadosQuick);

        GeradorGraficos.gerarGrafico(
                "Comparação: Todos os Algoritmos de Ordenação",
                "Tamanho do Vetor (n)",
                "Tempo de Execução (ms)",
                todos,
                "grafico_ordenacoes_todos.png"
        );

        // Gráfico 2: somente O(n log n)
        Map<String, double[][]> eficientes = new LinkedHashMap<>();
        eficientes.put("Merge Sort — O(n log n)", dadosMerge);
        eficientes.put("Quick Sort — O(n log n)", dadosQuick);

        GeradorGraficos.gerarGrafico(
                "Merge Sort vs Quick Sort — O(n log n)",
                "Tamanho do Vetor (n)",
                "Tempo de Execução (ms)",
                eficientes,
                "grafico_merge_vs_quick.png"
        );

        // Gráfico 3: somente O(n²)
        Map<String, double[][]> quadraticos = new LinkedHashMap<>();
        quadraticos.put("Bubble Sort — O(n²)",    dadosBubble);
        quadraticos.put("Selection Sort — O(n²)", dadosSelection);
        quadraticos.put("Insertion Sort — O(n²)", dadosInsertion);

        GeradorGraficos.gerarGrafico(
                "Algoritmos O(n²) — Detalhe",
                "Tamanho do Vetor (n)",
                "Tempo de Execução (ms)",
                quadraticos,
                "grafico_on2_detalhe.png"
        );
    }

    // ══════════════════════════════════════════════
    //  Utilitários
    // ══════════════════════════════════════════════
    private static int[] gerarVetorOrdenado(int n) {
        int[] v = new int[n];
        for (int i = 0; i < n; i++) v[i] = i + 1;
        return v;
    }

    private static int[] gerarVetorAleatorio(int n) {
        Random rnd = new Random(42); // semente fixa para reprodutibilidade
        int[] v = new int[n];
        for (int i = 0; i < n; i++) v[i] = rnd.nextInt(n * 10);
        return v;
    }
}