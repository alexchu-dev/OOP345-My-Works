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
   //SpellChecker receives a dictionary's file name and stores the contents as bad words and good words for substitution using the operator overload below
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
         file >> m_badWords[cnt];
         file >> m_goodWords[cnt];
         cnt++;
         /*getline(file, strWord);
         if (file) {
            size_t pos = strWord.find(" ");
            m_badWords[cnt] = strWord.substr(0, pos);
            strWord.erase(0, pos);
            m_goodWords[cnt] = strWord.erase(0, strWord.find_first_not_of(" "));
            cnt++;
         }*/
      } while (file && cnt < MAX_WORDS);
      file.close();
   }
   //This operator overload serves the functions to replace the bad words with the good ones. It uses find(), replace(), length() and string::npos which is something new in this two workshops.
   void SpellChecker::operator()(std::string& text)
   {
      for (size_t i = 0; i < MAX_WORDS; i++) {
         while (text.find(m_badWords[i]) != string::npos) {
            text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
            m_count[i]++;
         }
      }
   }
   //The following functions shows the records of how many word replacements have been made by the SpellChecker.
   void SpellChecker::showStatistics(std::ostream& out) const
   {
      out << "Spellchecker Statistics" << endl;
      for (size_t i = 0; i < MAX_WORDS; i++) {
         out.setf(ios::right);
         out.width(15);
         out << m_badWords[i] << ": " << m_count[i] << " replacements" << endl;
         out.unsetf(ios::right);
      }
   }

}
