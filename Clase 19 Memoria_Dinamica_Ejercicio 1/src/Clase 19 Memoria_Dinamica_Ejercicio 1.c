//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
#define TAM 5
int buscaElimina(int* arrayEnteros,int tam,int entero);

int main(void)
{
	setbuf(stdout,NULL);

	int *enteros;
	int i;
	int numBorrar;

	enteros=(int*)malloc(TAM*sizeof(int));

	if(enteros!=NULL)
	{
		for(i=0;i<TAM;i++)
		{
			*(enteros+i)=i;
			printf("Numero cargado en pos %d : %d\n",i,*(enteros+i));
		}
		printf("Ingrese numero a borrar del 0 al 4\n");
		fflush(stdin);
		scanf("%d",&numBorrar);

		buscaElimina(enteros,TAM,numBorrar);
	}
	else
	{
		printf("No hay espacio en memoria dinamica\n");
	}

	return 0;
}

int buscaElimina(int* arrayEnteros,int tam,int entero)
{
	int exito=0;
	int i;
	int j;
	int *auxArrayEnteros;

	for(i=0;i<tam;i++)
	{
		if(*(arrayEnteros+i)==entero)
		{
			for(j=i;j<tam;j++)
			{
				*(arrayEnteros+i)=*(arrayEnteros+(j+1));
				i++;
			}
		}
	}

	auxArrayEnteros=(int*)realloc(arrayEnteros,sizeof(int)*(tam-1));
	if(auxArrayEnteros!=NULL)
	{
		arrayEnteros=auxArrayEnteros;
		for(i=0;i<tam-1;i++)
		{
			printf("Los nuevos numeros son pos %d numero %d\n",i,*(arrayEnteros+i));
		}
	}
	else
	{
		printf("realloc no encontro espacio dinamico\n");
	}

	return exito;
}
