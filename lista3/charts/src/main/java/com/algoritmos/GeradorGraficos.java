package com.algoritmos;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.axis.NumberAxis;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.chart.plot.XYPlot;
import org.jfree.chart.renderer.xy.XYLineAndShapeRenderer;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;
import org.jfree.chart.ChartUtils;

import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.util.Map;

/**
 * Gerador de gráficos de linha usando JFreeChart.
 * Salva os gráficos como arquivos PNG.
 */
public class GeradorGraficos {

    private static final int LARGURA  = 900;
    private static final int ALTURA   = 550;

    /**
     * Gera um gráfico de linha comparando séries de dados.
     *
     * @param titulo     título do gráfico
     * @param eixoX      rótulo do eixo X
     * @param eixoY      rótulo do eixo Y
     * @param series     mapa de nome → pares (tamanho, tempo)
     * @param arquivo    caminho de saída (.png)
     */
    public static void gerarGrafico(
            String titulo,
            String eixoX,
            String eixoY,
            Map<String, double[][]> series,
            String arquivo
    ) throws IOException {

        XYSeriesCollection dataset = new XYSeriesCollection();

        for (Map.Entry<String, double[][]> entry : series.entrySet()) {
            XYSeries s = new XYSeries(entry.getKey());
            double[][] pontos = entry.getValue();
            for (double[] ponto : pontos) {
                s.add(ponto[0], ponto[1]);
            }
            dataset.addSeries(s);
        }

        JFreeChart chart = ChartFactory.createXYLineChart(
                titulo, eixoX, eixoY,
                dataset,
                PlotOrientation.VERTICAL,
                true, true, false
        );

        // Estilo
        chart.setBackgroundPaint(Color.WHITE);
        XYPlot plot = chart.getXYPlot();
        plot.setBackgroundPaint(new Color(245, 245, 250));
        plot.setDomainGridlinePaint(Color.LIGHT_GRAY);
        plot.setRangeGridlinePaint(Color.LIGHT_GRAY);

        XYLineAndShapeRenderer renderer = new XYLineAndShapeRenderer();
        Color[] cores = {
                new Color(31, 119, 180),
                new Color(255, 127, 14),
                new Color(44, 160, 44),
                new Color(214, 39, 40),
                new Color(148, 103, 189),
                new Color(140, 86, 75),
                new Color(227, 119, 194)
        };

        for (int i = 0; i < dataset.getSeriesCount(); i++) {
            renderer.setSeriesLinesVisible(i, true);
            renderer.setSeriesShapesVisible(i, true);
            renderer.setSeriesStroke(i, new BasicStroke(2.5f));
            renderer.setSeriesPaint(i, cores[i % cores.length]);
        }
        plot.setRenderer(renderer);

        NumberAxis xAxis = (NumberAxis) plot.getDomainAxis();
        xAxis.setAutoRangeIncludesZero(false);

        ChartUtils.saveChartAsPNG(new File(arquivo), chart, LARGURA, ALTURA);
        System.out.println("  → Gráfico salvo: " + arquivo);
    }
}