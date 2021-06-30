//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*Puntero a función como parámetro de otra función*/
void restar(int parametroA, int parametroB, int* pResultado);
//void sumar(int parametroA, int parametroB, int* pResultado);
void sumar(int , int, int*);
int calcular( int parametroA, int parametroB, void(*pFuncion)(int,int,int*));

int main(void)
{
    //declaro variables
    int auxiliar;
    int* prueba;
    void (*pHacer)(int,int,int*); //declaro puntero a funcion
    //Asigno la dir de memoria del inicio de una funcion al puntero a funcion
    pHacer = restar;
    auxiliar = calcular(12 , 2 , pHacer);

    printf("\nEl resultado de la resta es %d\n",auxiliar);
    printf("\n\n");

    //Asigno otra funcion al puntero a funcion
    pHacer = sumar;
    auxiliar = calcular(12 , 2 , pHacer);
    pHacer(12,2 &prueba);
    sumar(12,2 &prueba);

    printf("\nEl resultado de la suma es %d\n",auxiliar);
    printf("\n\n");


    return 0;
}

void restar(int parametroA, int parametroB, int* pResultado)
{
    printf("\nRestar Parametro A %d ", parametroA);
    printf("\nRestar Parametro B %d ", parametroB);
    printf("\n\n");

    *pResultado = parametroA - parametroB;
}
void sumar(int parametroA, int parametroB, int* pResultado)
{
    printf("\nSumar Parametro A %d ", parametroA);
    printf("\nSumar Parametro B %d ", parametroB);
    printf("\n\n");

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
