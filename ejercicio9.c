#include <stdio.h>
#include <conio.h>
#include <math.h>

// Prototipos
unsigned int pasar_a_pies(float centimetros);
float pasar_a_pulgadas(float centimetros);

int main()
{
    unsigned int pies;
	float cm, pulgadas;
	/*
	�     \xa0
    �     \x82
    �     \xa1
    �     \xa2
    �     \xa3
    �     \xb5
    �     \x90
    �     \xd6
    �     \xe0
    �     \xe9
    �     \xa4
    �     \xa5
    �     \xa8
    */

	printf("Este programa le mostrar\xa0 el equivalente en pies y pulgadas\n"
    "de su n\xa3mero ingresado en cent\xa1metros.\n"
    "Para salir ingrese cero ...");
    do{
         printf("\n\nIngrese una longitud en cm (cero para salir): "); 
         
         scanf("%f",&cm);
         
         pies = pasar_a_pies(cm);
         pulgadas = pasar_a_pulgadas(cm);
         
         printf("\n\nLa longitud en cm ingresada es: %.2f\n"
         "Su equivalente en pies: %i\n"
         "Y su equivalente en pulgadas: %.1f\n\n",
         cm, pies, pulgadas);
         
    } while(cm != 0);

	return 0;
}

// Funciones Considerar 2.54 cm por pulgada y 12 pulgadas por pie
unsigned int pasar_a_pies(float centimetros)
{
     unsigned int result;
     result = (int)round(pasar_a_pulgadas(centimetros)/12);
     return result;
}
float pasar_a_pulgadas(float centimetros)
{
      float result;
      result = centimetros / 2.54;
      return result;
}
