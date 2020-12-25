/*
 * airportManager.h
 *
 *  Created on: 14 Dec 2020
 *      Author: matan
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "generalFunc.h"
#include "airport.h"

#ifndef AIRPORTMANAGER_H_
#define AIRPORTMANAGER_H_

typedef struct
{

	Airport* apList;
	int numOfAirports;

} AirportManager;

int initAirportManager(AirportManager* apm);
void printAirportManager(const AirportManager* apm);
void freeAirportManager(AirportManager* apm);
int addAirportToList(AirportManager* apm);
int expandAirportList(AirportManager* apm);
Airport* findAirportByIataCode(const AirportManager* apm, const char* iata);
int checkIfIataMatchToAirport(const AirportManager* apm, const char* iata);

#endif /* AIRPORTMANAGER_H_ */
