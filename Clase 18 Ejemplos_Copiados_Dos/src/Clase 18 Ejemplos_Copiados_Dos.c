#include <stdio.h>
#include <stdlib.h>

/*Podemos utilizar typedef para simplificar el uso de punteros de función*/
typedef void(*tFuncionOperacion)(int,int,int*);
void restar(int parametroA, int parametroB, int* pResultado);
void sumar(int parametroA, int parametroB, int* pResultado);
int calcular( int parametroA, int parametroB, tFuncionOperacion pFuncion);
//int calcular( int , int , tFuncionOperacion);
typedef int miTipo;

int main(void)
{
    //declaro variables
    miTipo auxiliar;

    int valorA=10;
    int valorB=2;
    void (*pHacer)(int,int,int*); //declaro puntero a funcion

    //Asigno la dir de memoria del inicio de una funcion al puntero a funcion
    pHacer = restar;
    auxiliar = calcular(valorA ,valorB , pHacer);

    printf("\nEl resultado de la resta es %d\n",auxiliar);
    printf("\n\n");

    //Asigno otra funcion al puntero a funcion
    pHacer = sumar;
    auxiliar = calcular(valorA , valorB , pHacer);

    printf("\nEl resultado de la suma es %d\n",auxiliar);
    printf("\n\n");


    return 0;
}

void restar(int parametroA, int parametroB, int* pResultado)
{
    printf("\nRestar Parametro A %d ", parametroA);
    printf("\nRestar Parametro B %d ", parametroB);
    printf("\n");

   *pResultado = parametroA - parametroB;
}
void sumar(int parametroA, int parametroB, int* pResultado)
{
    printf("\nSumar Parametro A %d ", parametroA);
    printf("\nSumar Parametro B %d ", parametroB);
    printf("\n");

    *pResultado = parametroA + parametroB;
}
int calcular( int parametroA, int parametroB, void(*pFuncion)(int,int,int*) )
{
    int auxResultado;
    printf("\nCalcular Parametro A %d ", parametroA);
    printf("\nCalcular Parametro B %d ", parametroB);
    printf("\n\n");

    pFuncion(parametroA , parametroB , &auxResultado);

    return auxResultado;
}
