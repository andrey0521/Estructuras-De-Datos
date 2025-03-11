#pragma once

#define REN 27  
#define COL 26

#define ARRIBA 0b0001
#define IZQUIERDA 0b0010
#define ABAJO 0b0100
#define DERECHA 0b1000

typedef struct nodo
{
    int x;
    int y;
    struct nodo* siguiente;
}Nodo;

typedef struct
{
    Nodo *cima;
    int cantNodos;
}Pila;

Nodo* crearNodo(int,int);
void inicializarPila(Pila*);
void push(Pila*,Nodo*);
void push(Pila*,Nodo*);
Nodo* pop(Pila*);
int pilaVacia(Pila);
void desplegar(Pila*);
void vaciar(Pila*);
unsigned char ** crearLaberinto(void);
Nodo* puntoInicial(unsigned char**,char);
unsigned char alternativas(unsigned char**,int,int);
void buscarSalida(Pila*, unsigned char**);
Nodo* cima(Pila* pila);
void imprimirLaberinto(unsigned char**);
