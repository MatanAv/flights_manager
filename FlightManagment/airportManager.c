/*
 * airportManager.c
 *
 *  Created on: 14 Dec 2020
 *      Author: matan
 */

#include "airportManager.h"
#include "airport.h"

/**** Basic Functions *****/

int initAirportManager(AirportManager* apm)
{

	apm->apList = (Airport*)malloc(sizeof(Airport));	// allocating memory for one airport
	if (!apm->apList)
		return 0;

	apm->numOfAirports = 0;

	return 1;

}

void printAirportManager(const AirportManager* apm)
{

	printf("Airports list:\n\n");

	for (int i = 0; i < apm->numOfAirports; i++) {
		printAirport(apm->apList+i);
		printf("\n");
	}

}

void freeAirportManager(AirportManager* apm)
{

	for (int i = 0; i < apm->numOfAirports; i++)
		freeAirport(apm->apList+i);
	free(apm->apList);

}

int addAirportToList(AirportManager* apm)
{

	Airport ap;

	if (!initAirport(&ap))
		return 0;

	for (int i = 0; i < apm->numOfAirports; i++)	 // checks if the airport is already exists
		if (checkEqualsByIata(apm->apList+i, &ap)) {
			puts("This airport is already exists.");
			return 0;
		}

	if (!expandAirportList(apm))
		return 0;

	apm->apList[apm->numOfAirports-1] = ap;		// adding the airport by value

	return 1;

}

Airport* findAirportByIataCode(const AirportManager* apm, const char* iata)
{

	for (int i = 0; i < apm->numOfAirports; i++)
		if (strcmp(apm->apList[i].iata,iata) == 0)
			return apm->apList+i;

	return NULL;

}

/**** Additional Functions *****/

int expandAirportList(AirportManager* apm)
{

	apm->numOfAirports++;
	apm->apList = (Airport*)realloc(apm->apList,		// Expand list by 1
			apm->numOfAirports*sizeof(Airport));

	if (!apm->apList)
		return 0;
	return 1;

}

int checkIfIataMatchToAirport(const AirportManager* apm, const char* iata)
{

	for (int i = 0; i < apm->numOfAirports; i++)
		if (strcmp(apm->apList[i].iata,iata) == 0)
			return 1;		// IATA code belongs to an airport from the list
	return 0;			// IATA code doesn't belong to any airport from the list

}
