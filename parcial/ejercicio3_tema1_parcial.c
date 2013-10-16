#include <stdio.h>
#include <conio.h>

struct fecha {
	int dia;
	int mes;
	int anio;
}; struct fecha fecha;

// Prototipo
void setFecha(struct fecha *fecha);
void getFecha(struct fecha *fecha);


int main()
{
	
	// No me acuerdo el nombre de la funcion, pero es de este estilo
	setFecha(&fecha);
	
	getFecha(&fecha);
	
	printf("Presione una tecla para salir...");
	getch();
	return 0;
}

void setFecha(struct fecha *fecha)
{
	printf("Ingrese el dia: ");
	scanf("%d",&fecha->dia);
	printf("Ingrese el mes: ");
	scanf("%d",&fecha->mes);
	printf("Ingrese el anio: ");
	scanf("%d",&fecha->anio);
}

void getFecha(struct fecha *fecha)
{
	printf("La fecha ingresada es: %d/%d/%d\n",
		fecha->dia,fecha->mes,fecha->anio);
}