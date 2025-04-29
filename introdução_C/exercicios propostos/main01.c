#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* code */
    int i, j , k , l , m , n;/*  declara que o tipo da variavel*/
    /* variaveis que calcula as operações*/
    i = 1 + 3 * (2 - 4 * 10 / 5); 
    j = 6 - 3 / 2;
    k = 2 + 3 * (2 - 4 * 10 % 10);
    l = 9.0 / 2 + 1;
    m = 2 * 4 > 13;
    n = (5 > 2) && (1 + 3 == 10 - 6);
    /* mostra a saida */ 
    printf("%d\n",i);
    printf("%d\n",j);
    printf("%d\n",k);
    printf("%d\n",l);
    printf("%d\n",m);
    printf("%d\n",n);
    return 0; 
}
