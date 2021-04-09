//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
#define TOTALEMPLEADOS 10
int main(void)
{
	setbuf(stdout,NULL);

	int edad[TOTALEMPLEADOS];
	float sueldo[TOTALEMPLEADOS];
	int i;
	float promedioSueldos;
	float acumuladorSueldos=0;

	for(i=0;i<10;i++)
	{
		printf("Ingrese edad de 10 empleados\n");
		scanf("%d",&edad[i]);
		while(edad[i]<1||edad[i]>110)
		{
			printf("ERROR,Ingrese edad de 10 empleados\n");
			scanf("%d",&edad[i]);
		}

		printf("Ingrese sueldo de 10 empleados\n");
		scanf("%f",&sueldo[i]);
		while(sueldo[i]<0)
		{
			printf("ERROR,Ingrese sueldo de 10 empleados\n");
			scanf("%f",&sueldo[i]);
		}

		acumuladorSueldos=acumuladorSueldos+sueldo[i];
	}

	for(i=0;i<10;i++)
	{
		printf("El sueldo y edad del legajo %d\n edad %d\n sueldo%.2f \n",i,edad[i],sueldo[i]);
	}

	promedioSueldos=acumuladorSueldos/TOTALEMPLEADOS;

	printf("El promedio de sueldos es %.2f\n",promedioSueldos);

	return EXIT_SUCCESS;
}
