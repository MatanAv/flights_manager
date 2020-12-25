/*
 * airline.h
 *
 *  Created on: 14 Dec 2020
 *      Author: matan
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "flight.h"
#include "generalFunc.h"

#ifndef AIRLINE_H_
#define AIRLINE_H_

typedef struct
{

	char* name;
	int numOfFlights;
	Flight** flightList;

} Airline;

int initAirline(Airline* al);
void printAirline(const Airline* al);
void freeAirline(Airline* al);
int addFlightToList(Airline* al, const char* src, const char* dst);
int getNumOfFlightsInLine(const Airline* al);
int expandFlightList(Airline* al);

#endif /* AIRLINE_H_ */
