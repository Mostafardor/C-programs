#include <stdio.h>

// retorna el tamanio de un array 
#define sizeAr(a)(sizeof(a)/sizeof(*a)) 
 
void quicksort(int *A, int len);

/** intercamio con punteros,
 * 	hay que tener en cuenta que un array 
 * 	ya es un apuntador por ello no hay que pasar 
 * 	su direccion de memoria 
 */
 
void inter(int *arr,int *a,int *b)
{
	int x; 
	x 			= arr[*a]; 
	arr[*a] 	= arr[*b];
	arr[*b] 	= x;
	
	// estoy inseguro de esto pero 
	// podria funcionar.
	// x = x + y;  // x ahora vale 15
	// y = x - y;  // y ahora vale 10
	// x = x - y;  // x ahora vale 5
} 
 
int main (int argc,char *argv[])
{
	int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
	int n = sizeAr(a);
 
	int i;
	for (i = 0; i < n; i++) {
		printf("[%d] ", a[i]);
	}
	printf("\n");
 
	quicksort(a, n);
 
	for (i = 0; i < n; i++) {
		printf("[%d] ", a[i]);
	}
	printf("\n");
 
	return 0;
}
 
void quicksort(int *A, int len) {
	
	// ya es muy pequenio para ordenarlo 
	if (len < 2) return; 
	
	// obtiene el pivote(medio): ejemplo: [5/2] = [3]
	int pivot = A[len / 2]; 
	
	// iteradores
	int i; // i = izq = 0
	int j; // j = len - 1 (para evitar '\0')
	
 	for (i = 0, j = len - 1; ; i++, j--) 
	{
		/** si  [i] < [pivot] 
		 * 	no habra intercambio con esta 
		 * 	posicion incrementa a la siguiente.
		 */
		while (A[i] < pivot) 
			i++;
		
		/** si [pivot] > [i] 
		 * 	no habra intercambio con esta 
		 * 	posicion decrementa a la siguiente.
		 */
		while (A[j] > pivot) 
			j--;
 
		if (i >= j) break;
 
		inter(A,&i,&j);
	}
	
	// vuelve a llamar a la funcion 
	// pero el tamanio del array ahora es 
	// i .
	quicksort(A, i);
	
	// llegara un punto en el que solo 
	// queden dos  
	quicksort(A + i, len - i);
}
