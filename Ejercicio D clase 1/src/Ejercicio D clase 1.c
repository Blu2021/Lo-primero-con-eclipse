//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*
d-Operadores Logicos
Aplicando el concepto de Operadores Lógicos con valores booleanos en el condicional:
Solicitar un número al usuario
Informar si el mismo es par o impar.
*/
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
