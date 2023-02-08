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
namespace sdds {
Child::Child(std::string name, int age, const Toy* toys[], size_t count)
{
   setChild(name,age,toys,count,true);
}

Child::~Child()
{
   deallocation();
}

void Child::deallocation()
{
   for (auto i = 0u; i < m_numToys; ++i) {
      delete m_toys[i];
   }
   delete[] m_toys;
   m_toys = nullptr;
}

void Child::setChild(std::string name, int age, const Toy* toys[], size_t count, bool copy)
{
   m_nameChild = name;
   m_age = age;
   m_numToys = count;
   if (toys) {
      if (copy) {
         m_toys = new const Toy * [count];
         for (auto i = 0u; i < count; ++i) {
            m_toys[i] = new Toy(*(toys[i]));
         }
      }
      else {
         m_toys = toys;
      }
   }
}

Child::Child(const Child& src)
{
   *this = src;
}

Child& Child::operator=(const Child& src)
{
   if (this != &src) {
      deallocation();
      setChild(src.m_nameChild, src.m_age, src.m_toys, src.m_numToys, true);
   }
   return *this;
}
Child::Child(Child&& src)noexcept
{
   *this = std::move(src);
}
Child& Child::operator=(Child&& src)noexcept
{
   if (this != &src) {
      deallocation();
      setChild(src.m_nameChild, src.m_age, src.m_toys, src.m_numToys, false);
      src.m_nameChild = {};
   }
}
}
