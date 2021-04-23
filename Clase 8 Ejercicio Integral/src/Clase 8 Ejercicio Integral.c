//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "iniciadordearrays.h"
#include "cargadatosarrays.h"
#define ALUMNOS 5
#define LARGOAPELLIDO 20

void mostrarAlumno(int tamanioArraysRecibidos,int legajo[],char sexo[],int edad[],int notaUno[],int notaDos[],float promedio[],char apellido[][20]);
void mostrarAlumnos(int tamanioArrayRecibido,int legajo[],char sexo[],int edad[],int notaUno[],int notaDos[],float promedio[],char apellido[][20]);
int main(void)
{
	setbuf(stdout,NULL);

	int i;
	int j;
	int legajoAuxiliar;
	int legajo[ALUMNOS];
	int edad[ALUMNOS];
	int notaUno[ALUMNOS];
	int notaDos[ALUMNOS];
	float promedio[ALUMNOS];
	char sexo[ALUMNOS];
	char apellido[ALUMNOS][LARGOAPELLIDO];

	iniArrayInt(legajo,ALUMNOS);
	iniArrayChar(sexo,ALUMNOS);
	iniArrayInt(edad,ALUMNOS);
	iniArrayInt(notaUno,ALUMNOS);
	iniArrayInt(notaDos,ALUMNOS);
	iniArrayFloat(promedio,ALUMNOS);
	iniArrayCadenaChar(apellido,ALUMNOS);

	cargaDatosArrayInt(legajo,ALUMNOS,"Ingrese numero de legajo\n",1000,9999);
	cargaDatosArrayChar(sexo,ALUMNOS,"Ingrese f ó m por favor\n",'f','m');
	cargaDatosArrayInt(edad,ALUMNOS,"Ingrese edad",1,110);
	cargaDatosArrayInt(notaUno,ALUMNOS,"Ingrese notaUno",1,10);
	cargaDatosArrayInt(notaDos,ALUMNOS,"Ingrese notaDos",1,10);
	cargaDatosArrayFloat(promedio,ALUMNOS);
	cargaDatosArrayCadenaChar(apellido,ALUMNOS,"Ingrese apellido del alumno");

	mostrarAlumno(ALUMNOS,legajo,sexo,edad,notaUno,notaDos,promedio,apellido);
	mostrarAlumnos(ALUMNOS,legajo,sexo,edad,notaUno,notaDos,promedio,apellido);

	for(i=0;i<ALUMNOS-1;i++)
	{
		for(j=i+1;j<ALUMNOS;j++)
		{
			if(legajo[i]>legajo[j])
			{
				legajoAuxiliar=legajo[i];
				legajo[i]=legajo[j];
				legajo[j]=legajoAuxiliar;
			}
		}
	}
	return EXIT_SUCCESS;
}

void mostrarAlumno(int tamanioArraysRecibidos,int legajo[],char sexo[],int edad[],int notaUno[],int notaDos[],float promedio[],char apellido[][20])
{
	char continuar;
	int i;

	do
	{
		printf("Ingrese el numero de alumno que desea visualizar\n");
		scanf("%d",&i);
		while(i<0||i>tamanioArraysRecibidos-1)
		{
			printf("ERROR,Ingrese el numero de alumno que desea visualizar\n");
			scanf("%d",&i);
		}

		printf("El alumno posicion %d\nlegajo %d\nsexo %c\nedad %d\nnotaUno %d\nnotaDos %d\npromedio %.2f\napellido %s\n",i,legajo[i],sexo[i],edad[i],notaUno[i],notaDos[i],promedio[i],apellido[i]);
		printf("Desea continuar ingrese 's'\n");
		fflush(stdin);
		scanf("%c",&continuar);
	}while(continuar=='s');
}

void mostrarAlumnos(int tamanioArrayRecibido,int legajo[],char sexo[],int edad[],int notaUno[],int notaDos[],float promedio[],char apellido[][20])
{
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		printf("Datos alumno indice %d\nlegajo %d\nsexo %c\nedad %d\nnotaUno %d\nnotaDos %d\npromedio %.2f\napellido %s\n",i,legajo[i],sexo[i],edad[i],notaUno[i],notaDos[i],promedio[i],apellido[i]);
	}

}
