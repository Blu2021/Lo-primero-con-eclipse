//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
/*Ejercicio 2-2:
Ingresar 10 números enteros, distintos de cero. Mostrar:
a. Cantidad de pares e impares.
b. El menor número ingresado.
c. De los pares el mayor número ingresado.
d. Suma de los positivos.
e. Producto de los negativos.*/
int main()
{
    setbuf(stdout, NULL);

    int numIngresado;
    int i;
    int contadorPares=0;
    int contadorImpares=0;
    int menorNumeroIngresado;
    int banderaParMayor=0;
    int parMayor;
    int acumuladorPositivos=0;
    int multiplicadorNegativos=1;
    int banderaMultiplicador=0;


    for(i=0;i<10;i++)
    {
        printf("Ingrese numero");
        fflush(stdin);
        scanf("%d",&numIngresado);
        while(numIngresado==0)
        {
            printf("Ingrese numero");
            fflush(stdin);
            scanf("%d",&numIngresado);
        }

        if(numIngresado%2==0)
        {
            contadorPares=contadorPares+1;
            if(banderaParMayor==0)
            {
                parMayor=numIngresado;
                banderaParMayor=1;
            }
            else
            {
            	if(numIngresado>parMayor)
            	{
            		parMayor=numIngresado;
            	}
            }
        }
        else
        {
            contadorImpares=contadorImpares+1;
        }

        if(i==0||numIngresado<menorNumeroIngresado)
        {
            menorNumeroIngresado=numIngresado;
        }

        if(numIngresado>0)
        {
            acumuladorPositivos=acumuladorPositivos+numIngresado;
        }
        else
        {
            multiplicadorNegativos=multiplicadorNegativos*numIngresado;
            banderaMultiplicador=1;
        }
    }

    if(banderaMultiplicador==0)
    {
        multiplicadorNegativos=0;
    }

    printf("\ncantidad de pares %d",contadorPares);
    printf("\ncantidad de impares %d",contadorImpares);
    printf("\nel mayor par es %d",parMayor);
    printf("\nla suma positivos %d",acumuladorPositivos);
    printf("\nproducto negativos %d",multiplicadorNegativos);


    return 0;
}
