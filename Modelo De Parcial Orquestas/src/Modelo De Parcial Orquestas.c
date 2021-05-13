//DAUD MANZO JUAN PABLO
/*Un teatro necesita gestionar las orquestas que realizan conciertos en el lugar, para ello es necesario desarrollar un software que contará con el siguiente menú:

1) Agregar Orquesta: Se da de alta una orquesta con nombre, lugar y tipo. Se generará un ID único para esta orquesta que se imprimirá por pantalla si el alta es correcta.

2) Eliminar Orquesta: Se imprime la lista de orquestas. Luego se pide que se ingrese un ID y la misma se eliminará, junto con los músicos que la componen.

3) Imprimir Orquestas: Se imprime la lista de orquestas.

4) Agregar Músico: Se da de alta un músico con nombre, apellido, edad, ID de la orquesta en la que tocará, e ID del instrumento que toca.

5) Modificar Músico: Se imprime la lista de músicos con ID, Nombre y Apellido. Luego se pide que se ingrese un ID y se podrán modificar los campos edad o ID de orquesta donde toca.

6) Eliminar Músico: Se imprime la lista de músicos con ID, Nombre y Apellido. Luego se pide que se ingrese un ID y el músico se eliminará.

7) Imprimir Músicos: Se imprime la lista de músicos con ID, Nombre y Apellido, nombre y tipo de instrumento.

8) Agregar Instrumento: Se da de alta un instrumento con nombre y tipo. Se generará un ID único para este instrumento que se imprimirá por pantalla si el alta es correcta.

9) Imprimir instrumentos: Se imprime la lista de instrumentos indicando ID, nombre y tipo (Indicar el tipo con un texto, no con números)




Datos:
•	Los tipos de orquesta que existirán son:
◦	Sinfónica
◦	Filarmónica
◦	Cámara
•	Los tipos de instrumento que existirán son:
◦	Cuerdas
◦	Viento-madera
◦	Viento-metal
◦	Percusión
•	Existirán 50 orquestas como máximo.
•	Existirán 20 instrumentos como máximo.
•	Existirán 1000 músicos como máximo.
•	Un músico solo pertenece a una orquesta.


Recomendaciones:

•	Agregar al campo “isEmpty” a cada entidad.
•	Generar un ID auto incrementable para cada entidad.
•	Tratar a los “tipos” de orquesta e instrumento, como valores numéricos.
•	Antes de comenzar, realizar un diagrama con las entidades, todos sus campos y cómo se relacionan.
•	Antes de comenzar, realizar las funciones para imprimir cada uno de los arrays con todos sus campos (sin relacionarlos con los otros arrays) para poder probar los ABM.
•	Para poder probar los informes, realizar funciones que carguen con datos falsos los arrays de las entidades, y ejecutarlas al comenzar el programa.


Nota 1: Se deberán desarrollar bibliotecas por cada entidad las cuales contendrán las funciones (Alta, Baja, Modificar, etc.). Los informes deberán estar en una biblioteca aparte.
Nota 2: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de estilo de la cátedra.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesBlu.h"

#define ORQUESTAS 3
#define MUSICOS 3
#define INSTRUMENTOS 3

typedef struct
{
	char nombreOrquesta[15];
	char lugarOrquesta[15];
	int idTipoOrquesta;
	int idOrquesta;
	int estaVacio;
}eOrquesta;

typedef struct
{
	int idTipoOrquesta;
	char tipoOrquesta[15];
	int estaVacio;
}eTipoOrquesta;

typedef struct
{
	char nombre[15];
	char apellido[15];
	int edad;
	int idOrquesta;
	int idTipoInstrumento;
	int idMusico;
	int estaVacio;
}eMusico;

typedef struct
{
	char nombreInstrumento[15];
	int idInstrumento;
	int idTipoInstrumento;
	int estaVacio;
}eInstrumentos;

typedef struct
{
	int idTipoInstrumento;
	char descripcion[15];
	int estaVacio;
}eTipoInstrumento;

int inicializarArrayOrquesta(eOrquesta arrayRecibido[],int tamanioArrayRecibido);
int inicializarArrayMusico(eMusico arrayRecibido[],int tamanioArrayRecibido);
int inicializarArrayInstrumentos(eInstrumentos arrayRecibido[],int tamanioArrayRecibido);
int buscarLibreOrquesta(eOrquesta arrayRecibido[],int tamanioArrayRecibido);
int buscarLibreMusico(eMusico arrayRecibido[],int tamanioArrayRecibido);
int buscarLibreInstrumento(eInstrumentos arrayRecibido[],int tamanioArrayRecibido);
int cargaDatosOrquesta(eOrquesta arrayRecibido[],int posicion,eTipoOrquesta arrayRecibidoDos[]);
int cargaDatosInstrumento(eInstrumentos arrayRecibido[],int posicion);
int cargaDatosMusico(eMusico arrayRecibido[],int posicion,eOrquesta arrayRecibidoDos[],eInstrumentos arrayRecibidoTres[]);
void muestraOrquestaCargada(eOrquesta estructuraRecibida,char descripcionRecibida[]);
int muestraOrquestasCargadas(eOrquesta arrayRecibido[],int tamanioArrayRecibido,eTipoOrquesta arrayRecibidoDos[],int tamanioArrayRecibidoDos);
void consigueTipoOrquesta(eTipoOrquesta arrayRecibido[],int tamanioArrayRecibido,int idTipoOrquesta,char tipo[]);
int muestraMusicosCargados(eMusico arrayRecibido[],int tamanioArrayRecibido,eTipoInstrumento arrayRecibidoDos[],int tamanioArrayRecibidoDos,eInstrumentos arrayRecibidoTres[],int tamanioArrayRecibidoTres);
void muestraMusicoCargado(eMusico estructuraRecibida,char descripcionInstrumento[],char descripcionTipoInstrumento[]);
void consigueTipoInstrumento(eTipoInstrumento arrayRecibido[],int tamanioArrayRecibido,int idTipoInstrumento,char tipo[]);
void consigueNombreInstrumento(eInstrumentos arrayRecibido[],int tamanioArrayRecibido,int idInstrumento,char nombre[]);
int bajaDatosOrquesta(eOrquesta arrayRecibido[],int tamanioArrayRecibido,eMusico arrayRecibidoDos[],int tamanioArrayRecibidoDos);

int main(void)
{
	setbuf(stdout,NULL);

	eOrquesta orquestas[ORQUESTAS];
	eTipoOrquesta tipoOrquesta[3]={{1,"Sinfonica",0},{2,"Filarmonica",0},{3,"Camara",0}};
	eMusico musicos[MUSICOS];
	eInstrumentos instrumentos[INSTRUMENTOS];
	eTipoInstrumento tipoInstrumento[4]={{1,"Cuerdas",0},{2,"Viento-madera",0},{3,"Viento-metal",0},{4,"Percusión",0}};
	int idOrquestas=0;
	int idMusicos=0;
	int idInstrumentos=0;
	int resultadoOpcionMenu;
	int posLibre;

	inicializarArrayOrquesta(orquestas,ORQUESTAS);
	inicializarArrayMusico(musicos, MUSICOS);
	inicializarArrayInstrumentos(instrumentos, INSTRUMENTOS);

	do
	{
		printf("Bienvenido al Menu Orquestas\n"
		          "1: AGREGAR ORQUESTA\n"
		          "2: ELIMINAR ORQUESTA\n"
		          "3: IMPRIMIR ORQUESTAS\n"
	              "4: AGREGAR MUSICO\n"
		          "5: MODIFICAR MUSICO\n"
		          "6: ELIMINAR MUSICO\n"
				  "7: IMPRIMIR MUSICOS\n"
				  "8: AGREGAR INSTRUMENTO\n"
				  "9: SALIR\n");
		if(utn_levantaEnteros(&resultadoOpcionMenu,"Ingrese opcion Menu","ERROR,opcion invalida",1,9,3))
		{
			switch(resultadoOpcionMenu)
			{
				case 1:
					posLibre=buscarLibreOrquesta(orquestas,ORQUESTAS);
					if(posLibre!=-1)
					{
						if(cargaDatosOrquesta(orquestas,posLibre,tipoOrquesta))
						{
							orquestas[posLibre].idOrquesta=idOrquestas;
							idOrquestas++;
							printf("Pulse cualquiera tecla para volver\n");
							fflush(stdin);
							getchar();
						}
						else
						{
							printf("Algo fallo en la carga de datos\n");
							printf("Pulse cualquiera tecla para volver\n");
							fflush(stdin);
							getchar();
						}
					}
					else
					{
						printf("No hay lugar disponible, elimine al menos uno\n");
						printf("Pulse cualquiera tecla para volver\n");
						fflush(stdin);
						getchar();
					}
				break;
				case 2:
					muestraOrquestasCargadas(orquestas,ORQUESTAS,tipoOrquesta,3);
					bajaDatosOrquesta(orquestas,ORQUESTAS,musicos,MUSICOS);
				break;
				case 3:
					muestraOrquestasCargadas(orquestas,ORQUESTAS,tipoOrquesta,3);
					printf("Pulse cualquiera tecla para volver\n");
					fflush(stdin);
					getchar();
				break;
				case 4:
					posLibre=buscarLibreMusico(musicos,MUSICOS);
					if(posLibre!=-1)
					{
						if(cargaDatosMusico(musicos,posLibre,orquestas,instrumentos))
						{
							musicos[posLibre].idMusico=idMusicos;
							idMusicos++;
							printf("Pulse cualquiera tecla para volver\n");
							fflush(stdin);
							getchar();
						}
						else
						{
							printf("Algo fallo en la carga de datos\n");
							printf("Pulse cualquiera tecla para volver\n");
							fflush(stdin);
							getchar();
						}
					}
					else
					{
						printf("No hay lugar disponible, elimine al menos uno\n");
						printf("Pulse cualquiera tecla para volver\n");
						fflush(stdin);
						getchar();
					}
				break;
				case 5:
				break;
				case 6:
				break;
				case 7:
					muestraMusicosCargados(musicos,MUSICOS,tipoInstrumento,4,instrumentos,INSTRUMENTOS);
					printf("Pulse cualquiera tecla para volver\n");
					fflush(stdin);
					getchar();
				break;
				case 8:
					posLibre=buscarLibreInstrumento(instrumentos,INSTRUMENTOS);
					if(posLibre!=-1)
					{
						if(cargaDatosInstrumento(instrumentos,posLibre))
						{
							instrumentos[posLibre].idTipoInstrumento=idInstrumentos;
							idInstrumentos++;
							printf("Pulse cualquiera tecla para volver\n");
							fflush(stdin);
							getchar();
						}
						else
						{
							printf("Algo fallo en la carga de datos\n");
							printf("Pulse cualquiera tecla para volver\n");
							fflush(stdin);
							getchar();
						}
					}
					else
					{
						printf("No hay lugar disponible, elimine al menos uno\n");
						printf("Pulse cualquiera tecla para volver\n");
						fflush(stdin);
						getchar();
					}
				break;
				case 9:
					printf("Menu esta finalizando...");
				break;
			}
		}
		else
		{
			printf("Usted debe ingresar del 1 al 9 , intente de nuevo\n");
		}

	}while(resultadoOpcionMenu!=9);


	return EXIT_SUCCESS;
}

int inicializarArrayOrquesta(eOrquesta arrayRecibido[],int tamanioArrayRecibido)
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

int inicializarArrayMusico(eMusico arrayRecibido[],int tamanioArrayRecibido)
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

int inicializarArrayInstrumentos(eInstrumentos arrayRecibido[],int tamanioArrayRecibido)
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

int buscarLibreOrquesta(eOrquesta arrayRecibido[],int tamanioArrayRecibido)
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

int buscarLibreMusico(eMusico arrayRecibido[],int tamanioArrayRecibido)
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

int buscarLibreInstrumento(eInstrumentos arrayRecibido[],int tamanioArrayRecibido)
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

int cargaDatosOrquesta(eOrquesta arrayRecibido[],int posicion,eTipoOrquesta arrayRecibidoDos[])
{
	int exito=0;
	char auxNombreOrquesta[15];
	char auxLugarOrquesta[15];
	int auxTipoOrquesta;

	inicializarCadenaCaracteres(auxNombreOrquesta,15);
	inicializarCadenaCaracteres(auxLugarOrquesta,15);

	if(arrayRecibido!=NULL&&arrayRecibidoDos!=NULL)
	{
		utn_levantaCadenaCaracteres(auxNombreOrquesta,"Ingrese nombre orquesta","Error,Reingrese nombre sin numeros",15);
		utn_levantaCadenaCaracteres(auxLugarOrquesta,"Ingrese lugar orquesta","Error,Reingrese lugar sin numeros",15);
		printf("Ingrese tipo    Sinfonica    1\n"
			   "                Filarmonica  2\n"
			   "                Camara       3\n");
		fflush(stdin);
		scanf("%d",&auxTipoOrquesta);
		while(auxTipoOrquesta<1||auxTipoOrquesta>3)
		{
			printf("ERROR,Ingrese tipo Sinfonica    1\n"
			       "                   Filarmonica  2\n"
			       "                   Camara       3\n");
			fflush(stdin);
			scanf("%d",&auxTipoOrquesta);
		}
		arrayRecibido[posicion].idTipoOrquesta=auxTipoOrquesta;
		strcpy(arrayRecibido[posicion].nombreOrquesta,auxNombreOrquesta);
		strcpy(arrayRecibido[posicion].lugarOrquesta,auxLugarOrquesta);
		arrayRecibido[posicion].estaVacio=0;
		exito=1;
	}
	return exito;
}

int cargaDatosMusico(eMusico arrayRecibido[],int posicion,eOrquesta arrayRecibidoDos[],eInstrumentos arrayRecibidoTres[])
{
	int exito=0;
	char auxNombre[15];
	char auxApellido[15];
	int auxEdad;
	int auxTipoOrquesta;

	inicializarCadenaCaracteres(auxNombre,15);
	inicializarCadenaCaracteres(auxApellido,15);

	if(arrayRecibido!=NULL&&arrayRecibidoDos!=NULL&&arrayRecibidoTres!=NULL)
	{
		utn_levantaCadenaCaracteres(auxNombre,"Ingrese nombre musico","Error,Reingrese nombre sin numeros",15);
		utn_levantaCadenaCaracteres(auxApellido,"Ingrese apellido musico","Error,Reingrese apellido sin numeros",15);
		utn_levantaEnteros(&auxEdad,"Ingrese edad","Error,reingrese edad",18,90,3);
		printf("Ingrese tipo orquesta  Sinfonica    1\n"
			   "   para el musico      Filarmonica  2\n"
			   "                       Camara       3\n");
		fflush(stdin);
		scanf("%d",&auxTipoOrquesta);
		while(auxTipoOrquesta<1||auxTipoOrquesta>3)
		{
			printf("ERROR,Ingrese tipo Sinfonica    1\n"
				   "                   Filarmonica  2\n"
				   "                   Camara       3\n");
			fflush(stdin);
			scanf("%d",&auxTipoOrquesta);
		}
		strcpy(arrayRecibido[posicion].nombre,auxNombre);
		strcpy(arrayRecibido[posicion].apellido,auxApellido);
		arrayRecibido[posicion].edad=auxEdad;
		arrayRecibido[posicion].idOrquesta=auxTipoOrquesta;
		arrayRecibido[posicion].estaVacio=0;
		exito=1;
	}
	return exito;
}

int cargaDatosInstrumento(eInstrumentos arrayRecibido[],int posicion)
{
	int exito=0;
	char auxNombreInstrumento[15];
	int auxIdTipoInstrumento;

	inicializarCadenaCaracteres(auxNombreInstrumento,15);

	if(arrayRecibido!=NULL)
	{
		utn_levantaCadenaCaracteres(auxNombreInstrumento,"Ingrese Nombre Instrumento","ERROR,reingrese",15);
		printf("Ingrese tipo  cuerdas       1\n"
			   "              viento-madera 2\n"
			   "              viento-metal  3\n"
			   "              percusion     4\n");
		fflush(stdin);
		scanf("%d",&auxIdTipoInstrumento);
		while(auxIdTipoInstrumento<1||auxIdTipoInstrumento>4)
		{
			printf("ERROR,Ingrese tipo  cuerdas       1\n"
				   "                    viento-madera 2\n"
				   "                    viento-metal  3\n"
				   "                    percusion     4\n");
			fflush(stdin);
			scanf("%d",&auxIdTipoInstrumento);
		}
		strcpy(arrayRecibido[posicion].nombreInstrumento,auxNombreInstrumento);
		arrayRecibido[posicion].idTipoInstrumento=auxIdTipoInstrumento;
		arrayRecibido[posicion].estaVacio=0;
		exito=1;
	}
	return exito;
}

int muestraOrquestasCargadas(eOrquesta arrayRecibido[],int tamanioArrayRecibido,eTipoOrquesta arrayRecibidoDos[],int tamanioArrayRecibidoDos)
{
	int i;
	int exito=0;
	int sePuedeMostrar=1;
	char orquestaDescripcion[15];

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		if(arrayRecibido[i].estaVacio==0)
		{
			if(sePuedeMostrar)
			{
				printf("-------DATOS ORQUESTA-------\n");
				printf("NOMBRE      LUGAR       TIPO\n");
				sePuedeMostrar=0;
			}
			consigueTipoOrquesta(arrayRecibidoDos,tamanioArrayRecibidoDos,arrayRecibido[i].idTipoOrquesta,orquestaDescripcion);
			muestraOrquestaCargada(arrayRecibido[i],orquestaDescripcion);
			exito=1;
		}
	}
	if(sePuedeMostrar)
	{
		printf("No hay datos cargados que mostrar\n\n");
	}
	return exito;
}

void muestraOrquestaCargada(eOrquesta estructuraRecibida,char descripcionRecibida[])
{
	printf("%-12s%-12s%s\n",estructuraRecibida.nombreOrquesta,estructuraRecibida.lugarOrquesta,descripcionRecibida);
}

void consigueTipoOrquesta(eTipoOrquesta arrayRecibido[],int tamanioArrayRecibido,int idTipoOrquesta,char tipo[])
{
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		if(arrayRecibido[i].estaVacio==0&&idTipoOrquesta==arrayRecibido[i].idTipoOrquesta)
		{
			strncpy(tipo,arrayRecibido[i].tipoOrquesta,15);
		}
	}
}

int muestraMusicosCargados(eMusico arrayRecibido[],int tamanioArrayRecibido,eTipoInstrumento arrayRecibidoDos[],int tamanioArrayRecibidoDos,eInstrumentos arrayRecibidoTres[],int tamanioArrayRecibidoTres)
{
	int i;
	int exito=0;
	int sePuedeMostrar=1;
	char descripcionTipoInstrumento[15];
	char nombreDeInstrumento[15];

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		if(arrayRecibido[i].estaVacio==0)
		{
			if(sePuedeMostrar)
			{
				printf("-------------------DATOS MUSICOS------------------\n");
				printf("ID      NOMBRE      APELLIDO    INSTRUMENTO   TIPO\n");
				sePuedeMostrar=0;
			}
			consigueTipoInstrumento(arrayRecibidoDos,tamanioArrayRecibidoDos,arrayRecibido[i].idTipoInstrumento,descripcionTipoInstrumento);
			consigueNombreInstrumento(arrayRecibidoTres,tamanioArrayRecibidoTres,arrayRecibido[i].idTipoInstrumento,nombreDeInstrumento);
			muestraMusicoCargado(arrayRecibido[i],nombreDeInstrumento,descripcionTipoInstrumento);
			exito=1;
		}
	}
	if(sePuedeMostrar)
	{
		printf("No hay datos cargados que mostrar\n\n");
	}
	return exito;
}

void muestraMusicoCargado(eMusico estructuraRecibida,char descripcionInstrumento[],char descripcionTipoInstrumento[])
{
	printf("%-8d%-11s%-11s%-13s%s\n",estructuraRecibida.idMusico,estructuraRecibida.nombre,estructuraRecibida.apellido,descripcionInstrumento,descripcionTipoInstrumento);
}

void consigueTipoInstrumento(eTipoInstrumento arrayRecibido[],int tamanioArrayRecibido,int idTipoInstrumento,char tipo[])
{
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		if(arrayRecibido[i].estaVacio==0&&idTipoInstrumento==arrayRecibido[i].idTipoInstrumento)
		{
			strncpy(tipo,arrayRecibido[i].descripcion,15);
		}
	}
}

void consigueNombreInstrumento(eInstrumentos arrayRecibido[],int tamanioArrayRecibido,int idInstrumento,char nombre[])
{
	int i;

	for(i=0;i<tamanioArrayRecibido;i++)
	{
		if(arrayRecibido[i].estaVacio==0&&idInstrumento==arrayRecibido[i].idTipoInstrumento)
		{
			strncpy(nombre,arrayRecibido[i].nombreInstrumento,15);
		}
	}
}

int bajaDatosOrquesta(eOrquesta arrayRecibido[],int tamanioArrayRecibido,eMusico arrayRecibidoDos[],int tamanioArrayRecibidoDos)
{
	int exito=0;
	int opcionBaja;
	int orquestaBaja;
	int orquestaExistente=0;
	int i;

	if(arrayRecibido!=NULL)
	{
		exito=1;
		printf("Ingrese idOrquesta a dar de baja\n");
		scanf("%d",&orquestaBaja);
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			if(orquestaBaja==arrayRecibido[i].idOrquesta&&arrayRecibido[i].estaVacio==0)
			{
				orquestaExistente=1;
				break;
			}
		}

		if(orquestaExistente)
		{
			printf("Usted dara de baja la idOrquesta %d, presione 1 para continuar o 2 para cancelar\n",orquestaBaja);
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
				for(i=0;i<tamanioArrayRecibidoDos;i++)
				{
					if(arrayRecibidoDos[i].idOrquesta==orquestaBaja)
					{
						arrayRecibidoDos[i].estaVacio=1;
					}
				}
				printf("Los datos se han dado de baja exitosamente\n");
				printf("Pulse cualquiera tecla para volver\n");
				fflush(stdin);
				getchar();
			}
		}
		else
		{
			printf("No hay datos cargados cuales dar de baja ó el idOrquesta es invalido, verifique\n");
			printf("Pulse cualquiera tecla para volver\n");
			fflush(stdin);
			getchar();
		}
	}
	return exito;
}
