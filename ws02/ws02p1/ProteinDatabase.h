/******************************************************************************
//                    OOP345NDD - WS02 @ 24 Jan 2023
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/

#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_
#include <iostream>
#include <chrono>
namespace sdds {
   typedef class ProteinDatabase {
      std::string* m_arr{};
      long int m_noStrings{};
   public:
      ProteinDatabase() {};
      ProteinDatabase(const std::string filename);
      ~ProteinDatabase() {};
      ProteinDatabase(const ProteinDatabase& src);
      ProteinDatabase& operator=(const ProteinDatabase& src);
      ProteinDatabase(ProteinDatabase&& src);
      ProteinDatabase& operator=(ProteinDatabase&& src);
      size_t size();
      std::string operator[](size_t);
   };
}
#endif