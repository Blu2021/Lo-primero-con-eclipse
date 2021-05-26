//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>

int cargaMuestraNumerosUno(int numeros[],int tamUno);
int cargaMuestraNumerosDos(int numeros[],int tamUno);
int cargaMuestraNumerosTres(int* numeros,int tamUno);
int cargaMuestraNumerosCuatro(int* numeros,int tamUno);

int main(void)
{
	setbuf(stdout,NULL);

	int numeros[10];

	cargaMuestraNumerosUno(numeros,10);
	cargaMuestraNumerosDos(numeros,10);
	cargaMuestraNumerosTres(numeros,10);
	cargaMuestraNumerosCuatro(numeros,10);

	return EXIT_SUCCESS;
}
/*1era funci�n: Recibe el array como vector y accede a los datos utilizando notaci�n vectorial ([])*/
int cargaMuestraNumerosUno(int numeros[],int tamUno)
{
	int exito=0;
	int i;

	for(i=0;i<tamUno;i++)
	{
		numeros[i]=i+1;
	}

	for(i=0;i<tamUno;i++)
	{
		printf("Los datos en pos %d son %d\n",i,numeros[i]);
	}
	return exito;
}
/*2da funci�n: Recibe el array como vector y accede a los datos utilizando aritm�tica de punteros*/
int cargaMuestraNumerosDos(int numeros[],int tamUno)
{
	int exito=0;
	int i;

	for(i=0;i<tamUno;i++)
	{
		*(numeros+i)=i+1;
	}

	for(i=0;i<tamUno;i++)
	{
		printf("Los datos en pos %d son %d\n",i,*(numeros+i));
	}
	return exito;
}
/*3era funci�n: Recibe el array como puntero y accede a los datos utilizando notaci�n vectorial ([])*/
int cargaMuestraNumerosTres(int* numeros,int tamUno)
{
   int exito=0;
   int i;

   for(i=0;i<tamUno;i++)
   {
	   numeros[i]=i+1;
   }

   for(i=0;i<tamUno;i++)
   {
	   printf("Los datos en pos %d son %d\n",i,numeros[i]);
   }
   return exito;
}
/*4da funci�n: Recibe el array como puntero y accede a los datos utilizando aritm�tica de punteros*/
int cargaMuestraNumerosCuatro(int* numeros,int tamUno)
{
   int exito=0;
   int i;

   for(i=0;i<tamUno;i++)
   {
	   *(numeros+i)=i+1;
   }

   for(i=0;i<tamUno;i++)
   {
	   printf("Los datos en pos %d son %d\n",i,*(numeros+i));
   }
   return exito;
}
