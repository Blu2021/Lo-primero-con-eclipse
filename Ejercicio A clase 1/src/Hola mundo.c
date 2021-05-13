//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*a-Salida/Eclispe/Compilar
Crear un proyecto desde cero en Eclipse y modificar en el mensaje
de "Hello world" por el de "Bienvenidos a Programación 1-UTN".*/
/*
int main(void)
{
	printf("Bienvenidos a Programación 1-UTN");
	return EXIT_SUCCESS;
}
*/
int main()
{
	int i;
	for(i=0;i<11;i++)
	{
		if(!(i%2))
		{
			printf("%d\n",i);
		}
	}
	return 0;
}
