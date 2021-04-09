//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);

	int numerosPedidos[5];
	int i;
	int sumador=0;

	for(i=0;i<5;i++)
	{
		printf("Ingrese numero por favor\n");
		scanf("%d",&numerosPedidos[i]);

		printf("El numero ingresado es %d\n",numerosPedidos[i]);
		sumador=sumador+numerosPedidos[i];
	}

	printf("El resultado de la suma de sus numeros es %d",sumador);

	return EXIT_SUCCESS;
}
