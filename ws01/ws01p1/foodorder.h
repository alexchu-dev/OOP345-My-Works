/******************************************************************************
//                    OOP345NDD - WS01 @ 15 Jan 2023
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_FOODORDER_H_
#define SDDS_FOODORDER_H_
#include <iostream>
namespace sdds {
   class FoodOrder {
      char m_customer[10] = { '\0' };
      char m_food[25] = { '\0' };
      double m_price = 0;
      bool m_dailyspecial = false;
   public:
      FoodOrder();
      std::istream& read(std::istream& istr);
      std::ostream& display() const;
   };
}
#endif