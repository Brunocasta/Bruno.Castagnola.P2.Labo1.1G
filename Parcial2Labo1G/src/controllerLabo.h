/*
 * controllerLabo.h
 *
 *  Created on: 25 nov. 2022
 *      Author: Lenovo
 */

#ifndef CONTROLLERLABO_H_
#define CONTROLLERLABO_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "funcionesParcial.h"
#include "parserLabo.h"

int controller_movie(char* path , LinkedList* plista);
int controller_guardarMoviesModoTexto(char* path , LinkedList* plista);
int controller_ordenarMovie(LinkedList* plista);

#endif /* CONTROLLERLABO_H_ */
