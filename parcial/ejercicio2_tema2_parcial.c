#include <stdio.h>
#include <conio.h>

// Prototipo
void sumar(int num1,int num2);

int main()
{
	int valor1 = 4, valor2 = 7;
	
	sumar(valor1,valor2);
	
	printf("Presione una tecla para salir...");
	getch();
	return 0;
}

// Funcion

void sumar(int num1,int num2)
{
	printf("La suma de dos enteros es %d\n\n",num1+num2);
}