#pragma once
#define MAX 256
typedef struct nodo
{
    char valor;
    struct nodo* siguiente;
}Nodo;

typedef struct nodoarbol
{
    char valor;
    float *valor1;
    struct nodoarbol* izq;
    struct nodoarbol* der;
}NodoArbol;

typedef struct nodoaux
{
    NodoArbol* valor;
    struct nodoaux* siguiente;
}NodoAux;


typedef struct pila
{
    Nodo *cima;
}Pila;

typedef struct pilaaux
{	
    NodoAux *cima;    
}PilaAux;


Nodo* crearNodo(char dato);
void inicializarPila(Pila* pila);
void push(Pila* pila,Nodo* nueNodo);
Nodo* pop(Pila* pila);
int postFix(Pila* pila, char* infix);
int jerarquia(char valor);
void desplegar(Pila *pila);
void vaciar(Pila* pila);
int verificarParentesis(char*);
void desplegarExpresion(char*);
int verificarOperandos(char *);
NodoArbol* crearNodoArbol(char);
NodoAux* crearNodoAux(NodoArbol*);
void inicializarPilaAux(PilaAux* pila);
void pushAux(PilaAux*,NodoAux* );
NodoAux* popAux(PilaAux* pila);
void crearArbol(PilaAux*,Pila*);
void imprimirArbol(NodoArbol* ,int);
void mapearOperandos(NodoArbol*, NodoArbol**, int*);
void eliminarArbol(NodoArbol*);
void liberarArreglo(NodoArbol**);
void ingresarValores(NodoArbol**);
float evaluarExpresion(NodoArbol*);
void eliminarValores(NodoArbol**);

