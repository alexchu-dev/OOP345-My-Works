/******************************************************************************
//                    OOP345NDD - WS05 @ 13 Feb 2023
//Module:      Book Module Header
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>
namespace sdds {
   class Book {
      std::string m_author{};
      std::string m_title{};
      std::string m_country{};
      size_t m_year{};
      double m_price{};
      std::string m_desc{};
   public:
      Book() {};
      const std::string& title() const { return m_title; }
      const std::string& country() const { return m_country; }
      const size_t& year() const { return m_year; }
      double& price() { return m_price; }
      Book(const std::string& strBook);
      friend std::ostream& operator << (std::ostream& os, const Book& src);

      //This is a template function which operates as a functor. It sits inside of the header.
      template<typename T>
      void fixSpelling(T& spellChecker)
      {
         spellChecker(m_desc);
      }
   };
}
#endif // !SDDS_BOOK_H
