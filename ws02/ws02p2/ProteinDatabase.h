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
   class ProteinDatabase {
      std::string* m_arr{};
      size_t m_noOfStrings{};
   public:
      ProteinDatabase() {};
      ProteinDatabase(const std::string filename);
      ~ProteinDatabase();
      ProteinDatabase(const ProteinDatabase& src);
      ProteinDatabase& operator=(const ProteinDatabase& src);
      ProteinDatabase(ProteinDatabase&& src)noexcept;
      ProteinDatabase& operator=(ProteinDatabase&& src)noexcept;
      size_t size() const;
      std::string operator[](size_t index) const;
   };
}
#endif