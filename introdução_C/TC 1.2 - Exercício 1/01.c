#include <stdio.h>

int fatorial(unsigned int n){
    int fatorial = 1;
    for(int i = n; i > 1; i--){
        fatorial = fatorial * i;
    }
    return fatorial;
}

int main(){
    int valor;
    printf("\n De um numero inteiro positivo : ");
    scanf("%d", &valor);
    
    int r_fatorial = fatorial(valor);
    printf("O FATORIAL DE %d e: %d\n", valor, r_fatorial);

}