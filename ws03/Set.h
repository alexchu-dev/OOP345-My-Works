/******************************************************************************
//                    OOP345NDD - WS03 @ 31 Jan 2023
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
// Inclusion Polymorphism
#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <iostream>
#include <string>
#include "Collection.h"
namespace sdds {
   template<typename T, unsigned int CAPACITY>
   class Set : public Collection<T, 100> {
   public:
      bool add(const T& item) {
         bool flag{ false };
         for (int i = 0; i < this->size(); i++) {
            std::cout << this[i];
         }

         this->Collection<T, 100>::add(item);
         bool itemAdded{ false };
         return flag;
      };
   };
}
#endif