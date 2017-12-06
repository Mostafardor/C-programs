/**
 * 	Tercer intento lista enlazada 
 *	@author joseph
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct  Libro {
	char *titulo;
	char *autor;
} Libro;

typedef struct Nodo {
	Libro libro ;        
	struct Nodo *sgte;
} Nodo;
    
typedef struct Nodo Lista; 

Libro* new_Libro(char *titulo,char *autor)
{
	Libro *libro = (Libro*) malloc(sizeof(Libro));
	libro->titulo = titulo;
	libro->autor = autor;
	return libro;
}

Nodo* new_Nodo(Libro *libro)
{
	Nodo *nodo = (Nodo*) malloc(sizeof(Nodo));
	nodo->libro.autor  = libro->autor;
	nodo->libro.titulo = libro->titulo;
	nodo->sgte = NULL;
	return nodo;
}
 
void delete_Nodo(Nodo *nodo)
{
	nodo->sgte = NULL;
	free(nodo);
} 

void insertarInicio(Lista **lista,Libro *libro)
{
    Nodo *nodo = new_Nodo(libro);
    nodo->sgte = *lista;
    *lista = nodo;
}
 
/**
 *  la ventaja de los punteros dobles,
 * 	se pueden usar para recorer los nodos sin crear otro.
 * 	es decir : p2 = &(*p1)  
 */
 
void insertarFinal(Lista **lista,Libro *libro)
{
    if( *lista == NULL)
    {
        *lista = new_Nodo(libro);
    }
	else
    {
		while( (*lista)->sgte != NULL)
        {
            lista = &(*lista)->sgte;
        }
        (*lista)->sgte = new_Nodo(libro);
    }
} 
  
void insertarElemento(Lista **lista,Libro *libro, int pos)
{
    Nodo *nodo = new_Nodo(libro);
	int i;
	
    if(pos == 1)
    {
        nodo->sgte = *lista;
        *lista = nodo;
    }
    else
    {
		/** lista = (*lista)->sgte // mmm...
         * 	para declarar el iterador dentro del 
         * 	bucle for se necesita C99, --std=c99  
         */
        Nodo *j = *lista;
        
        for( i = 1; j != NULL; i++) 
        {
            if(i == pos)
            {
                nodo->sgte = j->sgte;
                j->sgte = nodo;
                return;
            }
            j = j->sgte;
        }
    }
    printf(" error: No hay la cantidad de nodos.\n");
}
 
Libro* getElemento(Lista **lista,int n)
{
	if (*lista != NULL)
	{
		int i = 0;
	 
		while(*lista != NULL)
		{
			if(i == n)
			{
				return &(*lista)->libro;
			}
			//nodo = nodo->sgte;
			lista = &(*lista)->sgte;
			i++;
		}
		printf(" error: la posicion no existe \n");
	}
	return NULL;
}
  
void eliminarElemento(Lista **lista,unsigned int pos)
{
    if(*lista != NULL && pos != 0)
    {	
		int i = 1;
		while (i < (pos - 1))
		{
			lista = &(*lista)->sgte;
			++i;
		}
		/* que no se te olvide esto */
		Nodo *aux = (*lista)->sgte;
		(*lista)->sgte = (*lista)->sgte->sgte;
		delete_Nodo(aux);
    }
    else
        printf(" %s \n\n",(pos == 0)? "posicion invalida":"lista vacia");
}

void imprimeLibro(Libro *libro)
{
	if (libro != NULL)
	{
		printf(" Titulo : %s \n",libro->titulo);
		printf(" Autor  : %s \n",libro->autor);
		puts("\n");
	}
}

void imprimeLista(Lista **lista)
{
	if (*lista != NULL)
	{
		int i = 0;
		while(*lista != NULL)
		{
			imprimeLibro(&(*lista)->libro);
			
			lista = &(*lista)->sgte;
			i++;
		}
		printf(" elementos : %d \n\n",i);
	} 
	else
	{
		printf("error: No hay elementos.\n\n");
	}
}
   
int getVacia(Lista *p)
{
	return (p == NULL)? 0 : 1;
}  
  
void interNodos(Nodo **lista,int n)  
{
	if(*lista == NULL) { return; }
	
	Nodo *i = *lista;
	while (i != NULL && i->sgte != NULL)
    {

		i = i->sgte->sgte;
		
		// esto podria, ser una funcion pero 
		// no se como exactamente.
		if(n == 0)
		{
			Libro *org = &i->sgte->libro;
			Libro *des = &i->sgte->sgte->libro;
			Libro *p = org;
			p = org;
			org = des;
			des = p;
		}
	}
}
   
int main(int argc,char **argv)
{
	Lista *lista = NULL;
	
	eliminarElemento( &lista, 2);
	   
	insertarInicio( &lista, new_Libro("C languaje ", "D & K")); 
	insertarInicio( &lista, new_Libro("Bioligia II", "Elizabeth Leon"));
	
	insertarFinal( &lista, new_Libro("Don Quijote de la Mancha", "Miguel de Cervantes"));
	insertarFinal( &lista, new_Libro("Lenin IV", "Vladimir Lenin"));
	
	insertarElemento( &lista, new_Libro("Un Mundo Feliz", "Aldous Huxley"), 3);
	
	imprimeLista( &lista);
 
	eliminarElemento( &lista,1 );
	
	imprimeLista( &lista );
 
	imprimeLibro(getElemento(&lista,1));
	
	interNodos( &lista, 2);
	
	imprimeLista( &lista );
 
   return 0;
}
