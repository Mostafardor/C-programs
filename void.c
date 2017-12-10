/**
 *	punteros void 
 */

#include <stdio.h>
#include <stdio.h>

typedef struct Animal {
	int patas;
	char *nombre;
} Animal;

typedef struct Perro {
	Animal animal;
	char *raza;
} Perro;

int main(int argc, char **argv)
{
	Animal oA;
	Perro oP;
	
	void* p = &oP;
	
	((Perro*)p)->raza = "Chocoitzcuintle";
	((Perro*)p)->animal.nombre = "Perro";
	((Perro*)p)->animal.patas = 4;
	
	
	printf(" Animal : %s \n",((Perro*)p)->animal.nombre);
	printf(" patas  : %d \n",((Perro*)p)->animal.patas);
	printf(" raza   : %s \n",((Perro*)p)->raza);
	
	p = &oA;   printf("\n");
	
	((Animal*)p)->nombre = "Animal";
	((Animal*)p)->patas = 0;
	
	printf(" Animal : %s \n",((Animal*)p)->nombre);
	printf(" patas  : %d \n",((Animal*)p)->patas);
	
	
	
	return 0;
}

