#include <stdio.h>
#include <time.h>

int main(void)
{

    int vetor[65];
//    int vetor[5] = {6,5,7,4,1};
    int tamanho = 65;
    int aux;

	for (int p=0; p < tamanho ; p++) {
	vetor[p] = rand()%10000;
}

    for(int i=tamanho-1; i >= 1; i--) {
        for( int j=0; j < i ; j++) {
            if(vetor[j]>vetor[j+1]) {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
          		}
	          }
    }

    for( int r = 0; r < 65; ++r)
    {
        printf("%d\n",vetor[r]);
    }
}
