#pragma once

typedef struct alumno{
	int matricula;
	char* apellido;
}Alumno;

typedef struct nodo{
	Alumno *alumno;
	struct nodo* siguiente;
}Nodo;

void agregarNodo(Nodo** cabeza,int);
void recorrerNodos(Nodo*);
void imprimirAlumno(Alumno*);
Alumno* crearAlumno(int,char*);
Nodo* crearNodo(Alumno*);
char* obtenerCadena(char*);
int obtenerValor(char*);
int evaluarParametro(Alumno*,Alumno*,int);
void eliminarNodo(Nodo**,int);
void eliminarNodos(Nodo**);

