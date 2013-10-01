#include <stdio.h>
#include <conio.h>

int main()
{
	int cont=0;
	float n, total=0;

	while (cont<5)
	{
		printf("Ingrese un n£mero: ");
		scanf("%f", &n);
		total = total + n;
		cont++;
	}
	printf("\n\nSu promedio es: %.2f\n\n", total / 5);

	printf("Presione una tecla para salir");
	getch();
	return 0;
}
