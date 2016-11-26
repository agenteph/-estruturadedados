#include <stdio.h>
#include <time.h>

//#define MAX 10

const MAX = 10;

int main () {
//  int vetor[MAX] = {7, 3, 1, 0, 79,4,21,34,67,33};

int vetor [MAX];
int i, j, min, aux, k;

    for (int p=0; p < MAX ; p++)
	{
	     vetor[MAX] = rand()%1000;
	}

  for (i = 0; i < MAX - 1; i++) // inicialização i = 0
  {
    min = i;

    for (j = i + 1; j < MAX; j++) 
    	{
      if (vetor[j] < vetor[min])
      	{
	    min = j;
     	}
    	}
    aux = vetor[i]; // 
    vetor[i] = vetor[min]; //Faz a troca
    vetor[min] = aux; // Faz a troca
  }

	  for (k = 0; k < MAX; k++) 
	{
	printf("%d\n", vetor[k]);
	}

}
