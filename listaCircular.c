#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo
{
    char *clausula;
    struct Nodo *sgte;
    struct Nodo *ante;
} Nodo;
 
Nodo* new_Nodo(char *clausula) 
{
	Nodo *temp = (Nodo*) malloc(sizeof(Nodo));
	temp->clausula = clausula;
	temp->sgte = temp->ante = NULL;
	return temp;
} 

void delete_Nodo(Nodo *nodo)
{
	nodo->ante = nodo->sgte = NULL;
	free(nodo);
}

// el titulo de esta funcion  esta escrita en Latin moderno
 
void inserereIni(struct Nodo** list, char *texto)
{
    Nodo *nodo = new_Nodo(texto);
    
    if (*list == NULL)
    {
        nodo->sgte = nodo->ante = nodo;
        *list = nodo;
        return;
    }

    /* tomar el : ultimo -> cabeza -> sgte */
    Nodo *ulti = (*list)->ante;
 
	/* mover la cabeza : nodo -> cabeza */
    nodo->sgte = *list;

	/* conectar la : cabeza <- nodo */
    (*list)->ante = nodo;
 
    /* conectar el ultimo ultimo <- nodo */ 
    nodo->ante = ulti;
 
    /* ulti -> nodo */
    ulti->sgte = nodo;
}
 
void inserereFin(Nodo **list,char *texto)
{
	Nodo *nodo = new_Nodo(texto);
	if (*list == NULL)
	{
		nodo->sgte = nodo->ante = nodo;
        *list = nodo;
        return;
	} 
	
	// realmente no se como lo hize pero 
	// funciono a la primera prueba.
	
	/* nodo -> cabeza */
	nodo->sgte = *list;
	
	/*  ante <- ante  <- cabeza <- nodo*/
	nodo->ante = (*list)->ante;
	
	/*  ante -> nodo <- cabeza  */
	(*list)->ante->sgte = nodo;
	
	/*  nodo <- cabeza 	*/
	(*list)->ante = nodo;
	
}

void insererEntre(Nodo **list,char *texto,int psc)
{
    if(!*list) { return; } // la lista esta vacia
    
    Nodo *nodo = new_Nodo(texto);
   
    Nodo *i = *list;
    
    while (i->sgte != *list)
    {  
		if(psc == 1) // la lista comienza desde 0 
		{
			// auxiliar
			Nodo *aux = i->sgte;
			
			/* i -> nodo */
			i->sgte = nodo;
			
			/*  i <- nodo */
			nodo->ante = i;
			
			/* nodo -> aux */
			nodo->sgte = aux;
			
			/* aux -> nodo */
			aux->ante = nodo;
			
			return;
		}
		psc--;
        i = i->sgte;
	}	
	delete_Nodo(nodo);
}
 
void removeNodo(Nodo **list,int psc)
{
	if (!*list) { return; }
	
	Nodo *i = *list;
	while (i->sgte != *list )
	{
		i = i->sgte;
		psc--;
		if (psc == 0)
		{
			Nodo *aux = i->sgte;
			
			i->sgte = i->sgte->sgte;	
			i->sgte->ante = i->ante->ante->ante;

			delete_Nodo(aux);				
			
			return;
		}
		
	}	
} 

Nodo* getNodo(Nodo **list,int psc)
{
	Nodo *aux = *list; 
	while( aux->sgte != *list)
	{
		aux = aux->sgte;
		psc--;
		if (psc == 0 )
		{	
			return aux; 
		}
	}
	return NULL;
}
  
// el titulo de esta funcion  esta escrita en Latin moderno

void videreAlbumIni(Nodo **list)
{
	// esta es la forma experimental
    Nodo *aux = *list; 
 
    while ((*list)->sgte != aux)
    {
        
        printf(" %s \n", (*list)->clausula);
        list = &(*list)->sgte;
    
    }
    
    printf(" %s \n", (*list)->clausula);
}

void viderereAlbumFin(Nodo **list) 
{
	Nodo *aux = *list; 
 
    while (aux->ante != *list)
    {
        aux = aux->ante;
		printf(" %s \n", aux->clausula);
    }
    
    aux = aux->ante;
    printf(" %s \n", aux->clausula);
}

int main(int argc,char **argv)
{
    Nodo *foo = NULL;
	
    inserereIni( &foo, " ->");
    inserereIni( &foo, " ich : yo ");
    inserereIni( &foo, " du  : tu");
    inserereIni( &foo, " er  : el ");
    inserereIni( &foo, " sie : ella/el ");
    inserereIni( &foo, " es  : algo ");
    inserereIni( &foo, " man : eso ");
 
	inserereFin( &foo," <-");
	
	insererEntre( &foo, " ihr : nosotros ", 2);
	
    printf(" lista desde delante : \n");
    videreAlbumIni( &foo);
 
	printf(" lista desde atras   : \n");
	viderereAlbumFin( &foo);
	
	// regresa lo que tenga el nodo, no su puntero.
	// 2 es la [3] posicion
	Nodo n = *getNodo(&foo, 2); 
	
	printf("\n Nodo 2 : %s \n",n.clausula);
 
	removeNodo( &foo , 1);
	
	videreAlbumIni( &foo );
 
    return 0;
}

