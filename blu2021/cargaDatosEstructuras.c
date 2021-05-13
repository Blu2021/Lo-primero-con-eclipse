/*int cargaDatosEstructura(datosPersonales arrayRecibido[],int posicion)
{
	int exito=0;
	char auxSexo;
	int auxEdad;
	int auxNotaUno;
	int auxNotaDos;
	int opcionCarrera;

	if(arrayRecibido!=NULL)
	{
		printf("Ingrese sexo m ó f\n");
		fflush(stdin);
		scanf("%c",&auxSexo);
		while(auxSexo!='m'&&auxSexo!='f')
		{
			printf("ERROR,Ingrese sexo m ó f\n");
			fflush(stdin);
			scanf("%c",&auxSexo);
		}
		arrayRecibido[posicion].sexo=auxSexo;
		printf("Ingrese edad\n");
		fflush(stdin);
		scanf("%d",&auxEdad);
		while(auxEdad<18||auxEdad>100)
		{
			printf("ERROR,Ingrese edad entre 18 y 100\n");
			fflush(stdin);
			scanf("%d",&auxEdad);
		}
		arrayRecibido[posicion].edad=auxEdad;
		printf("Ingrese nota Uno\n");
		fflush(stdin);
		scanf("%d",&auxNotaUno);
		while(auxNotaUno<1||auxNotaUno>10)
		{
			printf("ERROR,Ingrese nota Uno\n");
			fflush(stdin);
			scanf("%d",&auxNotaUno);
		}
		arrayRecibido[posicion].notaUno=auxNotaUno;
		printf("Ingrese nota Dos\n");
		fflush(stdin);
		scanf("%d",&auxNotaDos);
		while(auxNotaDos<1||auxNotaDos>10)
		{
			printf("ERROR,Ingrese nota Dos\n");
			fflush(stdin);
			scanf("%d",&auxNotaDos);
		}
		arrayRecibido[posicion].notaDos=auxNotaDos;
		printf("Ingrese apellido\n");
		fflush(stdin);
		fgets (arrayRecibido[posicion].apellido,19,stdin);
		printf("Ingrese carrera Programacion 1\n"
			   "                Laboratorio  2\n"
			   "                Sistemas     3\n");
		fflush(stdin);
		scanf("%d",&opcionCarrera);
		while(opcionCarrera<1||opcionCarrera>3)
		{
			printf("ERROR,Ingrese carrera Programacion 1\n"
				   "                      Laboratorio  2\n"
				   "                      Sistemas     3\n");
			fflush(stdin);
			scanf("%d",&opcionCarrera);
		}
		arrayRecibido[posicion].idCarrera=opcionCarrera;
		arrayRecibido[posicion].estaVacio=0;
		promedioDosNotas(arrayRecibido,posicion);
		exito=1;
	}
	return exito;
}
*/
