#include <stdio.h>

int main() {
    int numeros[10]; // Array para armazenar os 10 números
    int i;
    int menor, maior;

    // Solicita ao usuário para inserir 10 números inteiros
    printf("Digite 10 números inteiros:\n");

    // Lê os 10 números e inicializa menor e maior com o primeiro valor digitado
    for (i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);

        if (i == 0) {
            menor = maior = numeros[i];
        } else {
            // Atualiza o menor e o maior, se necessário
            if (numeros[i] < menor) {
                menor = numeros[i];
            }
            if (numeros[i] > maior) {
                maior = numeros[i];
            }
        }
    }

    // Exibe o menor e o maior valor digitado
    printf("O menor valor digitado é: %d\n", menor);
    printf("O maior valor digitado é: %d\n", maior);

    return 0;
}
