//DAUD MANZO JUAN PABLO
/*Desarrollar un programa que permita guardar los datos de 5 alumnos. Los datos a guardar para cada alumno:
 * legajo, sexo, edad, nota1, nota2, promedio, apellido.
Hacer con estructuras - Crear un menú
Crear funciones para: *
1-Inicializar
2-cargar datos
3-Mostrar1Estudiante
4-mostrarEstudiantes
5-Ordenar por legajo
6-Ordenar por Apellido
7-Ordenar por Promedio, si se repite ordenar por legajo
*/
//TIPS SHIFT + TAB TABULO , CTRL + ESPACIO COMPLETO
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
	int legajo;
	char sexo;
	int edad;
	int notaUno;
	int notaDos;
	float promedio;
	char apellido[20];
	int idCarrera;
	int estaVacio;
}datosPersonales;

typedef struct
{
	int idCarrera;
	char descripcionCarrera[20];
	int estaVacio;
}eCarrera;

int inicializarArrayInstrumento(datosPersonales arrayRecibido[],int tamanioArrayRecibido);
int buscarLibre(datosPersonales arrayRecibido[],int tamanioArrayRecibido);
int cargaDatosEstructura(datosPersonales arrayRecibido[],int posicion);
int muestraEstructurasCargadas(datosPersonales arrayRecibido[],int tamanioArrayRecibido,eCarrera carreraElegida[],int tamanioCarrera);
int bajaDatosEstructura(datosPersonales arrayRecibido[],int tamanioArrayRecibido);
void menuModificar(datosPersonales arrayRecibido[],int tamanioArrayRecibido);
void muestraEstructuraCargada(datosPersonales estructuraRecibida,char descripcion[]);
void promedioDosNotas(datosPersonales arrayRecibido[],int posicion);
void ordenarArrayLegajo(datosPersonales arrayRecibido[],int tamanioArrayRecibido);
void ordenarArrayApellido(datosPersonales arrayRecibido[],int tamanioArrayRecibido);
void ordenarArrayPromedio(datosPersonales arrayRecibido[],int tamanioArrayRecibido);
void menuOrdenar(datosPersonales arrayRecibido[],int tamanioArrayRecibido);
void consigueDescripcion(eCarrera arrayRecibido[],int tamanioArrayRecibido,int idCarrera,char descripcion[]);
#define DATOS 5

int main(void)
{
	setbuf(stdout,NULL);
	datosPersonales datosAlumnos[DATOS];
	eCarrera carreraElegida[3]={{1,"Programacion",0},{2,"Laboratorio",0},{3,"Sistemas",0}};
	int opcionMenu;
	int posLibre;
	int legajoIncremental=1000;

	inicializarArrayInstrumento(datosAlumnos,DATOS);
	do
	{
		printf("Bienvenido al Menu DatosAlumnos\nIngrese opcion\n");
		printf("1: DAR DE ALTA\n");
		printf("2: LISTAR\n");
		printf("3: DAR DE BAJA\n");
		printf("4: MODIFICAR\n");
		printf("5: ORDENAR\n");
		printf("6: SALIR\n");
		scanf("%d",&opcionMenu);
		while(opcionMenu>6||opcionMenu<1)
		{
			printf("Error, ingrese una opcion de menu valida\n");
			scanf("%d",&opcionMenu);
		}
		switch(opcionMenu)
		{
			case 1:
				posLibre=buscarLibre(datosAlumnos,DATOS);
				if(posLibre!=-1)
				{
					cargaDatosEstructura(datosAlumnos,posLibre);
					datosAlumnos[posLibre].legajo=legajoIncremental;
					legajoIncremental++;
					printf("ALTA EXITOSA\n");
					printf("Pulse cualquiera tecla para volver\n");
					fflush(stdin);
					getchar();
				}
				else
				{
					printf("No hay posicion libre en cual cargar datos, elimine al menos una\n");
					printf("Pulse cualquiera tecla para volver\n");
					fflush(stdin);
					getchar();
				}
			break;
			case 2:
				    muestraEstructurasCargadas(datosAlumnos,DATOS,carreraElegida,3);
					printf("Pulse cualquiera tecla para volver\n");
					fflush(stdin);
					getchar();
			break;
			case 3:
				bajaDatosEstructura(datosAlumnos,DATOS);
			break;
			case 4:
				menuModificar(datosAlumnos,DATOS);
			break;
			case 5:
				menuOrdenar(datosAlumnos,DATOS);
			break;
		}
	}while(opcionMenu!=6);

	return EXIT_SUCCESS;
}

