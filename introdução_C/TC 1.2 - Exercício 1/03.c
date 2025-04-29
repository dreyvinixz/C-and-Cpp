#include <stdio.h>


void pegar_naturais_imp(unsigned int n){
    printf("Numeros naturais impares menores que %u:\n", n);
    for (int i = 1; i < n; i += 2){
        printf("%d ", i);
    }
    printf("\n");
}

int main (){
    int valor;
    printf("\nENTRE COM UM NUMERO POSITIVO: \n");
    scanf("%d", &valor);
    
    pegar_naturais_imp(valor);

    return 0;
}
