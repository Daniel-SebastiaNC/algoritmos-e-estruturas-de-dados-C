//1. Troca de valores sem variável auxiliar

/*

#include <stdio.h>

void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;

    *a = *a - *b;
}

int main() {

    int a;
    int b;

    printf("n1: ");
    scanf("%d", &a);

    printf("n2: ");
    scanf("%d", &b);

    printf("Antes do swap\n");

    printf("a = %d | b = %d\n", a, b);

    swap(&a, &b);
    
    printf("Depois do swap\n");

    printf("a = %d | b = %d\n", a, b);

    return 0;
}

*/


//2.Remoção de caracteres repetidos consecutivos

/*

#include <stdio.h>
#include <string.h>

void removeRepetido(char texto[]) {
    texto[strcspn(texto, "\n")] = '\0';
    char novo[strlen(texto)+1];

    int count = 0;

    novo[0] = texto[0];
    
    for (int i = 0; i < strlen(texto); i++) {
        char atual = texto[i];
    
        if(novo[count] == atual) {
            continue;
        }

        count++;
        novo[count] = atual;
    }

    novo[count+1] = '\0';
    strcpy(texto, novo);
}

int main() {

    char texto[20];

    printf("texto: ");
    fgets(texto, sizeof(texto), stdin);

    printf("texto original: %s", texto);

    removeRepetido(texto);

    printf("texto tratado: %s", texto);

    return 0;
}

*/


//3.Cadastro de alunos com média

/*

#include <stdio.h>
#include <string.h>

typedef struct {
    char matricula[10];
    char nome[20];
    float nota[3];
    float media;
} Aluno;

int main() {
    Aluno alunos[5];

    for (int i = 0; i < 5; i++) {
        printf("Cadastro Aluno %d\n", i+1);
        printf("Matricula: ");
        fgets(alunos[i].matricula, sizeof(alunos[i].matricula) ,stdin);
        alunos[i].matricula[strcspn(alunos[i].matricula, "\n")] = '\0';

        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome) ,stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        float soma = 0;
        for (int j = 0; j < 3; j++) {
            printf("nota %d: ", j+1);

            scanf("%f", &alunos[i].nota[j]);
            soma += alunos[i].nota[j];
        }

        alunos[i].media = soma/3;
        getchar();
    }
    
    float maior = 0;
    int indiceMaior = 0;
    printf("Alunos: \n");

    for (int i = 0; i < 5; i++) {
        printf("Aluno %d\n", i+1);
        printf("matricula = %s \nnome = %s \nnota 1 = %.2f\nnota 3 = %.2f\nnota 3 = %.2f \nmedia = %.2f\n", 
            alunos[i].matricula, 
            alunos[i].nome, 
            alunos[i].nota[0], 
            alunos[i].nota[1],
            alunos[i].nota[2],
            alunos[i].media
        );

        if (maior < alunos[i].media) {
            maior = alunos[i].media;
            indiceMaior = i;
        }
    }

    printf("Aluno com Maior media: \n");
    printf("matricula = %s \nnome = %s \nnota 1 = %.2f\nnota 2 = %.2f\nnota 3 = %.2f \nmedia = %.2f", 
            alunos[indiceMaior].matricula, 
            alunos[indiceMaior].nome, 
            alunos[indiceMaior].nota[0], 
            alunos[indiceMaior].nota[1],
            alunos[indiceMaior].nota[2],
            alunos[indiceMaior].media
        );
    return 0;
}

*/


//4.Cadastro dinâmico de alunos

