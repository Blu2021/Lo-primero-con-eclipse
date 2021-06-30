//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	int legajo;
	char nombre[20];
	int edad;
	int estaVacio;
}eEstudiante;

int funcionPunteroChar(char* puntero,char uno,char dos);
eEstudiante funcionCargaEstructura(int* retorno);

int main(void)
{
	setbuf(stdout,NULL);

	char puntero[20];
	eEstudiante estudiantes[3];
	int i;
	int retornoCargaEstructura;

	funcionPunteroChar(puntero,'a','b');

	for(i=0;i<3;i++)
	{
		*(estudiantes+i)=funcionCargaEstructura(&retornoCargaEstructura);
	}

	for(i=0;i<3;i++)
	{
		printf("%-8d%-10s%d",(*(estudiantes+i)).legajo,(*(estudiantes+i)).nombre,(*(estudiantes+i)).edad);
	}
	return EXIT_SUCCESS;
}
/*1-Utilizar aritm�tica de punteros. Realizar una funci�n que reciba un puntero a char y dos char.
La funci�n deber� reemplazar en la cadena cada ocurrencia del primer car�cter recibido, por el segundo.
Retornando la cantidad de reemplazos o -1 en caso de error. */
int funcionPunteroChar(char* puntero,char uno,char dos)
{
	int i;
	int contadorReemplazos=0;

	for(i=0;i<(strlen(puntero));i++)
	{
		if(*(puntero+i)==uno)
		{
			*(puntero+i)=dos;
			contadorReemplazos++;
		}
	}
	if(contadorReemplazos==0)
	{
		contadorReemplazos=-1;
	}
	return contadorReemplazos;
}

/*2-Utilizar aritm�tica de punteros. Realizar una funci�n que reciba como par�metros un array de enteros
y un entero por referencia. La funci�n calcular� el valor m�ximo de ese array y utilizar� el valor por
referencia para retornar ese valor.*/
int funcionPunteroInt(int* enteroCadena,int* enteroReferencia)
{
	int exito=0;
	int i;
	int maximo;

	if(enteroCadena!=NULL&&enteroReferencia!=NULL)
	{
		exito=1;
		for(i=0;i<10;i++)
		{
			if(i==0||*(enteroCadena+i)>maximo)
			{
				maximo=*(enteroCadena+i);
			}
		}
		*enteroReferencia=maximo;
	}

	return exito;
}

/*3-Utilizar aritm�tica de punteros. Dada la siguiente estructura: int legajo; char nombre[20]; int edad;
Realizar una funci�n que cargue un array de 3 estudiantes. Recibe un entero. Retorna el estudiante dado de alta
y por par�metro 0 si funcion� correctamente -1 mal. Una vez devuelto el estudiante cargarlo en una posici�n del array.
Al final mostrar el array cargado*/
eEstudiante funcionCargaEstructura(int* retorno)
{
	eEstudiante devuelto;
	*retorno=-1;

	if(retorno!=NULL)
	{
		printf("Ingrese legajo\n");
		fflush(stdin);
		scanf("%d",&devuelto.legajo);

		printf("Ingrese nombre\n");
		fflush(stdin);
		scanf("%s",devuelto.nombre);

		printf("Ingrese edad\n");
		fflush(stdin);
		scanf("%d",&devuelto.edad);

		devuelto.estaVacio=0;
		*retorno=0;
	}

	return devuelto;
}

/*4-Utilizar aritm�tica de punteros. Dada la siguiente estructura: int legajo; char nombre[20]; int edad;
Realizar una funci�n que cargue un array de 3 estudiantes. Recibe un puntero al array de estudiantes,
lo carga y retorna 0 si funcion� correctamente -1 mal. Una vez cargados los estudiantes mostrar el array cargado*/
