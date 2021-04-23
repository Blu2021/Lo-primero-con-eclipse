//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
int utn_levantaEnteros(int* resultado,char* mensaje,char* mensajeError,int min,int max,int reintentos);
int main(void)
{
	setbuf(stdout,NULL);

	int resultado;

	if(!utn_levantaEnteros(&resultado,"Ingrese numero","Error debe ser entre 1 y 10",1,10,2))
	{
		printf("Ta toh piolita %d",resultado);
	}
	else
	{
		printf("oh my gash");
	}

	return EXIT_SUCCESS;
}
int utn_levantaEnteros(int* resultado,char* mensaje,char* mensajeError,int min,int max,int reintentos)
{
	int aux;
	int exito=1;

	if(resultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&min<=max&&reintentos>-1)
	{
		do{
			printf("%s\n",mensaje);
			scanf("%d",&aux);
			if(aux<min||aux>max)
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
			else
			{
				*resultado=aux;
				exito=0;
				break;
			}

		}while(reintentos>-1);
	}
	return exito;
}
