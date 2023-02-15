/******************************************************************************
//                    OOP345NDD - WS05 @ 13 Feb 2023
//Module:      SpellChecker Module Header
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <string>
#define MAX_WORDS 6
namespace sdds {
   class SpellChecker {
      std::string m_badWords[MAX_WORDS]{};
      std::string m_goodWords[MAX_WORDS]{};
      size_t m_count[MAX_WORDS]{};
   public:
      SpellChecker(const char* filename);
      void operator()(std::string& text);
      void showStatistics(std::ostream& out) const;
   };
}
#endif