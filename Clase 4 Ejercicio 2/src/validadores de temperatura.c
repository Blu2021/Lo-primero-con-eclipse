//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
int validadorCelsius(float gradosCelsius,float* punteroCelsius)
{
	setbuf(stdout,NULL);

	int exito=0;

	if(punteroCelsius!=NULL)
	{
		while(gradosCelsius<0||gradosCelsius>100)
		{
			printf("ERROR Ingrese temperatura celsius de 0 a 100 para pasarla a fahrenheit\n");
			scanf("%f",&gradosCelsius);
		}
		*punteroCelsius=gradosCelsius;
		exito=1;
	}
	return exito;
}

int validadorFahrenheit(float gradosFar,float* punteroFar)
{
	int exito=0;

	if(punteroFar!=NULL)
	{
		while(gradosFar<32||gradosFar>212)
		{
			printf("ERROR Ingrese temperatura Fahrenheit de 32 a 212 para pasarla a celsius\n");
			scanf("%f",&gradosFar);
		}
		*punteroFar=gradosFar;
		exito=1;
	}

	return exito;
}

