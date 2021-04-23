#include <stdio.h>
#include <stdlib.h>

void cargaDatosArrayInt(int arrayRecibido[],int tamanioArrayRecibido,char* mensaje,int numMin,int numMax)
{
	int i;
	int auxInt=0;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		printf("%s\n",mensaje);
		scanf("%d",&auxInt);
		while(auxInt<numMin||auxInt>numMax)
		{
			printf("ERROR, %s\n",mensaje);
			scanf("%d",&auxInt);
		}
		arrayRecibido[i]=auxInt;
	}
}

void cargaDatosArrayChar(char arrayRecibido[],int tamanioArrayRecibido,char* mensaje,char carUno,char carDos)
{
	int i;
	char auxChar='0';

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		printf("%s\n",mensaje);
		fflush(stdin);
		scanf("%c",&auxChar);
		while(auxChar!=carUno&&auxChar!=carDos)
		{
			printf("ERROR, %s\n",mensaje);
			fflush(stdin);
			scanf("%c",&auxChar);
		}
		arrayRecibido[i]=auxChar;
	}
}

void cargaDatosArrayFloat(float arrayRecibido[],int tamanioArrayRecibido)
{
	int i;
	float auxFloat=0;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		printf("Ingresar numero float\n");
		scanf("%f",&auxFloat);
		arrayRecibido[i]=auxFloat;
	}
}

void cargaDatosArrayCadenaChar(char arrayRecibido[][20],int tamanioArrayRecibido,char* mensaje)
{
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		printf("%s\n",mensaje);
		gets(arrayRecibido[i]);
	}
}
