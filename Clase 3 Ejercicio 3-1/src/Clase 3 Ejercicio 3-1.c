//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*
Ejercicio 3-1:
Crear una función que permita determinar si un número es par o no. La función retorna 1 en caso afirmativo y 0 en caso contrario. Probar en el main.
*/

int esParONo(int numerete);

int main(void)
{
	setbuf(stdout,NULL);

	int numeroIngresado;
	int resultado;

	printf("Ingrese un numero\n");
	scanf("%d",&numeroIngresado);

	resultado=esParONo(numeroIngresado);

	printf("Si el numero es par 1 si no 0 : %d",resultado);

	return EXIT_SUCCESS;
}

int esParONo(int numerete)
{
	int resultado;

	resultado=numerete%2==0;

	return resultado;
}
