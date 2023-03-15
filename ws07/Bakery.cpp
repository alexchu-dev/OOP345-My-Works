/******************************************************************************
//                    OOP345NDD - WS06 @ 15 Mar 2023
//Module:      Bakery CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "Bakery.h"
using namespace std;
namespace sdds {
   /* Using map to map the enum to string for i/o */
   std::map<BakedType, std::string> bakedTypeNames{
    {BakedType::BREAD, "Bread"},
    {BakedType::PASTRY, "Pastry"}
   };

   Bakery::Bakery(const std::string filename)
   {
      ifstream file(filename);
      string line;
      string token;
      if (!file) {
         throw ("Filename incorrect!");
      }
      while (getline(file, line))
      {
         try {
            BakedGood bg;
            /* Retrieve first token and trim. In the case if we need it to be upper, we can use transform after trim:
            *  transform(token.begin(), token.end(), token.begin(), ::toupper); */
            trim(token = line.substr(0, 8));
            if (token == "Bread") bg.m_type = BakedType::BREAD;
            else if (token == "Pastry") bg.m_type = BakedType::PASTRY;
            bg.m_desc = trim(token = line.erase(0, 8).substr(0, 20));
            bg.m_shelfLife = stoi(line.erase(0, 20).substr(0, 14));
            bg.m_stock = stoi(line.erase(0, 14).substr(0, 8));
            bg.m_price = stod(line.erase(0, 8).substr(0, 6));
            m_collection.push_back(bg);
         }
         catch (const std::string msg) {
            cout << "ERROR: " << msg << endl;
         }
         catch (std::invalid_argument const& msg) {
            cout << "ERROR: " << msg.what() << endl;
         }
         catch (...) {
            cout << "Error(s) found in Bakery(const string) constructor ." << endl;
         }
      }
   }
   void Bakery::showGoods(std::ostream& os) const
   {
      //for (auto it = m_collection.begin(); it != m_collection.end(); ++it)
      //   os << *it;
      //The above iterator is also a regular "for" loop. Hence, using "for_each" from algorithm.
      for_each(m_collection.begin(), m_collection.end(), [&os](const BakedGood& src) {os << src; });
   }
   std::ostream& operator<<(std::ostream& os, const BakedGood& bg)
   {
      os << "* ";
      os << left << setw(10) << bakedTypeNames[bg.m_type] << " * ";
      os << setw(20) << bg.m_desc << " * ";
      os << setw(5) << bg.m_shelfLife << " * ";
      os << setw(5) << bg.m_stock << " * ";
      os << right << fixed << setprecision(2) << setw(8) << bg.m_price << " * " << endl;
      return os;
   }
   std::string& trim(std::string& s)
   {
      s.erase(0, s.find_first_not_of(" "));  // Erase leading spaces
      s.erase(s.find_last_not_of(" ") + 1);  // Erase trailing spaces
      return s;
   }
}