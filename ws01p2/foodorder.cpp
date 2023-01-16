/******************************************************************************
//                    OOP345NDD - WS01 @ 15 Jan 2023
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
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
         char flag = '\0';
         istr.get(flag);
         if (flag == 'Y') {
            m_dailyspecial = true;
         }
         else { m_dailyspecial = false; }
      }
      else { m_customer[0] = '\0'; }
      return istr;
   }
   std::ostream& FoodOrder::display() const
   {
      static int counter = 1;
      double taxPrice = m_price * g_taxrate + m_price;
      double specialPrice = taxPrice - g_dailydiscount;
      cout.setf(std::ios::left);
      cout.width(2);
      cout << counter++ << ". ";
      if (m_customer.length()!=0) {
         cout.width(10);
         cout << m_customer << "|";
         cout.width(25);
         cout << m_food << "|";
         cout.width(12);
         cout << fixed << setprecision(2) << taxPrice << "|";
         cout.unsetf(std::ios::left);
         cout.setf(std::ios::right);
         cout.width(13);
         if (m_dailyspecial) {
            cout << fixed << setprecision(2) << specialPrice;
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
