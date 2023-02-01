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
namespace sdds {
   template<typename T, unsigned int CAPACITY>
   class Collection
   {
      T m_collection[CAPACITY];
      static int m_size; //or just int? check with prof.
      T dummy{};
   public:
      static int size();
      std::ostream& display(std::ostream& os = std::cout)const;
      bool add(const T& item);
      T& operator[](unsigned i)const;
   };
   template <typename T, unsigned int CAPACITY>
   int Collection<T, CAPACITY>::m_size{};

   template<typename T, unsigned int CAPACITY>
   inline static int Collection<T, CAPACITY>::size()
   {
      return m_size;
   }

   template<typename T, unsigned int CAPACITY>
   inline std::ostream& Collection<T, CAPACITY>::display(std::ostream& os) const
   {
      os << "----------------------\n| Collection Content |\n----------------------\n" << std::endl;
      for (int i = 0; i < m_size; i++) {
         os << m_collection[i] << std::endl;
      }
      os << "----------------------" << std::endl;
      return os;
   }

   template<typename T, unsigned int CAPACITY>
   inline bool Collection<T, CAPACITY>::add(const T& item)
   {
      bool itemAdded{ false };
      if (m_size < CAPACITY) {
         m_collection[m_size] = item;
         m_size++;
         itemAdded = true;
      }
      return itemAdded;
   }

   template<typename T, unsigned int CAPACITY>
   inline T& Collection<T, CAPACITY>::operator[](unsigned i) const
   {
      return i < CAPACITY ? m_collection[i] : dummy;
   }
}
#endif