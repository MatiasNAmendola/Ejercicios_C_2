#include <stdio.h>
#include <conio.h>
// Prototipo
float cuadrado(float num);

int main()
{
	float num=0, result=0.0;
	
	do{
           printf("Ingrese un n£mero mayor a cero: ");
           scanf("%f", &num);
           
           if(num <= 0)
                  printf("ERROR, el n£mero debe ser mayor que cero\n\n");
                  
    } while (num <= 0);
    
    result = cuadrado(num);
    
    printf("\n\nEl cuadrado de %.2f es: %.2f\n\n",num,result);
    
	printf("Presione una tecla para salir");
	getch();
	return 0;
}
// Función
float cuadrado(float num){
      return num *= num;
}
