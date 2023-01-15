#include <iostream>
#include <iomanip>
#include "foodorder.h"
double g_taxrate;
double g_dailydiscount;
using namespace std;
namespace sdds {
   FoodOrder::FoodOrder() {
      m_customer[0] = '\0';
      m_food[0] = '\0';
      m_price = 0;
      m_dailyspecial = false;
   };
   std::istream& FoodOrder::read(std::istream& istr)
   {
      if(istr) {
         getline(istr, m_customer, ',');
         getline(istr, m_food, ',');
         istr >> m_price;
         istr.ignore();
         std::string flag;
         getline(istr,flag);
         if (flag == "Y") {
            m_dailyspecial = true;
         }
         else { m_dailyspecial = false; }
      }
      return istr;
   }
   std::ostream& FoodOrder::display() const
   {
      static int counter = 1;
      cout.setf(std::ios::left);
      cout.width(2);
      cout << counter++ << ". ";
      if (m_customer.length()!=0) {
         cout.width(10);
         cout << m_customer << "|";
         cout.width(25);
         cout << m_food << "|";
         cout.width(12);
         cout << fixed << setprecision(2) << m_price + m_price*g_taxrate << "|";
         cout.unsetf(std::ios::left);
         cout.setf(std::ios::right);
         cout.width(13);
         if (m_dailyspecial) {
            cout << fixed << setprecision(2) << (m_price + m_price * g_taxrate) - g_dailydiscount;
         }
         cout.unsetf(std::ios::right);
         cout << endl;
      }
      else {
         cout << "No Order" << endl;
      }
      return cout;
   }
}