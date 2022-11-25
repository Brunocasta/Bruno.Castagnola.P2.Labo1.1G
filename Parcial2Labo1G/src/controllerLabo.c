/*
 * controllerLabo.c
 *
 *  Created on: 25 nov. 2022
 *      Author: Lenovo
 */

#include "controllerLabo.h"
int controller_movie(char* path , LinkedList* plista)
{
	int retorno=0;
	FILE* pFile;
	pFile=fopen(path,"r");

	if(pFile!=NULL)
	{
		parser_movie(pFile,plista);
		retorno= 1;
	}
	fclose(pFile);
   return retorno;
}

int controller_ordenarMovie(LinkedList* plista)
{
	int retorno=0,opcion;
	if(ll_len(plista)>0)
	{
		printf("\n1. ORDEN ASCENDENTE\n0. ORDEN DESCENDENTE \n");
		scanf("%d",&opcion);
		retorno=ll_sort(plista, OrdenadoXGenero, opcion);
		parser_listMovie(plista);
	}

	 return retorno;
}

int controller_guardarMoviesModoTexto(char* path , LinkedList* plista)
{
	FILE* pFile;
	pFile=fopen(path,"w");
	if(plista!=NULL)
	{
		parser_TextFromMovies(pFile,plista);
	}
	fclose(pFile);

	return 1;
}
