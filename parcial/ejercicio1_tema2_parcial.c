#include <stdio.h>
#include <conio.h>

int main()
{
	int valor1 = 4, valor2 = 7;
	
	// mayor a
	if(valor1 > valor2)
		printf("%d es mayor a %d\n",valor1,valor2);
	
	// menor a
	if(valor1 < valor2)
		printf("%d es menor a %d\n",valor1,valor2);
	
	// igual a
	if(valor1 == valor2)
		printf("%d es igual a %d\n",valor1,valor2);
	
	// distinto a
	if(valor1 != valor2)
		printf("%d es distinto a %d\n",valor1,valor2);
	
	
	printf("Presione una tecla para salir...");
	getch();
	return 0;
}