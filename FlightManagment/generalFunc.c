/*
 * generalFunc.c
 *
 *  Created on: 14 Dec 2020
 *      Author: matan
 */

#include "generalFunc.h"

char* getStrExactLength(const char* msg)	// *Requires to free the return string*
{

	char* theStr = NULL;
	char inpStr[MAX_LEN];

	puts(msg);
	myGets(inpStr, sizeof(inpStr));

	theStr = (char*)malloc((strlen(inpStr)+1)*sizeof(char));

	if(theStr != NULL)
		strcpy(theStr,inpStr);

	return theStr;

}

char* myGets(char* buf, size_t size)
{

	if(buf != NULL && size > 0)
	{
		if(fgets(buf,size,stdin))
		{
			buf[strcspn(buf,"\n")] = '\0';
			return buf;
		}
		*buf = '\0';
	}

	return NULL;

}

int getIntFromUser(const char* msg)
{
	int num;
	puts(msg);
	scanf("%d", &num);
	getchar();

	return num;
}

void getIataFromUser(const char* msg, char* iata)
{

	int check = 0;
	char* checkIata;

	while (!check) {

		checkIata = getStrExactLength(msg);

		if (strlen(checkIata) == IATA_CHARS) {

			for (int i = 0; i < IATA_CHARS; i++) {
				if (!isalpha((int)*(checkIata+i)))
					break;
				else {
					*(checkIata+i) = toupper((int)*(checkIata+i));
					if (i == IATA_CHARS-1)
						check = 1;
				}
			}

		}

		if (!check)
			printf("Invalid IATA code, please re-enter the code.\n");

	}

	strcpy(iata,checkIata);
	free(checkIata);

}
