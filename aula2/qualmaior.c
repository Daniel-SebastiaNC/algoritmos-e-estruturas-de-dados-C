#include <stdio.h>

int main() {
    int num1, num2;

    scanf("%d", &num1);
    scanf("%d", &num2);

    int vof = (num1 > num2) ? 1 : 0;

    // if (num1 > num2) 
    if (vof){
        printf("%d é maior que %d", num1, num2);
    } else {
        printf("%d é maior que %d, ou sao iguais", num2, num1);
    }
}