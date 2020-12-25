/*
 * airport.c
 *
 *  Created on: 14 Dec 2020
 *      Author: matan
 */

#include "airport.h"

/**** Basic Functions *****/

int initAirport(Airport* ap)
{

	char* name;
	int check = 0;

	do {
		name = getStrExactLength("Enter the airport's name: ");
		if(name == NULL)
			return 0;
		if (*(name) == ' ' || *(name+strlen(name)-1) == ' ')
			printf("first/last character cannot be space.\n");
		else
			check = 1;
	} while (!check);

	ap->name = fixAirportName(name);	// function returns the fixed name

	ap->nation = getStrExactLength("Enter the airport's nation: ");
	if(ap->name == NULL)
		return 0;

	getIataFromUser("Enter the IATA code: ", ap->iata);
	if (ap->iata == NULL)
		return 0;

	return 1;

}

void printAirport(const Airport* ap)
{

	printf("Name: %s\n", ap->name);
	printf("Nation: %s\n", ap->nation);
	printf("IATA Code: %s\n", ap->iata);

}

void freeAirport(Airport* ap)
{
	free(ap->name);
	free(ap->nation);
}

int checkIfSameIataCode(const Airport* ap, char* iata)
{

	int res = strcmp(ap->iata,iata);

	if (res == 0)
		return 1;
	else
		return 0;

}

int checkEqualsByIata(const Airport* ap1, const Airport* ap2)
{

	int res = strcmp(ap1->iata,ap2->iata);

	if (res == 0)
		return 1;
	else
		return 0;

}

/**** Additional Functions *****/

char* fixAirportName(char* name)		// Assuming that user has entered a normal sentence
{

	int inputLen = strlen(name);
	int numOfWords = 0;

	for (int i = 0; i < inputLen; i++)
		if (*(name+i) == ' ')  				// count words by number of spaces
			numOfWords++;


	// SINGLE WORD


	if (numOfWords == 0) {

		if(inputLen % 2 == 0)				// in case the word has even number of chars
			for (int i = 0; i < inputLen; i++)
				if (i%2==0)
					*(name+i) = toupper((int)*(name+i));
				else
					*(name+i) = tolower((int)*(name+i));
		else									// in case the word has odd number of chars
			*(name) = toupper((int)*(name));

		return name;

	}


	// SENTENCE


	char* newName = (char*)malloc((2*numOfWords+inputLen+1)*sizeof(char));	// 2 bytes for each space
	char* word;
	int wordLen;

	word = strtok(name," ");
	while (word != NULL) {

		if(strlen(word) % 2 == 0)		// in case the word has even number of chars
			for (int i = 0; i < strlen(word); i++)
				if (i%2==0)
					*(word+i) = toupper((int)*(word+i));
				else
					*(word+i) = tolower((int)*(word+i));

		else							// in case the word has odd number of chars
			*(word) = toupper((int)*(word));

		strcat(newName,word);

		wordLen = strlen(word);

		word = strtok(NULL," ");
		if (word != NULL)				// if there's another word, 2 spaces will be added
			strcat(newName,"  ");
		else if (wordLen % 2 == 1)		// if it's the last word, and this word is odd:
			*(newName+(strlen(newName)-wordLen)) =
					tolower((int)*(newName+(strlen(newName)-wordLen)));	// make lower the first letter

	}

	free(name);				// Won't be used anymore
	return newName;

}

