//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	 int idProducto;
	 char marca[20];
	 int precio;
	 int estaVacio;
}eProducto;

typedef int(*funcion)(eProducto*,eProducto*);
int ordenador(eProducto*,int,funcion);
int compararMarca(eProducto*,eProducto*);

int main(void)
{
	setbuf(stdout,NULL);

	eProducto productos[5]={{1000,"Generica",500,0},{1001,"Mestiza",505,0},{1002,"Otros",510,0},
	{1003,"Desmarcado",515,0},{1004,"Marco",520,0}};

	ordenador(productos,5,compararMarca);

	return EXIT_SUCCESS;
}

int ordenador(eProducto* arrayEstructuras,int tam,funcion funcionRecibida)
{
	int exito=0;
	int i;
	int j;


	return exito;
}

int compararMarca(eProducto* estructuraUno,eProducto* estructuraDos)
{
	int exito=0;

	return exito;
}
