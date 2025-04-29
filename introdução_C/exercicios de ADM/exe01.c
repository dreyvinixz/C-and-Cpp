#include<stdio.h>
#include<stdlib.h>

int main(){
	int a = 5;
	int *p = &a;
	
	printf("a - Endereco: %p Valor: %i \n",&a,a);
	
	printf("p - Endereco: %p Valor: %p Final do Ponteiro: %i\n",&p,p,*p);
	
	return 0;
}
