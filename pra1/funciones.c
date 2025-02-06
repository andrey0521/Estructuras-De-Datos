#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "prototipos.h"

int obtenerValor(char* texto){
	int valor=-1;
	printf("%s",texto);
	scanf("%d",&valor);
	while(getchar()!='\n' );
	return valor;
}

char* obtenerCadena(char* texto) {
    char buffer[100];
    printf("%s",texto);
    fgets(buffer, sizeof(buffer), stdin);

    buffer[strcspn(buffer, "\n")] = '\0';

    int n = strlen(buffer) + 1;
    
    char *apellido =NULL; 
	apellido=(char*)calloc(n, sizeof(char));
    if (apellido != NULL) {
        strcpy(apellido, buffer);
    }

    return apellido;
}

void liberarMemoria(void *ptr) {
    if (ptr != NULL) 
	{
        free(ptr);
        printf("Memoria liberada.\n");
    }
}

Alumno* crearAlumno(int matricula, char* apellido){
	Alumno * nuevoAlumno=NULL;
	nuevoAlumno=(Alumno*)calloc(1,sizeof(Alumno));
	if(nuevoAlumno==NULL)
	{
		return NULL;
	}
	nuevoAlumno->matricula=matricula;
	nuevoAlumno->apellido=apellido;
	return nuevoAlumno;
}

Nodo* crearNodo(Alumno *alumno){
	Nodo * nuevoNodo=NULL;
	nuevoNodo=(Nodo*)calloc(1,sizeof(Nodo));
	if(nuevoNodo==NULL)
	{
		return NULL;
	}
	nuevoNodo->alumno=alumno;
	nuevoNodo->siguiente=NULL;
	return nuevoNodo;
}

void agregarNodo1(Nodo** cabeza,int eleccion){
    if(*cabeza == NULL){
        *cabeza = crearNodo(crearAlumno(obtenerValor("Ingresar tu matricula:"), obtenerCadena("Ingresar tu apellido:")));
        return;
    }
    else {
        Nodo* nuevoNodo = crearNodo(crearAlumno(obtenerValor("Ingresar tu matricula:"), obtenerCadena("Ingresar tu apellido:")));
        Nodo* aux = *cabeza;
        Nodo* aux_1 = NULL;
        
        while(aux != NULL && evaluarParametro(aux->alumno,nuevoNodo->alumno,eleccion)){
            aux_1 = aux;
            aux = aux->siguiente;
        }
        
        if(aux_1 == NULL) {
            nuevoNodo->siguiente = *cabeza;
            *cabeza = nuevoNodo;
        }
        else {
			nuevoNodo->siguiente = aux;
            aux_1->siguiente = nuevoNodo;
        }
    }
}

void recorrerNodos(Nodo* cabeza){
	Nodo *c=cabeza;
	Nodo *aux=NULL;
	if(c!=NULL)
	{
		while(c!=NULL)
		{
			imprimirAlumno(c->alumno);
			aux=c;
			c=c->siguiente;
			liberarMemoria(aux->alumno->apellido);
			liberarMemoria(aux->alumno);
			liberarMemoria(aux);
			if(c==NULL){
				printf("NULL");
			}				
		}
	}
	else
	{
		printf("NULL");
	}		
}

void imprimirAlumno(Alumno* alumno){
	printf("[Apellido: %s. Matricula->%d]->",alumno->apellido,alumno->matricula);
}

int evaluarParametro(Alumno* alumno1,Alumno* alumno2,int eleccion){
	if(eleccion==1)
	{
		if(alumno1->matricula<alumno2->matricula){
			return 1;
		}
		return 0;
	}
	else
	{
		if(strcmp(alumno1->apellido,alumno2->apellido)<0)
		{
			return 1;
		}
		return 0;
	}
}