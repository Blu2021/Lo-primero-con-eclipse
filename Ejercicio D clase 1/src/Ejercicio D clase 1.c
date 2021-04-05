//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);

	int numIngresado;

	printf("Ingrese un numero \n");
	scanf("%d",&numIngresado);

	if(numIngresado%2==0)
	{
		printf("El numero es par");
	}
	else
	{
		printf("El numero es impar");
	}
	return EXIT_SUCCESS;
}
