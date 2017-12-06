/*
 * 	Colas.c
 * 	una de clientes.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente
{
	char *nombre;
	char *apellidos;
	double saldo;
	double credito;
} Cliente;

typedef struct Nodo
{
	Cliente *cliente;
	struct Nodo *sgte; 
} Nodo; 

typedef struct Cola
{
	unsigned int turno;
	Nodo *primer;
	Nodo *ultimo;
} Cola;

Cliente* new_Cliente(char *nombre,char *apellidos,double saldo,double credito)
{
	Cliente *cli = (Cliente*) malloc(sizeof(Cliente));
	cli->nombre = nombre;
	cli->apellidos = apellidos;
	cli->saldo = saldo;
	cli->credito = credito;
	return cli;
}

Cola* new_Cola()
{
	Cola *cola = (Cola*) malloc(sizeof(Cola)); 
	cola->primer = cola->ultimo = NULL;
	cola->turno = 0;
	return cola;
}

Nodo* new_Nodo(Cliente *cliente)
{
	Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));
	nodo->cliente = cliente;
	nodo->sgte = NULL;
	return nodo;
}

void delete_Nodo(Nodo *nodo)
{
	nodo->sgte = NULL;
	nodo->cliente = NULL;
	free(nodo);
}

void Encolar(Cola **cola,Cliente *cliente)
{
	Nodo *nodo = new_Nodo(cliente);
	
	/**
	 *  si solo hay un nodo debe
	 * 	ser tanto el primero como el ultimo.
	 */
	
	if((*cola)->primer == NULL)
	{
		(*cola)->primer = nodo;
		(*cola)->ultimo = nodo;
	} 
	else
	{
		/** 
		 * 	en esta parte era mas sencillo de lo que pense. 
		 * 	ya teniendo el ultimo para que recorrer la cola ?
		 */
		
		(*cola)->ultimo->sgte = nodo;
		(*cola)->ultimo = nodo;
	}
	(*cola)->turno++;
}

Cliente* getCliente(Cola *cola)
{
	if (cola->primer != NULL)
	{
		return cola->primer->cliente; 
	} 
	else 
	{
		return NULL;
	}
} 

void Eliminar(Cola *cola)
{
	/**
	 * 	se ha eliminado el primero, 
	 * 	y si solo habia un nodo ?
	 */
	if (cola->primer != NULL)
	{
		Nodo *i = cola->primer;
		cola->primer = cola->primer->sgte;
		delete_Nodo(i);
		if (cola->primer == NULL)
		{
			cola->ultimo = NULL;
		}
	}
}

void imprimeCliente(Cliente *cliente)
{
	printf(" Nombre   : %s \n",cliente->nombre);
	printf(" Apellido : %s \n",cliente->apellidos);
	printf(" Saldo    : %.2f \n",cliente->saldo);
	printf(" Credito  : %.2f \n",cliente->credito);
}

void AtenderCliente(Cola *cola)
{
	if (cola->primer != NULL)
	{
		imprimeCliente(getCliente(cola));
		Eliminar(cola);
		printf(" restantes : %d \n\n",--cola->turno);
	}
	else 
	{
		printf(" No tenemos clientes en la Cola.\n");
	}
}

int main(int argc, char **argv)
{
	Cola *cola = new_Cola();
	
	Encolar(&cola, new_Cliente("Ernesto","Rodriguez",2000.0,0.0));
	Encolar(&cola, new_Cliente("Juanito","Perez",0.0,1500));
	Encolar(&cola, new_Cliente("Armando","Casas",700.0,0.0));
	Encolar(&cola, new_Cliente("Elizabeth","Contreras",800.0,400.0));
	
	while(cola->primer != NULL)
	{
		AtenderCliente(cola);
	}
	
	return 0;
}




