
/**
 * 	POO.c
 * 	simulando poo en c.	
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct persona {
	char *nombre;
	int edad;
	bool sexo;
	void (*setSexo)(struct persona*,bool);
	void (*setEdad)(struct persona*,int);
	void (*setNombre)(struct persona*,char*); 
	void (*mostrarInfo)(const struct persona*);
	
} Persona ;

static void setNombre(struct persona *this,char *nombre){
	this->nombre = nombre;	
}

static void setEdad(struct persona *this,int edad){
	this->edad = edad;
}

static void setSexo(struct persona *this,bool sexo){
	this->sexo = sexo;
}

static void mostrarInfo(const struct persona *p)
{
	printf(" nombre : %s \n",p->nombre);
	printf(" edad  : %d \n",p->edad);
	printf(" sexo  : %s ",(p->sexo)? " mujer " : "hombre" );
}

// hay que tener en cuenta que los metodos esten antes 
// del constructor.

Persona* new_Persona()
{
	Persona *p = (Persona*) malloc(sizeof(Persona));  
	p->nombre 	= NULL;
	p->edad 	= 0;
	p->sexo 	= false;
	p->setSexo	= &setSexo;
	p->setNombre	= &setNombre;
	p->setEdad 		= &setEdad;
	p->mostrarInfo 	= &mostrarInfo;
	return (p);
}

// destructor

void delete_Persona(Persona *p){
	free(p);
}

int main(int argc, char **argv)
{
	Persona oPer = *new_Persona();
	
	oPer.setEdad( &oPer, 70);
	oPer.setNombre( &oPer, "Rick Sanchez");
	oPer.setSexo( &oPer, false );
	
	oPer.mostrarInfo(&oPer);

	delete_Persona(&oPer);

	return 0;
}

