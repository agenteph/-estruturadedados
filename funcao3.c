#include<stdlib.h>
#include<stdio.h>

void soma ( int n ) {
	n = n + 1;
	printf("Dentro da funcao : x = %d\n", n);
}

int main () {

	int x = 5;

	printf ("Antes da funcao : x = %d\n", x);
	soma(x);
	printf("Depois da funcao : x = %d\n ", x);

	return 0;
}
