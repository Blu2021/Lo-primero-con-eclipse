//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int opcionSubMenu;
	int logueo=0;
	int comprar=0;
	int vender=0;

    do
    {
    	if(menu(&opcion))
    	{
    		switch(opcion)
    		{
				case 1:
					if(logueo==0)
					{
						printf("Se ha logueado con exito\n");
						logueo=1;
					}
					else
					{
						printf("Ya se encuentra logueado\n");
					}
					printf("Pulse cualquier tecla para volver al menu\n");
				break;
				case 2:
					if(logueo==0)
					{
						printf("Debe loguearse primero \n");
					}
					else
					{
						comprar=1;
						printf("Ha comprado\n");
					}
				break;
				case 3:
					if(comprar==0)
					{
						printf("Debe comprar para ver sus compras\n");
					}
				break;
				case 4:
						if(comprar==1)
						{
							do
							{
								if(subMenu(&opcionSubMenu))
								{
									switch(opcionSubMenu)
									{
										case 1:
											if(vender==0)
											{
												printf("Usted ha vendido\n");
												vender=1;
											}
											else
											{
												printf("Usted no puede vender si ya compro y vendio\n");
											}
											break;
										case 2:
											printf("se esta realizando la factura\n");
											break;
									}
								}
								else
								{
									printf("Algo en subMenu ha fallado");
								}
							}while(opcionSubMenu!=3);
						}
						else
						{
							printf("Usted debe comprar para vender\n");
						}
				break;
    		}
    	}
    	else
    	{
    		printf("Algo en Menu fallo");
    	}
    }while(opcion!=5);

	return EXIT_SUCCESS;
}
