/******************************************************************************
//                    OOP345NDD - WS06 @ 28 Feb 2023
//Module:      Professor CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include <string>
#include "Utilities.h"
#include "Professor.h"
using namespace std;
namespace sdds {
   Professor::Professor(std::istream& is) : Employee(is)
   {
      getline(is, m_department, '\n');
      trim(m_department);
   }
   void Professor::display(ostream& out) const
   {
      Employee::display(out);
      out << m_department << "|" << " Professor";
   }
   std::string Professor::status() const
   {
      return std::string("Professor");
   }
   std::string Professor::department() const
   {
      return m_department;
   }
}