/* Conta número de linhas de um arquivo */

#include <stdio.h>

int main () {

	 int  num;
	 
    FILE *fp;
    fp = fopen("entrada.txt", "a");

    printf("Telefone: ");
    scanf("%d", &num);


    fprintf(fp, "\n[ %d ]\n\n", num);
    fclose(fp);
    
    }