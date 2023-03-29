/******************************************************************************
//                    OOP345NDD - MS3 @ 26 Mar 2023
//Module:      Workstation CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
******************************************************************************/
#include <iostream>
#include <algorithm>
#include "Workstation.h"
using namespace std;
namespace sdds {
   void Workstation::fill(std::ostream& os)
   {
      if (!m_orders.empty()) m_orders.front().fillItem(*this, os);
   }

   bool Workstation::attemptToMoveOrder()
   {
      bool moved = false;
      // If order is not empty, check if it is filled or not. If it is empty, "move" will stay "false" as default.
      if (!m_orders.empty()) {
         CustomerOrder& order = m_orders.front();
         if (order.isItemFilled(getItemName())) {
            if (!m_pNextStation) {
               g_completed.push_back(std::move(order));
            }
            else {
               *m_pNextStation += std::move(order);
               m_orders.pop_front();
            }
         }
         else {
            if (!m_pNextStation) {
               g_incomplete.push_back(std::move(order));
            }
            else {
               *m_pNextStation += std::move(order);
               m_orders.pop_front();
            }
         }
         moved = true;
      }
      return moved;
   }

   void Workstation::setNextStation(Workstation* station = nullptr)
   {
      m_pNextStation = station;
   }

   Workstation* Workstation::getNextStation() const
   {
      return m_pNextStation;
   }

   void Workstation::display(std::ostream& os) const
   {
      os << getItemName() << " --> ";
      os << m_pNextStation ? m_pNextStation->getItemName() : "End of Line";
      os << endl;
   }

   Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
   {
      m_orders.push_back(std::move(newOrder));
      return *this;
   }
}