#pragma once

typedef struct alumno{
	int matricula;
	char* apellido;
}Alumno;

typedef struct nodo{
	Alumno *alumno;
	struct nodo* siguiente;
}Nodo;

void agregarNodo1(Nodo** cabeza,int eleccion);
void recorrerNodos(Nodo* cabeza);
void imprimirAlumno(Alumno* alumno);
Alumno* crearAlumno(int matricula, char* apellido);
Nodo* crearNodo(Alumno *alumno);
char* obtenerCadena(char* texto);
int obtenerValor(char* texto);
void liberarMemoria(void *ptr);
int evaluarParametro(Alumno* alumno1,Alumno* alumno2,int eleccion);
