#include <stdio.h>

int main() {
    int v[50];
    int t;

    printf("Número de figurinhas compradas: ");
    scanf("%d", &t);

    for (int a = 0; a < t; a++) {
        printf("Figurinha %d: ", a + 1);
        scanf("%d", &v[a]);
    }

    printf("Figurinhas compradas:\n");
    for (int i = 0; i < t; i++) {
        printf("%d\n", v[i]);
    }

    int procurada;
    printf("Digite o número da figurinha procurada: ");
    scanf("%d", &procurada);

    // Verifica se a figurinha procurada está no vetor
    int encontrada = 0;
    for (int i = 0; i < t; i++) {
        if (v[i] == procurada) {
            printf("Encontramos a figurinha %d no índice %d do vetor.\n", procurada, i);
            encontrada = 1;
            break;  // Se encontrou, não precisa continuar procurando
        }
    }

    if (!encontrada) {
        printf("A figurinha %d não foi encontrada nas figurinhas compradas.\n", procurada);
    }

    return 0;
}
