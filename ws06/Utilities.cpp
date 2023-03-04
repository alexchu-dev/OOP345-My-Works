/******************************************************************************
//                    OOP345NDD - WS06 @ 28 Feb 2023
//Module:      Utilities CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include <sstream>
#include "Utilities.h"
#include "Employee.h"
using namespace std;
namespace sdds {
   Person* buildInstance(std::istream& in)
   {
      string line{};
      stringstream tempStream{};
      Person* personPtr{};
      getline(in, line, '\n');
      tempStream << line;
      if (line[0] == 'e' || line[0] == 'E') {
         personPtr = new Employee(tempStream);
      }
      else {
         personPtr = nullptr;
      }
      return personPtr;
   }
}
