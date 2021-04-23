//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>

#define cantidadNumeros 10
void inicializarArray(float arrayRecibido[],int tamanioArrayRecibido);
void cargarDatosArray(float arrayRecibido[],int tamanioArrayRecibido);

int main(void)
{
	setbuf(stdout,NULL);

	float numeros[cantidadNumeros];
	int i;
	int contadorPositivos=0;
	float acumuladorPositivos=0;
	float promedioPositivos;

	inicializarArray(numeros,cantidadNumeros);
	cargarDatosArray(numeros,cantidadNumeros);

	for(i=0;i<cantidadNumeros;i++)
	{
		if(numeros[i]!=0)
		{
			if(numeros[i]>0)
			{
				contadorPositivos++;
				acumuladorPositivos=acumuladorPositivos+numeros[i];
			}
		}
	}
	promedioPositivos=acumuladorPositivos/contadorPositivos;

	printf("El promedio de los positivos es %.2f\n",promedioPositivos);

	return EXIT_SUCCESS;
}

void inicializarArray(float arrayRecibido[],int tamanioArrayRecibido)
{
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		arrayRecibido[i]=0;
	}
}
void cargarDatosArray(float arrayRecibido[],int tamanioArrayRecibido)
{
	char continuar;
	float numeroCargadoAux;
	int posicion;

	do
	{
		printf("Ingrese posicion a cargar del 0 al 9\n");
		scanf("%d",&posicion);
		while(posicion<0||posicion>9)
		{
			printf("ERROR,Ingrese posicion a cargar del 0 al 9\n");
			scanf("%d",&posicion);
		}
		printf("Posicion cargada con exito\n");

		printf("Ahora Ingrese numero distinto de 0\n");
		scanf("%f",&numeroCargadoAux);
		while(numeroCargadoAux==0)
		{
			printf("ERROR,Ingrese numero distinto de 0\n");
			scanf("%f",&numeroCargadoAux);
		}
		printf("Numero cargado con exito\n");
		arrayRecibido[posicion]=numeroCargadoAux;

		printf("Ingrese s si desea continuar\n");
		fflush(stdin);
		scanf("%c",&continuar);

	}while(continuar=='s');
}
