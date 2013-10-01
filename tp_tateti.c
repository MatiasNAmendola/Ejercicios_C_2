#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
void inicializar_tablero(char tateti[][MAX_COLUMNAS]);
void inicializar_jugador(Jugador *oponente);
void imprimir_tateti(char tateti[][MAX_COLUMNAS]);
int cargar_tateti(char casillero[],char tateti[][MAX_COLUMNAS],char ficha);
void establecer_jugadores(Jugador *oponente1,Jugador *oponente2);
void definir_nombre(Jugador *oponente,int orden);
void definir_ficha(Jugador *oponente,int orden);
int validar_nombre(Jugador *oponente1,Jugador *oponente2);
int validar_ficha(Jugador *oponente1,Jugador *oponente2);
void mayuscula(char string[]);
int validar_tateti_estandar(char tateti[][MAX_COLUMNAS],char jugador1, char jugador2);
int quien_gano(char ficha, char jugador1, char jugador2);
int realizar_jugada(Jugador *oponente,char tateti[][MAX_COLUMNAS]);
void limpiar_nombre(Jugador *oponente);

int main()
{
    
    Jugador oponente1,oponente2;
    int ocupados = 0, resultado = 0, jugadas = 0;
    char tateti[MAX_FILAS][MAX_COLUMNAS];

    inicializar_tateti(tateti,&oponente1,&oponente2);

    printf("Este es el juego del Tres en Linea o Ta-Te-Ti\n\n"
           "A continuacion se deberan definir los jugadores\n\n\n"
           "Presione una tecla para continuar...");

    getch();

    system("CLS");
    establecer_jugadores(&oponente1,&oponente2);
    
    imprimir_tateti(tateti);
    printf("Comencemos...\n\n\n");
    
    do{
           resultado = realizar_jugada(&oponente1,tateti);
           if(resultado<0)
                continue;
                               
           resultado = validar_tateti_estandar(tateti,oponente1.ficha,oponente2.ficha);
           switch(resultado)
           {
                case 1:
                     printf("Ha ganado el Jugador %s\n\n\n",oponente1.nombre);
                     break;
                case 2:
                     printf("Ha ganado el Jugador %s\n\n\n",oponente2.nombre);
                     break;
           }
           if(resultado == 1 || resultado == 2)
                 break;
                          
           jugadas++;
           
           if(jugadas == MAX_JUGADAS)
                break;
                              
           resultado = realizar_jugada(&oponente2,tateti);
           if(resultado<0)
                continue;
                                       
           resultado = validar_tateti_estandar(tateti,oponente1.ficha,oponente2.ficha);
           switch(resultado)
           {
                case 1:
                     printf("Ha ganado el Jugador %s\n\n\n",oponente1.nombre);
                     break;
                case 2:
                     printf("Ha ganado el Jugador %s\n\n\n",oponente2.nombre);
                     break;
           }
           if(resultado == 1 || resultado == 2)
                 break;
                            
           jugadas++;
           
           if(jugadas == MAX_JUGADAS)
                break;
                                
    } while(jugadas<MAX_JUGADAS);
    
    if(jugadas == MAX_JUGADAS)
    {
           printf("Empate!!!\n\n\n");
    }
    getch();
    return 0;
}

/*
 * Setea la Matriz
*/
void inicializar_tateti(char tateti[][MAX_COLUMNAS],Jugador *oponente1,Jugador *oponente2)
{
     inicializar_tablero(tateti);
     inicializar_jugador(&(*oponente1));
     inicializar_jugador(&(*oponente2));    
}
void inicializar_tablero(char tateti[][MAX_COLUMNAS])
{
     int i=0,j=0;
     for(i=0;i<MAX_FILAS;i++)
          for(j=0;j<MAX_COLUMNAS;j++)
                tateti[i][j] = ' ';
}
void inicializar_jugador(Jugador *oponente)
{   
    (*oponente).ficha = '_';
}

void definir_nombre(Jugador *oponente,int orden)
{
     do{
       printf("\n\nIngrese el nombre del Jugador %d: ",orden);
       fflush(stdin);
       fgets((*oponente).nombre,TAM_NOMBRE,stdin);
       // gets((*oponente).nombre);
       // scanf("%s",(*oponente).nombre);
       if(strcmp((*oponente).nombre,"\n") == 0)
       {
               system("CLS"); // clrscr();
               printf("ERROR: No puede ingresar un nombre vacio...");                    
       }       
    } while(strcmp((*oponente).nombre,"\n") == 0);
    limpiar_nombre(&(*oponente));
}

void limpiar_nombre(Jugador *oponente)
{
     int i=0;
     for(i=0;i<TAM_NOMBRE;i++){
          if((*oponente).nombre[i] == '\n')
          {
              (*oponente).nombre[i] = ' ';
          }
     }
}

