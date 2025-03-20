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
	if(estructuraIgual(arbol1,arbol2)==1){
		printf("La estructura es igual");
	}
	orden(arbol1,arbol2);
}

void orden(Nodo* raiz1, Nodo* raiz2){
	if (raiz1==NULL && raiz2==NULL)
		return;
		
	if (raiz1!=NULL){
		orden(raiz1->izq,NULL);
		printf("1 %d\n",raiz1->dato);
		if(raiz2!=NULL){
			orden(NULL,raiz2->izq);
			printf("2 %d\n",raiz2->dato);
			orden(NULL,raiz2->der);
		}
		orden(raiz1->der,NULL);
	}else if(raiz2!=NULL){
		printf("2 %d\n",raiz2->dato);
		orden(NULL,raiz2->der);
	}
}

int estructuraIgual(Nodo* raiz1,Nodo* raiz2){
	if (raiz1==NULL && raiz2==NULL)
		return 1;
	if(raiz1==NULL || raiz2==NULL)
		return 0;
		
	int subAIzq=estructuraIgual(raiz1->izq,raiz2->izq);
	int subADer=estructuraIgual(raiz1->der,raiz2->der);
	return subAIzq && subADer;
}

int profundidad(Nodo* raiz) {
    if (raiz == NULL)
        return 0;

    int subAIzq = profundidad(raiz->izq);
    int subADer = profundidad(raiz->der);

    if (subAIzq > subADer) 
        return subAIzq + 1;
    else 
        return subADer + 1;
    
}
