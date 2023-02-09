/******************************************************************************
//                    OOP345NDD - WS04 @ 6 Feb 2023
//Module:      ConfirmOrder Module CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include "ConfirmOrder.h"
namespace sdds {
   ConfirmOrder::~ConfirmOrder()
   {
      deallocation();
   }
   void ConfirmOrder::deallocation()
   {
      delete[] m_toysOrder;
      m_toysOrder = nullptr;
   }
   ConfirmOrder::ConfirmOrder(const ConfirmOrder& src)
   {
      *this = src;
   }

   ConfirmOrder& sdds::ConfirmOrder::operator=(const ConfirmOrder& src)
   {
      if (this != &src)
      {
         deallocation();
         m_numOrder = src.m_numOrder;
         if (src.m_toysOrder) {
            m_toysOrder = new const Toy * [m_numOrder];
            for (auto i = 0u; i < m_numOrder; i++) {
               m_toysOrder[i] = src.m_toysOrder[i];
            }
         }
      }
      return *this;
   }
   ConfirmOrder::ConfirmOrder(ConfirmOrder&& src) noexcept
   {
      *this = std::move(src);
   }
   ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& src) noexcept
   {
      if (this != &src) {
         deallocation();
         m_numOrder = src.m_numOrder;
         m_toysOrder = src.m_toysOrder;
         src.m_numOrder = 0;
         src.m_toysOrder = nullptr;
      }
      return *this;
   }
   ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
   {
      bool found = false;
      for (auto i = 0u; i < m_numOrder; i++) {
         if (m_toysOrder[i] == &toy) {
            found = true;
         }
      }
      if (found == false) {
         const Toy** temp_toysOrder = new const Toy * [++m_numOrder];
         for (auto i = 0u; i < m_numOrder - 1; i++) {
            temp_toysOrder[i] = m_toysOrder[i];
         }
         temp_toysOrder[m_numOrder - 1] = &toy;
         delete[] m_toysOrder;
         m_toysOrder = temp_toysOrder; //Passing address only.
      }
      return *this;
   }
   ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
   {
      bool found = false;
      for (auto i = 0u; i < m_numOrder; i++) {
         if (m_toysOrder[i] == &toy) {
            found = true;
            m_toysOrder[i] = nullptr;
         }
      }
      /****** Challenge Part - resize the array after setting nullptr above ******/
      //The algorithm is to first define a size-1 temp array, move all non nullptr pointers to temp
      //Then when it is a nullptr, we move the temp array pointer at current pos to the pos+1 of original source
      //The reason we do this is since the current pos is nullptr, we should +1 to next one.
      //After that we assign the src as nullptr again, which makes it a loop until it is all sorted.
      //Note that in else case the condition is m_numOrder-1 because it would exceed over m_numOrder in line 99 when i+1
      //At the end, we delete *this and resize it with size of (--m_numOrder) and move it back from the temp array.
      if (found == true) {
         const Toy** temp_toysOrder = new const Toy * [m_numOrder - 1];
         for (auto i = 0u; i < m_numOrder; i++) {
            if (m_toysOrder[i] != nullptr) {
               temp_toysOrder[i] = m_toysOrder[i];
            }
            else {
               if (i < m_numOrder - 1) {
                  temp_toysOrder[i] = m_toysOrder[i + 1];
                  m_toysOrder[i + 1] = nullptr;
               }
            }
         }
         delete[] m_toysOrder;
         --m_numOrder;
         m_toysOrder = temp_toysOrder; //Passing address only.
      }
      return *this;
   }
   std::ostream& operator<<(std::ostream& os, const ConfirmOrder& src)
   {
      os << "--------------------------" << std::endl;
      os << "Confirmations to Send" << std::endl;
      os << "--------------------------" << std::endl;
      if (src.m_toysOrder) {
         for (auto i = 0u; i < src.m_numOrder; i++)
         {
            std::cout << *src.m_toysOrder[i];
         }
      }
      else {
         std::cout << "There are no confirmations to send!" << std::endl;
      }
      std::cout << "--------------------------" << std::endl;
      return os;
   }
}