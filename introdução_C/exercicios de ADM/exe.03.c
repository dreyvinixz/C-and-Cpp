#include<stdio.h>
#include<stdlib.h>

#define N 8500000

int main() {
    // Usando alocacao dinamica
    char *c = (char *)malloc(N);
    // Verificando se a alocação foi bem-sucedida
    if (c == NULL) {
        fprintf(stderr, "Falha na alocação de memória.\n");
        return 1; // Retornando um código de erro
    }
    // Inicializando o array com espaços em branco
    for (int i = 0; i < N; i++) {
        c[i] = ' ';
    }
    // Loop infinito
    for (;;) {
        
    }
    // Liberando a memória alocada dinamicamente
    free(c);

    return 0;
}