int inicializarArrayInstrumento(datosPersonales arrayRecibido[],int tamanioArrayRecibido)
{
	int exito=0;
	int i;
	if(arrayRecibido!=NULL)
	{
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			arrayRecibido[i].estaVacio=1;
		}
		exito=1;
	}
	return exito;
}

int buscarLibre(datosPersonales arrayRecibido[],int tamanioArrayRecibido)
{
	int i;
	int auxLibre=-1;

	if(arrayRecibido!=NULL)
	{
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			if(arrayRecibido[i].estaVacio==1)
			{
				auxLibre=i;
				break;
			}
		}
	}
	return auxLibre;
}

int cargaDatosEstructura(datosPersonales arrayRecibido[],int posicion)
{
	int exito=0;
	char auxSexo;
	int auxEdad;
	int auxNotaUno;
	int auxNotaDos;
	int opcionCarrera;

	if(arrayRecibido!=NULL)
	{
		printf("Ingrese sexo m ó f\n");
		fflush(stdin);
		scanf("%c",&auxSexo);
		while(auxSexo!='m'&&auxSexo!='f')
		{
			printf("ERROR,Ingrese sexo m ó f\n");
			fflush(stdin);
			scanf("%c",&auxSexo);
		}
		arrayRecibido[posicion].sexo=auxSexo;
		printf("Ingrese edad\n");
		fflush(stdin);
		scanf("%d",&auxEdad);
		while(auxEdad<18||auxEdad>100)
		{
			printf("ERROR,Ingrese edad entre 18 y 100\n");
			fflush(stdin);
			scanf("%d",&auxEdad);
		}
		arrayRecibido[posicion].edad=auxEdad;
		printf("Ingrese nota Uno\n");
		fflush(stdin);
		scanf("%d",&auxNotaUno);
		while(auxNotaUno<1||auxNotaUno>10)
		{
			printf("ERROR,Ingrese nota Uno\n");
			fflush(stdin);
			scanf("%d",&auxNotaUno);
		}
		arrayRecibido[posicion].notaUno=auxNotaUno;
		printf("Ingrese nota Dos\n");
		fflush(stdin);
		scanf("%d",&auxNotaDos);
		while(auxNotaDos<1||auxNotaDos>10)
		{
			printf("ERROR,Ingrese nota Dos\n");
			fflush(stdin);
			scanf("%d",&auxNotaDos);
		}
		arrayRecibido[posicion].notaDos=auxNotaDos;
		printf("Ingrese apellido\n");
		fflush(stdin);
		fgets (arrayRecibido[posicion].apellido,19,stdin);
		printf("Ingrese carrera Programacion 1\n"
			   "                Laboratorio  2\n"
			   "                Sistemas     3\n");
		fflush(stdin);
		scanf("%d",&opcionCarrera);
		while(opcionCarrera<1||opcionCarrera>3)
		{
			printf("ERROR,Ingrese carrera Programacion 1\n"
				   "                      Laboratorio  2\n"
				   "                      Sistemas     3\n");
			fflush(stdin);
			scanf("%d",&opcionCarrera);
		}
		arrayRecibido[posicion].idCarrera=opcionCarrera;
		arrayRecibido[posicion].estaVacio=0;
		promedioDosNotas(arrayRecibido,posicion);
		exito=1;
	}
	return exito;
}
void promedioDosNotas(datosPersonales arrayRecibido[],int posicion)
{
	float promedio;
	float notaUno=arrayRecibido[posicion].notaUno;
	float notaDos=arrayRecibido[posicion].notaDos;

	promedio=(notaUno+notaDos)/2;
	arrayRecibido[posicion].promedio=promedio;
}

int muestraEstructurasCargadas(datosPersonales arrayRecibido[],int tamanioArrayRecibido,eCarrera carreraElegida[],int tamanioCarrera)
{
	int i;
	int exito=0;
	int sePuedeMostrar=1;
	char descripcionCarrera[19];

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		if(arrayRecibido[i].estaVacio==0)
		{
			if(sePuedeMostrar)
			{
				printf("--------------------------------DATOS DE ALUMNOS------------------------------\n");
				printf("Legajo    sexo    edad     notaUno    notaDos    promedio  apellido    carrera\n");
				sePuedeMostrar=0;
			}
			consigueDescripcion(carreraElegida,tamanioCarrera,arrayRecibido[i].idCarrera,descripcionCarrera);
			muestraEstructuraCargada(arrayRecibido[i],descripcionCarrera);
			exito=1;
		}
	}
	if(sePuedeMostrar)
	{
		printf("No hay datos cargados que mostrar\n\n");
	}
	return exito;
}

