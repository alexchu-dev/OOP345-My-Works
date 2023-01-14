#ifndef SDDS_FOODORDER.H_
#define SDDS_FOODORDER.H_
#include <iostream>
double g_taxrate;
double g_dailydiscount;
namespace sdds {
   class FoodOrder {
      char m_customer[10];
      char m_food[25];
      double m_price;
      bool m_dailyspecial;
   public:
      //need to write a constrcutor
      //need to write a read()
   };
}
#endif // !FOODORDER.H