/******************************************************************************
//                    OOP345NDD - MS1 @ 13 Mar 2023
//Module:      Station CPP
//Full Name  : Alex Chuplease
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
******************************************************************************/
#include <string>
#include <iostream>
#include <iomanip>
#include "Station.h"
using namespace std;
namespace sdds {
   size_t Station::m_widthField = 0;
   size_t Station::id_generator = 0;
   Station::Station(const string& str)
   {
      Utilities util;
      bool more = true;
      size_t next_pos = 0u;
      m_id = ++id_generator;
      m_name = util.extractToken(str, next_pos, more);
      m_serial = stoi(util.extractToken(str, next_pos, more));
      m_numInStock = stoi(util.extractToken(str, next_pos, more));
      m_widthField = (m_widthField < util.getFieldWidth()) ? util.getFieldWidth() : m_widthField;
      m_desc = util.extractToken(str, next_pos, more);
   }
   const std::string& Station::getItemName() const
   {
      return m_name;
   }
   size_t Station::getNextSerialNumber()
   {
      return m_serial++;
   }
   size_t Station::getQuantity() const
   {
      return m_numInStock;
   }
   void Station::updateQuantity()
   {
      (m_numInStock > 0) ? m_numInStock-- : 0;
   }
   void Station::display(std::ostream& os, bool full) const
   {
      os << setfill('0') << right << setw(3) << m_id << " | ";
      os << setfill(' ');
      os << setw(m_widthField) << left << m_name << " | ";
      os << setfill('0') << right << setw(6) << m_serial << " | ";
      os << setfill(' ');
      if (full) {
         os << setw(4) << right << m_numInStock << " | ";
         os << left << m_desc;
      }
      os << endl;
   }
}