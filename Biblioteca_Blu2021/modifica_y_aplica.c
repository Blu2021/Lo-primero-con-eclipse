#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "modifica_y_aplica.h"
//FUNCIONES PARA COPIAR Y PEGAR , NECESITAN MODIFICACIONES MINIMAS PARA APLICAR A CADA CASO.
int buscarLibreEstructura(int arrayRecibido[],int tamanioArrayRecibido)//AQUI REEMPLAZAR PRIMER PARAMETRO CON TIPO ESTRUCTURA
{
	int i;
	int auxLibre=-1;

	if(arrayRecibido!=NULL)
	{
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			if(arrayRecibido[i]==1)//AQUI AGREGAR .estaVacio
			{
				auxLibre=i;
				break;
			}
		}
	}
	return auxLibre;
}

int inicializarArrayEstructura(int arrayRecibido[],int tamanioArrayRecibido)//AQUI REEMPLAZAR PRIMER PARAMETRO CON TIPO ESTRUCTURA
{
	int exito=0;
	int i;
	if(arrayRecibido!=NULL)
	{
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			arrayRecibido[i]=1;//AQUI AGREGAR .estaVacio
		}
		exito=1;
	}
	return exito;
}
