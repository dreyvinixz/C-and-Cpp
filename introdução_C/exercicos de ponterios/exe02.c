// sequencia de numeros amazernados em memoria
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numeros;
    int tamanho, i;

    printf("Digite o tamanho da sequencia de numeros: ");
    scanf("%d", &tamanho);

    numeros = (int *)malloc(tamanho * sizeof(int));

    if (numeros == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    printf("Digite a sequencia de numeros:\n");
    for (i = 0; i < tamanho; ++i) {
        scanf("%d", numeros + i);
    }

    printf("Sequencia de numeros inserida: ");
    for (i = 0; i < tamanho; ++i) {
        printf("%d ", *(numeros + i));
    }

    free(numeros);

    return 0;
}
