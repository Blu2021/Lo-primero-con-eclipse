//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*Ejercicio 4-1:
Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un número.
Por ejemplo:
5! = 5*4*3*2*1 = 120
*/
int main(void)
{
	setbuf(stdout,NULL);

	int numIngresado;
	int ResFactorial=1;
	int i;

	printf("Ingrese un numero para calcular su factorial\n");
	scanf("%d",&numIngresado);

	for(i=numIngresado;i>1;i--)
	{
		ResFactorial=ResFactorial*i;
	}

	printf("El resultado de %d! es : %d",numIngresado,ResFactorial);

	return EXIT_SUCCESS;
}
