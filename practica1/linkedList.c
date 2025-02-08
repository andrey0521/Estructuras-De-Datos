#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(void){
	
	Nodo* lista1=NULL;
	Nodo* lista2=NULL;
	int eleccion=0;
	while(eleccion!=8){
		printf("###########Menu###########\n");
		printf("Agregar alumno(L1).......1\n");
		printf("Agregar alumno(L2).......2\n");
		printf("Eliminar alumno(L1)......3\n");
		printf("Eliminar alumno(L2)......4\n");
		printf("Mostrar L1...............5\n");
		printf("Mostrar L2...............6\n");
		printf("Eliminar listas..........7\n");
		printf("Salir....................8\n");
		printf("Ingresa una opccion: ");
		scanf("%d",&eleccion);
		while(getchar()!='\n' );
		switch(eleccion){
			case 1:
				agregarNodo(&lista1,1);
				break;
			case 2:
				agregarNodo(&lista2,2);
				break;
			case 3:
				eliminarNodo(&lista1,1);
				break;	
			case 4:
				eliminarNodo(&lista2,2);
				break;
			case 5:
				recorrerNodos(lista1);
				break;
			case 6:
				recorrerNodos(lista2);
				break;				
			case 7:
				eliminarNodos(&lista1);
				eliminarNodos(&lista2);
				break;				
			case 8:
				printf("Fin del programa...\n");
				break;				
			default:
				printf("Ingresa una opccion valida\n");
				break;
		}
		printf("\n");
	}
	return 0;
}