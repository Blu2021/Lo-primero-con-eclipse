//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*Ejercicio 1-2:ingresar 3 números y mostrar el mayor de los tres.*/
int main(void)
{
	setbuf(stdout,NULL);

	int a;
	int max;
	int banderaMax=1;
	int i;

	for(i=0;i<3;i++)
	{
		printf("Ingrese 3 numeros\n");
		fflush(stdin);
		scanf("%d",&a);
		if(banderaMax||a>max)
		{
			max=a;
			banderaMax=0;
		}
	}

	printf("El numero mayor es %d",max);

	return EXIT_SUCCESS;
}
