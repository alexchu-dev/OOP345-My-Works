/******************************************************************************
//                    OOP345NDD - WS06 @ 28 Feb 2023
//Module:      Student Header
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
#include "Person.h"
#include <iostream>
#include <string>
#include <vector>
namespace sdds {
   class Student :
      public Person
   {
      std::string m_name{};
      std::string m_age{};
      std::string m_id{};
      std::string* m_courses{};
      size_t m_count{};
   public:
      Student(std::istream& is);
      ~Student();
      Student(const Student&) = delete;
      Student& operator=(const Student&) = delete;
      std::string status() const;
      std::string name() const;
      std::string age() const;
      std::string id() const;
      void display(std::ostream& os) const;
   };
}
#endif