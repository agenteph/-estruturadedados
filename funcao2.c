#include <stdio.h>
#include <stdlib.h>

int fat(int n) {
   if (n)
       return n*fat(n-1);
   else return 1;
}

int main() {
    int n;
    printf("\nDigite um valor para a fatorial: ");
    scanf("%d", &n);
    printf("\nO fatorial de %d é %d \n", n, fat(n));
    return 0;
}
