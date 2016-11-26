#include <stdio.h>
#include <stdlib.h>

struct lista {
								int info;
								struct lista* prox;
};

typedef struct lista Lista;

Lista* inicializa (void) {

								return NULL;
}

Lista* insere (Lista* l, int i) {

								Lista* novo = (Lista*) malloc(sizeof(Lista));

								novo->info = i;
								novo->prox = l;

								return novo;
}

void imprime (Lista* l) {
								Lista* p;

								for (p = l; p != NULL; p = p->prox)

																printf("Listagem na Lista: = %d\n", p->info);
}

int main () {
								int escolha;
								printf ("\n#####################################################");
								printf ("\nVoce quer Vetor (digite 1) ou Matriz? (digite 2):");
								scanf("%d", &escolha);
								if (escolha==1) {
																vetor();
								} else if (escolha==2) {
																matriz();
								} else {
																return 0;
								}
}

void quick(int vet[], int esq, int dir){
								int pivo = esq,i,ch,j, contador;
								contador=0;
								for(i=esq+1; i<=dir; i++) {
																j = i;

																if(vet[j] < vet[pivo]) {
																								ch = vet[j];

																								while(j > pivo) {
																																vet[j] = vet[j-1];
																																j--;

																								}
																								vet[j] = ch;
																								pivo++;
																								contador++;
																}
								}
								if(pivo-1 >= esq) {
																quick(vet,esq,pivo-1);

								}
								if(pivo+1 <= dir) {
																quick(vet,pivo+1,dir);
								}

}

int vetor () {
								int tamanhovetor;
								int escolhav;
								printf("Qual o tamanho do Vetor? [x]");
								scanf("%d",&tamanhovetor);

								int vetor[tamanhovetor];

								printf("Deseja inserir os elementos? 1-SIM / 2-AUTOMÁTICO:");
								scanf("%d",&escolhav);
								if (escolhav==1) {
																for (int iv=0; iv < tamanhovetor; iv++) {
																								printf("Insira elemento vetor[%d]:",iv);
																								scanf("%d",&vetor[iv]);
																}
																for (int iv=0; iv < tamanhovetor; iv++) {
																								printf("\nElementos inseridos: POSIÇÃO VETOR[%d], VALOR[%d]\n",iv,vetor[iv]);
																}
																goto continua_na_lista;
								} if (escolhav==2) {
																for (int iv=0; iv < tamanhovetor; iv++) {
																								vetor[iv] = rand()%1000;
																}
																for (int iv=0; iv < tamanhovetor; iv++) {
																								printf("\nElementos inseridos AUTOMATICAMENTE: POSIÇÃO VETOR[%d], VALOR[%d]\n",iv,vetor[iv]);
																}
								}
continua_na_lista:
								printf ("\n#####################################################");
								printf ("\nVoce quer inserir em uma Lista? 1-SIM OU 2-NAO:");
								int escolha= 0;
								scanf("%d", &escolha);
								if (escolha==1) {
																Lista* l;
																l = inicializa();
																for (int iv=0; iv < tamanhovetor; iv++) {
																								l = insere(l, vetor[iv]);
																}
																imprime(l);
								}
								printf ("\n#####################################################");
								printf ("\nVoce ordenar seus números com? 1-BUBBLE OU 2-QUICK:");
								escolha = 0;
								scanf("%d", &escolha);
								if (escolha==1) {
																int aux;
																int iv=0;
																for(iv=tamanhovetor-1; iv >= 1; iv--) {
																								for( int jv=0; jv < iv; jv++) {
																																if(vetor[jv]>vetor[jv+1]) {
																																								aux = vetor[jv];
																																								vetor[jv] = vetor[jv+1];
																																								vetor[jv+1] = aux;
																																}
																								}
																}

																for( int rv = 0; rv < tamanhovetor; rv++) {
																								printf("Organizador com Bubble! %d\n",vetor[rv]);
																}

																printf ("\n#####################################################");
																printf ("\nVoce quer salvar em um arquivo tudo isso? 1-SIM OU 2-NAO:");
																int escolhas = 0;
																scanf("%d", &escolhas);
																if (escolhas==1) {

																								FILE *fp;

																								fp = fopen("vetor.txt", "a");

																								int iv=0;
																								for(iv=0; iv<tamanhovetor; iv++) {
																																fprintf(fp,"\nVetor organizado com Bubble: %d ",vetor[iv]);

																								}
																								printf("\nVerifique o diretório o arquivo vetor.txt:");

																								fclose(fp);
																}

								}

								if(escolha==2) {
																quick(vetor,0,tamanhovetor-1);
																int iv=0;
																for(iv=0; iv<tamanhovetor; iv++) {
																								printf("\nOrganizados com Quick! (mais rápido com muitos números): %d ",vetor[iv]);
																								printf("\n");
																}
																printf ("\n#####################################################");
																printf ("\nVoce quer salvar em um arquivo tudo isso? 1-SIM OU 2-NAO:");
																escolha = 0;
																scanf("%d", &escolha);
																if (escolha==1) {

																								int num;

																								FILE *fp;

																								fp = fopen("vetor.txt", "a");

																								int iv=0;
																								for(iv=0; iv<tamanhovetor; iv++) {
																																fprintf(fp,"\nVetor organizado com Quick: %d ",vetor[iv]);

																								}
																								printf("\nVerifique o diretório o arquivo vetor.txt:");

																								fclose(fp);
																}

								}
}


