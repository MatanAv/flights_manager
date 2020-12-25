/*
 * menu.c
 *
 *  Created on: 17 Dec 2020
 *      Author: matan
 */

#include "menu.h"

void runMenu()
{

	AirportManager apm;
	Airline al;

	puts("Welcome to the airport manager program!\n");

	// Initializing Airport Manager //

	initAirportManager(&apm);

	int apToAdd = getIntFromUser("How many airports would you like to add? ");
	for (int i = 0; i < apToAdd; i++) {
		printf("\nAirport %d-\n\n", i+1);
		addAirportToList(&apm);
	}
	printf("\n");

	// Initializing Airline //

	initAirline(&al);

	// Menu //

	int choice;

	do {

		showOptions();
		choice = getIntFromUser("Enter your choice: ");
		switch(choice)
				{

					case 1:					// Add flight
						addFlightToAirlineList(&apm, &al);
						break;
					case 2:					// Add airport
						addAirportToList(&apm);
						break;
					case 3:					// Print airline data
						printAirline(&al);
						break;
					case 4:					// Print airport manager data
						printAirportManager(&apm);
						break;
					case 5:					// Get number of flights in route (2-directions)
						getNumOfFlightsBetween2Airports(&al);
						break;
					case -1:				// Exit
						puts("Goodbye!");
						break;
					default:
						puts("Wrong input!");
				}

	} while (choice != -1);

	freeAirportManager(&apm);
	freeAirline(&al);

}

void showOptions()
{

	puts("\nPlease choose one of this following options:\n");
	puts("1 - Add flight");
	puts("2 - Add airport");
	puts("3 - Print airline data");
	puts("4 - Print airport manager data");
	puts("5 - Get the number of flights between 2 airports (both directions)");
	puts("-1 - Exit\n");

}

void getNumOfFlightsBetween2Airports(const Airline* al)
{

	int sum = 0;
	char ap1[IATA_CHARS+1];
	char ap2[IATA_CHARS+1];

	getIataFromUser("Enter the 1st airport's IATA code: ", ap1);
	getIataFromUser("Enter the 2nd airport's IATA code: ", ap2);
	if(ap1 == NULL || ap2 == NULL)
		puts("Invalid input!");

	else {

		sum += getNumOfFlightsInRoute(al->flightList, al->numOfFlights,
				ap1, ap2);	// 1st direction
		sum += getNumOfFlightsInRoute(al->flightList, al->numOfFlights,
				ap2, ap1);	// 2nd direction

		printf("There are %d flights between both of the airports. \n", sum);

	}

}

int addFlightToAirlineList(const AirportManager* apm, Airline* al)
{

	char src[IATA_CHARS+1];
	char dst[IATA_CHARS+1];

	getIataFromUser("Enter the flight's source (IATA): ", src);
	if(src == NULL)
		return 0;

	getIataFromUser("Enter the flight's destination (IATA): ", dst);
	if(dst == NULL)
		return 0;

	if(!(checkIfIataMatchToAirport(apm,src) &&		// A check for if inserted IATA's are exist
			checkIfIataMatchToAirport(apm,dst))) {
		puts("Source/Destination isn't exist.");
		return 0;
	}

	addFlightToList(al,src,dst);
	return 1;

}
