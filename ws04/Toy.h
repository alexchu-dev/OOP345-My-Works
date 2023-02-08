/******************************************************************************
//                    OOP345NDD - WS04 @ 6 Feb 2023
//Module:      Toy Module Header
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
      unsigned int m_orderid{};
      std::string m_nameToy{};
      unsigned int m_numItems{}; //this is horizontal, number of items of the toy to be ordered
      double m_price{};
      double m_hst{ 0.13 };
   public:
      Toy() {};
      Toy(const std::string& toy);
      void update(const unsigned int);
      friend std::ostream& operator << (std::ostream& os, const Toy& src);
   };
}
#endif