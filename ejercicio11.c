#include <stdio.h>
#include <conio.h>
#define REPET 5

int main()
{
    float mayor = 0, menor = 0, num, ingresados[REPET] =  {0.0};
    int i = 0;
    
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
	printf("Este programa indicar\xa0 el n\xa3mero m\xa0s grande y el menor\n"
    "de una serie de 5.\n");
    
    for(i=0;i<REPET;i++)
    {
         printf("\nIngrese un n\xa3mero (%i): ",i+1);
         scanf("%f",&num);
         ingresados[i] = num;
         
         if( i==0 )
         {
             mayor = num;
             menor = num;
         } else {
             if ( num > mayor )
                mayor = num;
             if ( num < menor )
                menor = num;  
         }   
    }
    
    printf("\n\nEl n\xa3mero m\xa0s grande: %.2f\n"
    "El n\xa3mero m\xa0s chico: %.2f\n\n"
    "N\xa3meros ingresados: ",mayor,menor);
    
    for(i=0;i<REPET;i++)
    {
         if( i!=0 )
             printf(", ");
         printf("%.2f",ingresados[i]);
    }

    printf("\n\nPresione una tecla para salir...");
    getch();
	return 0;
}
