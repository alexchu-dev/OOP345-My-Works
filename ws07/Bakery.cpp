/******************************************************************************
//                    OOP345NDD - WS06 @ 15 Mar 2023
//Module:      Bakery CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include <fstream>
#include "Bakery.h"
using namespace std;
namespace sdds {
   Bakery::Bakery(const std::string filename)
   {
      ifstream file(filename);
      string line;
      if (!file) {
         throw ("Filename incorrect!");
      }
      while (file)
      {
         getline(file, line);

      }
   }
}