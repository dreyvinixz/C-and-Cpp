// troca de variaveis 
#include <stdio.h>

void ordena( int *a , int *b ){
    if ((*a) > (*b)) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main(){
    int a  =1, b = 0;
    printf("%i , %i\n", a, b);
    ordena(&a,&b);
    printf("%i , %i\n", a, b);
    return 0;
}