#include <stdio.h>
#include <conio.h>
#include <ctype.h>

// Prototipos
float pasar_a_celsius(float grados);
float pasar_a_fahrenheit(float grados);

int main()
{
	float grados_ini, grados_result;
	char unidad;
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

	printf("Este programa le permitir\xa0 definir el equivalente en grados \n"
    "Fahrenheit de su n\xa3mero ingresado o en grados celsius seg\xa3n su \n"
    "elecci\xa2n.\n"
    "Para salir ingrese la letra 'a' ...");
    do{
         printf("\n\nIngrese la unidad termom\x82trica ('a' para salir): "); 
         
         unidad = toupper(getch()); // Pasa a mayúsculas
         
         switch(unidad)
         {
              case 'C':
                   printf("\nIngrese ahora los grados: ");
                   scanf("%f", &grados_ini);
                   grados_result = pasar_a_fahrenheit(grados_ini);
                   printf("\nEl equivalente a %.2f grados Celsius en grados "
                   "Fahrenheit es: %.2f",grados_ini,grados_result);
                   break;
              case 'F':
                   printf("\nIngrese ahora los grados: ");
                   scanf("%f", &grados_ini);
                   grados_result = pasar_a_celsius(grados_ini);
                   printf("\nEl equivalente a %.2f grados Fahrenheit en grados "
                   "Celsius es: %.2f",grados_ini,grados_result);
                   break;
              case 'A':
                   // Se usará para salir
                   break;
              default:
                   printf("\nLetra incorrecta. Intente nuevamente...\n");
         };
    } while(unidad != 'A');

	return 0;
}

// Funciones
float pasar_a_celsius(float grados)
{
      float result;
      result = ( grados - 32.0 ) / 1.8;
      return result;
}
float pasar_a_fahrenheit(float grados)
{
      float result;
      result = (grados * 1.8) + 32.0;
      return result;
}
