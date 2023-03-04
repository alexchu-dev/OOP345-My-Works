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
      string tempStr{};
      Person* tempPer{};
      getline(in, tempStr, '\n');
      if (tempStr[0] == 'e' || tempStr[0] == 'E') {
         tempPer = new Employee(in);
      }
      else {
         throw ("Invalid!");
      }
      return tempPer;
   }
}
