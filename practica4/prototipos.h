#pragma once

typedef struct nodo{
	int dato;
	struct nodo* izq;
	struct nodo* der;
}Nodo;

Nodo* crearNodo(int);
void imprimirArbol(Nodo*, int);
void agregarNodo(Nodo**,Nodo*);
void comprarArboles(Nodo*,Nodo*);
int datosIguales(Nodo*,int);
int profundidad(Nodo* raiz,int valor);