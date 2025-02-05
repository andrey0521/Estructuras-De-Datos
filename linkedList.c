#include <stdio.h>
#include <stdlib.h>

int main(void){
	Alumno* alumno1=nueAlumno(21,¨Juan¨,¨Lopez¨);
	free(alumno1);
	return 0;
}