/*
 ============================================================================
 Name        : Parcial2Labo1G.c
 Author      : Bruno Castagnola 1G
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "funcionesParcial.h"
#include "parserLabo.h"
#include "controllerLabo.h"

int main() {
	setbuf(stdout,NULL);
	int option;
	LinkedList* peliculas = ll_newLinkedList();
	do{
	    	printf("\n1. CARGAR ARCHIVO \n2. IMPRIMIR LISTA \n3. ASIGNAR RATING \n4. ASIGNAR GENERO \n5. FILTRAR POR GENERO \n6. ORDENAR PELICULAS "
	    			"\n7. GUARDAR PELICULAR \n8. SALIR ");
	    	fflush(stdin);
	    	scanf("%d",&option);
	        switch(option)
	        {
	            case 1:
	            	if(controller_movie("movies.csv",peliculas)==1)
					{
						printf("\nSE CARGO CORRECTAMENTE LOS ARCHIVOS...\n");
					}
	            break;
	            case 2:
	            	if(parser_listMovie( peliculas)==1)
					{
						printf("\nSE IMPRIMIO CON EXITO");
					}
	            	break;
	            case 3 :
	            	break;
	            case 4 :
	           	    break;
	            case 5 :
	           	    break;
	            case 6 :
	            	if(controller_ordenarMovie(peliculas)==1)
					{
						printf("\n	ESTA ORDENADO LAS PELICULAS");
					}
					break;
				case 7 :
					if(ll_len(peliculas)>0)
					{
						controller_guardarMoviesModoTexto("MoviesText.txt",peliculas);
						printf("\n SE GUARDARON LAS PELICULAS EXITOSAMENTE");
					}

					break;
				case 8 :
					printf("\nGRACIAS POR UTILIZAR EL PROGRAMA");
					break;
	        }
	 }while(option!=8);
	return 0;
}
