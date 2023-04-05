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
      if (!m_orders.empty()) {
         if (m_orders.front().isItemFilled(getItemName()) || this->getQuantity() <= 0) {
            if (m_pNextStation) {
               *m_pNextStation += std::move(m_orders.front());
               m_orders.pop_front();
            }
            else {
               if (!m_orders.front().isOrderFilled()) {
                  g_incomplete.push_back(std::move(m_orders.front()));
               }
               else { g_completed.push_back(std::move(m_orders.front())); }
               m_orders.pop_front();
            }
            moved = true;
         }
      }
      return moved;

      //bool moved = false;
      //// If order is not empty, check if it is filled or not. If it is empty, "move" will stay "false" as default.
      //if (!m_orders.empty()) {
      //   if (m_orders.front().isItemFilled(getItemName()) || this->getQuantity() <= 0) {
      //      if (!m_pNextStation) {
      //         g_completed.push_back(std::move(m_orders.front()));
      //         m_orders.pop_front();
      //      }
      //      else {
      //         *m_pNextStation += std::move(m_orders.front());
      //         m_orders.pop_front();
      //      }
      //   }
      //   else {
      //      if (!m_pNextStation) {
      //         g_incomplete.push_back(std::move(m_orders.front()));
      //         m_orders.pop_front();
      //      }
      //      else {
      //         *m_pNextStation += std::move(m_orders.front());
      //         m_orders.pop_front();
      //      }
      //   }
      //   moved = true;
      //}
      //return moved;
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
      os << (m_pNextStation ? m_pNextStation->getItemName() : "End of Line");
      os << endl;
   }

   Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
   {
      m_orders.push_back(std::move(newOrder));
      return *this;
   }
}