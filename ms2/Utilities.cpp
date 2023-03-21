/******************************************************************************
//                    OOP345NDD - MS1 @ 13 Mar 2023
//Module:      Utilities CPP
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
******************************************************************************/
#include "Utilities.h"
using namespace std;
namespace sdds {
   char Utilities::m_delimiter = ' ';
   void Utilities::setFieldWidth(size_t newWidth)
   {
      m_widthField = newWidth;
   }
   size_t Utilities::getFieldWidth() const
   {
      return m_widthField;
   }
   string Utilities::extractToken(const string& str, size_t& next_pos, bool& more)
   {
      string token;
      size_t found = str.find(m_delimiter, next_pos);
      token = str.substr(next_pos, found - next_pos);
      trim(token);
      if (found == next_pos) {
         more = false;
         string e = "Error: A delimiter is found at " + next_pos;
         throw (e);
      }
      else if (found != string::npos) {
         next_pos = found + 1;
         more = true;
      }
      else {
         more = false;
      }
      m_widthField = (m_widthField < token.length()) ? token.length() : m_widthField;
      //The below string var declaration is on purpose, seems Visual Studio has a bug when it goes to line 24 string token, it jumps to line 42 return line and back to line 25 and the token shown "Error reading characters of string" in the Auto console. Therefore, this redundant string assignment is solely for clearing the bug.
      string line = token;
      return line;
   }
   void Utilities::setDelimiter(char newDelimiter)
   {
      m_delimiter = newDelimiter;
   }
   char Utilities::getDelimiter()
   {
      return m_delimiter;
   }
   string& Utilities::trim(string& s)
   {
      s.erase(0, s.find_first_not_of(" "));  // Erase leading spaces
      s.erase(s.find_last_not_of(" ") + 1);  // Erase trailing spaces
      return s;
   }
}
