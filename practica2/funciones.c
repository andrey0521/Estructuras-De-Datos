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

void agregarNodo(Nodo** cabeza, Alumno* alumno){
	Nodo* nuevoNodo=crearNodo(alumno);
	
	if(*cabeza==NULL){
		*cabeza=nuevoNodo;
		(*cabeza)->siguiente=nuevoNodo;
		(*cabeza)->anterior=nuevoNodo;
		return;
	}
	
	if((*cabeza)->siguiente==*cabeza){
		(nuevoNodo)->siguiente=*cabeza;
		(*cabeza)->anterior=nuevoNodo;
		(*cabeza)->siguiente=nuevoNodo;
		nuevoNodo->anterior=*cabeza;
	}else{
		(*cabeza)->anterior->siguiente=nuevoNodo;
		nuevoNodo->siguiente=*cabeza;
		nuevoNodo->anterior=(*cabeza)->anterior;
		(*cabeza)->anterior=nuevoNodo;
	}
}

void agregarNodo1(Nodo** cabeza, Alumno* alumno){
	Nodo* nuevoNodo=crearNodo(alumno);
	
	if(*cabeza==NULL){
		*cabeza=nuevoNodo;
		(*cabeza)->siguiente=nuevoNodo;
		(*cabeza)->anterior=nuevoNodo;
		return;
	}
	
	Nodo* aux=*cabeza;
	
	do{
		if(strcmp(alumno->apellido,aux->alumno->apellido)<0){
			if(aux==*cabeza){
				nuevoNodo->siguiente=*cabeza;
				nuevoNodo->anterior=(*cabeza)->anterior;
				(*cabeza)->anterior->siguiente=nuevoNodo;
				(*cabeza)->anterior=nuevoNodo;
				*cabeza=nuevoNodo;	
				return;
			}
			nuevoNodo->siguiente=aux;
			nuevoNodo->anterior=aux->anterior;
			aux->anterior->siguiente=nuevoNodo;
			aux->anterior=nuevoNodo;
			return;
		}
		aux=aux->siguiente;
	}while(aux!=*cabeza);
	
	nuevoNodo->anterior=(*cabeza)->anterior;
	nuevoNodo->siguiente=*cabeza;
	(*cabeza)->anterior->siguiente=nuevoNodo;
	(*cabeza)->anterior=nuevoNodo;

	
}

void agregarNodoNumero(Nodo** listaM,Nodo* listaO,int min, int max){
	if(listaO==NULL){
		return;
	}

	if(*listaM!=NULL){	
		if(listaO->anterior->alumno->matricula>=min && listaO->anterior->alumno->matricula<=max)
			agregarNodo(listaM,listaO->anterior->alumno);
		return;
	}
	
	Nodo* aux=listaO;
	do{
		if(aux->alumno->matricula>=min && aux->alumno->matricula<=max)
			agregarNodo(listaM,aux->alumno);
		aux=aux->siguiente;
	}while(aux!=listaO);
}

void agregarNodoLetra(Nodo** listaM,Nodo* listaO,char min, char max){
	if(listaO==NULL){
		return;
	}
	
	if(*listaM!=NULL){	
		if((strcmp(listaO->anterior->alumno->apellido,&min)>=0) && (strcmp(listaO->anterior->alumno->apellido,&max)<=0))
			agregarNodo(listaM,listaO->anterior->alumno);
		return;
	}
	
	Nodo* aux=listaO;
	do{
		if((strcmp(aux->alumno->apellido,&min)>=0) && (strcmp(aux->alumno->apellido,&max)<=0))
			agregarNodo(listaM,aux->alumno);
		aux=aux->siguiente;
	}while(aux!=listaO);
}

Alumno* buscarAlumnoR(Nodo* lista,Alumno* alumno){
	Nodo* aux=lista;
	
	do{
		if(aux->alumno==alumno)
			return alumno;
		aux=aux->siguiente;
	}while(aux!=lista);
	return NULL;
}