int matriz () {
								int tamanhomatriz, escolham;
								printf("Qual o tamanho do Matriz? [x][x]");
								scanf("%d",&tamanhomatriz);

								int matriz[tamanhomatriz][tamanhomatriz];

								printf("Deseja inserir os elementos? 1-SIM / 2-AUTOMÁTICO:");
								scanf("%d",&escolham);
								if (escolham==1) {
																for (int im1=0; im1 < tamanhomatriz; im1++) {
																								for (int im2=0; im2 < tamanhomatriz; im2++) {
																																printf("Insira elemento da matriz[%d][%d]:",im1,im2);
																																scanf("%d",&matriz[im1][im2]);
																								}
																}
																for (int im1=0; im1 < tamanhomatriz; im1++) {
																								for (int im2=0; im2 < tamanhomatriz; im2++) {
																																printf("\nElementos inseridos: POSIÇÃO MATRIZ[%d][%d], VALOR[%d]\n",im1,im2,matriz[im1][im2]);
																								}
																}
																goto continua_na_lista_m;
								} if (escolham==2) {
																for (int im1=0; im1 < tamanhomatriz; im1++) {
																								for (int im2=0; im2 < tamanhomatriz; im2++) {
																																matriz[im1][im2]=rand()%1000;
																								}
																}
																for (int im1=0; im1 < tamanhomatriz; im1++) {
																								for (int im2=0; im2 < tamanhomatriz; im2++) {
																																printf("\nElementos inseridos: POSIÇÃO MATRIZ[%d][%d], VALOR[%d]\n",im1,im2,matriz[im1][im2]);
																								}
																}
								}
continua_na_lista_m:
								printf ("\n#####################################################");
								printf ("\nVoce quer inserir em uma Lista? 1-SIM OU 2-NAO:");
								int escolha=0;
								scanf("%d", &escolha);
								if (escolha==1) {
																Lista* l;
																l = inicializa();
																for (int im1=0; im1 < tamanhomatriz; im1++) {
																								for (int im2=0; im2 < tamanhomatriz; im2++) {
																																l = insere(l, matriz[im1][im2]);
																								}
																}
																imprime(l);
								}
								printf ("\n#####################################################");
								printf ("\nVoce ordenar seus números com? 1-BUBBLE OU 2-QUICK:");
								escolha = 0;
								scanf("%d", &escolha);
								int aux=0;
								int km,lm,im,jm;
								if (escolha==1) {
																for(km=0; km<tamanhomatriz; km++) {
																								for(lm=0; lm<tamanhomatriz; lm++) {
																																for(im=0; im<tamanhomatriz; im++) {
																																								for(jm=0; jm<tamanhomatriz; jm++) {
																																																if(matriz[km][lm] < matriz[im][jm]) {
																																																								aux = matriz[im][jm];
																																																								matriz[im][jm] = matriz[km][lm];
																																																								matriz[km][lm] = aux;
																																																}
																																								}
																																}
																								}
																}

																for(im=0; im<tamanhomatriz; im++) {
																								for(jm=0; jm<tamanhomatriz; jm++) {
																																printf("\nElmentos da Matriz organizados com Bubble: %5d \n",matriz[im][jm]);
																								}
																}

																printf ("\n#####################################################");
																printf ("\nVoce quer salvar em um arquivo tudo isso? 1-SIM OU 2-NAO:");
																int escolhas = 0;
																scanf("%d", &escolhas);

																if (escolhas==1) {

																								FILE *fp;

																								fp = fopen("matriz.txt", "a");

																								int iv=0;
																								for(im=0; im<tamanhomatriz; im++) {
																																for(jm=0; jm<tamanhomatriz; jm++) {

																																								fprintf(fp,"\nMatriz organizada com Bubble: %d ",matriz[im][jm]);

																																}
																								}
																								printf("\nVerifique o diretório o arquivo matriz.txt:");

																								fclose(fp);
																}


								}

								if(escolha==2) {

																int t;

																t = tamanhomatriz*tamanhomatriz;


																int vetm[t];

																int contadorvetor=0;

																for(im=0; im<tamanhomatriz; im++) {
																								for(jm=0; jm<tamanhomatriz; jm++) {
																																vetm[contadorvetor] = matriz[im][jm];

																																contadorvetor++;

																								}
																}

																quick(vetm,0,t-1);

																int iv=0;
																for(iv=0; iv<t; iv++) {
																								printf("\nOrganizados com Quick! (mais rápido com muitos números): %d ",vetm[iv]);
																								printf("\n");
																}

																printf ("\n#####################################################");
																printf ("\nVoce quer salvar em um arquivo tudo isso? 1-SIM OU 2-NAO:");
																escolha = 0;
																scanf("%d", &escolha);
																if (escolha==1) {

																								int num;

																								FILE *fp;

																								fp = fopen("matriz.txt", "a");

																								int iv=0;
																								for(iv=0; iv<t; iv++) {

																																fprintf(fp,"\nMatriz organizada com Quick: %d ",vetm[iv]);

																								}
																								printf("\nVerifique o diretório o arquivo matriz.txt:");

																								fclose(fp);
																}

								}

}
