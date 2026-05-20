#include <stdio.h>

int main() {
    int idade;

    scanf("%d", &idade);


    // if (num1 > num2) 
    if (idade >= 60){
        printf("Voce eh idoso");
    } else if (idade >= 18) {
        printf("Voce eh maior de idade");
    }
    else {
        printf("Voce eh menor de idade");
    }
}