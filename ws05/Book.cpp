/******************************************************************************
//                    OOP345NDD - WS05 @ 13 Feb 2023
//Module:      Book Module CPP
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
#include "Book.h"
//#define debug
using namespace std;
sdds::Book::Book(const string& strBook)
{
   //Temp assigned as a copy of the received string. TempCopy is an array to store the first 3 strings and assign it to the corresponding member variables after processed.
   string temp = strBook;
   string tempCopy[3]{};
   for (int i = 0; i < 3; i++) {
      temp.erase(0, temp.find_first_not_of(" "));
      tempCopy[i] = temp.substr(0, temp.find(","));
      tempCopy[i].erase(tempCopy[i].find_last_not_of(" ") + 1);
      temp.erase(0, temp.find(",") + 1);
   }
   m_author = tempCopy[0];
   m_title = tempCopy[1];
   m_country = tempCopy[2];
   m_price = stod(temp);
   temp.erase(0, temp.find(",") + 1);
   m_year = stod(temp);
   temp.erase(0, temp.find(",") + 1);
   temp.erase(0, temp.find_first_not_of(" "));
   m_desc = temp.substr(0, temp.find("\n"));
#ifdef debug
   cout << "=============Debug=============" << endl;
   cout << "M_author: " << m_author << endl;
   cout << "M_author length: " << m_author.length() << endl;
   cout << "M_title:" << m_title << endl;
   cout << "M_country:" << m_country << endl;
   cout << "Price:" << m_price << endl;
   cout << "Year:" << m_year << endl;
   cout << "M_desc:" << m_desc << endl;
#endif
}

ostream& sdds::operator<<(ostream& os, const Book& src)
{
   os.setf(ios::right);
   os.width(20);
   os << src.m_author << " | ";
   os.width(22);
   os << src.m_title << " | ";
   os.width(5);
   os << src.m_country << " | ";
   os.width(4);
   os << src.m_year << " | ";
   os.width(6);
   os << setprecision(2) << fixed << src.m_price << " | ";
   os.unsetf(ios::right);
   os << src.m_desc << endl;
   return os;
}
