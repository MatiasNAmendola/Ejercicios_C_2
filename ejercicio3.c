#include <stdio.h>
#include <conio.h>

int main()
{
	float num;
	int less_zero = 0, greater_zero = 0, equal_zero = 0, i, cant_num = 10;
	/*
	ñ -> \244
    Ñ -> \245
    á -> \240
    í -> \241
    ó -> \242
    ú -> \243
	*/
	printf("A continuaci\242n deber\240 ingresar %i n\243mero y el programa le"
    "\n indicar\240 cu\240ntos son mayores a cero y cu\240ntos son menores\n\n",
    cant_num);
	
	for (i=0;i<cant_num;i++)
	{
        printf("Ingrese un n\243mero: ");
        scanf("%f", &num);
        
        if(num > 0)
             greater_zero++;
        else if(num < 0)
             less_zero++;
        else
             equal_zero++;
	}
	printf("\n\nLa cantidad de n\243meros mayores a cero fue: %i;\n"
    "la cantidad de n\243meros menores a cero: %i,\n"
    "y la cantidad de ceros ingresados fue: %i\n\n",
    greater_zero,less_zero,equal_zero);

	printf("Presione una tecla para salir");
	getch();
	return 0;
}
