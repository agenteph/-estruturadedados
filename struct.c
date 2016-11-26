#include <stdio.h>

struct base {
	int num1;
	int num2;
};

struct base pegar;

int main () {
	pegar.num1 = 10;
	pegar.num2 = 10;

	int r;

	r = pegar.num1 + pegar.num2;

	printf ("\nSoma no struct: %d\n",r);
}
