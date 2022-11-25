/*
 * funcionesParcial.c
 *
 *  Created on: 25 nov. 2022
 *      Author: Lenovo
 */
#include "funcionesParcial.h"

eMovie* movie_newParametros(char* idPeli,char* titulo,char* genero, char* rating)
{
	eMovie* peliculas;
	peliculas=(eMovie*)malloc(sizeof(eMovie));

	if(peliculas!=NULL)
	{
		movie_setId(peliculas,idPeli);
		movie_setTitulo(peliculas,titulo);
		movie_setGenero(peliculas,genero);
		movie_setRating(peliculas,rating);

		return peliculas;
	}
	return NULL;
}

int movie_setId(eMovie* this,char* id)
{
	 int retorno = -1;
	if(this != NULL && id > 0)
	{
		this->id_peli = atoi(id);
		retorno = 1;
	}
	return retorno;
}

int movie_setTitulo(eMovie* this,char* titulo)
{
	int retorno = 0;
	if(this != NULL && titulo != NULL)
	{
		strcpy(this->titulo,titulo);
		retorno = 1;
	}
	return retorno;
}

int movie_setRating(eMovie* this,char* rating)
{
	int retorno = -1;
	if(this != NULL && rating >= 0)
	{
		this->rating = atof(rating);
		retorno = 1;
	}
	return retorno;
}

int movie_setGenero(eMovie* this,char* genero)
{
	int retorno = 0;
	if(this != NULL && genero != NULL)
	{
		strcpy(this->genero,genero);
		retorno = 1;
	}
	return retorno;
}


int movie_getId(eMovie* this,int* id)
{
	int retorno=-1;
	if(this != NULL)
	{
		*id= this->id_peli;
		 retorno =1;
	}
	return retorno;
}

int movie_getTitulo(eMovie* this,char* titulo)
{
	int retorno=0;

	if(this != NULL)
	{
		strcpy(titulo,this->titulo);
		retorno = 1;
	}
	return retorno;
}

int movie_getRating(eMovie* this,float* rating)
{
	int retorno=-1;
	if(this != NULL)
	{
		*rating= this->rating;
		 retorno =1;
	}
	return retorno;
}

int movie_getGenero(eMovie* this,char* genero)
{
	int retorno=0;

	if(this != NULL)
	{
		strcpy(genero,this->genero);
		retorno = 1;
	}
	return retorno;
}

void ratingCriterioMap(void* this)
{
	eMovie* pelicula;
     float rating;
     char ratingC[30];
    if(this != NULL)
    {
    	pelicula=(eMovie*) this;
    	movie_getRating(pelicula, &rating);
        if(rating>0 &&rating<10)
        {
        	rating=1;
        }
        movie_setRating(pelicula, ratingC);
    }
}

int OrdenadoXGenero(void* p1,void* p2)
{
	int retorno=0;

    eMovie* unaPeli;
    eMovie* otraPeli;

    char peliUno[40];
    char peliDos[40];

    unaPeli = (eMovie*) p1;
    otraPeli = (eMovie*) p2;
    movie_getGenero(unaPeli,peliUno);
    movie_getGenero(otraPeli,peliDos);
    if(peliUno!=0 && peliDos!=0)
    {
    	retorno=strcmp(peliUno,peliDos);
    }
    return retorno;
}
