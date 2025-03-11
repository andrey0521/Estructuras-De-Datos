#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main(void){
	int i=0;
	int j=0;
    unsigned char **laberinto;
    laberinto = crearLaberinto();
	imprimirLaberinto(laberinto);

    printf("\n\n");
	Pila stack;
	inicializarPila(&stack);
	push(&stack,puntoInicial(laberinto,'A'));//Se le hace push a la pila en el punto de inicio, una funcion recorre la matriz para determinar el punto de inicio indicado
	buscarSalida(&stack,laberinto);
	desplegar(&stack);
	imprimirLaberinto(laberinto);
	vaciar(&stack);
}
