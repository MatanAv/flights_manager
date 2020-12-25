/*
 * generalFunc.h
 *
 *  Created on: 14 Dec 2020
 *      Author: matan
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef GENERALFUNC_H_
#define GENERALFUNC_H_

#define MAX_LEN 255
#define IATA_CHARS 3

char* getStrExactLength(const char* str);
char* myGets(char* buf, size_t size);
int getIntFromUser(const char* msg);
void getIataFromUser(const char* msg, char* iata);
// TODO: ERROR MESSAGE

#endif /* GENERALFUNC_H_ */
