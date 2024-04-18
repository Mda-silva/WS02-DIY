/***********************************************************************
// OOP244 Workshop #02 p2: tester program
//
// File	Room.h
// Version 1.0
// Date: September 25, 2023
// Author: Yosef Ashibani, Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Marquez DaSilva           Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#include "Guest.h"

namespace seneca {

	struct Room {
		char m_roomNumber[6];
		int m_noOfGuests;
		Guest* m_guests;
	};
	

	// sets the Room by allocating a dynamic array of guests and setting the room number 
	// (no validation is done for room number);
	void set(Room& room, int numberOfGuests, const char* roomNumber);

	// Prints the room number and names of the guests in the following lines with four 
	// spaces of indentaion 
	// See correct_output.txt for the exact format
	void print(const Room& room);

	// Books a room by receiving the room number, number of guests and the guest information.
	// See correct_output.txt for the exact format
	void book(Room& room);

	// vacates the room by dallocating all the memory used.
	void vacate(Room& room);
}