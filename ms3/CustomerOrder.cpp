/*************************************************************************
//                    OOP345NDD - MS1 @ 20 Mar 2023
//Module:      CustomerOrder CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
******************************************************************************/
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "CustomerOrder.h"
using namespace std;
namespace sdds {
   size_t CustomerOrder::m_widthField = 0;
   CustomerOrder::CustomerOrder(const std::string& str)
   {
      Utilities util;
      bool more = true;
      size_t next_pos = 0u;
      std::vector<std::string> items;

      m_name = util.extractToken(str, next_pos, more);
      m_product = util.extractToken(str, next_pos, more);

      // This part can be done with the same idea as WS4, but since I have learnt container and algorithm, I'd do this with them to challenge. I assume there would be no memory leak due to this "Trick" of receiving the string in a vector form first.
      if (more) {
         while (more) {
            items.push_back(util.extractToken(str, next_pos, more));
         }
         m_cntItem = items.size();
         if (m_cntItem > 1) {
            m_lstItem = new Item * [m_cntItem];
            // The following is to practise for_each with lambda. It could be much easier by doing regular for loop to deep copy, again, this is just "for fun". Might have to take it off if it is not compatible with MS3.
            size_t i = 0;
            for_each(items.begin(), items.end(), [&](const std::string& item) {m_lstItem[i] = new Item(item); ++i; });
            m_widthField = (m_widthField < util.getFieldWidth()) ? util.getFieldWidth() : m_widthField;
         }
      }
      else {
         throw string("ERROR: in read-in data, possibly no item in the list.");
      }
   }
   CustomerOrder::CustomerOrder(const CustomerOrder& src)
   {
      throw string("ERROR: Object does not allow copy operations!");
   }
   CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
   {
      *this = std::move(src);
   }
   CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
   {
      if (this != &src) {
         deallocation();
         m_name = src.m_name;
         m_product = src.m_product;
         m_cntItem = src.m_cntItem;
         m_lstItem = src.m_lstItem;
         src.m_name = "";
         src.m_product = "";
         src.m_cntItem = 0;
         src.m_lstItem = nullptr;
      }
      return *this;
   }
   CustomerOrder::~CustomerOrder()
   {
      deallocation();
   }
   void CustomerOrder::deallocation() {
      std::for_each(m_lstItem, m_lstItem + m_cntItem, [](Item* item) { delete item; });
      /*for (auto i = 0u; i < m_cntItem; ++i) {
         delete m_lstItem[i];
      }*/
      delete[] m_lstItem;
      m_lstItem = nullptr;
   }
   bool CustomerOrder::isOrderFilled() const
   {
      return std::all_of(m_lstItem, m_lstItem + m_cntItem, [](const Item* item) { return item->m_isFilled; });
   }
   bool CustomerOrder::isItemFilled(const std::string& itemName) const
   {
      return std::all_of(m_lstItem, m_lstItem + m_cntItem, [&](const Item* item) {
         return (item->m_itemName == itemName) ? item->m_isFilled : true;
         });
   }
   void CustomerOrder::fillItem(Station& station, std::ostream& os)
   {
      for (size_t i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled) {
            if (station.getQuantity() > 0) {
               station.updateQuantity();
               m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
               m_lstItem[i]->m_isFilled = true;
               os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
               break;
            }
            else {
               os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
            }
         }
      }
   }
   void CustomerOrder::display(std::ostream& os) const
   {
      os << m_name << " - " << m_product << std::endl;
      for (size_t i = 0; i < m_cntItem; i++)
      {
         os << "[" << setw(6) << right << setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
         os << setw(m_widthField) << left << setfill(' ') << m_lstItem[i]->m_itemName << " - ";
         os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
      }
   }
}