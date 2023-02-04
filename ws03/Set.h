/******************************************************************************
//                    OOP345NDD - WS03 @ 2 Feb 2023
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
#include <cmath>
#include "Collection.h"
#include "Pair.h"
namespace sdds {
   template<typename T>
   class Set : public Collection<T, 100> {
   public:
      //This is a member function override using polymorphism, when the object is a derived class of the base class, it will call this function instead of the base's. The following function compares if the left operand and right operand are the same, if it is then it will have no action and only gives a flag and exit. If it is not duplicated, it will run the "add()" from the base class, am example of truly polymorphism of C++.
      bool add(const T& item) override {
         bool duplicate{ false };
         for (unsigned int i = 0; i < this->size(); i++) {
            if (this->operator[](i) == item) {
               duplicate = true;
            }
         }
         if (duplicate == false && this->size() < 100)
         {
            this->Collection<T, 100>::add(item);
         }
         return duplicate;
      };
   };
   //This is a specialisation of the template, to specialise when the type is double, it checks if the two operands are having a minimal difference of 0.01. If it is less than 0.01 it will be consider the same and use the logic above and only add item when they are different. Due to the difference of signature and specialisation, it cannot call the add() from the base class and hence it has its own code.
   template<>
   bool Collection<double, 100>::add(const double& item) {
      bool duplicate{ false };
      for (unsigned int i = 0; i < this->size(); i++) {
         if (std::fabs(this->operator[](i) - item) <= 0.01) {
            duplicate = true;
         }
      }
      if (duplicate == false)
      {
         if (m_size < 100) {
            m_collection[m_size] = item;
            m_size++;
         }
      }
      return duplicate;
   };
}
#endif