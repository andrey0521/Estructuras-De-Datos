#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
}Nodo;

typedef struct cola{
	Nodo* inicio;
	Nodo* fin;
	int num_nodos;
}Cola;

void imprimir(Cola *cola);
Cola* crearCola();	
int vacia(Cola *cola);
Nodo* crearNodo();
void encolar(Cola *cola, int dato);
void encolar1(Cola *cola,Nodo *nodo);
Nodo* desencolar(Cola *cola);
void imprimir(Cola *cola);
void ordenarCola(Cola* cola);

int main(void){
	Cola *original=crearCola();
       	encolar(original,3);	
       	encolar(original,9);	
       	encolar(original,7);	
       	encolar(original,3);	
       	encolar(original,1);	
       	encolar(original,9);
	ordenarCola(original);
	imprimir(original);	
	return 0;
}

Cola* crearCola(){	
	Cola *cola = (Cola*)calloc(1,sizeof(Cola));
	cola->inicio=NULL;
	cola->fin=NULL;
	cola->num_nodos=0;
	return cola;
}

int vacia(Cola *cola){
	return (cola->inicio==NULL);
}

Nodo* crearNodo(){
	Nodo * nodo=(Nodo*)calloc(1,sizeof(Nodo));
	nodo->siguiente=NULL;
	return nodo;	
}

void encolar(Cola *cola, int dato){
        Nodo *nodoEncolar=crearNodo();
        nodoEncolar->dato=dato;
        if(vacia(cola)){
                cola->inicio=cola->fin=nodoEncolar;
        }else{
                cola->fin->siguiente=nodoEncolar;
                cola->fin=nodoEncolar;
        }
        cola->num_nodos++;
}

void encolar1(Cola *cola,Nodo *nodo){
	if(vacia(cola)){
		cola->inicio=cola->fin=nodo;
	}else{
		cola->fin->siguiente=nodo;
		cola->fin=nodo;
	}
	cola->num_nodos++;
}

Nodo* desencolar(Cola *cola){
	if(vacia(cola)){
		return NULL;
	}
	Nodo* nodoRet=cola->inicio;
	if(cola->inicio==cola->fin){
		cola->inicio=cola->fin=NULL;
	}else{
		cola->inicio=cola->inicio->siguiente;
	}
	cola->num_nodos--;
	nodoRet->siguiente=NULL;
	return nodoRet;
}

void imprimir(Cola *cola)
{
	Cola* aux=crearCola();
	Nodo *nodo;
	printf("\n Cola: ");
	while(!vacia(cola))
	{	nodo =desencolar(cola);
		printf("%d ",nodo->dato);
		encolar1(aux, nodo);
	}
	*cola = *aux;
}

void ordenarCola(Cola* cola){
	if(vacia(cola)) return;
	
	Cola* colaAux =crearCola();
	Cola* colaOrdenada =crearCola();
	int max=0;
	int flag=1;

	while(vacia(cola)!=1 || vacia(colaAux)!=1){
		while(vacia(cola)!=1){
			Nodo* aux=desencolar(cola);
			encolar1(colaAux,aux);
			if(flag){
			       	max=aux->dato;
				flag=0;
			}else if(max<aux->dato){
			       	max=aux->dato;
			}	
		}	
		while(vacia(colaAux)!=1){
			Nodo* aux=desencolar(colaAux);
			if(aux->dato==max){
				encolar1(colaOrdenada,aux);
			}else{
				encolar1(cola,aux);
			}
			
		}
		flag=1;
		max=0;
	}	

	*cola=*colaOrdenada;
}
