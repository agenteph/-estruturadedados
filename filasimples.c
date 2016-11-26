#include <stdio.h>

struct lista {
	int info;
	struct lista* prox;
};

typedef struct lista Lista;


/* função de inicialização: retorna uma lista vazia */
Lista* inicializa (void) {

	return NULL;
}

/* inserção no início: retorna a lista atualizada */
Lista* insere (Lista* l, int i) {

	Lista* novo = (Lista*) malloc(sizeof(Lista));

	novo->info = i;
	novo->prox = l;
	
	return novo;
}

/* função imprime: imprime valores dos elementos */
void imprime (Lista* l) {
	Lista* p;
	
	/* variável auxiliar para percorrer a lista */
	for (p = l; p != NULL; p = p->prox)
	
	printf("info = %d\n", p->info);
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */

int vazia (Lista* l) {
	
	return (l == NULL);
}

/* função busca: busca um elemento na lista */
Lista* busca (Lista* l, int v) {
	Lista* p;

for (p=l; p!=NULL; p=p->prox)

	if (p->info == v)
	return p;
	return NULL;
	/* não achou o elemento */
	}


//Função para retirar elemento da fila.

Lista* retira (Lista* l,int v) {

	Lista* ant = NULL;  // ponteiro para elemento anterior 
	Lista* p = l;  // ponteiro para percorrer a lista

	/* procura elemento na lista, guardando anterior */

	while (p != NULL && p->info != v) {
		ant = p;
		p = p->prox;
		}

	/* verifica se achou elemento */

	if (p == NULL)

	return l;

	/* não achou: retorna lista original */
	/* retira elemento */
	
	if (ant == NULL) {
	
	/* retira elemento do inicio */
	l = p->prox;
	
	} else {
	/* retira elemento do meio da lista */
		ant->prox = p->prox;
			}
	free(p);
	return l;
}


void libera (Lista* l) {

	Lista* p = l;
	
	while (p != NULL) {
		Lista* t = p->prox; /* guarda referência para o próximo elemento */
		free(p);
		/* libera a memória apontada por p */
		p = t;
		/* faz p apontar para o próximo */
		}
}

int main (void) {
	Lista* l;
	l = inicializa();

	printf ("Inserir elemento?");
//	int esc;
//	scanf("%d",&esc);
	l = insere(l, 23);
	l = insere(l, 45);
	l = insere(l, 56);
	l = insere(l, 78);

	imprime(l);

	l = retira(l, 23);

	imprime(l);

	l = retira(l, 45);
	l = retira(l, 78);
//	l = retira(l, );


	imprime(l);
	libera(l);

	return 0;
}
