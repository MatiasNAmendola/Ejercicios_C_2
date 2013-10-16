#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define MAX_FILAS 3
#define MAX_COLUMNAS 3
#define MAX_JUGADAS 9
#define TAM_NOMBRE 50
#define CELDA 3

typedef struct {
    char nombre[TAM_NOMBRE];
    char ficha;
} Jugador;

// Prototipos
void inicializar_tateti(char tateti[][MAX_COLUMNAS],Jugador *oponente1,Jugador *oponente2);
void imprimir_tateti(char tateti[][MAX_COLUMNAS]);
int cargar_tateti(char casillero[],char tateti[][MAX_COLUMNAS],char ficha);
void establecer_jugadores(Jugador *oponente1,Jugador *oponente2);
void definir_nombre(Jugador *oponente,int orden);
void definir_ficha(Jugador *oponente,int orden);
int validar_nombre(char nombre1[],char nombre2[]);
int validar_ficha(char ficha1,char ficha2);
int validar_tateti_estandar(char tateti[][MAX_COLUMNAS],char ficha_jugador1, char ficha_jugador2);
int quien_gano(char ficha, char ficha_jugador1, char ficha_jugador2);
int realizar_jugada(Jugador oponente,char tateti[][MAX_COLUMNAS]);
void limpiar_nombre(Jugador *oponente);
int predecir(char tateti[][MAX_COLUMNAS],char ficha,char ficha_jugador1, char ficha_jugador2);
void guardar_historial(char jugador1[],char jugador2[],int estado,time_t inicial);

int main()
{
    
    Jugador oponente1,oponente2;
    int resultado = 0, jugadas = 0;
    time_t tiempo_inicial;
    char tateti[MAX_FILAS][MAX_COLUMNAS];
    
    srand(time(0));

    inicializar_tateti(tateti,&oponente1,&oponente2);

    printf("Este es el juego del Tres en Linea o Ta-Te-Ti\n\n"
           "A continuacion se deberan definir los jugadores\n\n\n"
           "Presione una tecla para continuar...");

    getch();

    system("CLS");
    establecer_jugadores(&oponente1,&oponente2);
    
    imprimir_tateti(tateti);
    tiempo_inicial = time(NULL);
    printf("Comencemos...\n\n\n");
    
    while(jugadas<MAX_JUGADAS)
	{
		   resultado = -1;
    	   do{
			   resultado = realizar_jugada(oponente1,tateti);
		   } while(resultado<0);
                               
           resultado = validar_tateti_estandar(tateti,oponente1.ficha,oponente2.ficha);
           switch(resultado)
           {
                case 1:
                     printf("Ha ganado el Jugador %s\n\n\n",oponente1.nombre);
                     guardar_historial(oponente1.nombre,oponente2.nombre,1,tiempo_inicial);
                     break;
                case 2:
                     printf("Ha ganado el Jugador %s\n\n\n",oponente2.nombre);
                     guardar_historial(oponente1.nombre,oponente2.nombre,2,tiempo_inicial);
                     break;
           }
           if(resultado == 1 || resultado == 2)
                 break;
                 
           /* 
              Predice la próxima jugada, por eso como ficha (segundo parámetro)
              Se pasa la ficha correspondiente del jugador actual.
           */
           resultado = predecir(tateti,oponente1.ficha,oponente1.ficha,oponente2.ficha);
           if(resultado<0)
           {
                printf("Empate!!!\n\n\n");
                break;
           } else {
			   if(jugadas == MAX_JUGADAS-1)
			   {
			   		printf("Ha ganado el Jugador %s\n\n\n",oponente2.nombre);
			   		guardar_historial(oponente1.nombre,oponente2.nombre,2,tiempo_inicial);
			   		break;
			   }	
		   }
                         
           jugadas++;
           
           if(jugadas == MAX_JUGADAS)
                break;
                              
           resultado = -1;
    	   do{
			   resultado = realizar_jugada(oponente2,tateti);
		   } while(resultado<0);
                                       
           resultado = validar_tateti_estandar(tateti,oponente1.ficha,oponente2.ficha);
           switch(resultado)
           {
                case 1:
                     printf("Ha ganado el Jugador %s\n\n\n",oponente1.nombre);
                     guardar_historial(oponente1.nombre,oponente2.nombre,1,tiempo_inicial);
                     break;
                case 2:
                     printf("Ha ganado el Jugador %s\n\n\n",oponente2.nombre);
                     guardar_historial(oponente1.nombre,oponente2.nombre,2,tiempo_inicial);
                     break;
           }
           if(resultado == 1 || resultado == 2)
                 break;
                            
           jugadas++;
           
           if(jugadas == MAX_JUGADAS)
                break;
           
           /* 
              Predice la próxima jugada, por eso como ficha (segundo parámetro)
              Se pasa la ficha correspondiente del jugador actual.
           */
           resultado = predecir(tateti,oponente2.ficha,oponente1.ficha,oponente2.ficha);
           if(resultado<0)
           {
                printf("Empate!!!\n\n\n");
                guardar_historial(oponente1.nombre,oponente2.nombre,0,tiempo_inicial);
                break;
           } else {
			   if(jugadas == MAX_JUGADAS-1)
			   {
			   		printf("Ha ganado el Jugador %s\n\n\n",oponente1.nombre);
			   		guardar_historial(oponente1.nombre,oponente2.nombre,1,tiempo_inicial);
			   		break;
			   }	
		   }                                
    }
    
    if(jugadas == MAX_JUGADAS)
    {
           printf("Empate!!!\n\n\n");
           guardar_historial(oponente1.nombre,oponente2.nombre,0,tiempo_inicial);
    }
    getch();
    return 0;
}

