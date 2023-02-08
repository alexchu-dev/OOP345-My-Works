/******************************************************************************
//                    OOP345NDD - WS04 @ 6 Feb 2023
//Module:      Toy Module CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include "Toy.h"
//#define debug
namespace sdds {
   Toy::Toy(const std::string& toy)
   {
      std::string temp = toy;
      m_orderid = stoi(temp);
      temp.erase(0, temp.find(":") + 1);
      temp.erase(0, temp.find_first_not_of(" "));
      m_nameToy = temp.substr(0, temp.find(":"));
      m_nameToy.erase(m_nameToy.find_last_not_of(" ") + 1);
      temp.erase(0, temp.find(":") + 1);
      m_numItems = stoi(temp);
      temp.erase(0, temp.find(":") + 1);
      m_price = stod(temp);
#ifdef debug
      std::cout << "=============Debug=============\nOrderID: " << m_orderid << std::endl;
      std::cout << "M_name: " << m_name << std::endl;
      std::cout << "M_name length: " << m_name.length() << std::endl;
      std::cout << "Amount:" << m_amount << std::endl;
      std::cout << "Price:" << m_price << std::endl;
      std::cout << "Rest of Temp String:" << std::endl << temp << std::endl;
#endif
   }

   void Toy::update(const unsigned int numItems)
   {
      m_numItems = numItems;
   }

   std::ostream& operator<<(std::ostream& os, const Toy& src)
   {
      os << "Toy";
      os.setf(std::ios::right);
      os.width(8);
      os << src.m_orderid << ":";
      os.width(18);
      os << src.m_nameToy;
      os.width(3);
      os << src.m_numItems << " items";
      os.width(8);
      os << src.m_price << "/item  subtotal:";
      os.width(7);
      os << std::setprecision(2) << std::fixed << src.m_price * src.m_numItems << " tax:";
      os.width(6);
      os << std::setprecision(2) << std::fixed << src.m_price * src.m_numItems * src.m_hst << " total:";
      os.width(7);
      os << std::setprecision(2) << std::fixed << src.m_price * src.m_numItems * (1 + src.m_hst) << std::endl;
      os.unsetf(std::ios::right);
      return os;
   }
}
