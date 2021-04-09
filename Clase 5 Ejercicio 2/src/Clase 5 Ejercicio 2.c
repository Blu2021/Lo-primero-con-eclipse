//DAUD MANZO JUAN PABLO
/*
	Listado de los números ingresados.Listado de los números pares
 * .Listado de los números de las posiciones impares.  Se deberán utilizar funciones y vectores.
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);

	int numerosPedidos[10];
	int i;
	int contadorPositivos=0;
	int contadorNegativos=0;
	int sumadorDePares=0;
	int mayorDeLosImpares;
	int banderaImpar=0;

	for(i=0;i<10;i++)
	{
		printf("El programa le pedira 10 numeros , ingrese numero\n");
		scanf("%d",&numerosPedidos[i]);
		while(numerosPedidos[i]<-1000||numerosPedidos[i]>1000)
		{
			printf("ERROR,El programa le pedira 10 numeros , ingrese numero\n");
			scanf("%d",&numerosPedidos[i]);
		}

		if(numerosPedidos[i]<0)
		{
			contadorNegativos++;
		}
		else
		{
			contadorPositivos++;
		}

		if(numerosPedidos[i]%2==0)
		{
			sumadorDePares=sumadorDePares+numerosPedidos[i];
		}
		else
		{
			if(banderaImpar==0||numerosPedidos[i]>mayorDeLosImpares)
			{
				mayorDeLosImpares=numerosPedidos[i];
				banderaImpar=1;
			}
		}
	}

	printf("La cantidad de positivos es %d y la cantidad de negativos %d\n",contadorPositivos,contadorNegativos);
	printf("La sumatoria de pares es %d\n",sumadorDePares);
	printf("El mayor de los impares es %d\n",mayorDeLosImpares);

	return EXIT_SUCCESS;
}
