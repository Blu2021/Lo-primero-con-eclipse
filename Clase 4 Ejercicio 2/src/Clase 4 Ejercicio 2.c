//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
#include "convertidores de temperatura.h"
#include "validadores de temperatura.h"
/*
Ejercicio 4-2:
Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit , validando que las temperaturas ingresadas estén entre el punto de congelación y ebullición del agua para cada tipo de escala.
Las validaciones se hacen en una biblioteca.
Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra biblioteca.*/
int main(void)
{
	setbuf(stdout,NULL);

	celsiusFahrenheit();

	fahrenheitCelsius();

	return EXIT_SUCCESS;
}
