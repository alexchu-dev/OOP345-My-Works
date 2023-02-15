/******************************************************************************
//                    OOP345NDD - WS05 @ 13 Feb 2023
//Module:      Movie Module Header
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>
namespace sdds {
   class Movie {
      std::string m_title{};
      size_t m_year{};
      std::string m_desc{};
   public:
      Movie() {};
      const std::string& title() const { return m_title; }
      Movie(const std::string& strMovie);
      friend std::ostream& operator << (std::ostream& os, const Movie& src);
      template<typename T>
      void fixSpelling(T& spellChecker) {
         spellChecker(m_title);
         spellChecker(m_desc);
      }
   };
}
#endif