#include <stdio.h>
#include <conio.h>

//Prototipo
float superficie_triangulo(float base,float altura);

int main()
{
	float base=0.00, altura=0.00, superficie=0.00;
	/*
	ñ -> \244
    Ñ -> \245
    á -> \240
    í -> \241
    ó -> \242
    ú -> \243
	*/
	printf("A continuaci\242n deber\240 ingresar la base y altura de un tri\240"
    "ngulo\n y el programa calcular\240 su superficie\n\n");
    
    do{
        printf("Ingrese la base del tri\240ngulo (en cent\241metros): ");
        scanf("%f", &base);
        
        printf("Ingrese ahora la altura (en cent\241metros): ");
        scanf("%f", &altura);
        
        if(base <= 0 || altura <= 0)
               printf("\n\nERROR, base o altura incorrectos, ingreselos "
               "nuevamente...\n\n");
        
    }while(base <= 0 || altura <= 0);
    
    superficie = superficie_triangulo(base,altura);
    
    printf("\n\nDatos del tri\240ngulo:\n\n"
    "Base escogida: %.2f cm\nAltura escogida: %.2f cm\nSuperficie: %.2f cm2\n\n"
    ,base,altura,superficie);

	printf("Presione una tecla para salir");
	getch();
	return 0;
}
// Función para calcular la superficie de un triángulo
float superficie_triangulo(float base,float altura)
{
      float resultado = 0.00;
      resultado = (base * altura)/2;
      return resultado;      
}
