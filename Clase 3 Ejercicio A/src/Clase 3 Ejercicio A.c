//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*a-Funciones
- Limpie la pantalla
- Asigne a la variable numero1 un valor solicitado al usuario
- Valide el mismo entre 10 y 100
- Realice un descuento del 5% a dicho valor a través de una función llamada realizarDescuento()
- Muestre el resultado por pantalla
float realizarDescuento(int numeroTratado);*/
float realizarDescuento(int numeroTratado);
int main(void)
{
	setbuf(stdout,NULL);

	int numeroUno;
	float resultado;

	printf("Ingrese un numero \n");
	scanf("%d",&numeroUno);
	while(numeroUno<10||numeroUno>100)
	{
		printf("Ingrese un numero \n");
		scanf("%d",&numeroUno);
	}

	resultado=realizarDescuento(numeroUno);

	printf("el resultado es %.2f",resultado);

	return EXIT_SUCCESS;
}

float realizarDescuento(int numeroTratado)
{
	float descuento;
	float resultadoDto;

	printf("Ingrese dto\n");
	scanf("%f",&descuento);

	resultadoDto=numeroTratado-((numeroTratado*descuento)/100);

	return resultadoDto;
}
