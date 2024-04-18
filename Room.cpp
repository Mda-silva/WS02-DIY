/***********************************************************************
// OOP244 Workshop #02 p2: tester program
//
// File	Room.cpp
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
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include "Room.h"

using namespace std;
namespace seneca {

	void set(Room& room, int numberOfGuests, const char* roomNumber)
	{

        strncpy(room.m_roomNumber, roomNumber, sizeof(room.m_roomNumber) - 1);
        room.m_roomNumber[sizeof(room.m_roomNumber) - 1] = '\0'; // Null-terminate the string

        
    
        // Allocate memory for guests
        room.m_guests = new Guest[numberOfGuests];

        // Set the number of guests
        room.m_noOfGuests = numberOfGuests;

	}

    void print(const Room& room)
    {
        if (room.m_noOfGuests == 0) {

            cout << "Empty Room!" << std::endl;
        }

        else
        {
            cout << "Room Number: " << room.m_roomNumber << endl;

            int i;
            for (i = 0; i < room.m_noOfGuests; i++) {

                if (room.m_guests[i].m_firstName != nullptr || room.m_guests[i].m_lastName != nullptr)
                {
                    cout << "    "
                        << room.m_guests[i].m_firstName
                        << " " << room.m_guests[i].m_lastName;
                        if (!room.m_guests[i].m_adult) cout << "(Child)";
                        cout << endl;
                }
                else
                {
                    cout << "    "
                        << "Vacated!"
                        << endl;
                }
            }
        }
            


    }

    void book(Room& room)
    {
        int age;
        cout << "Room number: ";
        cin >> room.m_roomNumber;

        cout << "Number of guests: ";
        cin >> room.m_noOfGuests;
        cin.ignore();

        if (room.m_guests != nullptr)
        {
            vacate(room);
        }
        else if (room.m_guests == nullptr)
        {
            room.m_guests = new Guest[room.m_noOfGuests];
        }

        int i;
        for (i = 0; i < room.m_noOfGuests ; i++)
        {
            room.m_guests[i].m_firstName = new char[80];
            room.m_guests[i].m_lastName = new char[80];
           
            cout << i + 1 << ":" << endl;
            
            cout << "Name: ";
            cin >> room.m_guests[i].m_firstName;
            

            cout << "Lastname: ";
            cin >> room.m_guests[i].m_lastName;
            

            cout << "Age: ";
            cin >> age;
            if (age < 18)
            {
                room.m_guests[i].m_adult = false;
            }
            else
            {
                room.m_guests[i].m_adult = true;

            }   
        }
    }

    void vacate(Room& room)
    {

        for (int i = 0; i < room.m_noOfGuests; i++)
        {

            delete[] room.m_guests[i].m_firstName;
            delete[] room.m_guests[i].m_lastName;

            room.m_guests[i].m_firstName = nullptr;
            room.m_guests[i].m_lastName = nullptr;

        }


        delete[] room.m_guests;
        room.m_guests = nullptr;
        room.m_noOfGuests = 0;
    }






}