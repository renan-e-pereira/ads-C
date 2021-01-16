#include <stdio.h>    // standard input and output (printf e scanf)
#include <stdlib.h>  // aloca��o de mem�ria (malloc)
#include <locale.h> // linguagem em portugu�s (acentua��o)

struct node
{
	int num;				//dados do n�
	struct node *nextptr;	//endere�o do pr�ximo n� 
}*stnode;

void creatNodeList (int n);		//function para criar a lista
void displayList ();			//function para mostrar a lista

int main () {

	setlocale (LC_ALL, "Portuguese");
	
	int n;
	
	printf ("Insira o n�mero de n�s: ");
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
	
	if (stnode == NULL)	//verifica se o fnNode est� como NULL e se n�o h� aloca��o de mem�ria
	{
		printf ("Mem�ria n�o pode ser alocada");
	}
	else
	{
		//l� os dados pelo teclado
		printf ("Insira os dados para o n� 1: ");
		scanf ("%d", &num);
		
		stnode -> num = num;
		stnode -> nextptr = NULL;	//vincula o campo endere�o a NULL
		tmp = stnode;
		
		// criar n n�s e manda para lista
		for (i = 2; i <= n; i++)
		{
			fnNode = (struct node *)malloc(sizeof(struct node));
			if (fnNode == NULL)
			{
				printf ("Mem�ria n�o pode ser alocada");
				break;
			}
			else
			{
				printf ("Insira os dados para o n� %d: ", i);
				scanf (" %d", &num);
				
				fnNode -> num = num;		//vincula o campo num do fnNode com num
				fnNode -> nextptr = NULL;	//vincula o endere�o do fnNode com NULL
				
				tmp -> nextptr = fnNode;	//vincula o n� anterior ao fnNode
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
			printf ("\Dado = %d\n", tmp -> num);	//mostra o dado do n� atual
			tmp = tmp -> nextptr;					//avan�a a posi��o do n�
		}
	}
}
