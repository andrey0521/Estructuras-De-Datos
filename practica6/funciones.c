#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

Nodo* crearNodo(char valor){
	Nodo* nueNodo=(Nodo*)calloc(1,sizeof(Nodo));
	if(nueNodo==NULL) return NULL;
	nueNodo->valor=valor;
	nueNodo->siguiente=NULL;
	return nueNodo;
}

NodoArbol* crearNodoArbol(char valor){
	NodoArbol* nueNodo=(NodoArbol*)calloc(1,sizeof(NodoArbol));
	if(nueNodo==NULL) return NULL;
	nueNodo->valor=valor;
	nueNodo->izq=NULL;
	nueNodo->der=NULL;
	return nueNodo;
}

NodoAux* crearNodoAux(NodoArbol* valor){
	NodoAux* nueNodo=(NodoAux*)calloc(1,sizeof(NodoAux));
	if(nueNodo==NULL) return NULL;
	nueNodo->valor=valor;
	return nueNodo;
}

void inicializarPila(Pila* pila){
	pila->cima=NULL;
}

void inicializarPilaAux(PilaAux* pila){
	pila->cima=NULL;
}

void push(Pila* pila,Nodo* nueNodo){
	if(nueNodo==NULL) return;
	nueNodo->siguiente=pila->cima;
	pila->cima=nueNodo;
}

Nodo* pop(Pila* pila){
	if(pila->cima==NULL)
		return NULL;
	Nodo* nPop=pila->cima;
	pila->cima=nPop->siguiente;
	return nPop;
}

void pushAux(PilaAux* pila,NodoAux* nueNodo){
	if(nueNodo==NULL) return;
	nueNodo->siguiente=pila->cima;
	pila->cima=nueNodo;
}

NodoAux* popAux(PilaAux* pila){
	if(pila->cima==NULL)
		return NULL;
	NodoAux* nPop=pila->cima;
	pila->cima=nPop->siguiente;
	return nPop;
}

int postFix(Pila* pila, char* infix) {
    if (verificarParentesis(infix)== 0){
        printf("Error de parentesis\n");
        return 0;
   	}
   	
   	if(verificarOperandos(infix)==0){
    	printf("Error de operador binario\n");
        return 0;
    }
    
    vaciar(pila);

    Pila pilaOperador;
    inicializarPila(&pilaOperador);

    for (int i = 0; i < MAX && infix[i] != '\0'; i++) {
        if (infix[i] == ')') {
            while (pilaOperador.cima != NULL && pilaOperador.cima->valor != '(') {
                push(pila, pop(&pilaOperador)); 
            }
            pop(&pilaOperador);
        }else if (infix[i] == '('){
        	    push(&pilaOperador, crearNodo(infix[i]));
        }else if(jerarquia(infix[i]) != 0) {
            while (pilaOperador.cima != NULL && jerarquia(pilaOperador.cima->valor) >= jerarquia(infix[i])) {
            	push(pila, pop(&pilaOperador));
               
            }
            push(&pilaOperador, crearNodo(infix[i]));
        }else{
            push(pila, crearNodo(infix[i]));
        }
    }
    
    while (pilaOperador.cima != NULL) {
        push(pila, pop(&pilaOperador));    
    } 
    return 1;
}

void crearArbol(PilaAux* pilaAux,Pila* pila){
	Pila aux;
	inicializarPila(&aux);
	while(pila->cima != NULL){
		push(&aux,pop(pila));
	}
	
	while(aux.cima!=NULL){
		if(jerarquia(aux.cima->valor)==0){
			pushAux(pilaAux,crearNodoAux(crearNodoArbol(pop(&aux)->valor)));
		}else{
			NodoArbol* arbolAux=crearNodoArbol(pop(&aux)->valor);
			NodoAux * nodoAux=popAux(pilaAux);
			arbolAux->der=nodoAux->valor;
			nodoAux=popAux(pilaAux);
			arbolAux->izq=nodoAux->valor;
			pushAux(pilaAux,crearNodoAux(arbolAux));
		}
	}
}

int verificarParentesis(char* infix){
	Pila pilaParentesis;
    inicializarPila(&pilaParentesis);
    
   	for (int i = 0; i < MAX && infix[i] != '\0'; i++){
   		if(infix[i]=='('){
   			push(&pilaParentesis,crearNodo(infix[i]));
   		}else if(infix[i]==')'){
   			if(pilaParentesis.cima==NULL)
   				return 0;
   			pop(&pilaParentesis);
   		}
   	}
   	
   	if(pilaParentesis.cima==NULL){
   		return 1;
   	}
   	vaciar(&pilaParentesis);
   	return 0;
}

