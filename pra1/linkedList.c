#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(void){
	
	Nodo* cabeza=NULL;
	agregarNodo1(&cabeza,1);
	agregarNodo1(&cabeza,1);
	agregarNodo1(&cabeza,1);
	agregarNodo1(&cabeza,1);
	recorrerNodos(cabeza);
	
	return 0;
}