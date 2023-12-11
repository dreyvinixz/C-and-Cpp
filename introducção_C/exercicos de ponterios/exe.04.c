#include <stdio.h>

int encontrarMaior(int *arr, int tamanho) {
    int maior = *arr;

    for (int i = 1; i < tamanho; ++i) {
        if (*(arr + i) > maior) {
            maior = *(arr + i);
        }
    }

    return maior;
}

int main() {
    int numeros[] = {10, 5, 8, 15, 3};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    
    int maior = encontrarMaior(numeros, tamanho);

    printf("O maior elemento no array e: %d\n", maior);

    return 0;
}
 