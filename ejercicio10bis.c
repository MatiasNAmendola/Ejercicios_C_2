#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define CANT_CAR 20

int main()
{
    char caracter;
    int i = 0, canta = 0, cante = 0, canti = 0, canto = 0, cantu = 0;
    int cantvoc = 0;
	/*
	á     \xa0
    é     \x82
    í     \xa1
    ó     \xa2
    ú     \xa3
    Á     \xb5
    É     \x90
    Í     \xd6
    Ó     \xe0
    Ú     \xe9
    ñ     \xa4
    Ñ     \xa5
    ¿     \xa8
    */

	printf("Este programa indicar\xa0 la cantidad de vocales ingresadas\n\n");
    
    for(i=0;i<CANT_CAR;i++)
    {
         printf("\nIngrese un caracter (%i): ",i+1);
         // caracter = toupper(getch()); // Pasa a mayúsculas
         fflush(stdin);
         scanf("%c",&caracter);
         caracter = toupper(caracter);
         switch(caracter)
         {
              case 'A':
                   canta++;
                   cantvoc++;
                   break;
              case 'E':
                   cante++;
                   cantvoc++;
                   break;
              case 'I':
                   canti++;
                   cantvoc++;
                   break;
              case 'O':
                   canto++;
                   cantvoc++;
                   break;
              case 'U':
                   cantu++;
                   cantvoc++;
                   break;
         }                  
    }
    
    printf("\n\nCantidad de vocales ingresadas: %i\n"
    "Cantidad de 'A': %i\nCantidad de 'E': %i\n"
    "Cantidad de 'I': %i\nCantidad de 'O': %i\n"
    "Cantidad de 'U': %i\n\n",cantvoc,canta,cante,canti,canto,cantu); 

    printf("Presione una tecla para salir...");
    getch();
	return 0;
}