void agregarNodoNL(Nodo** listaM,Nodo* listaO1,Nodo* listaO2){
	
	if(listaO1==NULL || listaO2==NULL){
		return;
	}
	
	Nodo* aux=listaO2;
	
	if(*listaM!=NULL){
		if(buscarAlumnoR(listaO1,aux->anterior->alumno)!=NULL && buscarAlumnoR(*listaM,aux->anterior->alumno)==NULL)
			agregarNodo1(listaM,aux->anterior->alumno);
		return;
	}
	
	do{
		if(buscarAlumnoR(listaO1,aux->alumno)!=NULL)
			agregarNodo1(listaM,aux->alumno);
		aux=aux->siguiente;
	}while(aux!=listaO2);
}

void eliminarAlumno(Alumno** alumno){
	free((*alumno)->apellido);
	free(*alumno);
}

void eliminarNodo(Nodo** lista){
	free(*lista);
}

void eliminarNodos(Nodo** lista, Alumno* alumno){
	if(*lista==NULL){
		return;
	}
	Nodo* aux=*lista;
	Nodo* aux_1=aux->anterior;
	
	if(aux_1==aux){
		eliminarNodo(lista);
		*lista=NULL;
		return;
	}
	
	aux_1=NULL;
	do{
		if(aux->alumno==alumno){
			break;
		}
		aux_1=aux;
		aux=aux->siguiente;
	}while(aux!=*lista);

	if(aux_1==NULL){
		aux_1=aux->anterior;
		aux->siguiente->anterior=aux_1;
		aux_1->siguiente=aux->siguiente;
		eliminarNodo(&aux);
		*lista=aux_1->siguiente;
		return;
	}
	
	if(aux==(*lista)->anterior){
		aux_1->siguiente=(*lista);
		(*lista)->anterior=aux_1;
		eliminarNodo(&aux);
	}
	
	if(aux!=*lista && aux!=(*lista)->anterior){
		aux_1->siguiente=aux->siguiente;
		aux->siguiente->anterior=aux_1;
		eliminarNodo(&aux);
	}
}

Alumno* buscarAlumnoM(Nodo* lista,int matricula){
	Nodo* aux=lista;
	do{
		if(aux->alumno->matricula==matricula)
			return aux->alumno;
		aux=aux->siguiente;
	}while(aux!=lista);
	return NULL;
}

void eliminar(Nodo** lista1,Nodo** lista2,Nodo** lista3,Nodo** lista4,int matricula){
	if(*lista1==NULL){
		return;
	}
	
	Alumno* alumnoEliminar=buscarAlumnoM(*lista1,matricula);
	if(alumnoEliminar==NULL)
		return;
	
	eliminarNodos(lista4,alumnoEliminar);
	eliminarNodos(lista3,alumnoEliminar);
	eliminarNodos(lista2,alumnoEliminar);
	eliminarNodos(lista1,alumnoEliminar);
	eliminarAlumno(&alumnoEliminar);
}

void imprimirAlumno(Alumno* alumno){
	printf("[Apellido: %s. Matricula->%d]->",alumno->apellido,alumno->matricula);
}

void recorrerAscendente(Nodo* cabeza){
    if (cabeza!= NULL) {
		Nodo *c = cabeza;
        do {
            imprimirAlumno(c->alumno);
            c = c->siguiente;
        } while (c != cabeza);
    } else {
        printf("NULL\n");
    }
}

void recorrerDescendente(Nodo* cabeza){

    if (cabeza!= NULL) {
		 Nodo *c = cabeza->anterior;
        do {
            imprimirAlumno(c->alumno);
            c = c->anterior;
        } while (c !=cabeza->anterior );
    } else {
        printf("NULL\n");
    }
}

void eliminarLista(Nodo** lista){
	if(*lista==NULL){
		return;
	}
	Nodo* aux=NULL;
	do{
		aux=*lista;
		*lista=(*lista)->siguiente;
		(*lista)->anterior=aux->anterior;
		aux->anterior->siguiente=(*lista);
		eliminarNodo(&aux);
	}while(aux->siguiente!=*lista);
	eliminarNodo(lista);
	*lista=NULL;
}
