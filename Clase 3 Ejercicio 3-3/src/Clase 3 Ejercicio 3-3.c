//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*Ejercicio 3-3:
Crear una función que pida el ingreso de un entero y lo retorne.*/
int retornaEnteros();

int main(void)
{
	setbuf(stdout,NULL);

	int numeroRetornado;

	numeroRetornado=retornaEnteros();

	printf("el numero retornado es %d ",numeroRetornado);

	return EXIT_SUCCESS;
}

int retornaEnteros()
{
	int enterin;

	printf("Ingrese un numero entero\n");
	scanf("%d",&enterin);

	return enterin;
}
