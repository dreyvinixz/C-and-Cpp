#include <stdio.h>

int validar_primo(unsigned int n){
    if(n <= 1){
        return 0;
    }

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main (){
    int valor;
    printf("\nENTRE COM UM NUMERO POSITIVO: \n");
    scanf("%d", &valor);
    
    int r_valida = validar_primo(valor);
    if(r_valida == 0){
        printf("O numero %d nao e primo\n", valor);
    } else {
        printf("O numero %d e primo\n", valor);
    }

    return 0;
}
