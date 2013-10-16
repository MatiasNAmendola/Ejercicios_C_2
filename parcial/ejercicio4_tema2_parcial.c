#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nodo {
	int dato;
	struct nodo *sig;
}; typedef struct nodo NODO;

// --- Esto no era necesario
int buscarelementoenlista(NODO *p,int n);

int main()
{
	
	NODO *lista;
	int resultado;
	int buscar = 2;
	
	lista = (NODO *)malloc(3*sizeof(NODO));
	
	lista[0].dato = 5;
	lista[0].sig = &lista[1];
	lista[1].dato = 2;
	lista[1].sig = &lista[2];
	lista[2].dato = 4;
	lista[2].sig = NULL;
	
	resultado = buscarelementoenlista(lista,buscar);
	
	if(resultado >= 0)
		printf("El numero %d se encuentra en la posicion %d\n",buscar,resultado);
	else
		printf("No se encontro el numero %d",buscar);
	
	printf("Presione una tecla para salir...");
	getch();
	return 0;	
}
// --- (fin) Esto no era necesario

int buscarelementoenlista(NODO *p,int n)
{
	int cont;
	NODO *x;
	
	if (p == NULL)
	{
		return -1;
	} else {
		if (p->sig == NULL)
        {
			if(p->dato == n)
				return 0;
			else
				return -1;
		} else {
			cont = 0;
			x = p;
			while (x != NULL)
			{
				if(x->dato == n)
				{
					return cont;
				}
				cont++;
				x = x->sig;
			}
		}
		return -1;
	}	
}