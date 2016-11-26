#include <stdlib.h>
#include <stdio.h>

struct bin_arvore {
        int dados;
        struct bin_arvore * direita, * esquerda;
        //struct bin_arvore * prox;
};
typedef struct bin_arvore node;

void inserir(node ** arvore, int val)
{
        node *temp = NULL;
        if(!(*arvore)) // VERIFICA SE A ARVORE ESTÁ VAZIA, ENTAO INSERE NÓ PAI.
        {
                temp = (node *)malloc(sizeof(node));
                temp->esquerda = temp->direita = NULL;
                temp->dados = val;
                *arvore = temp;
                return;
        }
        //Verifica se o valor do nó a ser inserido é menor que o valor do nó raiz, então
        if(val < (*arvore)->dados) //Função de inserir() recursivamente enquanto houver nó esquerdo não-NULO
        { // Verifique se o valor do nó a ser inserido é maior do que o valor do nó raiz, então
                inserir(&(*arvore)->esquerda, val); //Quando alcançado o nó mais à esquerda como NULL, insira o novo nó.
        }
        else if(val > (*arvore)->dados)
        {
                inserir(&(*arvore)->direita, val);
        }
}

void print_preordem(node * arvore)
{
        if (arvore)
        {
                printf("%d\n",arvore->dados);
                print_preordem(arvore->esquerda);
                print_preordem(arvore->direita);
        }

}

void print_emordem(node * arvore)
{
        if (arvore)
        {
                print_emordem(arvore->esquerda);
                printf("%d\n",arvore->dados);
                print_emordem(arvore->direita);
        }
}

void print_posordem(node * arvore)
{
        if (arvore)
        {
                print_posordem(arvore->esquerda);
                print_posordem(arvore->direita);
                printf("%d\n",arvore->dados);
        }
}

void delarvore(node * arvore)
{
        //Verifica se o Pai é NULL, então apaga esquerda e direita, depois o nó.
        if (arvore)
        {
                delarvore(arvore->esquerda);
                delarvore(arvore->direita);
                free(arvore);
        }
}

node* pesquisar(node ** arvore, int val)
{ // Verifica primeiro se a árvore está vazia e, em seguida, retorne NULL.
        if(!(*arvore))
        {
                return NULL;
        }
//Verifique se o valor do nó a ser pesquisado é igual ao valor do nó raiz e, em seguida, retorna o nó
//Verifique se o valor do nó a ser pesquisado é menor que o valor do nó raiz, então chamar a função pesquisar () recursivamente com o nó esquerdo
//Verifique se o valor do nó a ser pesquisado é maior que o valor do nó raiz, então chamar a função pesquisar() recursivamente com o nó direito
        if(val < (*arvore)->dados)
        {
                pesquisar(&((*arvore)->esquerda), val);
        }
        else if(val > (*arvore)->dados)
        {
                pesquisar(&((*arvore)->direita), val);
        }
        else if(val == (*arvore)->dados)
        {
                return *arvore;
        }
}

void main() {

        node *root;
        node *tmp;
        //int i;

       root = NULL;
        /* inserindo os valores */
        inserir(&root, 32);
        inserir(&root, 43);
        inserir(&root, 12);
        inserir(&root, 61);
        inserir(&root, 33);
        inserir(&root, 10);
        inserir(&root, 90);
        inserir(&root, 70);
        inserir(&root, 01);
        inserir(&root, 9);
        inserir(&root, 1951);

        /* Visualizando a árvore */
        printf("Árvore:  Nó Pai, Nó Esquerda e Nó da Direita\n");
        print_preordem(root);

        printf("Árvore: Nó da Esquerda, Nó Pai e Nó da Direita\n");
        print_emordem(root);

        printf("Árvore: Nó da Esquerda, Nó da Direita, Nó Pai.\n");
        print_posordem(root);

        /* pesquisar  arvore */
        tmp = pesquisar(&root, 1951);
        if (tmp)
        {
                printf("Nó pesquisado : %d\n", tmp->dados);
        }
        else
        {
                printf("Não foi encontrado o valor pedido...\n");
        }

        /* Apagando os nós da árvore */
        delarvore(root);
}
