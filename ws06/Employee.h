/******************************************************************************
//                    OOP345NDD - WS06 @ 28 Feb 2023
//Module:      Employee Header
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H
#include "Person.h"
namespace sdds
{
   class Employee :
      public Person
   {
      std::string m_name{};
      std::string m_age{};
      std::string m_id{};
   public:
      Employee(std::istream& is);
      std::string status() const;
      std::string name() const;
      std::string age() const;
      std::string id() const;
      void display(std::ostream&) const;
   };
}

#endif