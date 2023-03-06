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
#include <string>
#include "Utilities.h"
#include "Employee.h"
#include "Professor.h"
#include "Student.h"
using namespace std;
namespace sdds {
   Person* buildInstance(istream& is)
   {
      string line{};
      stringstream tempStream{};
      Person* personPtr{};
      getline(is, line, '\n');
      tempStream << line;
      if (line[0] == 'e' || line[0] == 'E') {
         personPtr = new Employee(tempStream);
      }
      else if (line[0] == 's' || line[0] == 'S') {
         personPtr = new Student(tempStream);
      }
      else if (line[0] == 'p' || line[0] == 'P') {
         personPtr = new Professor(tempStream);
      }
      else {
         personPtr = nullptr;
      }
      return personPtr;
   }
   bool my_isdigit(std::string& s)
   {
      auto it = s.begin();
      while (it != s.end() && std::isdigit(*it)) ++it;
      return !s.empty() && it == s.end();
   }
   std::string& trim(std::string& s)
   {
      s.erase(0, s.find_first_not_of(" "));  // Erase leading spaces
      s.erase(s.find_last_not_of(" ") + 1);  // Erase trailing spaces
      return s;
   }
}
