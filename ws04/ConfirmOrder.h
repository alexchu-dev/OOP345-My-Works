/******************************************************************************
//                    OOP345NDD - WS04 @ 6 Feb 2023
//Module:      ConfirmOrder Module Header
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_CONFIRMORDER_H
#define SDDS_CONFIRMORDER_H
#include <iostream>
#include <string>
namespace sdds {
   class Toy; //forward declaration
   //Aggregation
   class ConfirmOrder {
      const Toy** m_toysOrder{};
   public:
   };
}
#endif