int verificarOperandos(char *infix){
	int operandos=0;
	int operadores=0;
	for (int i = 0; i < MAX && infix[i] != '\0'; i++){
   		if(infix[i]!='(' && infix[i]!=')'){
   			if(jerarquia(infix[i]) != 0){
   				operandos++;
   			}else{
   				operadores++;
   			}
   		}
   	}
   	
	if(operandos+1==operadores)
		return 1;
	return 0;
}

int jerarquia(char valor) {
    if (valor=='^')
        return 3;
    if (valor=='*' || valor=='/')
        return 2;
    if (valor=='-' || valor=='+')
        return 1;
    else
        return 0;
}

void desplegarExpresion(char* expresion){
	for(int i=0; i<MAX && expresion[i]!='\0'; i++){
		printf("%c",expresion[i]);
	}
	printf("\n");
}
void desplegar(Pila *pila){
	if(pila->cima == NULL)
		return;
	
	Pila pilaAux;
	inicializarPila(&pilaAux);
	while(pila->cima != NULL){
		push(&pilaAux,pop(pila));
	}
	
	while(pilaAux.cima!=NULL){
		printf("[%c]",pilaAux.cima->valor);
		push(pila,pop(&pilaAux));
	}
}

void vaciar(Pila* pila){
	while(pila->cima!=NULL){
		free(pop(pila));
	}
}

void imprimirArbol(NodoArbol* raiz, int nivel){
    int i;
    if (raiz != NULL){
        printf(" %c", raiz->valor);
        if(raiz->der){
            printf("\n");
            for (i = 0; i < nivel+1; i++){
                if(i==nivel)
                    printf(" |____R ");
                else
                    printf(" |      ");
            }
            imprimirArbol(raiz->der, nivel + 1);
        }
        if(raiz->izq){
            printf("\n");
            for (i = 0; i < nivel+1; i++){
                printf(" |      ");
                //printf(" |      ");
            }
            printf("\n");
            for (i = 0; i < nivel+1; i++){
                if(i==nivel)
                    printf(" |____L ");
                else
                    printf(" |      ");
            }
            imprimirArbol(raiz->izq, nivel + 1);
        }
    }
}

void mapearOperandos(NodoArbol* raiz, NodoArbol** operandos, int* indice) {
    if (raiz == NULL) return;

    mapearOperandos(raiz->izq, operandos, indice);
    
    if (jerarquia(raiz->valor) == 0) {
        printf("%c", raiz->valor); 
        operandos[(*indice)++] = raiz;  
    }

    mapearOperandos(raiz->der, operandos, indice);
}

void eliminarArbol(NodoArbol* raiz){
    if (raiz == NULL) {
        return;
    }
    
    eliminarArbol(raiz->izq);
    eliminarArbol(raiz->der);

    free(raiz);
}

void liberarArreglo(NodoArbol** operandos){
	for(int i=0; i<MAX && operandos[i]!=NULL ; i++){
		operandos[i]=NULL;
	}
}

void ingresarValores(NodoArbol** operandos){
	for(int i=0; i<MAX && operandos[i]!=NULL ; i++){
		if(operandos[i]->valor1==NULL){
			printf("Ingresa el valor de operando %c:",operandos[i]->valor);
			operandos[i]->valor1 = (float*)calloc(1,sizeof(float));
			scanf("%f", operandos[i]->valor1);
			for(int j=i+1; j<MAX && operandos[j]!=NULL ; j++){
				if(operandos[i]->valor==operandos[j]->valor){
					operandos[j]->valor1=operandos[i]->valor1;
				}
			}	
		}
	}
	
}

void eliminarValores(NodoArbol** operandos){
	for(int i=0; i<MAX && operandos[i]!=NULL ; i++){
		free(operandos[i]->valor1);
		operandos[i]->valor1=NULL;
	}
}

float evaluarExpresion(NodoArbol* raiz) {
    if (raiz == NULL) {
        return 0.0; 
    }

    if (raiz->izq == NULL && raiz->der == NULL) {
        return *(raiz->valor1);
    }

    float izqValor = evaluarExpresion(raiz->izq);
    float derValor = evaluarExpresion(raiz->der);

    switch (raiz->valor) {
        case '+': return izqValor + derValor; 
        case '-': return izqValor - derValor;  
        case '*': return izqValor * derValor;  
        case '/': return izqValor / derValor;
        case '^': return izqValor + derValor; 
    }
}

void ver(NodoArbol* raiz) {
    if (raiz == NULL) {
        return; 
    }

	evaluarExpresion(raiz->izq);
	evaluarExpresion(raiz->der);
	printf("valor1 %f",raiz->valor1);
}


