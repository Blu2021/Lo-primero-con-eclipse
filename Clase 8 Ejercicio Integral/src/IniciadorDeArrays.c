//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void iniArrayInt(int arrayRecibido[],int tamanioArrayRecibido)
{
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		arrayRecibido[i]=0;
	}
}

void iniArrayChar(char arrayRecibido[],int tamanioArrayRecibido)
{
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		arrayRecibido[i]='0';
	}
}

void iniArrayCadenaChar(char arrayRecibido[][20],int tamanioArrayRecibido)
{
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		strcpy(arrayRecibido[i],"0");
	}
}

void iniArrayFloat(float arrayRecibido[],int tamanioArrayRecibido)
{
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		arrayRecibido[i]=0;
	}
}
