/**
 * 	Arbol.c
 * 
 * 	
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int valor;
	struct nodo *izq;
	struct nodo *der;
} Nodo ;

typedef Nodo Raiz; 

Nodo* crearNodo(int valor)
{
	Nodo *r = (Nodo*) malloc(sizeof(Nodo));  
	r->izq = r->der = NULL;
	r->valor = valor;
	return r;
}

void destruirNodo(Nodo *n)
{
	n->izq = n->der = NULL;
	free(n);
}

void Insertar(Nodo **arbol,int valor)
{
	if (*arbol == NULL)
	{
		*arbol = crearNodo(valor);
		//(*arbol)->nivel = nivel;
	} 
	else 
	{
		int vRaiz = (*arbol)->valor;
		if (valor < vRaiz)
		{
			Insertar( &(*arbol)->izq, valor );
		} 
		else 
		{
			Insertar( &(*arbol)->der, valor);
		}
	}
}

void imprimeArbol(Nodo *arbol,int n){
	if (arbol == NULL){
		printf(" ");	
	} 
	else
	{
		printf(" %d ",arbol->valor);
		imprimeArbol(arbol->izq, n++);
		imprimeArbol(arbol->der, n++);
	}
}

int main(int argc, char **argv)
{
	Nodo *root = NULL;
	
	Insertar( &root, 12);
	imprimeArbol(root, 0);
	puts("\n");
	
	Insertar( &root, 6 );
	imprimeArbol(root, 0);
	puts("\n");
	
	Insertar( &root, 3 );
	imprimeArbol(root, 0);
	puts("\n");
	
	Insertar( &root, 18 );
	imprimeArbol(root, 0);
	puts("\n");
	
	return 0;
}