void consigueDescripcion(eCarrera arrayRecibido[],int tamanioArrayRecibido,int idCarrera,char descripcion[])
{
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		if(arrayRecibido[i].estaVacio==0&&idCarrera==arrayRecibido[i].idCarrera)
		{
			strncpy(descripcion,arrayRecibido[i].descripcionCarrera,19);
		}
	}
}
void muestraEstructuraCargada(datosPersonales estructuraRecibida,char descripcion[])
{
	char auxCadena[19];

	strcpy(auxCadena,descripcion);
	auxCadena[strcspn(auxCadena,"\n")]=0;

	printf("%-10d%-8c%-9d%-11d%-11d%-10.2f%-12s%s\n",estructuraRecibida.legajo,estructuraRecibida.sexo,estructuraRecibida.edad,estructuraRecibida.notaUno,estructuraRecibida.notaDos,estructuraRecibida.promedio,estructuraRecibida.apellido,auxCadena);
}

int bajaDatosEstructura(datosPersonales arrayRecibido[],int tamanioArrayRecibido)
{
	int exito=0;
	int opcionBaja;
	int legajoBaja;
	int legajoExistente=0;
	int i;

	if(arrayRecibido!=NULL)
	{
		exito=1;
		printf("Ingrese legajo a dar de baja\n");
		scanf("%d",&legajoBaja);
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			if(legajoBaja==arrayRecibido[i].legajo&&arrayRecibido[i].estaVacio==0)
			{
				legajoExistente=1;
				break;
			}
		}

		if(legajoExistente)
		{
			printf("Usted dara de baja el legajo %d, presione 1 para continuar o 2 para cancelar\n",legajoBaja);
			//muestraEstructuraCargada(arrayRecibido[i]);
			scanf("%d",&opcionBaja);
			while(opcionBaja!=1&&opcionBaja!=2)
			{
				printf("ERROR,ingrese opcion valida\n");
				fflush(stdin);
				scanf("%d",&opcionBaja);
			}
			if(opcionBaja==1)
			{
				arrayRecibido[i].estaVacio=1;
				printf("Los datos se han dado de baja exitosamente\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
			}
		}
		else
		{
			printf("No hay datos cargados cuales dar de baja ó el legajo es invalido, verifique\n");
			printf("Pulse cualquiera tecla para volver\n");
			fflush(stdin);
			getchar();
		}
	}
	return exito;
}

void menuModificar(datosPersonales arrayRecibido[],int tamanioArrayRecibido)
{
	int legajoModificar;
	int legajoExistente=0;
	int campoModificar;
	int i;

	printf("Bienvenido a Menu Modificar\n");
	printf("Ingrese legajo a modificar\n");
	scanf("%d",&legajoModificar);
	for(i=0;i<tamanioArrayRecibido;i++)
	{
		if(legajoModificar==arrayRecibido[i].legajo&&arrayRecibido[i].estaVacio==0)
		{
			legajoExistente=1;
			break;
		}
	}
	if(legajoExistente)
	{
		printf("¿Que campo desea modificar?\n");
		printf("sexo=1\nedad=2\nnotaUno=3\nnotaDos=4\npromedio=5\napellido=6\n");
		scanf("%d",&campoModificar);
		while(campoModificar<1||campoModificar>6)
		{
			printf("ERROR,CAMPO INVALIDO ¿Que campo desea modificar?\n");
			printf("sexo=1\nedad=2\nnotaUno=3\nnotaDos=4\napellido=5\n");
			scanf("%d",&campoModificar);
		}
		switch(campoModificar)
		{
			case 1:
				printf("Reingrese sexo\n");
				fflush(stdin);
				scanf("%c",&arrayRecibido[i].sexo);
			break;
			case 2:
				printf("Reingrese edad\n");
				scanf("%d",&arrayRecibido[i].edad);
			break;
			case 3:
				printf("Reingrese nota Uno\n");
				scanf("%d",&arrayRecibido[i].notaUno);
				promedioDosNotas(arrayRecibido,i);
			break;
			case 4:
				printf("Reingrese nota Dos\n");
				scanf("%d",&arrayRecibido[i].notaDos);
				promedioDosNotas(arrayRecibido,i);
			break;
			case 5:
				printf("Reingrese apellido\n");
				fflush(stdin);
				fgets (arrayRecibido[i].apellido,19,stdin);
			break;
		}
	}
	else
	{
		printf("ERROR,usted no ha ingresado legajo valido, verifique y reingrese\n");
		printf("Pulse cualquiera tecla para volver\n");
		fflush(stdin);
		getchar();
	}
}

