#include<stdio.h>
int main() {
   int i, j, tamanho, chave, contador;
//   int vetor[10]= {7, 3, 1, 0, 79,4,21,34,67,33};
 int vetor[65000];

   tamanho=65000;

   printf("Vetor desordenado...\n");

 for(i=0;i<tamanho;i++)
  {
      vetor[i]=rand()%1000;
      printf("Vetor [%2d]: %3d\n",i+1,vetor[i]);
      }

   for (j=1;j<tamanho;j++) {
     chave = vetor[j];
      i = j - 1;
      while((i>=0) && (vetor[i]>chave))
         {
         vetor[i+1] = vetor[i];
         i = i - 1;
         contador++;
         }
      vetor[i+1] = chave;
      }

   printf("Vetor ordenado...\n");
   for(i=0;i<tamanho;i++)
      printf("Vetor[%d]: %d\n",i+1,vetor[i]);
   printf("Trocas efetuadas: %d\n\n",contador);
   return 0;
}
