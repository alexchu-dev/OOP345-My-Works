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
      setChild(name, age, toys, count, true);
   }

   Child::~Child()
   {
      deallocation();
   }
   /**********************************************************************************/
   /* The following two functions serve the purposes of reducing repetition on codes */
   /* on most cases occurs in this workshop. Assume inputs are always valid so these */
   /* codes are at minimal.                                                          */
   void Child::deallocation()
   {
      for (auto i = 0u; i < m_numToys; i++) {
         delete m_toys[i];
      }
      delete[] m_toys;
      m_toys = nullptr;
   }

   void Child::setChild(std::string name, int age, const Toy* toys[], size_t count, bool copy)
   {
      //Shallow copying
      m_nameChild = name;
      m_age = age;
      m_numToys = static_cast<unsigned int>(count);
      //Deep copying on resource only if toys is not nullptr. Boolean "copy" has the role of
      //redirecting to 2 different methods for constructor + copy constructor also the other
      //one for move constructor which is just rerouting pointer address
      if (toys) {
         if (copy) {
            m_toys = new const Toy * [count];
            for (auto i = 0u; i < count; i++) {
               m_toys[i] = new Toy(*(toys[i]));
            }
         }
         else {
            m_toys = toys;
         }
      }
   }
   /**********************************************************************************/

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
         delete[] m_toys;
         setChild(src.m_nameChild, src.m_age, src.m_toys, src.m_numToys, false);
         src.m_nameChild = "";
         src.m_age = 0;
         src.m_numToys = 0;
      }
      return *this;
   }
   size_t Child::size() const
   {
      return static_cast<size_t>(m_numToys);
   }
   std::ostream& operator<<(std::ostream& os, const Child& src)
   {
      static int call_cnt = 1;
      os << "--------------------------" << std::endl;
      os << "Child " << call_cnt++ << ": " << src.m_nameChild << " " << src.m_age << " years old:" << std::endl;
      os << "--------------------------" << std::endl;
      if (src.m_toys) {
         for (auto i = 0u; i < src.m_numToys; i++)
         {
            std::cout << *src.m_toys[i];
         }
      }
      else {
         std::cout << "This child has no toys!" << std::endl;
      }
      std::cout << "--------------------------" << std::endl;
      return os;
   }
}
