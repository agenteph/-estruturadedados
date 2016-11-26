//Código para Ordenar um vetor de 10 inteiros.
#include<stdio.h>
#include<stdlib.h>

#define TAM 65000

void quick(int vet[], int esq, int dir){
    int pivo = esq,i,ch,j, contador;
    contador=0;
    for(i=esq+1;i<=dir;i++){
        j = i;
        
        if(vet[j] < vet[pivo]){
         ch = vet[j];
         
         while(j > pivo){
            vet[j] = vet[j-1];
            j--;
            	
         }
         vet[j] = ch;
         pivo++;
         contador++;
        }
    }
    if(pivo-1 >= esq){
        quick(vet,esq,pivo-1);
        
    }
    if(pivo+1 <= dir){
        quick(vet,pivo+1,dir);
    }
      printf("\n Contagem: %d.",contador);
 }

int main() {
    int vet[TAM],i;

    for(i=0;i<TAM;i++)
//        scanf("%d",&vet[i]);
	vet[TAM]=rand()%1000;

   quick(vet,0,TAM-1);

    for(i=0;i<TAM;i++)
        printf("\n%d ",vet[i]);
    printf("\n");

    return 0;
}
