/******************************************************************************
//                    OOP345NDD - WS06 @ 28 Feb 2023
//Module:      Employee CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;
namespace sdds {
   Employee::Employee(std::istream& is)
   {
      string line;
      getline(is, line, ',');
   }
   std::string Employee::status() const
   {
      return std::string("Employee");
   }
   std::string Employee::name() const
   {
      return m_name;
   }

   std::string Employee::age() const
   {
      return m_age;
   }

   std::string Employee::id() const
   {
      return m_id;
   }

}