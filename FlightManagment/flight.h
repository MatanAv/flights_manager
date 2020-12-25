/*
 * flight.h
 *
 *  Created on: 14 Dec 2020
 *      Author: matan
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "date.h"
#include "generalFunc.h"

#ifndef FLIGHT_H_
#define FLIGHT_H_

typedef struct
{

	char src[IATA_CHARS+1];			// Source
	char dst[IATA_CHARS+1];			// Destination
	int flightTime;
	Date* flightDate;

} Flight;

int initFlight(Flight* pF, const char* src, const char* dst);
void printFlight(const Flight* pF);
void freeFlight(Flight* pF);
int checkRouteEqualsFlight(const Flight* pF, const char* src, const char* dst);
int getNumOfFlightsInRoute(Flight** flights, int size, const char* src, const char* dst);

#endif /* FLIGHT_H_ */
