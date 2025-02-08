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
    
    char *cadena =NULL; 
	cadena=(char*)calloc(n, sizeof(char));
    if (cadena != NULL) {
        strcpy(cadena, buffer);
    }

    return cadena;
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
		if(strcmp(alumno1->apellido,alumno2->apellido)<0){
			return 1;
		}
		return 0;
	}
}


int evaluarParametro1(Alumno* alumno1,Alumno* alumno2,int eleccion){
	if(eleccion==1)
	{
		if(alumno1->matricula==alumno2->matricula){
			return 1;
		}
		return 0;
	}
	else
	{
		if(strcmp(alumno1->apellido,alumno2->apellido)==0){
			return 1;
		}
		return 0;
	}
}

void agregarNodo(Nodo** cabeza,int eleccion){
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


void imprimirAlumno(Alumno* alumno){
	printf("[Apellido: %s. Matricula->%d]->",alumno->apellido,alumno->matricula);
}

void recorrerNodos(Nodo* cabeza){
	Nodo *c=cabeza;
	if(c!=NULL)
	{
		while(c!=NULL)
		{
			imprimirAlumno(c->alumno);
			c=c->siguiente;			
		}
	}	
	printf("NULL\n");
}

void eliminarNodo(Nodo** cabeza,int eleccion){
	Nodo* aux=*cabeza;
	Nodo* aux_1=NULL;
	Alumno* p=NULL;
	if(eleccion==1)
		p=crearAlumno(obtenerValor("'\nIngresa la matricula a eliminar:"),"a");
	else
		p=crearAlumno(1,obtenerCadena("\nIngresa el apellido a borrar"));
	
	while(aux!=NULL && !(evaluarParametro1(aux->alumno,p,eleccion))){
		aux_1=aux;
		aux=aux->siguiente;
	}
	
	if(aux==NULL)
		printf("No existe ningun nodo en la lista");
	else{
		if(aux_1==NULL){
			*cabeza=aux->siguiente;
		}else{
			aux_1->siguiente=aux->siguiente;
		}
		free(aux->alumno->apellido);
		free(aux->alumno);
		free(aux);
	}
	free(p->apellido);
	free(p);
}

void eliminarNodos(Nodo** cabeza){
	Nodo *c=*cabeza;
	if(c!=NULL)
	{
		Nodo*aux=NULL;
		while(c!=NULL)
		{
			aux=c;
			c=c->siguiente;
			free(aux->alumno->apellido);
			free(aux->alumno);
			free(aux);			
		}
	}
	*cabeza=NULL;
}