/**
 * Inicializa el tablero, y cada jugador (parámetros por referencia)
*/
void inicializar_tateti(char tateti[][MAX_COLUMNAS],Jugador *oponente1,Jugador *oponente2)
{
     int i=0,j=0;
     for(i=0;i<MAX_FILAS;i++)
          for(j=0;j<MAX_COLUMNAS;j++)
                tateti[i][j] = ' ';
            
     oponente1->ficha = '_';
     oponente2->ficha = '_';
}
/**
 * Solicita al usuario su nombre
 * Parámetros:
 * 1- struct Jugador (por referencia)
 * 2- entero Orden del Jugador (Ej: Jugador 1)
 */
void definir_nombre(Jugador *oponente,int orden)
{
     do{
       printf("\n\nIngrese el nombre del Jugador %d: ",orden);
       fflush(stdin);
       fgets(oponente->nombre,TAM_NOMBRE,stdin);
       if(strcmp(oponente->nombre,"\n") == 0)
       {
               system("CLS");
               printf("ERROR: No puede ingresar un nombre vacio...");                    
       }       
    } while(strcmp(oponente->nombre,"\n") == 0);
    
    limpiar_nombre(&(*oponente));
}
/**
 * Elimina el último caracter ingresado (enter) y lo reemplaza por un espacio
 * Esto se requiere ya que al momento de mostrar el nombre del jugador aparecia
 * el mensaje debajo y esto lo corrige.
 */
void limpiar_nombre(Jugador *oponente)
{
     int i=0;
     for(i=0;i<TAM_NOMBRE;i++){
          if(oponente->nombre[i] == '\n')
          {
              oponente->nombre[i] = '\0';
          }
     }
}
/**
 * Solicita al usuario que ingrese la ficha
 * Parámetros:
 * 1- struct Jugador (por referencia)
 * 2- entero Orden del Jugador (Ej: Jugador 1)
 */
void definir_ficha(Jugador *oponente,int orden)
{
     do{
       printf("\n\nIngrese el tipo de ficha para el Jugador %d: ",orden);
       fflush(stdin);
       oponente->ficha = getchar();
       if(oponente->ficha == '\n')
       {
               system("CLS");
               printf("ERROR: No puede ingresar una ficha vacia...");                    
       }       
    } while(oponente->ficha == '\n');
}
/**
 * Determina si el nombre ingresado no está en uso
 * Devuelve 0 (cero) si no se repite o -1 en caso de repetirse.
 */
int validar_nombre(char nombre1[],char nombre2[])
{
	// Pasa toda la cadena a mayúsculas
     strupr(nombre1);
     strupr(nombre2);
     // compara dos cadenas (insensible a las mayúsculas y minúsculas)
     if(strcasecmp(nombre1,nombre2) == 0)
     {
            system("CLS");
            printf("El nombre ingresado ya fue escogido\n\n");
            return -1;                                     
     }
     return 0;     
}
/**
 * Valida que la ficha ingresada no este repetida
 * Devuelve 0 en caso de exito o -1 si hubo un error
 */
int validar_ficha(char ficha1,char ficha2)
{
     if(toupper(ficha1)==toupper(ficha2))
      {
            system("CLS");
            printf("\nLa ficha ingresada ya fue escogida\n\n");
            return -1;                                    
      }
     return 0;
}

