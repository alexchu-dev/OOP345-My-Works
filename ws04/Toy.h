/******************************************************************************
//                    OOP345NDD - WS04 @ 6 Feb 2023
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#include <iostream>
#include <string>
namespace sdds {
   class Toy {
      int m_orderid{};
      std::string m_name{};
      int m_amount{};
      double m_price{};
      double m_hst{ 0.13 };
   public:
      Toy() {};
      Toy(const std::string& toy);
      void update(const int);
      friend std::ostream& operator << (std::ostream& os, const Toy& src);
   };
}
#endif