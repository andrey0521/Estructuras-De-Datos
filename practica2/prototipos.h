#pragma once

typedef struct alumno{
	int matricula;
	char* apellido;
}Alumno;

typedef struct nodo{
	struct nodo* anterior;
	Alumno *alumno;
	struct nodo* siguiente;
}Nodo;

Alumno* crearAlumno(int,char*);
Nodo* crearNodo(Alumno*);
char* obtenerCadena(char*);
int obtenerValor(char*);
void recorrerAscendente(Nodo*);
void imprimirAlumno(Alumno*);
void agregarNodo(Nodo**,Alumno*);
void recorrerDescendente(Nodo*);
void agregarNodoNumero(Nodo**,Nodo*,int,int);
void agregarNodoLetra(Nodo**,Nodo*,char,char);
void agregarNodoNL(Nodo**,Nodo*,Nodo*);
void eliminarAlumno(Alumno**);
void eliminarNodo(Nodo**);
void eliminarNodos(Nodo**, Alumno*);
Alumno* buscarAlumnoM(Nodo*,int);
void eliminar(Nodo**,Nodo**,Nodo**,Nodo**,int);
void eliminarLista(Nodo**);
