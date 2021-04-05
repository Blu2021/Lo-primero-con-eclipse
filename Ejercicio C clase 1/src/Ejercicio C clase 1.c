//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);

	int edad;
	char estadoCivil;

	printf("Ingrese su edad \n");
	scanf("%d",&edad);
	while(edad<1||edad>100)
	{
		printf("Error,Ingrese su edad \n");
		scanf("%d",&edad);
	}

	printf("Ingrese estado civil c,s,v,d \n");
	fflush(stdin);
	scanf("%c",&estadoCivil);
	while(estadoCivil!='c'&&estadoCivil!='s'&&estadoCivil!='v'&&estadoCivil!='d')
	{
		printf("Error,Ingrese estado civil c,s,v,d \n");
		fflush(stdin);
		scanf("%c",&estadoCivil);
	}

	if(edad<18)
	{
		if(estadoCivil!='s')
		{
			printf("Es muy pequeño para NO ser soltero");
		}
	}
	return EXIT_SUCCESS;
}
