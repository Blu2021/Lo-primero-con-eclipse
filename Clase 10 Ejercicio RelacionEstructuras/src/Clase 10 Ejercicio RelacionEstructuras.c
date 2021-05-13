//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
//Producto-Proveedor (Donde el producto solo puede tener un único proveedor)
typedef struct
{
	char calle[20];
	int altura;
	int estaVacio;
}direccion;

typedef struct
{
	int idProveedor;
	char razonSocial[20];
	direccion domicilio;
	int estaVacio;
}proveedor;

typedef struct
{
	int idProducto;
	char descripcion[20];
	float precio;
	int estaVacio;
	int idProveedor;
}producto;
//Dueño-Mascota (Donde la mascota solo puede tener un único dueño)
typedef struct
{
	char colorPelo[10];
	char largoPelaje[10];
	char tipoRaza[15];
	int estaVacio;
}raza;

typedef struct
{
	int idDuenio;
	char nombre[20];
	char sexo;
	int edad;
	int estaVacio;
}duenio;

typedef struct
{
	int idMascota;
	char nombre[20];
	char sexo;
	raza eRaza;
	int idDuenio;
	int estaVacio;
}mascota;
//Alumno-Localidad (Donde un alumno solo vive en una localidad)

typedef struct
{
	int idLocalidad;
	char descripcion[30];
	int codigoPostal;
}localidad;

typedef struct
{
	int idAlumno;
	char apellido[20];
	int idLocalidad;
}alumno;

int main(void)
{

	return EXIT_SUCCESS;
}
