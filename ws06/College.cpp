/******************************************************************************
//                    OOP345NDD - WS06 @ 28 Feb 2023
//Module:      College CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include <string>
#include "College.h"
using namespace std;
namespace sdds {
   College& College::operator+=(Person* thePerson)
   {
      m_persons.push_back(thePerson);
      return *this;
   }
   void College::display(std::ostream& out) const
   {
      cout << "-----------------------------------------" << endl;
      cout << " Test #1 Persons in the college!        |" << endl;
      cout << "-----------------------------------------" << endl;
      for (auto it = m_persons.begin(); it != m_persons.end(); it++) {
         (*it)->display(out);
      }

      cout << "-----------------------------------------" << endl;
      cout << " Test #2 Persons in the college!        |" << endl;
      cout << "-----------------------------------------" << endl;
      for (auto it = m_persons.begin(); it != m_persons.end(); it++) {
         cout.setf(ios::left);
         cout << "| ";
         cout.width(10);
         cout << (*it)->status();
         cout << "| ";
         cout.width(10);
         cout << (*it)->id();
         cout << "| ";
         cout.width(20);
         cout << (*it)->name();
         cout << "| ";
         cout.width(3);
         cout << (*it)->age();
         cout << "|" << endl;
      }
      cout << "-----------------------------------------" << endl;
   }
}