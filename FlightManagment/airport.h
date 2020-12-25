/*
 * airport.h
 *
 *  Created on: 14 Dec 2020
 *      Author: matan
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "generalFunc.h"

#ifndef AIRPORT_H_
#define AIRPORT_H_

typedef struct
{

	char* name;
	char* nation;
	char iata[IATA_CHARS+1];

} Airport;

int initAirport(Airport* ap);
void printAirport(const Airport* ap);
void freeAirport(Airport* ap);
int checkEqualsByIata(const Airport* ap1, const Airport* ap2);
int checkIfSameIataCode(const Airport* ap, char* iata);
char* fixAirportName(char* name);

#endif /* AIRPORT_H_ */
