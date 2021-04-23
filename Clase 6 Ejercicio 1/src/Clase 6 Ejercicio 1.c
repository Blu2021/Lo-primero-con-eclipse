//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);

	int numeroUno=5;
	int numeroDos=10;
	int auxiliar;

	auxiliar=numeroUno;
	numeroUno=numeroDos;
	numeroDos=auxiliar;

	printf("%d %d",numeroUno,numeroDos);

	return EXIT_SUCCESS;
}
