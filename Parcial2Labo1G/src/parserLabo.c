/*
 * parserLabo.c
 *
 *  Created on: 25 nov. 2022
 *      Author: Lenovo
 */

#include "parserLabo.h"

int parser_listMovie(LinkedList* plista)
{
	eMovie* peliculas;
	int i,movieCont,retorno=0;

	int idPeli;
	char titulo[40];
	float  rating;
	char  genero[50];


	if(plista!=NULL)
	{
		movieCont=ll_len(plista);
		printf("\n================================================================");
		printf("\n| ID   |     TITULO             |    GENERO    |      RATING  |");
		printf("\n================================================================");
		for(i=0;i<movieCont;i++)
		{
		peliculas=ll_get(plista,i);
			if(peliculas!=NULL)
			{
				movie_getId(peliculas,&idPeli);
				movie_getTitulo(peliculas,titulo);
				movie_getGenero(peliculas,genero);
				movie_getRating(peliculas,&rating);
				printf("\n|%4d  |%-20s    |%12s |%.2f          |",idPeli,titulo,genero,rating);
				printf("\n--------------------------------------------------------------");
				retorno =1;
			}
		}

	}
	return retorno;
}

int parser_movie(FILE* pFile , LinkedList* plista)
{
	eMovie* peliculas;
	int retorno=0;
	char idPeli[20],titulo[50],genero[20],rating[30];
	if(pFile!= NULL&&plista!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",idPeli,titulo,genero,rating);
		while(!feof(pFile))
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",idPeli,titulo,genero,rating)==4)
			{
				peliculas =movie_newParametros(idPeli,titulo,genero,rating);
				if(peliculas!=NULL)
				{
					ll_add(plista,peliculas);
					retorno=1;
				}
			}
		}
	}
    return retorno;
}


int parser_TextFromMovies(FILE* pFile , LinkedList* plista)
{
	eMovie* peliculas;
	int i,jugadorCont,retorno=0;
	int idPeli;
	char titulo[40];
	float  rating;
	char  genero[50];
	if(pFile!= NULL && plista!=NULL)
	{
		jugadorCont=ll_len(plista);
		for(i=0;i<jugadorCont;i++)
		{
			peliculas=ll_get(plista,i);
			movie_getId(peliculas,&idPeli);
			movie_getTitulo(peliculas,titulo);
			movie_getGenero(peliculas,genero);
			movie_getRating(peliculas,&rating);
			fprintf(pFile,"\n%4d %-10s %-10s %10f \n",idPeli,titulo,genero,rating);
		}
		retorno=1;
	}
    return retorno;
}
