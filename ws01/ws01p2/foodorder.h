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
#include <string>
#include <cstring>
extern double g_taxrate;
extern double g_dailydiscount;
namespace sdds {
   class FoodOrder {
      char m_customer[10]{};
      char* m_food{};
      double m_price{ 0 };
      bool m_dailyspecial = false;
      void setEmpty();
      void deallocate();
   public:
      FoodOrder() {};
      FoodOrder(const FoodOrder&);
      FoodOrder& operator=(const FoodOrder&);
      ~FoodOrder();
      std::istream& read(std::istream& istr);
      std::ostream& display() const;
   };
}
#endif