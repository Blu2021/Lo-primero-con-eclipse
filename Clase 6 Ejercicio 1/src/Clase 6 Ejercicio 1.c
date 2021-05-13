//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*
Disponemos de dos variables numéricas (a y b). Realizar un algoritmo que permita el intercambio de valores de dichas
variables.
*/
int main(void)
{
	setbuf(stdout,NULL);

	int numeroUno=5;
	int numeroDos=10;
	int auxiliar;

	auxiliar=numeroUno;
	numeroUno=numeroDos;
	numeroDos=auxiliar;

	printf("%d %d",numeroUno,numeroDos);

	return EXIT_SUCCESS;
}
