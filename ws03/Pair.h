/******************************************************************************
//                    OOP345NDD - WS03 @ 31 Jan 2023
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
#include <string>
#include "Collection.h"
namespace sdds {
   class Pair
   {
      std::string m_key{};
      std::string m_value{};
   public:
      Pair() {};
      const std::string& getKey() { return m_key; }
      const std::string& getValue() { return m_value; }
      Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};

      // TODO: Add here the missing prototypes for the members
      //           that are necessary if this class is to be used
      //           with the template classes described below.
      //       Implement them in the Pair.cpp file.
      std::ostream& display(std::ostream& os) const;
   };
   std::ostream& operator<<(std::ostream& os, const Pair&);
}
#endif