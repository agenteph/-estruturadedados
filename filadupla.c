#include <stdio.h>

struct lista2 {
	int info;
	struct lista2* ant;
	struct lista2* prox;
};

typedef struct Lista2 Lista2;


/* inserção no início */
Lista2* insere (Lista2* l, int v) {

	Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
	novo->info = v;
	novo->prox = l;
	novo->ant = NULL;

	/* verifica se lista não está vazia */

	if (l != NULL)
	l->ant = novo;

	return novo;
}

/* função busca: busca um elemento na lista */

Lista2* busca (Lista2* l, int v) {

	Lista2* p;

	for (p=l; p!=NULL; p=p->prox)
	if (p->info == v)

	return p;
	return NULL;
	/* não achou o elemento */
}

/* função retira: retira elemento da lista */
Lista2* retira (Lista2* l, int v) {

	Lista2* p = busca(l,v);
		if (p == NULL)
		return l;

	/* não achou o elemento: retorna lista inalterada */
	/* retira elemento do encadeamento */
		if (l == p)
		l = p->prox;
		else
			p->ant->prox = p->prox;
		if (p->prox != NULL)
		p->prox->ant = p->ant;
		free(p);

		return l;
}

int main (void) {

		Lista2* l;

//		l = inicializa();

//		l = insere(l, 23);
	
//		l = retira(l, 78);
	
//		imprime(l);

	return 0;
}
