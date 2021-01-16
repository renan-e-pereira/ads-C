#include <stdio.h>    // standard input and output (printf e scanf)
#include <stdlib.h>  // alocação de memória (malloc)
#include <locale.h> // linguagem em português (acentuação)

struct node
{
	int num;				//dados do nó
	struct node *nextptr;	//endereço do próximo nó 
}*stnode;

void creatNodeList (int n);		//function para criar a lista
void displayList ();			//function para mostrar a lista

int main () {

	setlocale (LC_ALL, "Portuguese");
	
	int n;
	
	printf ("Insira o número de nós: ");
	scanf ("%d", &n);
	creatNodeList (n);
	printf ("\nDados inseridos na lista: \n");
	displayList ();

	return 0;
}

void creatNodeList (int n)
{
	struct node *fnNode, *tmp;
	int num, i;
	stnode = (struct node *)malloc(sizeof(struct node));
	
	if (stnode == NULL)	//verifica se o fnNode está como NULL e se não há alocação de memória
	{
		printf ("Memória não pode ser alocada");
	}
	else
	{
		//lê os dados pelo teclado
		printf ("Insira os dados para o nó 1: ");
		scanf ("%d", &num);
		
		stnode -> num = num;
		stnode -> nextptr = NULL;	//vincula o campo endereço a NULL
		tmp = stnode;
		
		// criar n nós e manda para lista
		for (i = 2; i <= n; i++)
		{
			fnNode = (struct node *)malloc(sizeof(struct node));
			if (fnNode == NULL)
			{
				printf ("Memória não pode ser alocada");
				break;
			}
			else
			{
				printf ("Insira os dados para o nó %d: ", i);
				scanf (" %d", &num);
				
				fnNode -> num = num;		//vincula o campo num do fnNode com num
				fnNode -> nextptr = NULL;	//vincula o endereço do fnNode com NULL
				
				tmp -> nextptr = fnNode;	//vincula o nó anterior ao fnNode
				tmp = tmp -> nextptr;
			}
		}
	}
}

void displayList ()
{
	struct node *tmp, *num;
	if (stnode == NULL)
	{
		printf ("Lista vazia");
	}
	else
	{
		tmp = stnode;
		while (tmp != NULL)
		{
			printf ("\Dado = %d\n", tmp -> num);	//mostra o dado do nó atual
			tmp = tmp -> nextptr;					//avança a posição do nó
		}
	}
}
