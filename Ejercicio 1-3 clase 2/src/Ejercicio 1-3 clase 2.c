//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);

	int numIngresado;
	int a;
	int b;
	int c;
	int i;
	int max;
	int min;

	for(i=0;i<3;i++)
	{
		printf("Ingrese 3 numeros\n");
		fflush(stdin);
		scanf("%d",&numIngresado);

		switch(i)
		{
			case 0:
				a=numIngresado;
				max=numIngresado;
				min=numIngresado;
			break;
			case 1:
				b=numIngresado;
			break;
			case 2:
				c=numIngresado;
			break;
		}

		if(numIngresado>max)
		{
			max=numIngresado;
		}
		if(numIngresado<min)
		{
			min=numIngresado;
		}

	}

	if(a<max&&a>min)
	{
		printf("El numero inter es %d",a);
	}
	else
	{
		if(b<max&&b>min)
		{
			printf("El numero inter es %d",b);
		}
		else
		{
			if(c>max&&c<min)
			{
				printf("El numero inter es %d",c);
			}
			else
			{
				printf("No hay numero inter");
			}
		}
	}


	return EXIT_SUCCESS;
}

