#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

unsigned char ** crearLaberinto(void)
{
    int i,j;
    char *tmp =
"xxxxxxxxxxxxxxxxxxxxxxxxxx\
xAx*****x****************x\
x*xxx*x*x*xxxxxxxxx*xxxx*x\
x*****x*x******x**x****x*x\
xxxxxxx*xxxxxx*xx*xxxx*xxx\
x*****x*x****x*x****xx***x\
x*xxx*x*xxxx*x*x*xxxxx*x*x\
x***x*x****x*****xxxxxxx*x\
xxx*x*xxxx*xxxxxxx****x**x\
x*x*x***xx****xx***xx*x*xx\
x*x*x*x*xxxxx**x*xxxx*x**x\
x*x*x*x***x*xx*x****x*xx*x\
x*x*x*xxx****x*x*xx*x****x\
x*x*x*xxxxxxxx*x**x*xxxx*x\
x***x********x*xx*x*x****x\
x*xxxxxxxxxx*x**xxx*x*xxxx\
x***x******x**x*****x**x*x\
xxx*x*xxxxxxx*xxxxxxxx*x*x\
x*x*x*******x****xx****x*x\
x*x*x*xxxxx*xxxx*xx*xxxx*x\
x*x*x****xx***x**xx*x****x\
x*x*xxxxxxx*x**x*xx*x*x*xx\
x*x*********xx*x*xx*xxx*xx\
x*xxxxxxxxxxx**x*********x\
x***x***x***x*xxxxxxxxxx*x\
x*x***x***x**************x\
xxxxxxxxxxxxxxxxxxxxxxxxxx\0";



    unsigned char **lab;
    lab = (unsigned char**) malloc(sizeof(unsigned char *)*REN);

    for(i=0;i<REN;i++)
    {
        lab[i] = (unsigned char*) malloc(sizeof(unsigned char)*COL);
    }

    for(i=0;i<REN;i++)
    {
        //printf("\n\r");
        for(j=0;j<COL;j++)
        {
            //printf("%c",tmp[(i*COL)+j]);
            lab[i][j] = tmp[(i*COL)+j];
        }
    }
    return lab;
}

void imprimirLaberinto( unsigned char **laberinto){
	for(int i=0;i<REN;i++){
        printf("\n\r");
        for(int j=0;j<COL;j++){
            printf("%c",laberinto[i][j]);
        }
    }
}

Nodo* crearNodo(int x,int y){
	Nodo* nueNodo=(Nodo*)calloc(1,sizeof(Nodo));
	if(nueNodo==NULL) return NULL;
	nueNodo->x=x;
	nueNodo->y=y;
	nueNodo->siguiente=NULL;
	return nueNodo;
}

void inicializarPila(Pila* pila){
	pila->cima=NULL;
	pila->cantNodos=0;
}

int pilaVacia(Pila pila){
	if(!pila.cima)
		return 1;
	return 0;
}

Nodo* cima(Pila* pila){
	if(pila->cima==NULL){
		return NULL;
	}
	
	return pila->cima;
}

void push(Pila* pila,Nodo* nueNodo){
	if(nueNodo==NULL) return;
	
	nueNodo->siguiente=pila->cima;
	pila->cima=nueNodo;
	pila->cantNodos++;
}

Nodo* pop(Pila* pila){
	if(pilaVacia(*pila))
		return NULL;
	Nodo* nPop=pila->cima;
	pila->cima=nPop->siguiente;
	pila->cantNodos--;
	return nPop;
}

void desplegar(Pila *pila){
	if(pilaVacia(*pila))
		return;
	
	Pila pilaAux;
	inicializarPila(&pilaAux);
	while(cima(pila)!=NULL){
		push(&pilaAux,pop(pila));
	}
	
	
	printf("\n-------Solucion-------\n");
	while(cima(&pilaAux)!=NULL){
	printf("Posicion [%d][%d]\n",cima(&pilaAux)->x,cima(&pilaAux)->y);
		printf("----------------------\n");
		push(pila,pop(&pilaAux));
	}
}

void vaciar(Pila* pila){
	while(cima(pila)!=NULL){
		free(pop(pila));
	}
}

Nodo* puntoInicial(unsigned char** laberinto,char inicio){
	for(int i=0; i<REN; i++){
		for(int j=0; j<COL; j++){
			if(laberinto[i][j]==inicio){
				return crearNodo(i,j);
			}
		}
	}
	return NULL;
	
}

unsigned char alternativas(unsigned char **lab,int x,int y)
{
		unsigned char banderas;
		banderas = 0;	
		//EVALUAR ALTERNATIVA Y REGISTRAR POSIBILIDAD DE MOVIMIENTO
		//EN UN REGISTRO DE BITS/BANDERAS
		if(lab[x-1][y]!='x'  && lab[x-1][y]!='/' && lab[x-1][y]!='A' && lab[x-1][y]!='$'){
			banderas |= ARRIBA;
		}
		if(lab[x][y-1]!='x' && lab[x][y-1]!='/' && lab[x][y-1]!='A' && lab[x][y-1]!='$'){
			banderas |= IZQUIERDA;
		}
		if(lab[x+1][y]!='x' && lab[x+1][y]!='/' && lab[x+1][y]!='A' && lab[x+1][y]!='$'){
			banderas |= ABAJO;
		}
		if(lab[x][y+1]!='x' && lab[x][y+1]!='/' && lab[x][y+1]!='A' && lab[x][y+1]!='$'){
			banderas |= DERECHA;
		}
		
		return banderas;	
}

void buscarSalida(Pila* pila, unsigned char** laberinto){
	Nodo* peek=cima(pila);
	
	while(laberinto[peek->x][peek->y]!='B'){
		unsigned char direccion=alternativas(laberinto,peek->x,peek->y);
		if(laberinto[peek->x][peek->y]=='A' && direccion==0)
			 break;
		
		if((direccion & ARRIBA)){

			if(laberinto[peek->x-1][peek->y]!='B')
				laberinto[peek->x-1][peek->y]='/';
			push(pila,crearNodo(peek->x-1,peek->y));
		}
		else if( (direccion & IZQUIERDA)){
			if(laberinto[peek->x][peek->y-1]!='B')
				laberinto[peek->x][peek->y-1]='/';
			push(pila,crearNodo(peek->x,peek->y-1));
		}
		else if( (direccion & ABAJO)){
			if(laberinto[peek->x+1][peek->y]!='B')
					laberinto[peek->x+1][peek->y]='/';
			push(pila,crearNodo(peek->x+1,peek->y));
		}
		else if( (direccion & DERECHA)){
			if(laberinto[peek->x][peek->y+1]!='B')
				laberinto[peek->x][peek->y+1]='/';
			push(pila,crearNodo(peek->x,peek->y+1));
		}
		
		if(direccion==0){
			laberinto[cima(pila)->x][cima(pila)->y]='$';
			pop(pila);
		}
		peek=cima(pila);
	}
}