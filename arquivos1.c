/* Conta número de linhas de um arquivo */

#include <stdio.h>

int main (void) {
int c;

FILE *file;

file = fopen("entrada.txt", "r");

if (file) {
    while ((c = getc(file)) != EOF)
        
        putchar(c);
    
    fclose(file);
}

}