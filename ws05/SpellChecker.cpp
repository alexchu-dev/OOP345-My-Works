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
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "SpellChecker.h"
using namespace std;
namespace sdds {
   SpellChecker::SpellChecker(const char* filename)
   {
      size_t cnt = 0;
      ifstream file(filename);
      if (!file)
      {
         throw "Bad file name!";
      }
      string strWord;
      do {
         getline(file, strWord);
         if (file) {
            size_t pos = strWord.find(" ");
            m_badWords[cnt] = strWord.substr(0, pos);
            strWord.erase(0, pos);
            m_goodWords[cnt] = strWord.erase(0, strWord.find_first_not_of(" "));
            cnt++;
         }
      } while (file && cnt < MAX_WORDS);
      file.close();
   }

   void SpellChecker::operator()(std::string& text)
   {
      for (auto i = 0; i < MAX_WORDS; i++) {
         size_t pos = text.find(m_badWords[i]);
         if (pos != string::npos) {
            text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
            m_count[i]++;
         }
      }
   }

   void SpellChecker::showStatistics(std::ostream& out) const
   {
      out << "Spellchecker Statistics" << endl;
      for (auto i = 0; i < MAX_WORDS; i++) {
         out.setf(ios::right);
         out.width(15);
         out << m_badWords[i] << ": " << m_count[i] << " replacements" << endl;
         out.unsetf(ios::right);
      }
   }

}
