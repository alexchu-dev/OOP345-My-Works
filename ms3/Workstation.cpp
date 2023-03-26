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

void sdds::Workstation::fill(std::ostream& os)
{
   if (!m_orders.empty()) m_orders.front().fillItem(*this, os);
}

bool sdds::Workstation::attemptToMoveOrder()
{
   bool ret = false;
   // If order is not empty, check if it is filled or not.
   if (!m_orders.empty()) {
      if (m_orders.front().isItemFilled(getItemName())) {
         //
      }
      return false;
   }
