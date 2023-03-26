/******************************************************************************
//                    OOP345NDD - MS1 @ 13 Mar 2023
//Module:      Station Header
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
******************************************************************************/
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include "Utilities.h"
namespace sdds {
   class Station
   {
      size_t m_id{};
      std::string m_name{};
      size_t m_serial{};
      size_t m_numInStock{};
      std::string m_desc{};
      static size_t m_widthField;
      static size_t id_generator;
   public:
      Station(const std::string& str);
      const std::string& getItemName() const;
      size_t getNextSerialNumber();
      size_t getQuantity() const;
      void updateQuantity();
      void display(std::ostream& os, bool full) const;
   };
}
#endif