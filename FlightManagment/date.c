/*
 * date.c
 *
 *  Created on: 14 Dec 2020
 *      Author: matan
 */

#include "date.h"

int initDate(Date* d)
{

	char* date;
	int day,month,year;
	int check = 0;


	while(!check) {

		date = getStrExactLength("Please enter the date (dd/mm/yyyy): ");
		check = checkValidDate(date, strlen(date));		// the date changes to "dd mm yyyy"

		if (!check) {
			puts("Wrong input!");
			free(date);
		}

	}

	sscanf(date, "%d %d %d", &day, &month, &year);

	d->day = day;
	d->month = month;
	d->year = year;

	free(date);

	return 1;

}

void printDate(Date* d)
{

	char delimiter = '/';
	printf("%d%c%d%c%d", d->day, delimiter, d->month, delimiter, d->year);

}

int checkValidDate(char* date, int size)
{

	int day,month,year;

	if (size != 10)				// "dd/mm/yyyy" format has 10 chars
		return 0;

	if (*(date+2) != '/' || *(date+5) != '/')		// Check format
		return 0;

	*(date+2) = ' ';
	*(date+5) = ' ';

	for (int i = 0; i < size; i++)				// Checks if dd,mm,yyyy are all digits
		if (i != 2 && i != 5)
			if (!isdigit((int)*(date+i)))
				return 0;

	sscanf(date, "%d %d %d", &day, &month, &year);

	if (day < 1 || day > 31 || month < 1 || month > 12		// Check valid dates
			|| year < 1000 || year > 9999)
		return 0;

	// Now a check for specific invalid dates

	if (month == 2 && day > 28)
		return 0;
	if (month == 4 && day > 30)
		return 0;
	if (month == 6 && day > 30)
		return 0;
	if (month == 9 && day > 30)
		return 0;
	if (month == 11 && day > 30)
		return 0;

	return 1;	// In this function the date string will return in "dd mm yyyy" format

}

