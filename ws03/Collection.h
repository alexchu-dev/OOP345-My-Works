/******************************************************************************
//                    OOP345NDD - WS03 @ 2 Feb 2023
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
      T m_collection[CAPACITY]{};
      unsigned int m_size{};  //Checked with prof, this one is not static. To match the requirements I used unsigned int rather than just int.
      static T dummy;   //This one is static instead
   public:
      Collection() {};

      //Virtual destructor so that it will call respective derived or base destructor
      virtual ~Collection() {};

      //A member function to retrieve the current size.
      unsigned int size() const {
         return m_size;
      };

      //Standard display function
      std::ostream& display(std::ostream& os = std::cout) const {
         os << "----------------------\n| Collection Content |\n----------------------" << std::endl;
         for (unsigned int i = 0; i < m_size; i++) {
            os << m_collection[i] << std::endl;
         }
         os << "----------------------" << std::endl;
         return os;
      };

      //Virtual function of base class. This function will check if current size is smaller than "capacity", then assign the received argument to the array and increase the counter by one.
      virtual bool add(const T& item) {
         bool itemAdded{ false };
         if (m_size < CAPACITY) {
            m_collection[m_size] = item;
            m_size++;
            itemAdded = true;
         }
         return itemAdded;
      };
      T operator[](unsigned int i)const {
         return i < m_size ? m_collection[i] : dummy;
      };
   };

   //Instantiate of a template object (dummy), outside of the class.
   template <typename T, unsigned int CAPACITY>
   T Collection<T, CAPACITY>::dummy{};

   //Specialisation of a template for specific types, outside of the class.
   template<>
   Pair Collection<Pair, 100>::dummy{ "No Key", "No Value" };
}
#endif