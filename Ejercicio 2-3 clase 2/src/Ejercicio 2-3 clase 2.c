//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*Ejercicio 2-3:
Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas, de cada persona
debemos obtener los siguientes datos:
número de cliente,
estado civil (&#39;s&#39; para soltero&quot;, &#39;c&#39; para casado o &#39;v&#39; viudo),
edad( solo mayores de edad, más de 17),
temperatura corporal (validar por favor)
y sexo (&#39;f&#39; para femenino, &#39;m&#39; para masculino, &#39;o&#39; para no binario).
NOTA: el precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con estado &quot;viudo&quot; de más de 60 años.
b) el número de cliente y edad de la mujer soltera más joven.
c) cuánto sale el viaje total sin descuento.
d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que
solo mostramos si corresponde.*/
#define PRECIO 600

int main(void)
{
	setbuf(stdout,NULL);

	int numeroCliente;
	char estadoCivil;
	int edad;
	int tempCorp;
	char sexo;
	int contadorViudos=0;
	int mujerSolteraJoven;
	int numeroClienteMujer;
	int banderaMujerSoltera=0;
	int contadorPasajeros=0;
	char continuar='s';
	int precioTotal;
	int contadorViejos=0;
	int mitadPasajeros;
	int precioDto;

	while(continuar=='s')
	{
		printf("Ingrese numero de cliente\n");
		fflush(stdin);
		scanf("%d",&numeroCliente);

		printf("Ingrese estado civil s,c, ó v\n");
		fflush(stdin);
		scanf("%c",&estadoCivil);
		while(estadoCivil!='s'&&estadoCivil!='c'&&estadoCivil!='v')
		{
			printf("Error Ingrese estado civil s,c, ó v\n");
			fflush(stdin);
			scanf("%c",&estadoCivil);
		}

		printf("Ingrese edad\n");
		fflush(stdin);
		scanf("%d",&edad);
		while(edad<18||edad>110)
		{
			printf("Error Ingrese edad\n");
			fflush(stdin);
			scanf("%d",&edad);
		}

		printf("Ingrese temperatura c\n");
		fflush(stdin);
		scanf("%d",&tempCorp);
		while(tempCorp<32||tempCorp>44)
		{
			printf("Error Ingrese temp c\n");
			fflush(stdin);
			scanf("%d",&tempCorp);
		}

		printf("Ingrese sexo m o f ");
		fflush(stdin);
		scanf("%c",&sexo);
		while(sexo!='m'&&sexo!='f')
		{
			printf("Error Ingrese sexo ");
			fflush(stdin);
			scanf("%c",&sexo);
		}

		switch(estadoCivil)
		{
			case's':
				if(sexo=='f')
				{
					if(banderaMujerSoltera==0||edad<mujerSolteraJoven)
					{
						mujerSolteraJoven=edad;
						numeroClienteMujer=numeroCliente;
						banderaMujerSoltera=1;
					}
									}
			break;
			case'v':
				if(edad>60)
				{
					contadorViudos=contadorViudos+1;
				}
			break;
			case'c':
			break;
 		}

		if(edad>60)
		{
			contadorViejos=contadorViejos+1;
		}

		contadorPasajeros=contadorPasajeros+1;

		printf("Ingrese s para continuar");
		fflush(stdin);
		scanf("%c",&continuar);
	}

	if(contadorViudos!=0)
	{
		printf("La cantidad de personas viudas +60 es %d\n",contadorViudos);
	}

	if(banderaMujerSoltera==1)
	{
		printf("La mujer soltera joven tiene %d con num cliente %d\n",mujerSolteraJoven,numeroClienteMujer);
	}

	precioTotal=contadorPasajeros*PRECIO;

	mitadPasajeros=contadorPasajeros/2;

	printf("El precio total es %d\n",precioTotal);

	if(contadorViejos>mitadPasajeros)
	{
		precioDto=precioTotal-((precioTotal*25)/100);
		printf("El precio tiene dto! %d\n",precioDto);
	}

	return EXIT_SUCCESS;
}
