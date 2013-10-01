#include <stdio.h>
#include <conio.h>

int main()
{
	float n;
	int cant_neg = 0, cant_pos = 0;
	
	printf("Este programa identificar\240 si un n\243mero ingresado\n"
    "es negativo o positivo. Para salir ingrese el cero...");

    do{
         printf("\n\nIngrese un n\243mero: "); 
         scanf("%f", &n);
         if(n>0)
         {
              printf("\nEl n\243mero ingresado es mayor a cero.");
              cant_pos++;
         } else {
             if(n<0)
             {
                  printf("\nEl n\243mero ingresado es menor a cero.");
                  cant_neg++;
             }
         }
    } while(n!=0);
    
	printf("\n\nLa cantidad de n\243meros positivos ingresados fueron: %i\n"
    "Cantidad de negativos ingresados: %i\n\n", cant_pos, cant_neg);

	printf("Presione una tecla para salir");
	getch();
	return 0;
}
