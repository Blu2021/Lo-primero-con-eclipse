#include <stdio.h>
#include <stdlib.h>
int menu(int* opcionPuntero)
{
	int exito=0;
	int opcionTrabajada;

	if(opcionPuntero!=NULL)
	{
		printf(" 1-loguearse\n 2-comprar\n 3-ver sus compras\n 4-vender\n 5-salir\n");
		scanf("%d",&opcionTrabajada);
		while(opcionTrabajada<1||opcionTrabajada>5)
		{
			printf("No ha ingresado una opcion correcta\n 1-loguearse\n 2-comprar\n 3-ver sus compras\n 4-vender\n 5-salir\n");
			scanf("%d",&opcionTrabajada);
		}
		*opcionPuntero=opcionTrabajada;

		exito=1;
	}


	return exito;
}

int subMenu(int* opcionSubMenuPuntero)
{
	int exitoSubMenu=0;
	int opcionSubTrabajada;

	if(opcionSubMenuPuntero!=NULL)
	{
		printf("Ingrese 1-vender\n 2-hacer factura\n 3-volver atras\n");
		scanf("%d",&opcionSubTrabajada);
		while(opcionSubTrabajada<1||opcionSubTrabajada>3)
		{
			printf("ERROR\nIngrese\n 1-vender\n 2-hacer factura\n 3-volver atras\n");
			scanf("%d",&opcionSubTrabajada);
		}
		*opcionSubMenuPuntero=opcionSubTrabajada;

		exitoSubMenu=1;
	}

	return exitoSubMenu;
}

