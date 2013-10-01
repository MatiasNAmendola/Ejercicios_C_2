#include <stdio.h>
#include <conio.h>

// Prototipo
int es_par(unsigned int num);

int main()
{
	unsigned int num, tipo, cant_pares = 0, cant_impares = 0;
	
	printf("Este programa identificar\240 si los n\243meros ingresados son \n"
    "pares o impares (deber\240 introducir n\243meros enteros positivos.\n"
    "Para salir ingrese el cero...");

    do{
         printf("\n\nIngrese un n\243mero: "); 
         scanf("%i", &num);
         
         tipo = es_par(num);
         
         switch(tipo)
         {
              case 2: // Resultado que define al número como par
                   printf("\nEl n\243mero ingresado es par.");
                   cant_pares++;
                   break;
              case 1:
                   printf("\nEl n\243mero ingresado es impar.");
                   cant_impares++;
                   break;
         };
    } while(num!=0);
    
	printf("\n\nLa cantidad de n\243meros pares ingresados fueron: %i\n"
    "Cantidad de impares: %i\n\n", cant_pares, cant_impares);

	printf("Presione una tecla para salir");
	getch();
	return 0;
}

// Función
int es_par(unsigned int num)
{
    if( num == 0 )
        return 0;
    if( num%2 == 0 )  
       return 2;
       
    return 1;
}
