#include <stdio.h>

int main() {
    int soma = 0;
    int contador = 0;
    int numero = 1;  // Inicia com o primeiro número ímpar

    // Loop para calcular a soma dos 100 primeiros números naturais ímpares
    while (contador < 100) {
        soma += numero;
        numero += 2;  // Incrementa para o próximo número ímpar
        contador++;
    }

    // Exibe a soma
    printf("A soma dos 100 primeiros numeros naturais impares e: %d\n", soma);

    return 0;
}
