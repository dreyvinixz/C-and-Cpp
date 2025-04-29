#include <stdio.h>
#include <string.h>

int contar_ocorrencias(char frase[], char palavra[]) {
    int contador = 0;
    int len_palavra = strlen(palavra);
    int len_frase = strlen(frase);

    for (int i = 0; i <= len_frase - len_palavra; i++) {
        int j;
        for (j = 0; j < len_palavra; j++) {
            if (frase[i + j] != palavra[j]) {
                break;
            }
        }
        if (j == len_palavra) {
            contador++;
        }
    }
    return contador;
}

int main() {
    char frase[100];
    char palavra[20];

    printf("Digite a frase:\n");
    gets(frase);  // lê com espaços
    printf("Digite a palavra:\n");
    gets(palavra);

    int resultado = contar_ocorrencias(frase, palavra);
    printf("A palavra '%s' ocorre %d vezes na frase.\n", palavra, resultado);

    return 0;
}
