package com.algoritmos;

/**
 * Utilitário para medir o tempo de execução de algoritmos.
 * Utiliza System.nanoTime() para alta precisão.
 */
public class Cronometro {

    private long inicio;
    private long fim;

    /** Registra o instante de início da execução. */
    public void iniciar() {
        this.inicio = System.nanoTime();
    }

    /** Registra o instante de término da execução. */
    public void parar() {
        this.fim = System.nanoTime();
    }

    /** @return tempo total em nanossegundos */
    public long getTotalNanos() {
        return fim - inicio;
    }

    /** @return tempo total em milissegundos */
    public double getTotalMillis() {
        return (fim - inicio) / 1_000_000.0;
    }

    /** @return tempo total em microssegundos */
    public double getTotalMicros() {
        return (fim - inicio) / 1_000.0;
    }

    @Override
    public String toString() {
        double ms = getTotalMillis();
        if (ms < 1.0) {
            return String.format("%.3f µs", getTotalMicros());
        } else if (ms < 1000.0) {
            return String.format("%.3f ms", ms);
        } else {
            return String.format("%.3f s", ms / 1000.0);
        }
    }
}