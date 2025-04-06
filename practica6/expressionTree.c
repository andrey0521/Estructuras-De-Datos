#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(void){
	int opc=0;
	char buffer[MAX];
	NodoArbol* operandos[MAX];

	Pila pila;
	PilaAux pilaAux;
	buffer[0]='\0';
	inicializarPila(&pila);
	inicializarPilaAux(&pilaAux);
	do{
		printf("     Menu    \n");
		printf("Expresion: ");
		desplegarExpresion(buffer);
		desplegar(&pila);
		printf("\n[1] Capturar Expresion\n");
		printf("[2] Imprimir Arbol\n");
		printf("[3] Evaluar Expresion\n");
		printf("[4] Terminar Programa\n");
		printf("$ ");
		scanf("%d",&opc);
		while(getchar()!='\n' );
		switch(opc){
			case 1:	
				printf("Captura Expresion: ");
				fgets(buffer,sizeof(buffer),stdin);
				buffer[strcspn(buffer, "\n")] = '\0';
				if(postFix(&pila,buffer)==1){
					if(pilaAux.cima!=NULL){
						eliminarArbol(pilaAux.cima->valor);
						pilaAux.cima->valor=NULL;
					}
					crearArbol(&pilaAux,&pila);
					liberarArreglo(operandos);
					int indice=0;
					mapearOperandos(pilaAux.cima->valor,operandos,&indice);
				}
				break;
			case 2:
				if(pilaAux.cima!=NULL)
					imprimirArbol(pilaAux.cima->valor,0);
				break;				
			case 3:
				if(pilaAux.cima!=NULL){
					ingresarValores(operandos);
					printf("El valor resultante de la expresion es igual a: %.2f\n",evaluarExpresion(pilaAux.cima->valor));
					eliminarValores(operandos);
				}
				break;
			case 4:
				break;
			default:
				break;				
		}
	}while(opc!=4);	
	
	return 0;
}
