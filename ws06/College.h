/******************************************************************************
//                    OOP345NDD - WS06 @ 28 Feb 2023
//Module:      College Header
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_COLLEGE_H
#define SDDS_COLLEGE_H
#include <vector>
#include "Person.h"
namespace sdds
{
   class College
   {
      std::vector<Person*> m_persons;
   public:
      College() {};
      ~College();
      College(const College& src) = delete;
      College& operator +=(Person* thePerson);
      void display(std::ostream& out) const;
   };
}

#endif