#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nodo {
	int dato;
	struct nodo *sig;
}; typedef struct nodo NODO;

// --- Esto no era necesario
int reemplazarelementoenlista(NODO *p,int n,int x);

int main()
{
	
	NODO *lista;
	int resultado, buscar = 2, reemplazar = 15;
	
	lista = (NODO *)malloc(3*sizeof(NODO));
	
	lista[0].dato = 5;
	lista[0].sig = &lista[1];
	lista[1].dato = 2;
	lista[1].sig = &lista[2];
	lista[2].dato = 4;
	lista[2].sig = NULL;
	
	resultado = reemplazarelementoenlista(lista,buscar,reemplazar);
	
	if(resultado == 1)
		printf("Se pudo reemplazar el dato\n\n");
	else
		printf("No se pudo reemplazar el dato\n\n");
	
	free(lista);
	printf("Presione una tecla para salir...");
	getch();
	return 0;	
}
// --- (fin) Esto no era necesario

// esta era la funcion que habia que desarrollar en el punto 4
int reemplazarelementoenlista(NODO *p,int n,int x)
{
	NODO *z;
	
	if (p == NULL)
	{
		return -1;
	} else {
		if (p->sig == NULL)
        {
			if(p->dato == n)
			{
				p->dato = x;
				return 1;
			}
			else
				return -1;
		} else {
			z = p;
			while (z != NULL)
			{
				if(z->dato == n)
				{
					z->dato = x;
					return 1;
				}
				z = z->sig;
			}
		}
		return -1;
	}	
}