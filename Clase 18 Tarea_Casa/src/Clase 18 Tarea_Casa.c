//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*EJERCICIO
Realizar un programa que :
a)tenga 2 funciones una para calcular el minimo y otra para
calcular el maximo :
que retorne -1 si hubo errores y 0 si funcionó bien
que reciba dos número para comparar y un entero por referencia para devolver
el mínimo o máximo encontrado
b)Luego desarrollar una función que reciba por parámetro dos número enteros y
un puntero a función que ejecute la función recibida por parámetro y retorne el
resultado por retorno.  Puede recibir cualquiera de las dos funciones desarrolladas en
el punto a)
Crear un main donde se utilice la función del punto b) utilizando las 2 funciones
desarrolladas en el punto a)*/
int calculaMaximo(int numUno,int numDos,int* devolucion);
int calculaMinimo(int numUno,int numDos,int* devolucion);
typedef int(*funcion)(int,int,int*);
int calculaMaxMin(int numUno,int numDos,funcion puntero);
int main(void)
{
	setbuf(stdout,NULL);

	int numeroP;
	int numeroS;
	int resultadoPunteroFuncion;
	int(*funcionMinimo)(int,int,int*);

	printf("Ingrese numero 1\n");
	fflush(stdin);
	scanf("%d",&numeroP);
	printf("Ingrese numero 2\n");
	fflush(stdin);
	scanf("%d",&numeroS);

	funcionMinimo=calculaMinimo;
	resultadoPunteroFuncion=calculaMaxMin(numeroP,numeroS,funcionMinimo);

	printf("El minimo es %d",resultadoPunteroFuncion);

	return EXIT_SUCCESS;
}

int calculaMaximo(int numUno,int numDos,int* devolucion)
{
	int exito=-1;
	int maximo;

	if(devolucion!=NULL)
	{
		exito=0;
		if(numUno>numDos)
		{
			maximo=numUno;
		}
		else
		{
			if(numDos>numUno)
			{
				maximo=numDos;
			}
			else
			{
				exito=-1;
			}
		}
		*devolucion=maximo;
	}
	return exito;
}

int calculaMinimo(int numUno,int numDos,int* devolucion)
{
	int exito=-1;
	int minimo;

	if(devolucion!=NULL)
	{
		exito=0;
		if(numUno<numDos)
		{
			minimo=numUno;
		}
		else
		{
			if(numDos<numUno)
			{
				minimo=numDos;
			}
			else
			{
				exito=-1;
			}
		}
		*devolucion=minimo;
	}
	return exito;
}

int calculaMaxMin(int numUno,int numDos,funcion puntero)
{
	int resultado;

	puntero(numUno,numDos,&resultado);

	return resultado;
}
