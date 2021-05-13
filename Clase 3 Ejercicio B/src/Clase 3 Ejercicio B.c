//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*-Funciones
- Limpie la pantalla
- Asigne a las variables numero1 y numero2 los valores solicitados al usuario
- Valide los mismos entre 10 y 100
- Asigne a la variable operacion el valor solicitado al usuario
- Valide el mismo 's'-sumar, 'r'-restar
- Realice la operación de dichos valores a través de una función
- Muestre el resultado por pantalla*/
int sumar(int primerNum,int segundoNum);
int restar(int primerNum,int segundoNum);

int main(void)
{
	setbuf(stdout,NULL);

	int numeroUno;
	int numeroDos;
	char operacion;

	printf("ingrese dos numeros de 1 a 100\n");
	scanf("%d %d",&numeroUno,&numeroDos);
	while(numeroUno<1||numeroUno>100||numeroDos<1||numeroDos>100)
	{
		printf("ingrese dos numeros de 1 a 100\n");
		scanf("%d %d",&numeroUno,&numeroDos);
	}

	printf("Ingrese r para restar los numeros o s para sumarlos\n");
	fflush(stdin);
	scanf("%c",&operacion);
	if(operacion=='s')
	{
		printf("El resultado de suma es %d",sumar(numeroUno,numeroDos));
	}
	else
	{
		printf("El resultado de resta es %d",restar(numeroUno,numeroDos));
	}

	return EXIT_SUCCESS;
}

int sumar(int primerNum,int segundoNum)
{
	int resultado;

	resultado=primerNum+segundoNum;

	return resultado;
}

int restar(int primerNum,int segundoNum)
{
	int resultado;

	resultado=primerNum-segundoNum;

	return resultado;
}
