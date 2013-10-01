#include <stdio.h>
#include <conio.h>
#define PI 3.14

//Prototipos
float perimetro_circunferencia(float radio);
float area_circunferencia(float radio);

int main()
{
	float radio=0.00, perimetro=0.00, area=0.00;
	/*
	� -> \244
    � -> \245
    � -> \240
    � -> \241
    � -> \242
    � -> \243
	*/
	printf("A continuaci\242n deber\240 ingresar el radio y el programa le"
    "\n calcular\240 su per\241metro y \240rea \n\n");
    
    do{
        printf("Ingrese el radio (en cent\241metros): ");
        scanf("%f", &radio);
        
        if(radio <= 0)
               printf("\n\nERROR, el radio debe ser mayor que cero\n\n");
        
    }while(radio <= 0);
    
    perimetro = perimetro_circunferencia(radio);
    area = area_circunferencia(radio);
    
    printf("\n\nDatos de la circunferencia:\n"
    "Radio escogido: %.2f cm\nper\241metro: %.2f cm2\nArea: %.2f cm3\n\n",
    radio,perimetro,area);

	printf("Presione una tecla para salir");
	getch();
	return 0;
}
// A continuaci�n se listan las funciones
float perimetro_circunferencia(float radio)
{
      float resultado = 0.00;
      resultado = 2 * PI * radio;
      return resultado;      
}
float area_circunferencia(float radio)
{
      float resultado = 0.00;
      resultado = PI * radio * radio;
      return resultado;      
}
