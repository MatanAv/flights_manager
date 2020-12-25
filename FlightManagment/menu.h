/*
 * menu.h
 *
 *  Created on: 17 Dec 2020
 *      Author: matan
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "generalFunc.h"
#include "airportManager.h"
#include "airline.h"

#ifndef MENU_H_
#define MENU_H_

void runMenu();
void showOptions();
void getNumOfFlightsBetween2Airports(const Airline* al);
int addFlightToAirlineList(const AirportManager* apm, Airline* al);

#endif /* MENU_H_ */
