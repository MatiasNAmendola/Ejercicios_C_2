#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

#define CANT_MATERIAS 6

typedef struct{ /* estructura anónima */
       char nombre[20],apellido[20];
       float nota[CANT_MATERIAS-1], promedio;
} Alumnos;

int main()
{
    unsigned int cant_alumnos = 6, i, j;
    float lcl_nota = 0;
    Alumnos *alumno;
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
    printf("Defina cu\xa0ntos alumnos desea ingresar: ");
    scanf ("%d",&cant_alumnos);
    
    if (cant_alumnos <= 0)
    {
       printf("\n\nNo se desean Ingresar alumnos. Presione una tecla para salir");
       getch();
	   return 0;
    }     

    // Reservamos espacio suficiente para poder guardar la lista de Alumnos
    alumno = (Alumnos *)malloc(cant_alumnos*sizeof(Alumnos) );
    
    for( i=0; i<cant_alumnos; i++ )
    {
         printf("\n\nIngrese el nombre del alumno (%i): ",i+1);
         fflush(stdin);
         scanf("%s",alumno[i].nombre);
         printf("Ingrese el apellido del alumno (%i): ",i+1);
         fflush(stdin);
         scanf("%s",alumno[i].apellido);
         for( j=0; j<CANT_MATERIAS ; j++ )
         {
              printf("Ingrese la nota de la materia %d: ",j+1);
              scanf("%f",&alumno[i].nota[j]);
         }
         lcl_nota = 0;
         for( j=0; j<CANT_MATERIAS ; j++ )
              lcl_nota += alumno[i].nota[j];
         
         alumno[i].promedio = lcl_nota/CANT_MATERIAS;
    }
    printf("\n\nAlumnos Ingresados:\n\n");
    for( i=0; i<cant_alumnos; i++ )
    {
         printf("Alumno: %s, %s\n",alumno[i].apellido,alumno[i].nombre);
         printf("Promedio: %.2f\n\n",alumno[i].promedio);
    }   
         
    free( alumno );
    printf("Presione una tecla para salir...");
    getch();
	return 0;
}
