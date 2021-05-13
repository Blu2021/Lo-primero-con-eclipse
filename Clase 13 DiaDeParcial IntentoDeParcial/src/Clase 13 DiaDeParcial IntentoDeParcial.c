//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>

/*En el sistema existirán pantallas del tipo Led o LCD , las cuales se registrarán mediante
nombre, dirección y precio de la publicidad en dicha pantalla por cada día de publicación.
La plataforma permitirá vender a un cliente la publicación de un video publicitario en una
pantalla determinada.
La porción del sistema que deberá realizarse se centrará en la venta de publicidad y consta de
un menú con las siguientes opciones:

1) Alta de pantalla: Se solicitan al usuario los datos de la pantalla, para que el sistema
pueda funcionar se deberá generar un ID único para cada pantalla.
2) Modificar datos de pantalla: Se ingresa el ID de la pantalla, permitiendo modificar sus
datos.
3) Baja de pantalla: Se ingresa el ID de la pantalla, se eliminará la pantalla junto con todas
las contrataciones de publicidad para esta pantalla.
4) Contratar una publicidad: ​Se listaran todas las pantallas y se le pedirá al usuario que
elija la pantalla donde se quiere publicar, ingresando su ID. Luego se pedirán los datos
asociados a la publicidad: cuit del cliente, cantidad de días que dura la publicación y
nombre del archivo de video (p.ej. Video1.avi).

5) Modificar condiciones de publicación: ​Se pedirá que se ingrese el cuit del cliente y se
listaran todas las pantallas de video que el cliente tiene contratadas mostrando todos sus
campos. Luego de ingresar el ID de la pantalla, se permitirá modificar la cantidad de días
contratados para la misma.
6) Cancelar contratación: ​Se pedirá que se ingrese el cuit del cliente y se listaran todas las
pantallas de video que el cliente tiene contratadas mostrando todos sus campos. Luego
ingresar el ID de la pantalla de la cual se quiere cancelar la contratación.
7) Consulta facturación: Se deberá ingresar el cuit del cliente y se deberá listar el importe
a pagar por cada contratación.
8) Listar contrataciones: ​Se deberán listar las contrataciones indicando nombre de la
pantalla, nombre de video, cantidad de días y cuit de cliente.
9) Listar​ ​pantallas:​ ​Se deberán listar las pantallas existentes indicando todos sus campos.
10) Informar:
1. Lista de cada cliente con cantidad de contrataciones e importe a pagar por cada una.
2. Cliente con importe más alto a facturar (si hay más de uno indicar el primero)

Nota 0 : El sistema soportará una capacidad máxima de 100 pantallas y 1000 contrataciones
Nota 1: Se deberán desarrollar bibliotecas por cada entidad las cuales contendrán las
funciones (Alta, Baja, Modificar, etc.). Los informes deberán estar en una biblioteca aparte.
Nota 2: El código deberá tener comentarios con la documentación de cada una de las
funciones y respetar las reglas de estilo de la cátedra.*/

typedef struct
{
	int idPantalla;
	int idtipoPantalla;
	char nombre[20];
	char calle[20];
	int alturaCalle;
	float precio;
	int estaVacio;
}ePantallas;

typedef struct
{
	int	idPublicidad;
	int cuit;
	int dias;
	int archivo;
	int idPantalla;
}ePublicidad;

typedef struct
{
	int idtipoPantalla;
	char descripcionPantalla[2][3];
	int estaVacio;
}eTipoDePantalla;

void inicializarArrayPantallas(ePantallas arrayRecibido[],int tamanioArrayRecibido);

int main(void)
{
	int opcionMenu;
	ePantallas pantallas[5];

	inicializarArrayPantallas(pantallas,5);
	do
	{
		printf("Bienvenido al Menu Pantallas\nIngrese opcion\n");
		printf("1: DAR DE ALTA PANTALLA\n");
		printf("2: MODIFICAR\n");
		printf("3: DAR DE BAJA PANTALLA\n");
		printf("4: CONTRATAR PUBLICIDAD\n");
		printf("5: MODIFICAR CONDICIONES PUBLICACION\n");
		printf("6: CANCELAR CONTRATACION\n");
		printf("7: CONSULTA FACTURACION\n");
		printf("8: LISTAR CONTRATACIONES\n");
		printf("9: LISTAR PANTALLAS\n");
		printf("10: INFORMES\n");
		printf("11: SALIR\n");
		scanf("%d",&opcionMenu);
		while(opcionMenu>11||opcionMenu<1)
		{
			printf("Error, ingrese una opcion de menu valida\n");
			scanf("%d",&opcionMenu);
		}

		switch(opcionMenu)
		{
			case 1:

			break;
		}
	}while(opcionMenu!=11);

	return EXIT_SUCCESS;
}

void inicializarArrayPantallas(ePantallas arrayRecibido[],int tamanioArrayRecibido)
{
	int i;
	if(arrayRecibido!=NULL)
	{
		for(i=0;i<tamanioArrayRecibido;i++)
		{
			arrayRecibido[i].estaVacio=1;
		}
	}
}

void cargarDatosPantalla(ePantallas arrayRecibido[],int posicion)
{
	int opcionTipoPantalla;
	typedef struct
	{
		int idPantalla;
		int tipoPantalla;
		char nombre[20];
		char calle[20];
		int alturaCalle;
		float precio;
		int estaVacio;
	}ePantallas;
	printf("Ingrese tipo de pantalla\n"
		   "                   LCD:1\n"
		   "                   LED:2\n");
	fflush(stdin);
	scanf("%d",&opcionTipoPantalla);
	while(opcionTipoPantalla!=2&&opcionTipoPantalla!=1)
	{
		printf("ERROR,Ingrese tipo de pantalla\n"
			   "                         LCD:1\n"
			   "                         LED:2\n");
		fflush(stdin);
		scanf("%d",&opcionTipoPantalla);
	}
	printf("Ingrese Nombre\n");
	fflush(stdin);
	fgets();


}
