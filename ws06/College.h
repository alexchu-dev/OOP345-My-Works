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
#include <list>
#include "Person.h"
namespace sdds
{
   class College
   {
      std::vector<Person*> m_persons;
   public:
      College() {};
      ~College();
      College(const College&) = delete;
      College& operator=(const College&) = delete;
      College& operator +=(Person* thePerson);
      void display(std::ostream& out) const;
      template<typename T>
      void select(const T& test, std::list<const Person*>& persons) {
         for (auto it = m_persons.begin(); it != m_persons.end(); it++) {
            if (test(*it))
               persons.push_back(*it);
         }
      }
   };
}

#endif