void definir_ficha(Jugador *oponente,int orden)
{
     do{
       printf("\n\nIngrese el tipo de ficha para el Jugador %d: ",orden);
       fflush(stdin);
       (*oponente).ficha = getchar();
       // putchar((*oponente).ficha); // Muestra por pantalla el caracter
       if((*oponente).ficha == '\n')
       {
               system("CLS"); // clrscr();
               printf("ERROR: No puede ingresar una ficha vacia...");                    
       }       
    } while((*oponente).ficha == '\n');
}

int validar_nombre(Jugador *oponente1,Jugador *oponente2)
{
     mayuscula((*oponente1).nombre);
     mayuscula((*oponente2).nombre);
     if(strcmp((*oponente1).nombre,(*oponente2).nombre)== 0)
     {
            system("CLS");
            printf("El nombre ingresado ya fue escogido\n\n");
            return -1;                                     
     }
     return 0;     
}
int validar_ficha(Jugador *oponente1,Jugador *oponente2)
{
     if(toupper((*oponente1).ficha)==toupper((*oponente2).ficha))
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
         lbresp = validar_nombre(&(*oponente1),&(*oponente2));
         if(lbresp < 0){
             continue;
         }
         lbresp = 0;
    } while(lbresp < 0);
    do{    
         definir_ficha(&(*oponente1),1);
         lbresp = validar_ficha(&(*oponente1),&(*oponente2));
         if(lbresp < 0){
             continue;
         }
         lbresp = 0;                 
    } while(lbresp < 0);
    
    do{
         definir_nombre(&(*oponente2),2);
         lbresp = validar_nombre(&(*oponente1),&(*oponente2));
         if(lbresp < 0){
             continue;
         }
         lbresp = 0;
    } while(lbresp < 0);
    do{
         definir_ficha(&(*oponente2),2);
         lbresp = validar_ficha(&(*oponente1),&(*oponente2));
         if(lbresp < 0){
             continue;
         }
         lbresp = 0;                  
    } while(lbresp < 0);
}

void mayuscula(char string[])
{
     int i=0;
     char *p = string;
     while (*p != '\0')
    {
        *p = toupper(*p);
        p++;
    }
}

int realizar_jugada(Jugador *oponente,char tateti[][MAX_COLUMNAS])
{
    char casillero[CELDA];
    int resultado = 0;
    printf("Jugador %s, ingrese la celda: ",(*oponente).nombre);  
    fflush(stdin);
    fgets(casillero,CELDA,stdin);
    resultado = cargar_tateti(casillero,tateti,(*oponente).ficha);
    if(resultado <0){
        return -1;
    }
    imprimir_tateti(tateti);
    return 0;    
}

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
          return -2;                      
     }
     tateti[pos_fila][pos_col] = ficha;
     
     return 0;
}

/*
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
/*
 * Chequea si el simbolo ingresado corresponde
*/
int quien_gano(char ficha, char jugador1, char jugador2)
{
    ficha = toupper(ficha);
    jugador1 = toupper(jugador1);
    jugador2 = toupper(jugador2);
    
     if (ficha == jugador1)
        return 1;

     if (ficha == jugador2)
        return 2;

     return 0;
}
/*
 * Función que devuelve 0 si no ha habido aún ganadores, o 1 si ganó el
 * primer jugador o 2 si ganó el segundo jugador
*/
int validar_tateti_estandar(char tateti[][MAX_COLUMNAS],char jugador1, char jugador2)
{
    int j, i, resultado = 0;
    for ( i=0; i<MAX_FILAS; i++ ){
        // Si coinciden en alguna fila
        if ( tateti[i][0]==tateti[i][1] && tateti[i][1]==tateti[i][2]){
             resultado = quien_gano(tateti[i][0],jugador1,jugador2);
             if(resultado>0){
                 return resultado;
             }
        }
    }
    for ( j=0; j<MAX_COLUMNAS; j++ ){
        // Si coinciden en alguna columna
        if ( tateti[0][j]==tateti[1][j] && tateti[1][j]==tateti[2][j] ){
             resultado = quien_gano(tateti[0][j],jugador1,jugador2);
             if(resultado>0){
                 return resultado;
             }
        }
    }
    // Si coincide en la diagonal (decreciente)
    if ( tateti[0][0] == tateti[1][1] && tateti[1][1] == tateti[2][2] ){
         resultado = quien_gano(tateti[0][0],jugador1,jugador2);
         if(resultado>0){
             return resultado;
         }
    }
    // Si coincide en la diagonal (creciente)
    if ( tateti[2][0] == tateti[1][1] && tateti[1][1] == tateti[0][2] ){
         resultado = quien_gano(tateti[2][0],jugador1,jugador2);
         if(resultado>0){
             return resultado;
         }
    }
    return resultado;
}
