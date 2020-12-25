/*
 * airline.c
 *
 *  Created on: 14 Dec 2020
 *      Author: matan
 */

#include "airline.h"

/**** Basic Functions *****/

int initAirline(Airline* al)
{

	al->name = getStrExactLength("Enter the name of the airline: ");
	if(al->name == NULL)
		return 0;

	al->flightList = (Flight**)malloc(sizeof(Flight*));		// allocating memory for one airline
	if (!al->flightList)
		return 0;

	al->numOfFlights = 0;

	return 1;

}

void printAirline(const Airline* al)
{

	printf("%s flights list:\n\n", al->name);
	for (int i = 0; i < al->numOfFlights; i++) {
		printFlight(al->flightList[i]);
		printf("\n");
	}

}

void freeAirline(Airline* al)
{

	free(al->name);

	for (int i = 0; i < al->numOfFlights; i++) {
		freeFlight(al->flightList[i]);
		free(al->flightList[i]);
	}
	free(al->flightList);

}

int addFlightToList(Airline* al, const char* src, const char* dst)
{

	Flight* f = (Flight*)malloc(sizeof(Flight));
	if (!f)
		return 0;
	if (!initFlight(f,src,dst))
		return 0;

	if (expandFlightList(al))
		al->flightList[al->numOfFlights-1] = f;
	else
		return 0;

	return 1;

}

int getNumOfFlightsInLine(const Airline* al)
{

	char src[IATA_CHARS+1];
	char dst[IATA_CHARS+1];

	getIataFromUser("Enter the source IATA code: ", src);
	getIataFromUser("Enter the destination IATA code: ", dst);

	return getNumOfFlightsInRoute(al->flightList, al->numOfFlights, src, dst);

}

/**** Additional Functions *****/

int expandFlightList(Airline* al)
{

	al->numOfFlights++;
	al->flightList = (Flight**)realloc(al->flightList,		// Expand list by 1
			al->numOfFlights*sizeof(Flight*));

	if (!al->flightList)
		return 0;
	return 1;

}