void ordenarArrayLegajo(datosPersonales arrayRecibido[],int tamanioArrayRecibido)
{
	int i;
	int j;
	datosPersonales estructuraAuxiliar;

	for(i=0;i<tamanioArrayRecibido-1;i++)
	{
		for(j=i+1;j<tamanioArrayRecibido;j++)
		{
			if(arrayRecibido[i].estaVacio==0&&arrayRecibido[j].estaVacio==0)
			{
				if(arrayRecibido[i].legajo>arrayRecibido[j].legajo)
				{
					estructuraAuxiliar=arrayRecibido[i];
					arrayRecibido[i]=arrayRecibido[j];
					arrayRecibido[j]=estructuraAuxiliar;
				}
			}
		}
	}
}

void ordenarArrayApellido(datosPersonales arrayRecibido[],int tamanioArrayRecibido)
{
	int i;
	int j;
	datosPersonales estructuraAuxiliar;

	for(i=0;i<tamanioArrayRecibido-1;i++)
	{
		for(j=i+1;j<tamanioArrayRecibido;j++)
		{
			if(arrayRecibido[i].estaVacio==0&&arrayRecibido[j].estaVacio==0)
			{
				strlwr(arrayRecibido[i].apellido);
				strlwr(arrayRecibido[j].apellido);
				if(arrayRecibido[i].apellido[0]>arrayRecibido[j].apellido[0])
				{
					estructuraAuxiliar=arrayRecibido[i];
					arrayRecibido[i]=arrayRecibido[j];
					arrayRecibido[j]=estructuraAuxiliar;
				}
			}
		}
	}
}

void ordenarArrayPromedio(datosPersonales arrayRecibido[],int tamanioArrayRecibido)
{
	int i;
	int j;
	datosPersonales estructuraAuxiliar;

	for(i=0;i<tamanioArrayRecibido-1;i++)
	{
		for(j=i+1;j<tamanioArrayRecibido;j++)
		{
			if(arrayRecibido[i].estaVacio==0&&arrayRecibido[j].estaVacio==0)
			{
				if(arrayRecibido[i].promedio>arrayRecibido[j].promedio)
				{
					estructuraAuxiliar=arrayRecibido[i];
					arrayRecibido[i]=arrayRecibido[j];
					arrayRecibido[j]=estructuraAuxiliar;
				}
				else
				{
					if(arrayRecibido[i].promedio==arrayRecibido[j].promedio)
					{
						if(arrayRecibido[i].legajo>arrayRecibido[j].legajo)
						{
							estructuraAuxiliar=arrayRecibido[i];
							arrayRecibido[i]=arrayRecibido[j];
							arrayRecibido[j]=estructuraAuxiliar;
						}
					}
				}
			}
		}
	}
}

void menuOrdenar(datosPersonales arrayRecibido[],int tamanioArrayRecibido)
{
	int opcionOrdenar;

	printf("BIENVENIDO AL SUBMENU ORDENAR\n"
		   "ordenar por legajo:   1\n"
		   "ordenar por apellido: 2\n"
		   "ordenar por promedio: 3\n");
	fflush(stdin);
	scanf("%d",&opcionOrdenar);
	while(opcionOrdenar>3||opcionOrdenar<1)
	{
		printf("ERROR,ingrese opcion valida\n");
		fflush(stdin);
		scanf("%d",&opcionOrdenar);
	}

	switch(opcionOrdenar)
	{
		case 1:
			ordenarArrayLegajo(arrayRecibido,tamanioArrayRecibido);
			printf("ARRAY ORDENADO POR LEGAJO\n"
				   "Pulse cualquiera tecla para volver\n");
			fflush(stdin);
			getchar();
		break;
		case 2:
			ordenarArrayApellido(arrayRecibido,tamanioArrayRecibido);
			printf("ARRAY ORDENADO POR APELLIDO\n"
				   "Pulse cualquiera tecla para volver\n");
			fflush(stdin);
			getchar();
		break;
		case 3:
			ordenarArrayPromedio(arrayRecibido,tamanioArrayRecibido);
			printf("ARRAY ORDENADO POR PROMEDIO\n"
				   "Pulse cualquiera tecla para volver\n");
			fflush(stdin);
			getchar();
		break;
	}
}
