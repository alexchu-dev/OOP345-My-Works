/******************************************************************************
//                    OOP345NDD - WS03 @ 31 Jan 2023
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
#include "Pair.h"
namespace sdds {
   template<typename T, unsigned int CAPACITY>
   class Collection
   {
      T m_collection[CAPACITY];
      int m_size{}; //or just int? check with prof.
      static T dummy; //this one is static
   public:
      Collection() {};
      ~Collection() {};
      int size();
      std::ostream& display(std::ostream& os = std::cout)const {
         os << "----------------------\n| Collection Content |\n----------------------" << std::endl;
         for (int i = 0; i < m_size; i++) {
            os << m_collection[i] << std::endl;
         }
         os << "----------------------" << std::endl;
         return os;
      };
      bool add(const T& item) {
         bool itemAdded{ false };
         if (m_size < CAPACITY) {
            m_collection[m_size] = item;
            m_size++;
            itemAdded = true;
         }
         return itemAdded;
      };
      T operator[](unsigned i)const {
         return i < m_size ? m_collection[i] : dummy;
      };

   };
   template <typename T, unsigned int CAPACITY>
   T Collection<T, CAPACITY>::dummy{};

   template<>
   Pair Collection<Pair, 100>::dummy{ "No Key", "No Val" };

   template<typename T, unsigned int CAPACITY>
   int Collection<T, CAPACITY>::size()
   {
      return m_size;
   }
}
#endif