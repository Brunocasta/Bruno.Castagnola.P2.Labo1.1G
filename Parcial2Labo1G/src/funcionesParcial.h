/*
 * funcionesParcial.h
 *
 *  Created on: 25 nov. 2022
 *      Author: Lenovo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "parserLabo.h"
#include "controllerLabo.h"
#ifndef FUNCIONESPARCIAL_H_
#define FUNCIONESPARCIAL_H_

typedef struct
{
	int id_peli;
	char titulo[50];
	char genero[50];
	float rating;

}eMovie;

eMovie* movie_newParametros(char* idPeli,char* titulo,char* genero, char* rating);
int movie_setTitulo(eMovie* this,char* titulo);
int movie_setRating(eMovie* this,char* rating);
int movie_setGenero(eMovie* this,char* genero);
int movie_setId(eMovie* this,char* id);
int movie_getId(eMovie* this,int* id);
int movie_getTitulo(eMovie* this,char* titulo);
int movie_getRating(eMovie* this,float* rating);
int movie_getGenero(eMovie* this,char* genero);
int OrdenadoXGenero(void* p1,void* p2);
void ratingCriterioMap(void* this);
#endif /* FUNCIONESPARCIAL_H_ */
