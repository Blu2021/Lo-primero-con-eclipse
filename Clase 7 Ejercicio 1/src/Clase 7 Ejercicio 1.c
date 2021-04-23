//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(void)
{
	setbuf(stdout,NULL);

	char nombre[12];
	char apellido[12];
	char nombreApellido[24];
	int i;
	int hayNumero=1;

	while(hayNumero==1)
	{
		hayNumero=0;
		printf("Ingrese su nombre por favor\n");
		gets(nombre);
		printf("Ingrese su apellido por favor\n");
		gets(apellido);
		for(i=0;i<11;i++)
		{
			if(isdigit(nombre[i]))
			{
				hayNumero=1;
			}
			if(isdigit(apellido[i]))
			{
				hayNumero=1;
			}
		}
	}
	strlwr(apellido);
	strlwr(nombre);
	apellido[0]=apellido[0]-'a'+'A';
	nombre[0]=nombre[0]-'a'+'A';
	strncpy(nombreApellido,apellido,11);
	strcat(nombreApellido,", ");
	strcat(nombreApellido,nombre);

	printf("%s",nombreApellido);

	return EXIT_SUCCESS;
}
