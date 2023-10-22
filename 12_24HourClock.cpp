/**************************************
* Name: 12 and 24 Hour Clock; Project 1
* Author: Scotty Folker
* SNHU CS210
***************************************/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

// Variables
int hour = 0; // Hours for 12 hour clock
int minute = 0; // Minutes used for both clocks
int sec = 0; // Seconds used for both clocks
int hr24 = 0; // Separate variable for 24 hour clock hours
int menuInput;
bool exitChecker = true; // Turns to false and exits program if 4 is entered
string numStr; // Variable for convertToDoubleDigit
string amPm; // Variable for amPmChecker
// Methods

// Function to check for AM/PM
string amPmChecker(string amPm) {
	if (hr24 >=12) {
		amPm = "P M";
	}
	else {
		amPm = "A M";
	}
	return amPm;
}

// Function to convert 24 hour clock hours to double if less than 10
string convertToDoubleDigit(int num) {
	if (num < 10) {
		string numStr = to_string(num);

		numStr = '0' + numStr;

		return numStr;
	}

	return to_string(num);
}

// Function for 12 Hour Clock
string twelveHourClock(int hour, int minute, int sec) {
	return convertToDoubleDigit(hour) + ":" + convertToDoubleDigit(minute) + ":" + convertToDoubleDigit(sec) + " " + amPmChecker(amPm);
}

// Function for 24 Hour Clock
string twenty4HourClock(int hr24, int minute, int sec) {
	return convertToDoubleDigit(hr24) + ":" + convertToDoubleDigit(minute) + ":" + convertToDoubleDigit(sec);
}

// Prints time starting at zero
void printTime() {
	cout << "***************************  ***************************" << endl;
	cout << "*       12-Hour Clock     *  *        24-Hour Clock    *" << endl;
	cout << "*       " << twelveHourClock(hour, minute, sec) << "      *  *          " <<
		twenty4HourClock(hr24, minute, sec) << "       *" << endl;
	cout << "***************************  ***************************" << endl;
}
// Displays menu
void printMenu() {

	cout << "***************************\n";
	cout << "* 1 - Add One Hour        *\n";
	cout << "* 2 - Add One Minute      *\n";
	cout << "* 3 - Add One Second      *\n";
	cout << "* 4 - Exit Program        *\n";
	cout << "***************************\n";
}
// Tracks user input and takes appropriate course of action based on user input
void menuAction() {
	switch (menuInput) {
	case 1:
		hr24++;
		hour++;
		if (hr24 == 24) {
			hr24 = 0;
		}
		if (hour == 13) {
			hour = 1;
		}
		break;
	case 2:
		minute++;
		if (minute == 60) {
			hour++;
			hr24++;
			minute = 0;
			if (hour == 13) {
				hour = 1;
			}
			if (hr24 == 24) {
				hr24 = 0;
			}
		}
		break;
	case 3:
		sec++;
		if (sec == 60) {
			minute++;
			sec = 0;
			if (minute == 60) {
				hour++;
				hr24++;
				minute = 0;
				if (hour == 13) {
					hour = 1;
				}
				if (hr24 == 24) {
					hr24 = 0;
				}
			}
		}
		break;
	case 4:
		cout << "Exiting Clock Program" << endl;
		exitChecker = false;
		break;
	default:
		cout << "Invalid Entry. Please enter a valid menu option." << endl;
	}
}
// Main
// Prints time, displays menu, takes user input, changes time and displays clocks or exits program
int main() {

	while (exitChecker) {
		printTime();
		printMenu();
		cin >> menuInput;
		menuAction();
	}
	return 0;
}
