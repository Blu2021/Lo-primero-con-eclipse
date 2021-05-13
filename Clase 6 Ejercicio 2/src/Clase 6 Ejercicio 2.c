//DAUD MANZO JUAN PABLO
/*Ejercicio 6-2:
Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos). Necesito generar un
listado de los números positivos de manera creciente y negativos de manera decreciente. (Como máximo 4 for)
Ejemplo: Listado 1 : 4, 5, 6, 10, 18, 29 Listado 2 : -1,-5,-9,-12*/
#include <stdio.h>
#include <stdlib.h>
#define numerosTotal 10
int main(void)
{
	setbuf(stdout,NULL);

	int numeros[numerosTotal];
	int i;
	int j;
	int numeroAuxiliar;

	for(i=0;i<10;i++)
	{
		printf("Ingrese 10 numeros\n");
		scanf("%d",&numeroAuxiliar);
		numeros[i]=numeroAuxiliar;
	}

	for(i=0;i<numerosTotal-1;i++)
	{
		for(j=i+1;j<numerosTotal;j++)
		{
			if(numeros[i]>numeros[j])
			{
				numeroAuxiliar=numeros[i];
				numeros[i]=numeros[j];
				numeros[j]=numeroAuxiliar;
			}
		}
	}

	for(i=0;i<numerosTotal;i++)
	{
		if(numeros[i]>-1)
		{
			printf("posicion %d = %d\n",i,numeros[i]);
		}
	}

	for(i=numerosTotal-1;i>-1;i--)
	{
		if(numeros[i]<0)
		{
			printf("posicion %d = %d\n",i,numeros[i]);
		}
	}

	return EXIT_SUCCESS;
}
