/******************************************************************************
//                    OOP345NDD - WS02 @ 24 Jan 2023
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "ProteinDatabase.h"
using namespace std;
namespace sdds {
   ProteinDatabase::ProteinDatabase(const std::string filename)
   {
      std::ifstream fin(filename);
      if (fin.is_open() == false) {
         std::cout << "Cannot open file [" << filename << "]. Ignoring it!\n";
      }
      char prefix = '\0';
      while (fin) {
         fin >> prefix;
         if (prefix == '>')
         { }

         if (fin.fail())
            break;
      }
   }
   ProteinDatabase::ProteinDatabase(const ProteinDatabase& src)
   {
   }
}
