//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*
c-Control de Flujo
Pedirle al usuario su edad y su estado civil ('c'-casado, 's'-soltero, 'v'-viudo, 'd'-divorciado)
Si ingresa una edad menor a 18 años y un estado civil distinto a "Soltero",
mostrar el siguiente mensaje: 'Es muy pequeño para NO ser soltero.'
*/
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
