/******************************************************************************
//                    OOP345NDD - WS04 @ 6 Feb 2023
//Module:      Child Module CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include "Child.h"

sdds::Child::Child(std::string name, int age, const Toy* toys[], size_t count) : m_nameChild(name), m_age(age), m_numToys(count)
{
   m_toys = new const Toy * [count];
   for (auto i = 0u; i < count; ++i) {
      m_toys[i] = new Toy(*(toys[i]));
   }
}

sdds::Child::~Child()
{
   for (auto i = 0u; i < m_numToys; ++i) {
      delete m_toys[i];
   }
   delete m_toys;
}
