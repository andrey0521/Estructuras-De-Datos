#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

Nodo* crearNodo(int dato){
	Nodo* nodo=(Nodo*)calloc(1,sizeof(Nodo));
	if(nodo==NULL){
		return NULL;
	}
	nodo->dato=dato;
	return nodo;
}

void agregarNodo(Nodo** raiz,Nodo* nodo){	
	if(*raiz==NULL){
		*raiz=nodo;
		printf("34");
		return;
	}
	
	if((*raiz)->dato>nodo->dato){
		agregarNodo(&(*raiz)->izq,nodo);
	}else{
		agregarNodo(&(*raiz)->der,nodo);
	}
}

void imprimirArbol(Nodo* raiz, int nivel){
    int i;
    if (raiz != NULL){
        printf(" %d", raiz->dato);
        if(raiz->der){
            printf("\n");
            for (i = 0; i < nivel+1; i++){
                if(i==nivel)
                    printf(" |____R ");
                else
                    printf(" |      ");
            }
            imprimirArbol(raiz->der, nivel + 1);
        }
        if(raiz->izq){
            printf("\n");
            for (i = 0; i < nivel+1; i++){
                printf(" |      ");
                //printf(" |      ");
            }
            printf("\n");
            for (i = 0; i < nivel+1; i++){
                if(i==nivel)
                    printf(" |____L ");
                else
                    printf(" |      ");
            }
            imprimirArbol(raiz->izq, nivel + 1);
        }
    }
}

void comprarArboles(Nodo* arbol1,Nodo* arbol2){
	int valor1=datosIguales(arbol1,0);
	int valor2=datosIguales(arbol2,0);
	if(valor1==valor2){
		printf("La estructura es igual");
	}
}

int datosIguales(Nodo* raiz1, int valor){
	if(raiz1==NULL){
		return valor;
	}
	datosIguales(raiz1->izq,(valor+2)/2);;
}

int profundidad(Nodo* raiz,int valor){
	if(raiz==NULL){
		printf("%d\n",valor);
		return valor;
	}
	int p1=0;
	
	if(p1>valor){
		p1=profundidad(raiz->izq,p1);
	}else{
		p1=profundidad(raiz->izq,valor++);
	}
	printf("p1=%d\n",p1);
	if(p1>valor){
		p1=profundidad(raiz->der,p1);
	}else{
		p1=profundidad(raiz->der,valor++);
	}
	p1=0;
}