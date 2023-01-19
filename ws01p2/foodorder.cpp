/******************************************************************************
//                    OOP345NDD - WS01 @ 15 Jan 2023
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "foodorder.h"
double g_taxrate;
double g_dailydiscount;
using namespace std;
namespace sdds {
   FoodOrder::FoodOrder(const FoodOrder& src)
   {
      *this = src;
   }
   FoodOrder& FoodOrder::operator=(const FoodOrder& src)
   {
      if (this != &src) {
         deallocate();
         if (src.m_customer != nullptr && src.m_food != nullptr)
         {
            strcpy(m_customer, src.m_customer);
            m_food = new char[strlen(src.m_food) + 1];
            strcpy(m_food, src.m_food);
            m_price = src.m_price;
            m_dailyspecial = src.m_dailyspecial;
         } 
         else {
            setEmpty();
         }
      }
      return *this;
   }
   FoodOrder::~FoodOrder()
   {
      //deallocate();
   }
   void FoodOrder::setEmpty()
   {
      m_customer[0] = '\0';
      m_food = nullptr;
      m_price = 0;
      m_dailyspecial = false;
   }
   void FoodOrder::deallocate()
   {
      delete[] m_food;
      m_food = nullptr;
   }
   std::istream& FoodOrder::read(std::istream& istr)
   {
      if (istr) {
         istr.getline(m_customer, 10, ',');

         //WS2 - Using a string to receive as temp, then using DMA to copy to a Cstring
         string temp;
         getline(istr, temp, ',');
         m_food = new char[temp.length() + 1];
         strcpy(m_food, temp.c_str());
         istr >> m_price;
         istr.ignore();
         char flag = '\0';
         istr.get(flag);
         if (flag == 'Y') {
            m_dailyspecial = true;
         }
         else { m_dailyspecial = false; }
      }
      else { setEmpty(); }
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
      if (m_customer[0]!='\0') {
         cout.width(10);
         cout << m_customer << "|";
         cout.width(25);
         cout << m_food << "|";
         cout.width(12);
         cout << fixed << setprecision(2) << taxPrice << "|";
         cout.unsetf(std::ios::left);
         if (m_dailyspecial) {
            cout.setf(std::ios::right);
            cout.width(13);
            cout << fixed << setprecision(2) << specialPrice;
            cout.unsetf(std::ios::right);
         }
         cout << endl;
      }
      else {
         cout << "No Order" << endl;
      }
      return cout;
   }
   
}
