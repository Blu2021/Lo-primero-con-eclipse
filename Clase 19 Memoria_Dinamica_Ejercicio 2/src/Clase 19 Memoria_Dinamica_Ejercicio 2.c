//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int aumentadorArray(int* arrayEnteros,int tam,int valorEntero,int indice);

int main(void)
{
	setbuf(stdout,NULL);

	int *enteros;
	int i;
	int numIngresar;
	int posReemplazo;

	enteros=(int*)malloc(TAM*sizeof(int));

	if(enteros!=NULL)
	{
		for(i=0;i<TAM;i++)
		{
			*(enteros+i)=i;
			printf("Numero cargado en pos %d : %d\n",i,*(enteros+i));
		}
		printf("Ingrese numero\n");
		fflush(stdin);
		scanf("%d",&numIngresar);
		printf("Ingrese posicion para su numero del 0 al 4\n");
		fflush(stdin);
		scanf("%d",&posReemplazo);

		aumentadorArray(enteros,TAM,numIngresar,posReemplazo);
	}
	return EXIT_SUCCESS;
}

int aumentadorArray(int* arrayEnteros,int tam,int valorEntero,int indice)
{
	int exito=0;
	int *auxArrayEnteros;
	int i;

	auxArrayEnteros=(int*)realloc(arrayEnteros,sizeof(int)*(tam+1));
	if(auxArrayEnteros!=NULL)
	{
		arrayEnteros=auxArrayEnteros;
		for(i=tam;i>indice;i--)
		{
			*(arrayEnteros+i)=*(arrayEnteros+(i-1));
		}
		*(arrayEnteros+indice)=valorEntero;
		for(i=0;i<tam+1;i++)
		{
			printf("Los nuevos numeros son pos %d numero %d\n",i,*(arrayEnteros+i));
		}
	}
	return exito;
}
