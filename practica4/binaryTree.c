#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(void){
	Nodo* arbol1=NULL;
	Nodo* arbol2=NULL;
	int dato=0;
	int opc=0;
	agregarNodo(&arbol1,crearNodo(1));
	agregarNodo(&arbol2,crearNodo(0));
	agregarNodo(&arbol1,crearNodo(0));
	agregarNodo(&arbol2,crearNodo(1));
	//agregarNodo(&arbol1,crearNodo(10));
	//agregarNodo(&arbol2,crearNodo(5));

	do{
		printf("       Menu\n");
		printf("[1] Insertar en Árbol 1\n");
		printf("[2] Insertar en Árbol 2\n");
		printf("[3] Comparar Árboles\n");
		printf("[6] Mostrar profundidad\n");
		printf("[8] Mostrar arboles\n");
		printf("[9] Salir\n");
		printf("$");
		scanf("%d",&opc);
		switch(opc){
			case 1:
					printf("Ingresa un numero entero:");
					scanf("%d",&dato);
					agregarNodo(&arbol1,crearNodo(dato));
				break;
			case 2:
					printf("Ingresa un numero entero:");
					scanf("%d",&dato);
					agregarNodo(&arbol2,crearNodo(dato));
				break;
			case 3:
				comprarArboles(arbol1,arbol2);
				break;
			case 6:
				int p1= profundidad(arbol1);
				if(p1!=0){
					printf("La profundida del arbol 1 es:%d",p1);
				}
				break;
			case 8:
				imprimirArbol(arbol1,0);
				printf("\n\n");
				imprimirArbol(arbol2,0);
				break;
			case 9:
				printf("Fin del programa...\n");
				break;
			default:
				printf("Ingresa una opcion valida...\n");
				break;
		}
	}while(opc!=9);
	
	return 0;
}
