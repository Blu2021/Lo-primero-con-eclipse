//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la
aplicación con distintos valores.*/
int main(void)
{
	setbuf(stdout,NULL);

	int a;
	int ac=0;
	int i;
	float p;

	for(i=0;i<5;i++)
	{
		printf("Ingrese 5 numeros, despues de cada uno press enter\n");
		fflush(stdin);
		scanf("%d",&a);

		ac=ac+a;
	}

	p=(float)ac/i;//XQ NO LO PODIA DIVIDIR POR i??????

	printf("El promedio es %.2f",p);

	return EXIT_SUCCESS;
}
