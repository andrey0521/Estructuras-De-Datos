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
int estructuraIgual(Nodo*,Nodo*);
int profundidad(Nodo*);
void orden(Nodo*,Nodo*);