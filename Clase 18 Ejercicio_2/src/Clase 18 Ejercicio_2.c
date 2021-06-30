//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>

typedef int(*funcion)(int,int);
int calculador(int,int,funcion,int*);
int sumar(int numUno,int numDos);

int main(void)
{
	setbuf(stdout,NULL);

	int numP=5;
	int numS=6;
	int resultadoFinal;

	calculador(numP,numS,sumar,&resultadoFinal);

	printf("Resultado de sumar 5+6 es %d",resultadoFinal);

	return EXIT_SUCCESS;
}

int calculador(int operandoUno,int operandoDos,funcion funcionRecibida,int* resultado)
{
	int exito=0;

	*resultado=funcionRecibida(operandoUno,operandoDos);

	return exito;
}

int sumar(int numUno,int numDos)
{
	int resultadoSuma;

	resultadoSuma=numUno+numDos;

	return resultadoSuma;
}