void establecer_jugadores(Jugador *oponente1,Jugador *oponente2)
{
    int lbresp = 0;

    do{
         definir_nombre(&(*oponente1),1);
         lbresp = validar_nombre(oponente1->nombre,oponente2->nombre);
         if(lbresp < 0){
             continue;
         }
         lbresp = 0;
    } while(lbresp < 0);
    do{    
         definir_ficha(&(*oponente1),1);
         lbresp = validar_ficha(oponente1->ficha,oponente2->ficha);
         if(lbresp < 0){
             continue;
         }
         lbresp = 0;                 
    } while(lbresp < 0);
    
    do{
         definir_nombre(&(*oponente2),2);
         lbresp = validar_nombre(oponente1->nombre,oponente2->nombre);
         if(lbresp < 0){
             continue;
         }
         lbresp = 0;
    } while(lbresp < 0);
    do{
         definir_ficha(&(*oponente2),2);
         lbresp = validar_ficha(oponente1->ficha,oponente2->ficha);
         if(lbresp < 0){
             continue;
         }
         lbresp = 0;                  
    } while(lbresp < 0);
}
/**
 * Se le solicita al jugador que escoja una celda y se lo ingresa en el
 * tablero. En caso de no haber problemas se vuelve a imprimir el tablero.
 * Retorna 0 en caso de haberse realizado la jugada con exito o 
 * -1 en caso de error.
 */
int realizar_jugada(Jugador oponente,char tateti[][MAX_COLUMNAS])
{
    char casillero[CELDA];
    int resultado = 0;
    char columna = 'a';
    
    switch(rand()%3)
   {
        case 0:
             columna = 'a';
             break;
        case 1:
             columna = 'b';
             break;
   		case 2:
             columna = 'c';
             break;
	    default:
 		     columna = 'a';
	    	 break;
   }
    printf("Jugador %s, ingrese la celda (Ej: %c%d): ",
			oponente.nombre,columna,rand()%3+1);  
    fflush(stdin);
    fgets(casillero,CELDA,stdin);
    resultado = cargar_tateti(casillero,tateti,oponente.ficha);
    if(resultado <0){
        return -1;
    }
    imprimir_tateti(tateti);
    return 0;    
}

/** 
 * Devuelve:
 * 0: si se pudo grabar el dato y no hubo errores
 * -1: Si se ingreso mal la fila o la columna
 * -2: Si se escogio un casillero ocupado
 */
int cargar_tateti(char casillero[],char tateti[][MAX_COLUMNAS],char ficha)
{
     int pos_fila=0,pos_col=0;
     casillero[0]=toupper(casillero[0]);
     
     if(casillero[0] == '\n')
     {
           printf("\n\nERROR: Ingrese la Columna!\n\n");
           return -1;
     }
     if(casillero[1] == '\n')
     {
           printf("\n\nERROR: Ingrese la Fila!\n\n");
           return -1;
     }
     
     switch(casillero[0])
     {
          case 'A':
               pos_col = 0;
               break;
          case 'B':
               pos_col = 1;
               break;
          case 'C':
               pos_col = 2;
               break;
          default:
               printf("\n\nERROR: Columna Incorrecta. Intente nuevamente...\n\n");
               return -1;
     }
     switch(casillero[1])
     {
          case '1':
               pos_fila = 0;
               break;
          case '2':
               pos_fila = 1;
               break;
          case '3':
               pos_fila = 2;
               break;
          default:
               printf("\n\nERROR: Fila Incorrecta. Intente nuevamente...\n\n");
               return -1;
     }
     if(tateti[pos_fila][pos_col] != ' ')
     {
          printf("\n\nERROR: El Casillero no esta vacio. Intente con otro...\n\n");
          return -1;                      
     }
     tateti[pos_fila][pos_col] = ficha;
     
     return 0;
}