/*

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    float nota;
} Aluno;

int main() {
    
    int quant;
    
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &quant);
    getchar();
    
    Aluno *alunos = (Aluno *) malloc(quant * sizeof(Aluno));

    if (alunos == NULL) {
        printf("Erro de falta de memória!\n");
        return 0; 
    }

    int indiceMaior = 0;
    float maiorNota = -1; 

    for (int i = 0; i < quant; i++) {
        printf("Cadastro Aluno %d\n", i + 1);
        
        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
        
        getchar();

        if (alunos[i].nota > maiorNota) {
            maiorNota = alunos[i].nota;
            indiceMaior = i;
        }
    }

    if (quant > 0) {
        printf("Aluno com a Maior Nota\n");
        printf("Nome: %s\n", alunos[indiceMaior].nome);
        printf("Nota: %.2f\n", alunos[indiceMaior].nota);
    }

    free(alunos);

    return 0;
}

*/


//1003 - Soma Simples

/*

#include <stdio.h>
 
int main() {

    int a;
    int b;

    scanf("%d", &a);
    scanf("%d", &b);

    int soma = a +b;

    printf("SOMA = %d\n", soma);

    return 0;
}

*/

//1009 - Salário com Bônus

/*

#include <stdio.h>

int main() {
    char nome[20];
    double salario;
    double vendas;
    
    scanf("%s", nome);
    
    scanf("%lf", &salario);
    scanf("%lf", &vendas);
    
    double total = salario + (0.15 * vendas);
    
    printf("TOTAL = R$ %.2lf\n", total);
    return 0;
}

*/

//1017 - Gasto de Combustível

/*

#include <stdio.h>
 
int main() {
 
    int tempo;
    int velocidade;
    
    scanf("%d", &tempo);
    scanf("%d", &velocidade);
    
    int distancia = tempo * velocidade;
    
    float combustivel =  ((float) distancia)/12;
    
    printf("%.3f\n", combustivel);
    
    return 0;
}

*/

//1018 - Cédulas

/*

#include <stdio.h>
 
int main() {
 
    int valor;
   
    
    scanf("%d", &valor);
    
    printf("%d\n", valor);
    
    int notas100 = valor/100;
    valor -= notas100 * 100;
    
    int notas50 = valor/50;
    valor -= notas50 * 50;
    
    int notas20 = valor/20;
    valor -= notas20 * 20;
    
    int notas10 = valor/10;
    valor -= notas10 * 10;
    
     int notas5 = valor/5;
    valor -= notas5 * 5;
    
    int notas2 = valor/2;
    valor -= notas2 * 2;
    
    int notas1 = valor/1;
    valor -= notas1 * 1;
    
    printf("%d nota(s) de R$ 100,00\n", notas100);
    printf("%d nota(s) de R$ 50,00\n", notas50);
    printf("%d nota(s) de R$ 20,00\n", notas20);
    printf("%d nota(s) de R$ 10,00\n", notas10);
    printf("%d nota(s) de R$ 5,00\n", notas5);
    printf("%d nota(s) de R$ 2,00\n", notas2);
    printf("%d nota(s) de R$ 1,00\n", notas1);
    
    return 0;
    
}

*/

//1174 - Seleçao em Vetor I

/*

#include <stdio.h>
 
int main() {
 
    float vetor[100];
    
    for (int i = 0; i < 100; i++) {
        scanf("%f", &vetor[i]);
    }
    
    for (int i = 0; i < 100; i++) {
        if (vetor[i] <= 10)
            printf("A[%d] = %.1f\n",i,  vetor[i]);
    }
    
    
    return 0;
    
}

*/

//1253 - Cifra de César do Beecrowd

/*

#include <stdio.h>
#include <string.h>
 
int main() {
    
    int casos;
    
    scanf("%d", &casos);
    
    for (int j = 0; j < casos; j++) {
        int n;
        char mensagem[51];
        
        scanf("%s", mensagem);
        scanf("%d", &n);
        
        for (int i = 0; i < strlen(mensagem); i++) {
            int cn = ((int) mensagem[i]) - n;
            if (cn < 65) {
                cn = cn + 26;
            }
            
            char c = (char) cn;
            printf("%c", c);
        }
        printf("\n");
    }
    
    return 0;
    
}

*/

