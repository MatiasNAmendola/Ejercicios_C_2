#include <stdio.h>
#include <conio.h>
<<<<<<< HEAD:ejercicio10.c
#include <ctype.h>
=======
#include <ctype.h
>>>>>>> 6d7b1a6143464aa6e2925a2ced6970e1e883329d:ejercicio10.cpp
#define CANT_CAR 20

int main()
{
<<<<<<< HEAD:ejercicio10.c
    char caracter;
    int i = 0, canta = 0, cante = 0, canti = 0, canto = 0, cantu = 0;
    int cantvoc = 0;
=======
    int i = 0, canta = 0, cante = 0, canti = 0, canto = 0, cantu = 0, cantvoc = 0, cant_car = CANT_CAR;
    char letra;
>>>>>>> 6d7b1a6143464aa6e2925a2ced6970e1e883329d:ejercicio10.cpp
	/*
	ï¿½     \xa0
    ï¿½     \x82
    ï¿½     \xa1
    ï¿½     \xa2
    ï¿½     \xa3
    ï¿½     \xb5
    ï¿½     \x90
    ï¿½     \xd6
    ï¿½     \xe0
    ï¿½     \xe9
    ï¿½     \xa4
    ï¿½     \xa5
    ï¿½     \xa8
    */

<<<<<<< HEAD:ejercicio10.c
	printf("Este programa indicar\xa0 la cantidad de vocales ingresadas\n\n");
    
    for(i=0;i<CANT_CAR;i++)
    {
         printf("\nIngrese un caracter (%i): ",i+1);
         // caracter = toupper(getch()); // Pasa a mayúsculas
         fflush(stdin);
         scanf("%c",&caracter);
         caracter = toupper(caracter);
         switch(caracter)
=======
	printf("Este programa indicar\xa0 el n\xa3mero de vocales ingresadas de una serie de "
    "de una serie de %i.\n",cant_car);
    
    for(i=0;i<cant_car;i++)
    {
         printf("\nIngrese una letra (%i): ",i+1);
         letra = toupper(getch()); // Pasa a mayï¿½sculas
         switch(letra)
>>>>>>> 6d7b1a6143464aa6e2925a2ced6970e1e883329d:ejercicio10.cpp
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
