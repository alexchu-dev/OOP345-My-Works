/******************************************************************************
//                    OOP345NDD - WS05 @ 13 Feb 2023
//Module:      Movie Module CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"
//#define debug
using namespace std;
namespace sdds {
   Movie::Movie(const string& strMovie)
   {
      string temp = strMovie;
      temp.erase(0, temp.find_first_not_of(" "));
      m_title = temp.substr(0, temp.find(","));
      m_title.erase(m_title.find_last_not_of(" ") + 1);
      temp.erase(0, temp.find(",") + 1);
      m_year = stoi(temp);
      temp.erase(0, temp.find(",") + 1);
      temp.erase(0, temp.find_first_not_of(" "));
      m_desc = temp.substr(0, temp.find("\n"));
   }
   ostream& operator<<(ostream& os, const Movie& src)
   {
      os.setf(ios::right);
      os.width(40);
      os << src.m_title << " | ";
      os.width(4);
      os << src.m_year << " | ";
      os.unsetf(ios::right);
      os << src.m_desc << endl;
      return os;
   }
}
