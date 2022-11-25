/*
 * parserLabo.h
 *
 *  Created on: 25 nov. 2022
 *      Author: Lenovo
 */

#ifndef PARSERLABO_H_
#define PARSERLABO_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcionesParcial.h"
#include "LinkedList.h"
#include "controllerLabo.h"

int parser_listMovie(LinkedList* plista);
int parser_TextFromMovies(FILE* pFile , LinkedList* plista);
int parser_movie(FILE* pFile , LinkedList* plista);
#endif /* PARSERLABO_H_ */
