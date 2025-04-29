// teste de ponterios
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* code */
    int i;
    
    i = 27 + 1;
    int * ptr;
    ptr = &i;

    (*ptr)++;

    printf("%d\n", i);

    return 0;
}
