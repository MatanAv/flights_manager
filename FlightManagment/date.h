/*
 * date.h
 *
 *  Created on: 14 Dec 2020
 *      Author: matan
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "generalFunc.h"

#ifndef DATE_H_
#define DATE_H_

typedef struct
{

	int day, month, year;

} Date;

int initDate(Date* d);
void printDate(Date* d);
int checkValidDate(char* date, int size);

#endif /* DATE_H_ */
