//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*
Ejercicio 3-2:
Crear una funci�n que muestre por pantalla el n�mero flotante que recibe como par�metro.
*/
void mostrarNumero(float numerete);

int main(void)
{
	setbuf(stdout,NULL);

	float numeroFlotanteIngresado;

	printf("Ingrese un numero decimal\n");
	scanf("%f",&numeroFlotanteIngresado);

	mostrarNumero(numeroFlotanteIngresado);

	return EXIT_SUCCESS;
}

void mostrarNumero(float numerete)
{
	printf("El numero ingresado es %.2f",numerete);
}
