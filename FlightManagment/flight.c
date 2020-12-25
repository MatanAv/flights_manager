/*
 * flight.c
 *
 *  Created on: 14 Dec 2020
 *      Author: matan
 */

#include "flight.h"

/**** Basic Functions *****/

int initFlight(Flight* pF, const char* src, const char* dst)
{

	int flHour, check = 0;

	if(strcmp(src,dst) == 0) {
		puts("Source and destination cannot be the same.");
		return 0;
	}

	strcpy(pF->src,src);
	strcpy(pF->dst,dst);

	while (!check) {

		flHour = getIntFromUser("Enter the flight's time (0-23): ");

		if (flHour < 0 || flHour > 23)
			printf("Wrong input!");
		else
			check = 1;

	}

	pF->flightTime = flHour;

	Date* d = (Date*)malloc(sizeof(Date));
	if (!d)
		return 0;
	if (!initDate(d))
		return 0;

	pF->flightDate = d;

	return 1;

}

void printFlight(const Flight* pF)
{

	printf("%s to %s\n", pF->src, pF->dst);
	printf("Flight time: %d\n", pF->flightTime);
	printf("Date: ");
	printDate(pF->flightDate);
	printf("\n");

}

void freeFlight(Flight* pF)
{

//	free(pF->dst);
//	free(pF->src);
	free(pF->flightDate);

}

int checkRouteEqualsFlight(const Flight* pF, const char* src, const char* dst)
{

	if(strcmp(pF->src,src) != 0)
		return 0;
	if(strcmp(pF->dst,dst) != 0)
		return 0;
	return 1;

}

int getNumOfFlightsInRoute(Flight** flights, int size, const char* src, const char* dst)
{

	int count = 0;

	for (int i = 0; i < size; i++)
		if (checkRouteEqualsFlight(flights[i], src, dst))
			count++;

	return count;

}

/**** Additional Functions *****/
