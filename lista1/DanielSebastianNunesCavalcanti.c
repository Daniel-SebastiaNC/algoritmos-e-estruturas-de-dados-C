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

Cole aqui a sua resposta

*/


//1003 - Soma Simples

/*

Cole aqui a sua resposta

*/

//1009 - Salário com Bônus

/*

Cole aqui a sua resposta

*/

//1017 - Gasto de Combustível

/*

Cole aqui a sua resposta

*/

//1018 - Cédulas

/*

Cole aqui a sua resposta

*/

//1174 - Seleçao em Vetor I

/*

Cole aqui a sua resposta

*/

//1253 - Cifra de César do Beecrowd

/*

Cole aqui a sua resposta

*/

