#include <stdio.h>

struct base {
	int num1;
	int num2;
	int num3;
};

struct base pegar;

int main () {
	pegar.num1 = 10;
	pegar.num2 = 10;
	pegar.num3 = 10;

	int r;

	r = pegar.num1 + pegar.num2 + pegar.num3;

	printf ("\nSoma no struct: %d\n",r);
}
