/******************************************************************************
//                    OOP345NDD - WS04 @ 6 Feb 2023
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H
#include <iostream>
#include <string>
namespace sdds {
   class Toy; //forward declaration
   //Aggregation
   class Child {
      std::string m_childName{};
      int age{};
      const Toy** tAgg{}; //this is the syntax of Dynamic Array Pointers of Aggregation. They have weaker relationship and they are responsible for their own destructors
   public:
      Child();
      Child(std::string name, int age, const Toy* toys[], size_t count);
      ~Child();
      Child(const Child& src);
      Child& operator=(const Child& src);
      Child(Child&& src);
      Child& operator=(Child&& src);
      size_t size() const;
      friend std::ostream& operator << (std::ostream& os, const Child& src);
   };
}
#endif