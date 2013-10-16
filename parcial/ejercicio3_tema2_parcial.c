#include <stdio.h>
#include <conio.h>

struct datos_persona {
	char nombre[50];
	int id;
}; struct datos_persona legajo;

// Prototipo
void escribir_dato(struct datos_persona legajo);


int main()
{
	escribir_dato(legajo);
	
	printf("Presione una tecla para salir...");
	getch();
	return 0;
}

void escribir_dato(struct datos_persona legajo)
{
	printf("Ingrese el nombre: ");
	fflush(stdin);
	scanf("%s",legajo.nombre);
	printf("Ingrese el numero de legajo: ");
	scanf("%d",&legajo.id);

	printf("\nDatos: Nombre: %s, legajo: %d\n\n",legajo.nombre,legajo.id);
}

