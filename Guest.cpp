/***********************************************************************
// OOP244 Workshop #02 p2: tester program
//
// File	Guest.cpp
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
#include "Guest.h"

namespace seneca {

    void set(Guest& guest, const char* first, const char* last, int age)
    {
        guest.m_firstName = nullptr;
        guest.m_lastName = nullptr;
        if (first != nullptr && first[0] != '\0' && last != nullptr && last[0] != '\0') {
            guest.m_firstName = new char[strlen(first) + 1];
            strcpy(guest.m_firstName, first);


            guest.m_lastName = new char[strlen(last) + 1];
            strcpy(guest.m_lastName, last);

            
            guest.m_adult = (age >= 18);
        }
        

    }

    void print(const Guest& guest)
    {

        if (guest.m_firstName == nullptr || guest.m_lastName == nullptr)
        {
            cout << "Vacated!" ;
        }
        else {

            cout << guest.m_firstName << " " << guest.m_lastName;
            if (!guest.m_adult)
                cout << "(Child)";
        }
        cout << endl;
    }

    void book(Guest& guest)
    {
        char firstName[100];
        cout << "Name: ";
        cin.getline(firstName, sizeof(firstName));
        

        char lastName[100];
        cout << "Lastname: ";
        cin.getline(lastName, sizeof(lastName));
      
        int age;
        cout << "Age: ";
        cin >> age;
        
        set(guest, firstName, lastName, age);

    }

    void vacate(Guest& guest) {
        if (guest.m_firstName != nullptr || guest.m_lastName != nullptr) {
            delete[] guest.m_firstName;
            delete[] guest.m_lastName;
            guest.m_firstName = nullptr;
            guest.m_lastName = nullptr;
            guest.m_adult = false;
        }
    }

}
