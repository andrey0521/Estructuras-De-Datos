#pragma once

typedef struct alumno{
	int matricula;
	char nombre[20];
	char apellido[20];
	struct alumno * siguiente;
}Alumno;

Alumno* nueAlumno(int matricula, char nombre[],char apellido[]);
void imprimirAlumno(Alumno* alumno);