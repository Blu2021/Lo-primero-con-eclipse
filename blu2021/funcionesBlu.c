#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funcionesBlu.h"

int utn_levantaEnteros(int* resultado,char* mensaje,char* mensajeError,int min,int max,int reintentos)
{
	int aux;
	int exito=0;
	int tipoValidado;

	if(resultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&min<=max&&reintentos>-1)
	{
		do{
			printf("%s\n",mensaje);
			fflush(stdin);
			tipoValidado=scanf("%d",&aux);
			if(aux<min||aux>max||tipoValidado==0)
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
			else
			{
				*resultado=aux;
				exito=1;
				break;
			}
		}while(reintentos>-1);
	}
	return exito;
}

int utn_levantaCadenaCaracteres(char cadena[],char* mensaje,char* mensajeError,int largoCadena)
{
	int exito=0;
	int i;
	char auxCadena[largoCadena];

	inicializarCadenaCaracteres(auxCadena,largoCadena);

	if(cadena!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&largoCadena>0)
	{
		while(exito==0)
		{
			printf("%s\n",mensaje);
			fflush(stdin);
			if(fgets(auxCadena,largoCadena,stdin)!=NULL)
			{
				exito=1;
				for(i=0;i<largoCadena;i++)
				{
					if(isdigit(auxCadena[i]))
					{
						exito=0;
						break;
					}
				}
				auxCadena[strcspn(auxCadena,"\n")]=0;
				strcpy(cadena,auxCadena);
			}
			else
			{
				printf("%s\n",mensajeError);
			}
		}
	}
	return exito;
}

void ordenarArray(int arrayRecibido[],int tamanioArrayRecibido)
{
	int i;
	int j;
	int estructuraAuxiliar;

	for(i=0;i<tamanioArrayRecibido-1;i++)
	{
		for(j=i+1;j<tamanioArrayRecibido;j++)
		{
			if(arrayRecibido[i]==0&&arrayRecibido[j]==0)
			{
				if(arrayRecibido[i]>arrayRecibido[j])
				{
					estructuraAuxiliar=arrayRecibido[i];
					arrayRecibido[i]=arrayRecibido[j];
					arrayRecibido[j]=estructuraAuxiliar;
				}
			}
		}
	}
}

int inicializarCadenaCaracteres(char cadenaRecibida[],int largoCadena)
{
	int exito=0;
	int i;
	if(cadenaRecibida!=NULL)
	{
		for(i=0;i<largoCadena;i++)
		{
			cadenaRecibida[i]=' ';
		}
		exito=1;
	}
	return exito;
}