/**
 * Procedimiento para imprimir por pantalla el tablero de
 * Ta-Te-Ti
*/
void imprimir_tateti(char tateti[][MAX_COLUMNAS])
{
    //            A               B                   C
    // 1 -- tateti[0][0]  |  tateti[0][1]    |   tateti[0][2]
    //      -------------------------------------------------
    // 2 -- tateti[1][0]  |  tateti[1][1]    |   tateti[1][2]
    //      -------------------------------------------------
    // 3 -- tateti[2][0]  |  tateti[2][1]    |   tateti[2][2]
     int i;
     system("CLS"); // Borra la pantalla (se usa con la librería stdlib.h)

     printf("           A               B                C\n\n");
     for(i=0;i<MAX_FILAS;i++)
     {
           printf("%d --       %c       |       %c        |       %c\n",
               i+1,tateti[i][0],tateti[i][1],tateti[i][2]);
           if (i<2){
              printf("     -------------------------------------------------\n");
           }
     }
     printf("\n\n");

}
/**
 * Chequea el simbolo ingresado para compararlo entre los jugadores
 * Si la ficha que tomo como primer parametro es igual a algun jugador
 * devolvera un indicador:
 * 1- Gano el primer jugador
 * 2- Gano el segundo jugador
 * 0- No corresponde a ningun jugador (en el caso de que hayan espacios
 * por ejemplo, lo que segun este juego se considera ' ')
*/
int quien_gano(char ficha, char ficha_jugador1, char ficha_jugador2)
{
    ficha = toupper(ficha);
    ficha_jugador1 = toupper(ficha_jugador1);
    ficha_jugador2 = toupper(ficha_jugador2);
    
     if (ficha == ficha_jugador1)
        return 1;

     if (ficha == ficha_jugador2)
        return 2;

     return 0;
}
/**
 * Función que devuelve 0 si no ha habido aun ganadores, o 1 si gano el
 * primer jugador o 2 si ganó el segundo jugador
*/
int validar_tateti_estandar(char tateti[][MAX_COLUMNAS],char ficha_jugador1, char ficha_jugador2)
{
    int j, i, resultado = 0;
    for ( i=0; i<MAX_FILAS; i++ ){
        // Si coinciden en alguna fila
        if ( tateti[i][0]==tateti[i][1] && tateti[i][1]==tateti[i][2]){
             resultado = quien_gano(tateti[i][0],ficha_jugador1,ficha_jugador2);
             if(resultado>0){
                 return resultado;
             }
        }
    }
    for ( j=0; j<MAX_COLUMNAS; j++ ){
        // Si coinciden en alguna columna
        if ( tateti[0][j]==tateti[1][j] && tateti[1][j]==tateti[2][j] ){
             resultado = quien_gano(tateti[0][j],ficha_jugador1,ficha_jugador2);
             if(resultado>0){
                 return resultado;
             }
        }
    }
    // Si coincide en la diagonal (decreciente)
    if ( tateti[0][0] == tateti[1][1] && tateti[1][1] == tateti[2][2] ){
         resultado = quien_gano(tateti[0][0],ficha_jugador1,ficha_jugador2);
         if(resultado>0){
             return resultado;
         }
    }
    // Si coincide en la diagonal (creciente)
    if ( tateti[2][0] == tateti[1][1] && tateti[1][1] == tateti[0][2] ){
         resultado = quien_gano(tateti[2][0],ficha_jugador1,ficha_jugador2);
         if(resultado>0){
             return resultado;
         }
    }
    return resultado;
}

int predecir(char tateti[][MAX_COLUMNAS],char ficha,char ficha_jugador1, char ficha_jugador2)
{
    char temp[MAX_FILAS][MAX_COLUMNAS];
    int i=0,j=0,resultado=0;
    for(i=0;i<MAX_FILAS;i++)
          for(j=0;j<MAX_COLUMNAS;j++)
                if(tateti[i][j] == ' ')
                     temp[i][j] = ficha;
                else
                     temp[i][j] = tateti[i][j];
              
    resultado = validar_tateti_estandar(temp,ficha_jugador1,ficha_jugador2);
    if(resultado>0)
        return 0; // Hay posibilidades de ganar
    
    return -1; // No hay posibilidades de ganar
}

/**
 * Graba en el documento historial_tateti.txt los resultados del juego.
 * Por ultimo muestra todo el historial.
 * 
 * Parametros:
 * 1- Nombre del jugador 1 (arreglo de caracteres)
 * 2- Nombre del jugador 2 (arreglo de caracteres)
 * 3- estado (entero):
 * 		Si se pasa 0 guarda el resultado como empate,
 * 		Si se pasa 1 guarda el resultado que gano el jugador1,
 * 		Si se pasa 2 guarda el resultado que gano el jugador2.
 */
void guardar_historial(char jugador1[],char jugador2[],int estado,time_t inicial)
{
	FILE *file;
	char linea[150],*car;
	char resultado[100];
	time_t t,final;
	int cronometro;
	struct tm *tm;
	char fechayhora[100];
	
	final = time(NULL);
	cronometro = final - inicial;
	t=time(NULL);
	tm=localtime(&t);
	strftime(fechayhora, 100, "%d/%m/%Y %H:%M.%S", tm);
	
	switch(estado)
   {
        case 1:
             strcpy(resultado,"Ha ganado el Jugador ");
             strcpy(resultado,jugador1);
             break;
   		case 2:
             strcpy(resultado,"Ha ganado el Jugador ");
             strcpy(resultado,jugador2);
             break;
	    default:
 		     strcpy(resultado,"Empate");
	    	 break;
   } 	 
	
	file = fopen("historial_tateti.txt", "a+");
	fprintf(file,"Jugador1: %s, Jugador2: %s, Resultado: %s %s Tiempo de jugada %d seg.\n",
		jugador1,jugador2,resultado,fechayhora,cronometro);
    fclose(file);
	
	file = fopen("historial_tateti.txt", "r");
	
	printf("Historial\n");
	do {
		car = fgets(linea,sizeof(linea),file);
		if(car != NULL)
			printf("%s",linea);
		
	} while(car != NULL);
	
	
	fclose(file);
}