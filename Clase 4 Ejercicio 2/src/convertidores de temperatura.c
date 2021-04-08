//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
#include "validadores de temperatura.h"
int celsiusFahrenheit()
{
	float celsiusAFar;
	float celsius;

	printf("Ingrese temperatura celsius de 0 a 100 para pasarla a fahrenheit\n");
	scanf("%f",&celsius);

	if(validadorCelsius(celsius,&celsius))
	{
		celsiusAFar=(celsius*9/5)+32;
		printf("El resultado es %.2f\n",celsiusAFar);
	}
	else
	{
		printf("Hubo algun error");
	}

	return 0;
}
int fahrenheitCelsius()
{
	float farACelsius;
	float far;

	printf("Ingrese temperatura Fahrenheit de 32 a 212 para pasarla a celsius\n");
	scanf("%f",&far);

	if(validadorFahrenheit(far,&far))
	{
		farACelsius=(far-32)*5/9;
		printf("El resultado es %.2f\n",farACelsius);
	}
	else
	{
		printf("Hubo algun error");
	}

	return 0;
}
