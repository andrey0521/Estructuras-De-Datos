#include <stdio.h>
#include <stdlib.h>

Alumno* nueAlumno(int matricula, char nombre[],char apellido[]){
	Alumno* nuevoAlumno = NULL;
	nueAlumno = (Alumno*)calloc(1,sizeof(void));
	if(nueAlumno!=NULL){
		nueAlumno->matricula=matricula;
		nuevoAlumno->nombre=nombre;
		nuevoAlumno->apellido=apellido;
	}
	return nueAlumno;
}

void imprimirAlumno(Alumno* alumno){
	printf(¨Matricula->%d¨,alumno->matricula);
	printf(¨Nombre->%s¨,alumno->nombre);
	printf(¨Apellido->%s¨,alumno->apellido);
}