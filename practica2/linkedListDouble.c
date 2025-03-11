#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipos.h"

int main(void){
	
	Nodo* lista1=NULL;
	Nodo* lista2=NULL;
	Nodo* lista3=NULL;
	Nodo* lista4=NULL;
	int min_n=100;
	int max_n=500;
	char min_l='a';
	char max_l='h';
	int eleccion=0;
	Alumno* alumno=NULL;
	while(eleccion!=10){
		printf("###########Menu###########\n");
		printf("Agregar alumno....................1\n");
		printf("Eliminar alumno...................2\n");
		printf("Mostrar lista 1...................3\n");
		printf("Capturar filtro matricula.........4\n");
		printf("Capturar filtro apellido...........5\n");
		printf("Mostrar lista 2...................6\n");
		printf("Mostrar lista 3...................7\n");
		printf("Mostrar lista 4(ascendente).......8\n");
		printf("Mostrar lista 4(descendente)......9\n");
		printf("Terminar programa................10\n");
		printf("Ingresa una opccion: ");
		scanf("%d",&eleccion);
		while(getchar()!='\n' );
		printf("\n");
		switch(eleccion){
			case 1:
				alumno=crearAlumno(obtenerValor("Ingresar la matricula:"), obtenerCadena("Ingresar la apellido:"));
				agregarNodo(&lista1,alumno);
				agregarNodoNumero(&lista2,lista1,min_n,max_n);
				agregarNodoLetra(&lista3,lista1,min_l,max_l);
				agregarNodoNL(&lista4,lista2,lista3);
				break;
			case 2:
				eliminar(&lista1,&lista2,&lista3,&lista4,obtenerValor("Ingresar la matricula a eliminar:"));
				break;
			case 3:
				recorrerAscendente(lista1);
				break;	
			case 4:
				min_n=obtenerValor("Ingresa el nuevo limite inferior para las matriculas: ");
				max_n=obtenerValor("Ingresa el nuevo limite superior para las matriculas: ");
				eliminarLista(&lista2);
				eliminarLista(&lista4);	
				agregarNodoNumero(&lista2,lista1,min_n,max_n);
				agregarNodoNL(&lista4,lista2,lista3);
				break;
			case 5:
				printf("Ingresar el nuevo limite inferior para los apellidos:");
				min_l=getchar();
				while (getchar() != '\n'); 
				printf("Ingresar el nuevo limite superior para los apellidos:");
				max_l=getchar();
				recorrerAscendente(lista3);
				recorrerAscendente(lista4);				
				eliminarLista(&lista3);
				eliminarLista(&lista4);
				agregarNodoLetra(&lista3,lista1,min_l,max_l);
				agregarNodoNL(&lista4,lista2,lista3);
				break;
			case 6:
				recorrerAscendente(lista2);
				break;				
			case 7:
				recorrerAscendente(lista3);
				break;				
			case 8:
				recorrerAscendente(lista4);
				break;
			case 9:
				recorrerDescendente(lista4);
				break;
			case 10:
				printf("Fin del programa");
				break;
			default:
				printf("Ingresa una opccion valida\n");
				break;
		}
		printf("\n");
		alumno=NULL;
		system("pause");
		system("cls");
	}
	eliminarLista(&lista1);
	eliminarLista(&lista2);
	eliminarLista(&lista3);
	eliminarLista(&lista4);
	return 0;
}