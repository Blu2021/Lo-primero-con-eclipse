//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*
b-Entrada/salida
Pedir el sueldo al usuario. Sumarle un 10% e informarle cuál será su sueldo con aumento.
*/
int main(void)
{
	setbuf(stdout,NULL);

	float sueldo;
	float resultado;

	printf("Ingrese su sueldo ");
	scanf("%f",&sueldo);

	resultado=sueldo+((sueldo*10)/100);

	printf("Su sueldo mas el 10xciento es %.2f",resultado);

	return 0;
}
