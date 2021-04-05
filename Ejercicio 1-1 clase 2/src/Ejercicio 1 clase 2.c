//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);

	int a;
	int b;
	int resultado;

	printf("Ingrese 2 numeros para sumarlos\n");
	fflush(stdin);
	scanf("%d",&a);
	fflush(stdin);
	scanf("%d",&b);

	resultado=a+b;

	printf("el resultado es %d",resultado);
	return EXIT_SUCCESS;
}
