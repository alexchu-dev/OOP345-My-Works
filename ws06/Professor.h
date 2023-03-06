/******************************************************************************
//                    OOP345NDD - WS06 @ 28 Feb 2023
//Module:      Professor Header
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_PROFESSOR_H
#define SDDS_PROFESSOR_H
#include "Employee.h"
namespace sdds {
   class Professor :
      public Employee
   {
      std::string m_department;
   public:
      Professor(std::istream& is);
      void display(std::ostream& out) const;
      std::string status() const;
      std::string department() const;
   };
}
#endif
