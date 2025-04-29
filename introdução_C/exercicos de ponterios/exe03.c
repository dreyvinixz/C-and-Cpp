// troca de variveis 
#include <stdio.h>

void trocarValores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;

    printf("Valores originais: x = %d, y = %d\n", x, y);

    trocarValores(&x, &y);

    printf("Valores trocados: x = %d, y = %d\n", x, y);

    return 0;
}
