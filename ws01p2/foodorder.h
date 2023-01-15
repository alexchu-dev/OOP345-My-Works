#ifndef SDDS_FOODORDER_H_
#define SDDS_FOODORDER_H_
#include <iostream>
#include <string>
namespace sdds {
   class FoodOrder {
      std::string m_customer;
      std::string m_food;
      double m_price = 0;
      bool m_dailyspecial = false;
   public:
      FoodOrder();
      std::istream& read(std::istream& istr);
      std::ostream& display() const;
   };
}
#endif