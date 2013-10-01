#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#define MAX_ALUMNO 4

typedef struct{ /* estructura anónima */
       char nombre[20],apellido[20];
       float altura;
} Persona;

int main()
{
    Persona alumno[MAX_ALUMNO];
    unsigned int pos_max_alt, cant = 0, max = MAX_ALUMNO, i = 0;
    char salida;
    float max_altura;
    
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
	printf("Este programa indicar\xa0 cu\xa0l alumno es el m\xa0s alto\n"
    "de un m\xa0ximo de %i alumnos\n\n",max);
    
    for( i=0 ; i<MAX_ALUMNO ; i++ )
    {
         printf("\n\nIngrese el nombre del alumno (%i): ",i+1);
         fflush(stdin);
         scanf("%s",alumno[i].nombre);
         printf("Ingrese el apellido del alumno (%i): ",i+1);
         fflush(stdin);
         scanf("%s",alumno[i].apellido);
         printf("Ingrese la altura del alumno (%i) en metros: ",i+1);
         scanf("%f",&alumno[i].altura);
         
         printf("\nDesea continuar? (s = Si): ");
         salida = toupper(getch()); // Pasa a mayúsculas
         
         if( salida != 'S' )
             break;
         
         if ( i==0 )
         {
             pos_max_alt = i;
             max_altura = alumno[i].altura;
         } else {
             if ( alumno[i].altura > max_altura )
             {
                  pos_max_alt = i;
                  max_altura = alumno[i].altura;
             }
         }
         cant++;
    }
    if( cant == 0 )
        printf("\n\nNo se han ingresado alumnos.");
    else {
        printf("\n\nAlumno de mayor altura: %s\nAltura %.2f\n\n"
        "Alumnos ingresados: \n\n",
        alumno[pos_max_alt].nombre,alumno[pos_max_alt].altura);
        
        for(i=0;i<cant;i++){              
             printf("Alumno(%i): %s, %s\nAltura %.2f\n\n",
             i+1,alumno[i].nombre,alumno[i].apellido,alumno[i].altura);
        }
    }
    printf("Presione una tecla para salir...");
    getch();
	return 0;
}
