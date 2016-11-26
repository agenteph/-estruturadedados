#include <stdio.h>
#include <stdlib.h>

// PROCEDIMENTO

char procedimento () {
	printf("\n Um procedimento \n");
}



// FUNCAO...
int quadrado (int x) {

return (x * x);

}

// INICIANDO PELA ORDEM...
//int quadrado (int);

int main () {

    int p = 0x3E8;

    int numero, resultado;

    printf ("Digite um número inteiro: ");
    scanf ("%d", &numero);
    resultado = quadrado (numero);
    printf ("O quadrado: %d.\n", resultado);
	procedimento();
    return 0;
 }

