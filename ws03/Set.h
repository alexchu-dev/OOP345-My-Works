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
#include "Pair.h"
namespace sdds {
   template<typename T>
   class Set : public Collection<T, 100> {
      //T tempArray[100]{};
      unsigned int tempSize{};
   public:
      bool operator==(const Collection<T, 100>& RO) {
         return this->operator[] = RO.operator[];
      };
      bool add(const T& item) {
         bool flag{ false };
         //tempArray[tempSize] = item;
         //std::cout << "Debug: " << tempArray[tempSize];

         for (unsigned int i = 0; i < tempSize; i++)
         {
            //if (tempArray[i] == item) {
            if (item == Collection<T, 100>::operator[](i)) {
               std::cout << "DUPLICATED!" << std::endl;
            }
            else
            {
               this->Collection<T, 100>::add(item);
               flag = true;
            }
         }
         tempSize++;
         return flag;
      };

   };
}
#endif